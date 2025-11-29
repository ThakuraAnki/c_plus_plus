#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* MakeTree(){
    string ip;
    cin>>ip;
    if(ip=="false"){
        return NULL;
    }
    
    int val=stoi(ip);
    node*root=new node(val);
    string left,right;
    cin>>left;
    if(left=="true"){
    root->left=MakeTree();
    }
    cin>>right;
    if(right=="true"){
    root->right=MakeTree();
    }
    return root;
}
bool isBalance(node*root,int mi=INT_MAX,int mx=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data <=mi and root->data>mx and 
        isBalance(root,root->data,mx)and
        isBalance(root,mi,root->data)){
        return true;
    }else{
        return false;
    }
}

int main(){
    node* root=MakeTree();
    if(isBalance(root)){
        cout<<"True";
    }else{
        cout<<"False";
    }

}