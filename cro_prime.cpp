#include<bits/stdc++.h>
using namespace std;
bool primes[200005];
#define mx 200001
vector<int >prime;
int cont[200005];
int visit[200005];
void seive()
{

    primes[0]=primes[1]=1;
    for(int i=2; i*i<=mx; i++)
    {
        if(!primes[i])
            for(int j=i*i; j<=mx; j+=i)
                primes[j]=1;
    }

    prime.push_back(2);
    for(int i=3; i<=mx; i+=2)
        prime.push_back(i);

}

vector<int> prime_factor(int num)
{
    vector<int > factor;
    for(int i=2; i*i<= num; i++)
    {
        if(num%i==0)
        {
            factor.push_back(i);
            while(num%i==0)
                num/=i;
        }
    }
    if(num>1)
        factor.push_back(num);
    return factor;

}

void frequency(int num)
{
    vector<int > factor = prime_factor(num);
    int n = factor.size();
    for(int mask =1; mask<(1<<n); mask++)
    {
        int fact=1;
        for(int i=0; i< n; i++)
        {
            if(mask &(1<<i))
            {
                fact*= factor[i];
            }
        }
        cont[fact]++;
    }

}
int process(int x, int n)
{

    vector<int > factor = prime_factor(x);

    if(visit[x]> -1)
        return visit[x];
    int size_= factor.size();

    int result =0;

    for(int mask=1; mask< (1<<size_); mask++)
    {
        int fact =1;
        int c=0;
        for(int i=0; i<size_; i++)
        {
            if(mask & (1<<i))
            {
                fact*= factor[i];
                c++;
            }

        }
        if(c&1)
            result+= cont[fact];
        else
            result-= cont[fact];
    }

    return visit[x]= n-result;

}

int main()
{
    seive();
    int n, q,x;
    memset(visit, -1, sizeof(visit));
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        frequency(x);
    }
    for(int i=0; i<q; i++)
    {
        cin>>x;
        cout<<process(x,n)<<endl;
    }
    return 0;
}
