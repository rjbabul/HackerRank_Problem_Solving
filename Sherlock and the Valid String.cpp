#include <bits/stdc++.h>
using namespace std;

string isValid(string s) {
    map<char,int> mp;
    set<char> st;
    set<char>::iterator it;

    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;
        st.insert(s[i]);
    }
    vector<int> vt;
    for(it= st.begin(); it!= st.end();it++)
    {
        vt.push_back(mp[*it]);
    }
    sort(vt.begin(), vt.end());
    int i=1;

    while(i<vt.size())
    {
        if(vt[i]>vt[i-1]  )
        {
            if(vt[i]-vt[i-1]>1 && i!=1)return "NO";
            break;
        }
        i++;
    }

    if(i==1)
    {

         i++;
          while(i<vt.size())
    {

        if(vt[i]>vt[i-1])
        {
            if(vt[i]-vt[i-1]>1)return "NO";
            break;
        }
        i++;
    }
      if(i<vt.size()) return "NO";
    }
    if(i<vt.size()-1) return "NO";
    else return "YES";
}

int main()
{

    string s;
    getline(cin, s);

    string result = isValid(s);

    cout << result << "\n";



    return 0;
}
