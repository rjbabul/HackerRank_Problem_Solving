#include<bits/stdc++.h>
using namespace std;

int lmp(string str, string st)
{
    int n = str.length();
    int m= st.length();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j =1; j<=m;j++){
            if(str[i-1]== st[j-1]) dp[i][j]= dp[i-1][j-1]+1;
            else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}
int main()
{
    string str, st;
    st="Samsung";
    while(getline(cin, str)){
        int n= str.length(), m= st.length();

        int  c = lmp(str, st);

        if(c==st.length())cout<<"SRBD"<<endl;
        else cout<<"GHOST"<<endl;
    }
    return 0;
}
