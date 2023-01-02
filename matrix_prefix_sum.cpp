#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("I:\\input.txt","r",stdin);
    int n, m;
    cin>>n>>m;
    int matrix[100][100], sum[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) sum[i][j]= matrix[i][j];
            else if(i==0 ) sum[i][j]= matrix[i][j]+ sum[i][j-1];
            else if(j==0) sum[i][j]= matrix[i][j]+sum[i-1][j];
            else sum[i][j]= matrix[i][j]+ sum[i][j-1]+ sum[i-1][j] - sum[i-1][j-1];
        }
    }


     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    int ax,ay, bx,by,cx, cy, dx, dy;
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
    cout<<sum[dx][dy]-sum[cx][cy-1]- sum[bx-1][by]+ sum[ax-1][ay-1]<<endl;

    return 0;
}
