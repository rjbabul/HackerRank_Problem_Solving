#include<bits/stdc++.h>
using namespace std;
typedef pair< double, double> pii;

int primes[200005];
#define mx 200005

void seive()
{

    primes[0]= primes[1]=1;
    for(int i=2; i*i<=mx; i++)
    {
        if(primes[i]==0)
            for(int j=i*2; j<=mx; j+=i)
            {
                primes[j]=1;
            }
    }
}

int main()
{
    seive();
    // freopen("I:\\round.txt","r",stdin);

    int n1,q;
    int n[200005];

    while(cin>>n1>>q)
    {

        int x;
        map<int, int > co; int cnt=0;
        int f=0;
        for(int i=0; i<n1; i++)
            {
                cin>>x;
                if(primes[x]==0){
                cnt++; co[x]++;
                }
                else n[f++]=x;
            }
        int c;

        for(int i=0; i<q; i++)
        {
            c=0;
            cin>>x;
                for(int i=0; i<f; i++)
                {
                    if( __gcd(x,n[i])==1)
                        c++;
                }

                c+= (cnt-co[x]);
                cout<<c<<endl;
        }


    }

    return 0;
}
