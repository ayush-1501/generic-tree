#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>child;
};

/*
10  
20  30  40  
50  60  70  80  90  100  
110  120  
*/

vector<int>arr={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
void zig_zag(Node *root){
    vector<vector<int>>ans;
    vector<int>temp;
    queue<Node*>mq;
    mq.push(root);
    queue<Node*>cq;
    bool flip=true;

    while(mq.size()>0){
        auto it=mq.front();
        mq.pop();
        temp.push_back(it->data);

        for(Node *c:it->child){
           cq.push(c);
        }

        if(mq.size()==0){
            mq=cq;
            queue<Node*>l;
            cq=l;
            if(flip){ans.push_back(temp),flip=false;}
            else{
                flip=true;
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            temp.clear();
        }
    }

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<'\n';
    }
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
   zig_zag(root);
}