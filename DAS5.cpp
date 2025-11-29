#include<iostream>
using namespace std;

int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int largest=0;

    
    if(n1>largest)largest=n1;
    if (n2>largest)largest=n2;
    if(n3>largest) largest=n3;
     
    
   
    cout<<largest;
}