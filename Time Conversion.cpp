#include <bits/stdc++.h>

using namespace std;

string call(string st)
{
    int num=0;
    string str;

    num= (st[0]-'0')*10+ (st[1]-'0');
    num+= 12;

    if(num==24)
    {
        str="12";
    }
    else
    {
        str+= (char)(num/10+'0');
        str+= (char)(num%10+'0');
    }

    return str;
}
string timeConversion(string s)
{

    if(s[s.length()-2]=='A')
    {
        if(s.substr(0,2)=="12")
        {
            s[0]=s[1]='0';

        }
    }
    else
    {
        string st= call( s.substr(0,2));
        s[0]=st[0];
        s[1]=st[1];
    }

    return s.substr(0, s.length()-2);
}

int main()
{

    string s;
    getline(cin, s);

    string result = timeConversion(s);
    cout << result << "\n";


    return 0;
}
