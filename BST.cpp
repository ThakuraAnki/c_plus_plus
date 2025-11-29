#include<iostream>
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
node* ArraytoBST(int *arr,int s,int e){
    if(s>e){
        return NULL;
    }
    int m=(s+e)/2;
    node* root=new node(arr[m]);
    root->left=ArraytoBST(arr,s,m-1);
    root->right=ArraytoBST(arr,m+1,e);
    return root;
}
void InOrder(node*root){
    if(!root)return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
bool isBST(node*root,int mi=INT_MIN,int mx=INT_MAX){
    if(!root){
        return true;
    }
    if(root->data<mi || root->data > mx){
        return false;
    }
    return isBST(root->left,mi,root->data -1)&&
            isBST(root->right,root->data +1,mx);
}
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node*root=ArraytoBST(arr,0,n-1);
    InOrder(root);
    cout<<endl;
    if(isBST(root)){
        cout<<"Yes This is BST"<<endl;
    }else{
        cout<<"This not an BST"<<endl;
    }

}