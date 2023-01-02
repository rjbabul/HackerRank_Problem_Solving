#include<bits/stdc++.h>
using namespace std;
int mn[10000];
int num[1000];

void built_seg(int pos,int l, int r){

    if(l==r){
        mn[pos]= num[l];
        return ;
    }
    int mid= (l+r)/2;
    built_seg(pos*2, l,mid);
    built_seg(pos*2+1, mid+1, r);
    mn[pos] = min(mn[2*pos], mn[2*pos+1]);
}

int query(int pos, int l, int r, int i, int j){
  if(r<i || l>j) return INT_MAX;
  if(l>=i && j>=r) return mn[pos];
  int mid = (l+r)/2;
  int x =query(pos*2, l, mid, i,j);
  int y =  query(pos*2+1, mid+1, r, i,j);
  return min(x,y);

}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    built_seg(1,1,n);
    int q;

    cin>>q;
    while(q--){

    int i, j;
    cin>>i>>j;
    cout<<query(1,1,n,i,j)<<endl;
    }

    return 0;
}
