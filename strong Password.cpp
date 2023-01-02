#include<bits/stdc++.h>
using namespace std;
int alternate(string s) {
    int a[26];
    memset(a, 0, sizeof(a));
    for(int i=0;i<s.length();i++)a[s[i]-'a']++;

    int mx =0;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]!=s[i+1]){
            mx= max(mx,a[s[i]-'a']+a[s[i+1]-'a']);
            cout<<s[i]<<" "<<s[i+1]<<" "<<a[s[i]-'a']+a[s[i+1]-'a']<<endl;
        }
    }
    return mx;
}

int main()
{
    string str;
    while(cin>>str){
        cout<<alternate(str)<<endl;
    }
    return 0;
}
