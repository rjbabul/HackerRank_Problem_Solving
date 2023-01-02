#include<bits/stdc++.h>
using namespace std;
long long int dp[1000][1000];

int dp_(string str, string st, int n, int m)
{

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0) dp[i][j]=j;
            else if(j==0) dp[i][j]=i;
            else if(str[i-1]==st[j-1]) dp[i][j]= min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]));
            else dp[i][j]= min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+1));
        }
    }

    return dp[n][m];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str, st;
    while(cin>>str>>st){
        cout<<dp_(str, st, str.length(), st.length())<<endl;
    }
    return 0;
}
