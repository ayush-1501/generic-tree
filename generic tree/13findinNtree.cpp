#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>child;
};

vector<int>arr={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};

bool find(Node* root,int x){
   if(root->data==x){
    return true;
   }

   for(Node *c:root->child){
      bool temp=find(c,x);

      if(temp)return true;
   }

   return false;
}

int main(){
    stack<Node*>st;
    Node* root=nullptr;

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
    int x;cin>>x;
    cout<<find(root,x);
}