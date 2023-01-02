#include<bits/stdc++.h>
using namespace std;
typedef pair< double, double> pii;


double call(double x1, double y1, double x2, double y2){
  double c= x1*(y1-y2) - y1*(x1-x2);
  c/= (x2-x1);
  return c;

}
int main()
{
   freopen("I:\\round.txt","r",stdin);
   int t, n;
    cin>>t;
    while(t-- && cin>>n){
            vector< pii> vt;
            double x, y;
            double mx =0.00, ymx,xmx,mn;
            cin>>x>>y;
            mx=0.0;
            mn=INT_MAX;
            ymx=y;
            xmx=x;
            vt.push_back(pii(x,y));
         for(int i=1;i<n;i++){
            cin>>x>>y;
            vt.push_back(pii(x,y));
         }

         for(int i=1;i<n;i++){
                double cal= call(xmx, ymx, vt[i].first, vt[i].second);
            mx= cal>mx?cal:mx;
            mn= cal<mn?cal:mn;
            if(ymx<=vt[i].second) {ymx= vt[i].second;xmx= vt[i].first;}
         }
       if(mx>mn)
         cout<<mx-mn<<endl;
        else cout<<mx<<endl;

    }


    return 0;
}
