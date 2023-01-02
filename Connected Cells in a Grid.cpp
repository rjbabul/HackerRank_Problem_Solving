#include <bits/stdc++.h>
using namespace std;

 int mx ;
 int visit[100][101];
 int n, m;

 void dfs(vector<vector<int> > & matrix,int r, int c, int cnt)
 {
     int row[]={1,-1,0,0,-1,-1,1,1};
     int col[]={0,0,1,-1,-1,1,-1,1};
     queue< pair<int, int > > q;
     q.push({r,c});

     visit[r][c]=1;

     while(!q.empty())
     {
         r=q.front().first;
         c=q.front().second;
         q.pop();
          for(int i=0;i<8;i++)
            {
                if(r+row[i]< 0 || r+row[i]==n || c+col[i]<0 || c+col[i]==m) continue;

                if(!visit[r+row[i]][c+col[i]] && matrix[r+row[i]][c+col[i]]==1)
                {
                    visit[r+row[i]][c+col[i]]=1;
                    cnt++;

                    q.push({r+row[i], c+col[i]});

                }
            }
     }

     mx= max(mx, cnt);
 }
int connectedCell(vector<vector<int> > matrix) {
    if(matrix.size()==0) return 0;
      n = matrix.size();
      m = matrix[0].size();
    mx=0;
    memset(visit, 0, sizeof(visit));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visit[i][j] && matrix[i][j]==1)
            {

                dfs(matrix,i,j,1);
            }
        }
    }

    return mx;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > matrix(n);
    int x;
    for (int i = 0; i < n; i++) {
      for(int j=0;j<m;j++) {
        cin>>x;
        matrix[i].push_back(x);
      }
        }
    int result = connectedCell(matrix);
    cout << result << "\n";

    return 0;
}

