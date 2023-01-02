#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int > pii;

bool cmp(pii a, pii b){
  return a.second* b.first > a.first*b.second;
}
int main()
{
    vector<pii> vt;
    int n, w,ans=0;
    int wt, cost;
    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>wt>>cost;
        vt.push_back({wt, cost});  /// make_pair cancel ekhn theke
    }

    sort(vt.begin(), vt.end(), cmp);

    for(int i=0;i<n;i++){
        int carry= min(w, vt[i].first);
        w-= carry;
        ans+= carry* vt[i].second;
    }
    cout<<ans<<endl;

    return 0;
}
