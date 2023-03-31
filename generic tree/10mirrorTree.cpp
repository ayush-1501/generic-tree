#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>child;
};

vector<int>arr={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
/*
10  
20  30  40  
50  60  70  80  90  100  
110  120  
*/
void mirror(Node *root){
    if(root==NULL)return;
    int n = root->child.size();
    if(n<2)return;
 
    for (Node *c:root->child)mirror(c);
    reverse(root->child.begin(), root->child.end());
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
    Node* root;
   
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

   mirror(root);
   levelOrder(root);
}

