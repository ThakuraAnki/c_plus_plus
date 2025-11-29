#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
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
int CoinExchange(int amount,int *deno,int n){
    if(amount==0){
        return 0;
    }

    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(amount>=deno[i]){
            int chortAmount=amount-deno[i];
            int chotaAns=CoinExchange(chortAmount,deno,n);
            if(chotaAns!=INT_MAX){
            ans=min(ans,chotaAns+1);
            }
        }
    }
    return ans;
}
int main(){
    int deno[]={1,17,10};
    int n=3;
    int amount=85;
   cout<< CoinExchange(amount,deno,n);
}