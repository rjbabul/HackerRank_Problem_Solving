#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 1000000007;
    bool flag=false;
    for(int i=2;i*i<=n;i++)if(n%i==0)flag= true;
    cout<<flag<<endl;
    return 0;
}
