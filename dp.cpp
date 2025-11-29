#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int solve(string &s1,string &s2, int n,int m,int dp[][1000]){
    if(n==0 or m==0){
        return 0;
    }
    if(s1[n-1]==s2[m-1]){
        return dp[n][m]=1+solve(s1,s2,n-1,m-1,dp);
    }
    else{
       return dp[n][m]=max(solve(s1,s2,n-1,m,dp),solve(s1,s2,n,m-1,dp));
    }
}
int BottomUp(string &s1,string &s2){
    int s1_len=s1.size();
    int s2_len=s2.size();
    int dp[1000][1000]={};
    for (int  i = 0; i < s1_len; i++)
    {
       for (int  j = 0; j < s2_len; j++)
       {
        if(s1[i-1]==s2[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
        }
        else{
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
       }
       return dp[s1_len][s2_len];
    }
    void PrintLCS(string &s1,string &s2,int n,int m,int dp[][1000],string op=""){
        if(n==0 and m==0){
            cout<<op<<" ";
            return;
        }
        if(s1[n-1]==s2[m-1]){
            PrintLCS(s1,s2,n-1,m-1,op+[n-1]);

        }else{
            if(dp[n][m]==dp[n-1][m]){
                PrintLCS(s1,s2,n-1,m,dp,op);
            }
            if(dp[n][m]==dp[n][m-1]){
                PrintLCS()
            }
        }
    }

}
int main(){
    // int a[]={10,9,3,5,4,11,7,8};
    // int n=8;
    // vector<int>v;
    // for (int i = 0; i < n; i++)
    // {
    //    if(v.size()==0 or a[i]>v.back()){
    //     v.push_back(a[i]);
    //    }
    //    else{
    //     int pos=upper_bound(v.begin(),v.end(),a[i])-v.begin();
    //     v[pos]=a[i];

    //    }
    // }
    // cout<<v.size()<<endl;
    int dp[100][1000];
    memset(dp,-1,sizeof(dp));
    string s1="abcde";
    string s2="acbde";
    solve(s1,s2,s1.size(),s2.size(),dp)<<endl;
  //  cout<<BottomUp(s1,s2);
    
}