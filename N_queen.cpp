#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int > pii;
int main()
{
    int n, k;
    while(cin>>n>>k){
        map< pii, int > mp;
        int x,y;
        int xr, xc;
        cin>>xr>>xc;
        for(int i=0;i<k;i++){
            cin>>x>>y;
            mp[pii(x,y)]++;
        }
        x= xr; y=xc;
        int cnt=0;
        ///
        for(int i=xc+1;i<=n;i++)if(mp[pii(xr,i)]==0)cnt++;else break;

        for(int i=xc-1;i>=1;i--)if(mp[pii(xr,i)]==0)cnt++;else break;
        x= xr; y=xc;

        for(int i=xr+1;i<=n;i++)if(mp[pii(i,xc)]==0)cnt++;else break;
        for(int i=xr-1;i>=1;i--)if(mp[pii(i,xc)]==0)cnt++;else break;

        x= xr; y=xc;
        for(int i=xr+1,j=xc+1;i<=n && j<=n;i++,j++)if(mp[pii(i,j)]==0)cnt++;else break;
        for(int i=xr-1, j=xc-1;i>=1 && j>=1;i--,j--)if(mp[pii(i,j)]==0)cnt++;else break;

        x= xr; y=xc;
        for(int i=xr-1,j=xc+1;i>=1 && j<=n;i--,j++)if(mp[pii(i,j)]==0)cnt++;else break;

        for(int i=xr+1, j=xc-1;i<=n && j>=1;i++,j--)if(mp[pii(i,j)]==0)cnt++;else break;

        cout<< cnt<<endl;

    }
    return 0;
}
