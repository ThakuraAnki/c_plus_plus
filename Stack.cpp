#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// ----------------------UsingVector-----------------------------------
class Stack{
    vector<int>v;
    public:
    void push_back(int val){
        v.push_back(val);
    }
    void pop(){
        v.pop_back();
    }
    int Get_size(){
      int n=  v.capacity();
        return n;
    }
    bool empty(){
        return v.size()==0;
    }
    int top(){
        int n=v.size();
        return v[n-1];
    }
};
// ----------------------------LinkList----------------------------------------
class node{
public:
    int data;
    node*next;
    node(int value){
        data=value;
        next=NULL;
    }
};
class Stacks{
    public:

    node*head;
    Stacks(){
        head=NULL;
    }
   void push_back(int value){
    if(head==NULL){
        head=new node(value);
    }else{
        node* NewNode=new node(value);
        NewNode->next=head;
        head=NewNode;
    }
   }
   void pop(){
    if(head==NULL){
        return;
    }
    node*temp=head;
    head=head->next;
    delete temp;
}
    int top(){
        return head->data;
    }
    bool empty(){
        return head==NULL;
    }
};
// -----------------------------------Queue-----------------------------------

class Queue{
    public:

    node* head;
    node*tail;
    Queue(){
        head=NULL;
        tail=NULL;
    }
   void push_back(int value){
    if(head==NULL){
        tail=head=new node(value);
    }else{
        node* NewNode=new node(value);
       
        tail->next=NewNode;
        tail=NewNode;

    }
   }
   void pop(){
    if(head==NULL){
        return;
    }
    node*temp=head;
    head=head->next;
    delete temp;
}
    int top(){
        return head->data;
    }
    bool empty(){
        return head==NULL;
    }
};
// -----------------------------------CheckIsBalance----------------------------
bool isBalance(char*a){
    stack<char>st;
    
    for(int i=0;a[i]!='\0';i++){
        switch (a[i]){
        case '[':
        case '{':
        case '(':
        st.push(a[i]);
        break;
        case ')':
        if(!st.empty() and st.top()!='('){
            return false;
        }
        st.pop();
        break;
        case ']':
         if(!st.empty() and st.top()!='['){
            return false;
        }
        st.pop();
        break;
        case '}':
         if(!st.empty() and st.top()!='{'){
            return false;
        }
        st.pop();
        break;
        }
    }
}
// --------------------------ReverseStack------------------------
void push_Bottom(stack<int>&s,int x){

    if(s.empty()){
        s.push(x);
        return;
    }
    int d=s.top();
    s.pop();
    push_Bottom(s,x);
    s.push(d);
    
}
void ReverseStack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int x=st.top();
    st.pop();
    ReverseStack(st);
    push_Bottom(st,x);
}
// -----------------------StockSpan--------------------------------
void StockSpan(vector<int>stock,vector<int> span){
    stack<int>s;
    
    s.push(0);
    span[0]=(1);
    for(int i=1;i<stock.size();i++){
        int currStock=stock[i];
        while(!s.empty() and currStock>=stock[s.top()] ){
            s.pop();
        }
        if(s.empty()){
            span[i]=i+1;
        }else{
            int prvHigh=s.top();
            span[i]=i-prvHigh;
        }
    }
    for(int i=0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
}
//------------------------NextGreater--------------------------
void NextGreater(int *arr,int *ans){
    stack<int>s;
    int n=5;

    for(int i=0;i<5;i++){
        while(!s.empty() and arr[s.top()]<arr[i]){
            ans[s.top()]=arr[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        ans[s.top()]=-1;
        s.pop();
    }
    for(int i=0;i<5;i++){
        cout<<ans[i]<<" ";
    }

}
int main(){
    int arr[]={6,8,0,1,3};
    int ans[100];
    NextGreater(arr,ans);



}