#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>child;
};

Node* build(vector<int>&arr){
    Node* root=NULL;
    stack<Node*>st;

    for(int i=0;i<arr.size();i++){
        if(arr[i]==-1){
            st.pop();
        }else{
            Node *it=new Node();
        }
    }
}

int main(){

}