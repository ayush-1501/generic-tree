#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    vector<Node*>child;
};



Node* build(vector<int>&arr){
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
    return root;
}

bool isMirror(Node* root1,Node* root2){
    if(root1->child.size()!=root2->child.size()){
        return false;
    }

    for(int i=0;i<root2->child.size();i++){
        Node* it1=root1->child[i];
        int j=root1->child.size()-i-1;
        Node* it2=root2->child[j];

        if(!isMirror(it1,it2)){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int>arr1={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    vector<int>arr2={11,21,51,-1,61,-1,-1,31,71,-1,81,111,-1,121,-1,-1,91,-1,-1,41,101,-1,-1,-1};

    Node* root1=build(arr1);
    Node* root2=build(arr2);

    cout<<isMirror(root1,root2);
}