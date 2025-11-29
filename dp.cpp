#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int fibo(int n,int dp[]){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n];
}
int BottomApproach(int n){
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int solve(int n,vector<int>&dp){
    if(n==1){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
    if(n % 3==0){
        op1=solve(n/3,dp);
    }
    if(n % 2==0){
        op2=solve(n/2,dp);
    }
    op3=solve(n-1,dp);
    return min(op1,min(op2,op3))+1;
}
int solveBottomUp(int n){
    vector<int>dp(n+1);
    dp[1]=0;
    for(int i=2;i<=n;i++){
      int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
        if(i % 3==0)op1=dp[i/3];
        if(i % 2==0)op2=dp[i/2];
        op3=dp[i-1];
        dp[i]=min(op1,min(op2,op3))+1;
    }
    return dp[n];
}
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
}
    void PrintLCS(string &s1,string &s2,int n,int m,int dp[][1000],string op=""){
        if(n==0 and m==0){
            cout<<op<<" ";
            return;
        }
        if(s1[n-1]==s2[m-1]){
            PrintLCS(s1,s2,n-1,m-1,dp,op+s1[n-1]);

        }else{
            if(dp[n][m]==dp[n-1][m]){
                PrintLCS(s1,s2,n-1,m,dp,op);
            }
            if(dp[n][m]==dp[n][m-1]){
                PrintLCS(s1,s2,n,m-1,dp,op);
            }
        }
    }
int topDown(string &s1,strung &s2,int n,int m,int dp[][100]){
    //Base case.
    if(n==0)return m;
    if(m==0)return n;
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    //Recursive Case.
    if(s1[n-1]==s2[m-1]){
        return dp[n][m]=topDown(s1,s2,n-1,m-1,dp);
    }
    else{
        int op1=topDown(s1,s2,n-1,m-1,dp);
        int op2=topDown(s1,s2,n-1,m-1,dp);
        int op3=topDown(s1,s2,n-1,m-1,dp);
        return dp[n][m]=1+min(op1,min(op2,op3));
        
    }
}
int BottomUp(string &s1,string &s2){
    int n=s1.size();
    int m=s2.size();
    for (int i = 0; i <= n; i++)
    {
        for (int  j = 0; j <= m; j++)
        {
            if(i==0 and j==0){
                dp[i][j]=0;

            }else if(i==0){
                dp[i][j]=j;
            }else if(j==0){
                dp[i][j]=i;
            }else if(s1[])
        }
        
    }
    
}

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
    int dp[100][1000];
    memset(dp,-1,sizeof(dp));
    // string s1="abcde";
    // string s2="acbde";
        string s1="saturday";
    string s2="sunday";
    // cout<<solve(s1,s2,s1.size(),s2.size(),dp)<<endl;
    // PrintLCS(s1,s2,s1.size(),s2.size(),dp);
  //  cout<<BottomUp(s1,s2);
    
}