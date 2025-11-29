#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int t=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
         int cnt=0;
            for(int k=i;k<=j;k++){
               sum+=arr[k];
               cnt++;
               if(sum==0){
                ans=max(ans,cnt);
                sum=0;
               }else{
                continue;
               }
            }
        }
    }
    cout<<ans<<endl;
    
}