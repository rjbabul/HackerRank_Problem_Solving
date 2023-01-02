#include<bits/stdc++.h>
using namespace std;
int num[20];
int n, k;
int mn = INT_MIN;
void combination(int at_, int left){
    if(left>n - at_+1)return ;
    if(at_ == n+1){
        for(int i=1;i<=k;i++)cout<<num[i]<<" ";
        cout<<endl;
        return ;
    }

    if(left)
    {
        num[k-left+1] =at_;
        combination(at_+1, left-1);
    }
    combination(at_+1, left);
}
int main()
{
    cout<<mn<<endl;
    while(cin>>n>>k){
        combination(1, k);
    }

    return 0;
}
