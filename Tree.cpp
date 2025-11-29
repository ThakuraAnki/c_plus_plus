#include<iostream>
#include<queue>
using namespace std;
class node{
	public:
	int data;
	node*left;
	node*right;

	node(int val){
		data=val;
		left=right=NULL;
	}
};
node* BuildTree(){
	int d;
	cin>>d;
	if(d==-1)return NULL;
	node*root=new node(d);
	root->left=BuildTree();
	root->right=BuildTree();
	return root;
}
void PrintPreOrder(node*root){
	if(!root)return;
	cout<<root->data<<" ";
	PrintPreOrder(root->left);
	PrintPreOrder(root->right);
}
void PrintInOrder(node*root){
	if(!root)return;
	PrintPreOrder(root->left);
	cout<<root->data<<" ";
	PrintPreOrder(root->right);
}
void PrintPostOrder(node*root){
	if(!root)return;
	PrintPreOrder(root->left);
	PrintPreOrder(root->right);
	cout<<root->data<<" ";
}
int countNode(node*root){
	if(!root)return 0;
	return countNode(root->left)+countNode(root->right)+1;
}
int HieghtNode(node*root){
	if(!root)return 0;
	return max(HieghtNode(root->left),HieghtNode(root->right))+1;
}
int DiameterTree(node*root){
	if(!root)return 0;
	int op=HieghtNode(root->left)+HieghtNode(root->right);
	int op1=DiameterTree(root->left);
	int op2=DiameterTree(root->right);
	return max(op,max(op1,op2));
}
bool IsNode(node*root,int target){
	if(!root)return false;
	if(root->data==target){
		return true;
	}
	return IsNode(root->left,target);
	return IsNode(root->right,target);
}
void LevelOrderTraversal(node*root){
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* front=q.front();
		q.pop();
		if(front!=NULL){
			
			cout<<front->data<<" ";
			if(front->left!=NULL){
				q.push(front->left);
			}
			if(front->right!=NULL){
				q.push(front->right);
			}
		}else{
			cout<<endl;
			if(!q.empty()){
			q.push(NULL);
		}
	}
	}
}
void Mirror(node*root){
	if(!root)return;
	swap(root->left,root->right);
	Mirror(root->left);
	Mirror(root->right);
}
int main(){
	node*root=BuildTree();
	PrintPreOrder(root);
	cout<<endl;
	PrintInOrder(root);
	cout<<endl;
	PrintPostOrder(root);
	cout<<endl;
	cout<<countNode(root)<<endl;
	cout<<HieghtNode(root)<<endl;
	cout<<DiameterTree(root)<<endl;
	if(IsNode(root,8000)){
		cout<<"Yes Present"<<endl;
	}else{
		cout<<"Not Present"<<endl;
	}
	LevelOrderTraversal(root);
	cout<<endl;
	Mirror(root);
	LevelOrderTraversal(root);
	
}