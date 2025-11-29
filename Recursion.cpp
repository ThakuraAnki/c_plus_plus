// ----------------Recursin--------------------
#include<iostream>
#include<cstring>
using namespace std;
// -------------------Factorial-------------------
int factorial(int n){
    if(n==0)return 1;

    int ChortaAns=factorial(n-1);
    cout<<ChortaAns<<endl;
    int ans= n*ChortaAns;
    return ans;
}
// ----------------------PrintIncNo----------------------
void IncNo(int n){
    if(n==0)return;

    IncNo(n-1);
    cout<<n<<" ";

}
//-----------------------Fibonacci------------------------
int fibo(int n){
    if(n==0||n==1)return n;

    int sol=fibo(n-1);
    int sol1=fibo(n-2);

    return sol+sol1;
}
// ----------------------IsSorted--------------------------
bool IsSorted(int *arr,int n){
    if(n==0){
        return true;
    }
    bool agebat= IsSorted(arr+1,n-1);
    if(arr[0]<arr[1] && agebat){
        return true;
    } else{
        return false;
    }
}
// -------------------Iteration-----------------------------
int Find7(int *arr,int n,int target){

    if(n==0){
        return 0;
    }
       if(arr[n]==target){
        return n;
    }
    Find7(arr,n-1,target);
}
// -----------------------TailingProblem---------------------
int TailingFill(int n){
    if(n==1 ||n==2)return n;
    int s1=TailingFill(n-1);
    int s2=TailingFill(n-2);
    return s1+s2;

}
//----------------------RemoveDuplcate-----------------------
void RemoveDuplicates(string str,string ans,int*frq,int i){
    if(str[i]=='\0'){
        cout<<ans<<endl;;
        return;
    }
    if(frq[str[i]-'a']==0){
        frq[str[i]-'a']=1;
         ans+=str[i];
    }
    RemoveDuplicates(str,ans,frq,i+1);
}
//-----------------------BubbleSort--------------------------
int BubbleSort(int*arr,int i,int n){
    if(i==n){
        return 0;
    }

    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
    BubbleSort(arr,i+1,n);
}
// -------------------------TowerOfHanoi-------------------------
void TOH(int n,char Source,char Helper,char destination){
    if(!n)return;

    TOH(n-1,Source,destination,Helper);
        cout<<n<<" take dist "<<Source<<" From "<<destination<<endl;
    TOH(n-1,Helper,Source,destination);

}
// -------------------------Subsequences----------------------------
void PrintSubSequences(char * ch,char*ans,int i,int j){
    if(ch[i]=='\0'){
        ans[j]='\0';
        cout<<ans<<endl;
        return;
    }
    ans[j]=ch[i];
    PrintSubSequences(ch,ans,i+1,j+1);
    PrintSubSequences(ch,ans,i+1,j);

}
// ---------------------------Palindrome------------------------------
void PrintPalindrome(char *ch,int i){
    if(ch[i]=='\0'){
        cout<<ch<<endl;
        return;
    }
    for(int j=i;ch[j]!='\0';j++){
        swap(ch[i],ch[j]);
        PrintPalindrome(ch,i+1);
        swap(ch[i],ch[j]);
    }
}
// ------------------------------StringToInteger---------------------------

int  STI(string no,int n){
    if(n==0){
        return 0;
    }
    int digit=no[n-1]-'0';
    int cns=STI(no,n-1);
    return cns*10+digit;
}
// -------------------------------PrimeFactorisation---------------------------
void PrimeFactorisation(int n,int posi=2){
    if(n==0){
        return;
    }
    if(n%posi==0){
        cout<<posi<<" ";
        PrimeFactorisation(n/posi);
    }else{
        PrimeFactorisation(n,posi+1);
    }
}
//------------------------------MergeSort---------------------------------------
void mergeKro(int *arr,int *a,int *b,int s,int e){
    int i=s;
    int j=s;
    int m=(s+e)/2;
    int k=m+1;
    while(j<=m and k<=e ){
        if(a[j]<b[k]){
            arr[i++]=a[j++];
        }else{
            arr[i++]=b[k++];
        }
    }
    while(j<=m){
        arr[i++]=a[j++];
    }
    while( k<=e ){
         arr[i++]=b[k++];
    }
}
// ------------------------------//Merge Sort-------------------------------------
void MergeSort(int *arr,int s,int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    int a[100];int b[100];
    for(int i=s;i<=mid;i++){
        a[i]=arr[i];
    }
    for(int i=mid+1;i<=e;i++){
        b[i]=arr[i];
    } 
    MergeSort(a,s,mid);
    MergeSort(b,mid+1,e);
    mergeKro(arr,a,b,s,e);
}
// -----------------------------------RatInAMaze------------------------
bool PrintEscapeMaze(char maze[][5],int way[][5],int i,int j,int n,int m){
    //Base Case
    if(i==n-1 and j==m-1){
        way[i][j]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<way[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        return false;
    }
    way[i][j]=1;
    if(j+1<=m-1 && maze[i][j+1]!='X'){
       bool agebta=PrintEscapeMaze(maze,way,i,j+1,n,m);
       if(agebta){
            return true;
       } 
    }
      if(i+1<=m-1 && maze[i+1][j]!='X'){
       bool agebta=PrintEscapeMaze(maze,way,i+1,j,n,m);
       if(agebta){
            return true;
       } 
    }
    way[i][j]=0;
    return false;
}
// ----------------------------NQeenPlace--------------------------
bool IsSafe(int Board[][4],int i,int j,int n){
    int si=i;
    int sj=j;
    for(int k=0;k<i;k++){
        if(Board[k][j]){
            return false;
        }
    }
    //Check Right side.
    while(i>=0 && j<n){
        if(Board[i--][j++]){
            return false;
        }
    }
    i=si;
    j=sj;
     while(i>=0 && j>=0){
        if(Board[i--][j--]){
            return false;
        }
    }
    return true;
}
bool Qboard(int Board[][4],int i,int n){
    //Base case
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                 cout<<(Board[i][j]==1?'Q':'_')<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }


    for(int j=0;j<n;j++){
        if(IsSafe(Board,i,j,n)){
            Board[i][j]=1;
            bool agebta=Qboard(Board,i+1,n);
            if(agebta){
               return true;
            }else{
                Board[i][j]=0;
            }
        }
    }
    return false;
}
//----------------------PhoneKeypad-------------------------
char keys[10][10]={"ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX","YZ"};
void PrintKeyPad(char *a,int i,int j,char *op){
    //Base Case.
    if(a[i]=='\0'){
        op[j]='\0';
        cout<<op<<endl;
        return;
    }
    int d=a[i]-'0';
    for(int k=0;keys[d][k];k++){
        op[j]=keys[d][k];
        PrintKeyPad(a,i+1,j+1,op);
    }
}

// -------------------------------InversionCount---------------------
int mergeKro(int *arr, int s, int mid, int e){
    int temp[100];
    int i = s, j = mid + 1, k = s;
    int invCount = 0;
    while(i <= mid && j <= e){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    
    while(j <= e){
        temp[k++] = arr[j++];
    }
    
    for(i = s; i <= e; i++){
        arr[i] = temp[i];
    }
    
    return invCount;
}

int MergeSort(int *arr, int s, int e){
    int invCount = 0;
    if(s < e){
        int mid = (s + e) / 2;
        
        invCount += MergeSort(arr, s, mid);
        invCount += MergeSort(arr, mid + 1, e);
        invCount += mergeKro(arr, s, mid, e);
    }
    return invCount;
}


int main(){
    char a[]="01";
    char b[10]="";
    PrintKeyPad(a,0,0,b);



}