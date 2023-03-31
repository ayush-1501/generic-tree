#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>child;
};

vector<int>arr={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
Node* getTail(Node* root){
    while(root->child.size()==1){
        root=root->child[0];
    }
    return root;

}

void linearize(Node* root){
    for(Node* c:root->child){
        linearize(c);
    }

    while(root->child.size()>1){
        //storing last child
        Node *lc=root->child.back();
        //removing last child
        root->child.pop_back();
        //storing second last child
        Node *sl=root->child.back();
        Node *slt=getTail(sl);
        slt->child.push_back(lc);
    }
}

void levelOrder(Node* root){
    queue<Node*>mq;
    mq.push(root);

    queue<Node*>cq;
    while(mq.size()>0){
      auto it=mq.front();
      mq.pop();
      cout<<it->data<<"  ";

      for(Node *c:it->child){
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
   Node* root=NULL;

   for(int i=0;i<arr.size();i++){
    if(arr[i]==-1){
        st.pop();
    }else{
        Node* it=new Node();
        it->data=arr[i];
        if(st.size()>0){
            st.top()->child.push_back(it);
        }else{
            root=it;
        }
        st.push(it);
    }
   }

   levelOrder(root);
   cout<<"\n";
   linearize(root);
   levelOrder(root);
   }