#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>child;
};

vector<int>arr={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};

vector<int> NodeToPath(Node* root,int value){
    if(root->data==value){
        vector<int>ans;
        ans.push_back(root->data);
        return ans;
    }

    for(Node* c:root->child){
        vector<int>ptc=NodeToPath(c,value);

        if(ptc.size()>0){
            ptc.push_back(root->data);
            return ptc;
        }
    }
    return vector<int>();
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
  vector<int>ans=NodeToPath(root,110);
   for(int i:ans)cout<<i<<" ";
}  
    
