#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>child;
};
vector<int>arr={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};

vector<int> path(Node* root,int x){
    if(root->data==x){
        return {root->data};
    }

    for(Node* c:root->child){
        vector<int>par=path(c,x);

        if(par.size()>0){
            par.push_back(root->data);
            return par;
        }
    }
    return vector<int>();
}

int main(){
    Node* root=NULL;
    stack<Node*>st;

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
        int x,y;cin>>x>>y;
        vector<int>ans1=path(root,x);
        vector<int>ans2=path(root,y);

        int n1=ans1.size()-1,n2=ans2.size()-1;
        while(ans1[n1]==ans2[n2]){
            --n1,--n2;
        }
        ++n1,++n2;
        cout<<n1+n2-1;

}