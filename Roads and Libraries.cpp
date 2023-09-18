#include<bits/stdc++.h>
using namespace std;
vector<int>vt[100005];
int isVisit[100005];

void dfs(int s, int &cnt)
{
   cnt++;
   isVisit[s]=1;
   for(int i = 0; i<vt[s].size(); i++)
   {
       int v =vt[s][i];
       if(!isVisit[v])
        dfs(v, cnt);
   }
}
long long int getResult(long long int n , long long int c_road , long long int c_lib)
{

    if(c_lib<=c_road) return n*c_lib;
    long long int sum =0;
     for(int i=1;i<=n;i++)
     {
         int cnt=0;
         if(!isVisit[i])
         {

             dfs(i, cnt);
             sum+= (long long int)((cnt-1)*c_road + c_lib);
         }
     }
     return sum;
}
int main()
{
    freopen("input.txt", "r", stdin);
    long long int n  , m , c_road, c_lib;
    int t ;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>c_lib>>c_road;
        memset(vt, 0, sizeof(vt));
        memset(isVisit, 0 , sizeof(isVisit));
        int x, y;
        for(int i=0; i<m ; i++)
        {
            cin>>x>>y;
            vt[x].push_back(y);
            vt[y].push_back(x);
        }

        cout<<getResult(n,c_road, c_lib)<<endl;
    }
    return 0;
}
