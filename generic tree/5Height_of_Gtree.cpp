#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>child;
};

vector<int>arr={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};


int height_of_Gtree(Node* root){
    int ans=-1;
    for(Node *c:root->child){
       int ch=height_of_Gtree(c);
       ans=max(ans,ch);
    }
    ans++;
    return ans;
}


int main(){
    stack<Node*>st;
    Node *root=NULL;

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

    cout<<height_of_Gtree(root);
}