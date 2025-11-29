#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class  HEAP{
    vector<int>h;
   void heapify(int i){
        int l=2*i;
        int r=l+1;
        int a=i;
        if(l<h.size() and h[i]>h[l])a=l;
        if(r<h.size() and h[i]>h[r])a=r;
        if(a!=i){
        swap(h[i],h[a]);
        heapify(a);
        }

    }
public:
    HEAP(){
        h.push_back(-1);
    }
    void push(int val){
        h.push_back(val);
        int c=h.size()-1;
        int p=c/2;
        while(p>0 and h[c]<h[p] ){
            swap(h[c],h[p]);
            c=p;
            p=p/2;
        }
    }
   void pop(){
    swap(h[1],h[h.size()-1]);
    h.pop_back();
    heapify(1);
    }
   int top(){
     return h[1];
    }
    bool empty(){
        return h.size()==1;
    }
};
class cmp{
public:
    bool operator()(int a,int b){
        return a>b;
    }
};
int main(){
    // HEAP H;
    // H.push(5);
    // H.push(4);
    // H.push(3);
    // H.push(2);
    // H.push(1);

    // while(!H.empty()){
    //     cout<<H.top()<<" ";
    //     H.pop();
    // }
    priority_queue<int,vector<int>,cmp>h;
    h.push(6);
    h.push(5);
    h.push(4);
    h.push(3);
    h.push(2);
    h.push(1);
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }


}