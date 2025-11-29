#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int a[]={10,9,3,5,4,11,7,8};
    int n=8;
    vector<int>v;
    for (int i = 0; i < n; i++)
    {
       if(v.size()==0 or a[i]>v.back()){
        v.push_back(a[i]);
       }
       else{
        int pos=upper_bound(v.begin(),v.end(),a[i])-v.begin();
        v[pos]=a[i];

       }
    }
    cout<<v.size()<<endl;
    
}