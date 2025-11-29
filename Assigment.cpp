#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int d){
        data=d;
        next=NULL;
    }
};
void insertAtend(node*&head,node*&tail,int da){
    if(head==NULL){
        head=tail=new node(da);
        return ;
    }
    node*n=new node(da);
    tail->next=n;
    tail=n;
}
void RevseLL(node*&head,node*&tail){
    if(head==NULL or head->next==NULL){
        return ;
    }
    node* prv=NULL;
    node* cur=head;
    node* n;
    while(cur!=NULL){
        n=cur->next;
        cur->next=prv;
        prv=cur;
        cur=n;
    }
    
    swap(head,tail);

}
node*SplitKro(node*head,int k,int n){
  
    k=k%n;
       if(k==n){
        return NULL;
    }
    int i=1;
    while(i<k){
        head=head->next;
        i++;
    }
    node *h=head->next;
    head->next=NULL;
    return h;
}
node* merger(node* h1, node* h2){
    if(h1 == NULL) return h2;  
    node* temp = h1;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = h2;

    return h1;
}
void PrintLL(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    int n;
    cin>>n;
    int k;cin>>k;
    if(k==0){
        return 0;
    }
    node*head=NULL;
    node*tail=NULL;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        insertAtend(head,tail,data);
    }
    node*h=SplitKro(head,k,n);
  node*nh= merger(h,head);
  PrintLL(nh);

   

}