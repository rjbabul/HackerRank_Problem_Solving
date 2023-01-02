#include<bits/stdc++.h>
#define m 10007

using namespace std;
long long int ModPower(long long int n, long long int p){
     if(p==0) return 1%m;
     int x= ModPower(n, p/2)%m;
     if(p%2==1) return (n%m)*ModPower(n, p-1)%m;
     else return ((x%m)*(x%m))%m;

}

int main()
{
    long long int n, p;
    while(cin>>n>>p){
        cout<<ModPower(n, p)<<endl;
    }
    return 0;
}
