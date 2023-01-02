#include<bits/stdc++.h>
using namespace std;
long long int call(long long int n,long long int r){
 long long int ans=1;
 long long int mn = min(r, n-r);
 for(int i=1;i<=mn;i++){
    ans*= (n-i+1);
    ans/=i;
 }
 return ans;

}
int main()
{
    long long int n,r;
    while(cin>>n>>r){
        cout<<call(n,r)<<endl;
    }
    return 0;
}
