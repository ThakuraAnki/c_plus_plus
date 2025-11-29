#include<iostream>
using namespace std;
class Node{
public:

    int data;
    Node*next;

    Node(int val){
        data=val;
        next=NULL;
    }
};
class list{
public:
    Node* Head;
    Node*Tail;
    list(){
        Head=NULL;
        Tail=NULL;
    }               
    void push_front(int value){
        Node*newhead=new Node(value);
        
        if(Head==NULL){
            Head=Tail=newhead;
        }else{
            newhead->next=Head;
            Head=newhead;
        }
    }
    void push_back(int value){
        Node* newNode=new Node(value);
        if(Head==NULL){
            Head=Tail=newNode;
        }else{
        Tail->next=newNode;
        Tail = newNode;
        }
    }
     void push_middle(int val,int posi){
        Node* newNode=new Node(val);

        if(Head==NULL){
            return;
        }

        Node*t=Head;
        for(int i=0;i<posi-1;i++){
            t=t->next;
        }
        newNode->next=t->next;
        t->next=newNode;
    }
    void delete_front(){
        if(Head==NULL){
            return;
        }
        Node*temp=Head;
        Head=Head->next;
        delete temp;
    }
    void delete_back(){
        if(Head==NULL){
            return;
        }
        Node*temp=Head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        delete Tail;
        temp->next=NULL;
        Tail=temp;
    }
    void ReverseLL(){
        if(Head==NULL){
            return;
        }
        Node*cur=Head;
        Node*prv=NULL;
        Node*p;
        while(cur!=NULL){
            p=cur->next;
            cur->next=prv;
            prv=cur;
            cur=p;
        }
        swap(Head,Tail);
    }
    int get_size(){
        Node* temp=Head;
        int cnt=0;
        while(!temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    void RemoveIthLink(int posi){
        if(Head==NULL){
            return;
        }
        int size=get_size();
        Node*temp=Head; 
        for(int i=0;i<posi;i++){
            temp=temp->next;
        }
        Node*deltnode=temp->next;
        if(deltnode->next==NULL){
            return;
        }

        temp->next=temp->next->next;
        delete deltnode;

    }
};
 void PrintLL(Node*Head){
        Node*Temp=Head;
        while(Temp){
            cout<<Temp->data<<" ";
            Temp=Temp->next;
        }
    }
    bool IsCycle(Node*Head){
        Node*Fast=Head;
        Node*Slow=Head;
        while(Fast!=NULL and Fast->next!=NULL){
            Fast=Fast->next->next;
            Slow=Slow->next;
            if(Fast==Slow){
                cout<<"Yes Cycle."<<endl;
                return true;
            }
        }
        cout<<"No Cycle."<<endl;
         return false;
    }
        bool BreakCycle(Node*Head){
        Node*Fast=Head;
        Node*Slow=Head;
        Node*pf=Head;
        while(Fast!=NULL and Fast->next!=NULL){
            Fast=Fast->next->next;
            Slow=Slow->next;
            if(Fast==Slow){
               while(pf!=Fast){
                pf=pf->next;
               }
               Slow=Head;
               while(Slow!=Fast){
                pf=Fast;
                 Fast= Fast->next;
                Slow=Slow->next;
               }
               pf->next=NULL;
            }
        }
    }
    Node* Merge(Node*left,Node*right){
        Node*i=left;
        Node*j=right;

        list ans;

        while(i!=NULL && j!=NULL){
            if(i->data < j->data){
                ans.push_back(i->data);
                i=i->next;
            }else{
                ans.push_back(j->data);
                j=j->next;
            }
        }
        while(i!=NULL){ans.push_back(i->data);i=i->next;}
        while(j!=NULL){ans.push_back(j->data);j=j->next;}
        return ans.Head;

    }
    Node*RightSplitMid(Node*Head){
        Node*K=Head;
        Node*T=Head;
        Node*Prev=NULL;
        while(T!=NULL && T->next!=NULL){
            Prev=K;
            T=T->next->next;
            K=K->next;
        }
        if(Prev!=NULL){
        Prev->next=NULL;
        }
        
        return K;
    }
    Node* MergeSort(Node*Head){
        if(Head==NULL || Head->next==NULL){
            return Head;
        }
        Node*mid=RightSplitMid(Head);
        Node*left=MergeSort(Head);
        Node*right=MergeSort(mid);
       return Merge(left,right);
    }
     Node*ReverseLL(Node*Head){
        if(Head==NULL){
            return 0;
        }
        Node*cur=Head;
        Node*prv=NULL;
        Node*p;
        while(cur!=NULL){
            p=cur->next;
            cur->next=prv;
            prv=cur;
            cur=p;
        }
        return prv;
    }
    Node* Zig_zag(Node*Head){
        Node*SplitAtMId=RightSplitMid(Head);
        Node*RightHead=ReverseLL(SplitAtMId);
        Node*left=Head;
        Node*right=RightHead;
        Node*Tail=NULL;
        while(left!=NULL && right!=NULL){
           Node*leftNext=left->next;
           Node*rightNext=right->next;
           left->next=right;
           right->next=leftNext;
           Tail=right;
           left=leftNext;
           right=rightNext;
        }
        if(right!=NULL){
            Tail->next=right;
        }
    
        return Head;
    }
    
int main(){
    int n;
    cin>>n;
    list ll;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        ll.push_back(val);
    }
    Zig_zag(ll.Head);


     PrintLL(ll.Head);

    
}