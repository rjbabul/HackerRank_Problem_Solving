#include<bits/stdc++.h>
using namespace std;
typedef pair< int, int > pii;
bool cmp(pii a, pii b){

  return a.first + max(a.second, b.first)+ b.second <= b.first + max(b.second, a.first)+ a.second ;

}
int main()
{
    int a,b;
    int n;
    while(cin>>n){
            vector<pii> vt;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            vt.push_back(pii(a,b));
        }
        sort(vt.begin() , vt.end(), cmp);

         for(int i=0;i<n;i++){
            cout<<vt[i].first<<" "<<vt[i].second<<endl;
        }
    }
    return 0;
}
