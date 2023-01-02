
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


void absolutePermutation(int n, int k)
{
    vector<int> vt;
    vt.clear();
    if(k==0)
    {
        for(int i=1; i<=n; i++)
            vt.push_back(i);
    }
    else if(n%(2*k)!=0)
    {
        vt.push_back(-1);

    }
    else
    {
        int st =0;
        while(vt.size()<n)
        {
            int last= st+2*k;
            for(int j=last-k+1; j<=last; j++)
                vt.push_back(j);
            for(int j=st+1; j<= st+k; j++)
                vt.push_back(j);
            st+= 2*k;
        }
    }
    for(int i=0; i<vt.size(); i++)
    {
        cout<<vt[i];
        if(i<vt.size()-1)
            cout<<" ";
    }
    cout<<endl;
}

int main()
{
    int t ;
    cin>>t;
    int n, k;
    for (int test = 0; test < t; test++)
    {

        cin>>n>>k;
        absolutePermutation(n, k);
    }
    return 0;
}



