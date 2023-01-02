#include<bits/stdc++.h>
using namespace std;
#define mx 100000
int marge[mx], phi[mx];

void call(  ){
      for(int i=1;i<mx;i++) phi[i]=i;
      memset(marge, 0, sizeof(marge));
      for(int i=2; i<mx; i++){
        if(!marge[i]){
            for(int j=i;j<mx;j+=i){
                marge[j]=1;
                phi[j]= phi[j]/i*(i-1);
            }
        }
      }
}
int main()
{
    int n ;
    call();
    while(cin>>n){
         cout<<phi[n]<<endl;
    }
    return 0;
}
