/// Longest Palindrome Substring  O(N^2)

#include<bits/stdc++.h>
using namespace std;
#define mx_ 1002
int lcp[mx_][mx_];

int lcp_(string str){
 int mx=0;
 for(int i=0;i<str.length();i++){
        int k=0;
    for(int j=i;j<str.length();j++,k++){
        if(k==j)lcp[k][j]=1,mx=1;
        else if(str[k]== str[j] && k+1==j) lcp[k][j]=2,mx=2;
        else if(str[k] == str[j] && lcp[k+1][j-1]>=1) {
            lcp[k][j]=lcp[k+1][j-1]+2;
            mx= max(mx, j-k+1);
        }

    }
 }

 for(int i=0;i<str.length();i++){

    for(int j=0;j<str.length();j++){
     if(lcp[i][j]==0) cout<<". ";
      else  cout<<lcp[i][j]<<" ";
    }
    cout<<endl;
 }
 return mx;

}
int main()
{
    string str;
    while(cin>>str){
        memset(lcp, 0, sizeof(lcp));
        cout<<lcp_(str)<<endl;
    }
    return 0;
}
