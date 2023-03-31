#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data;
   vector<Node*>child;
};
vector<int>arr={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};

Node* remove_leaf(Node* root){
    if(root==NULL)return NULL; //if root is NULL return NULL

    if(root->child.size()==0){ //if root itself is leaf then return NULL
        delete root;
        return NULL;
    }

    for(int i=0;i<root->child.size();i++){//moving onto its child
        Node* child=root->child[i];
        if(child->child.size()==0){// if leaf then delete that node
            delete child;
            for(int j=i;j<root->child.size()-1;j++){// update the child vector as well
                root->child[j]=root->child[j+1];
            }
            root->child.pop_back();
            i--;
        }
    }
    
    for(int i=0;i<root->child.size();i++){  //recursive call
        root->child[i]=remove_leaf(root->child[i]);
    }
    return root;
}

void level_order(Node* root){
    queue<Node*>mq;
    mq.push(root);

    queue<Node*>cq;
    while(mq.size()>0){
        auto it=mq.front();
        mq.pop();
        cout<<it->data<<' ';

        for(Node* c:it->child){
            cq.push(c);
        }

        if(mq.size()==0){
            mq=cq;
            queue<Node*>temp;
            cq=temp;
            cout<<'\n';
        }
    }
}

int main(){
    stack<Node*>st;
    Node* root=nullptr;

    for(int i=0;i<arr.size();i++){
       if(arr[i]==-1){
        st.pop();
       }else{
        Node *t=new Node();
        t->data=arr[i];

        if(st.size()>0){
          st.top()->child.push_back(t);
        }else{
            root=t;
        }
        st.push(t);
       }
   }
   cout<<"Level order traversal before deletion\n";
   level_order(root);
   remove_leaf(root);
   cout<<"\nLevel order traversal after deletion\n";
   level_order(root);
    
}