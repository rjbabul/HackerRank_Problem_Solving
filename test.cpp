#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int visited[100004];
typedef long long int  ll;
vector< ll > vt[100004];
ll total_cities;
ll bfs_(ll s, vector<ll > vt[], ll c_lib, ll c_road){
    ll cost=10000000000;
    ll cnt=0;
    queue<ll >q;
    q.push(s);cnt++;visited[s]++;
    while(!q.empty()){
        s=q.front();

        q.pop();
        for(int i=0;i<vt[s].size();i++){
            int u= vt[s][i];
            if(!visited[u]){
                cnt++;
                visited[u]++;
                q.push(u);
            }
        }
    }
    ll temp_lib = c_lib;
    ll temp_road= (cnt-1)*c_road;
    total_cities+=cnt;

    for(int r=cnt;r>=1;r--){
        cost= min(cost,temp_lib+ temp_road);
        temp_lib+= c_lib;
        temp_road-= c_road;
    }
    return cost;
}

ll roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int> > cities) {
    memset(visited,0,sizeof(visited));total_cities=0;
    ll v=0, u=0;
    set<ll> st;
    set<ll> ::iterator x;
    ll total_cost=0;
    for(int i=0;i<cities.size();i++){
        u = cities[i][0];
        v = cities[i][1];
        vt[u].push_back(v);
        vt[v].push_back(u);

        st.insert(v);st.insert(u);
    }

    for(x= st.begin(); x !=st.end();x++){

        if(!visited[*x]) total_cost+= bfs_(*x,vt,c_lib, c_road);
    }
    if(n>total_cities) total_cost+= (n-total_cities)*c_lib;
    return total_cost;
}

int main()
{
    int q;
    freopen("I:\\input.txt", "r", stdin);
    cin>>q;
   int n, m, c_lib, c_road;

    for (int q_itr = 0; q_itr < q; q_itr++) {
         cin>>n>>m>>c_lib>>c_road;


        vector<vector<int> > cities;
        vector<int > vs;
        int x, y;
        for (int i = 0; i < m; i++) {
            cin>>x>>y;
            vs.push_back(x);
            vs.push_back(y);

            cities.push_back(vs);
            vs.clear();
        }


        long result = roadsAndLibraries(n, c_lib, c_road, cities);

       cout<<result<<endl;
    }



    return 0;
}

