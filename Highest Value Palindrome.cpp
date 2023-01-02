#include <bits/stdc++.h>
using namespace std;


string highestValuePalindrome(string s, int n, int k) {
         int cnt = 0;
         for(int i=0, r= n-1;i<r;i++,r--)
         {
             if(s[i]!=s[r]) cnt++;
         }
         if(cnt>k) return "-1";
         int l=0, r=n-1;
         while( cnt<=k && l<r)
         {
             if(s[l]==s[r] && s[l]=='9')
             {

             }
             else if(s[l]==s[r] && k-2>=cnt )
             {
                 s[r]='9';s[l]='9';
                 k-=2;
             }
             else if(s[l]!=s[r])
             {

                 if(s[l]!='9' && s[r]!='9' && k-1>=cnt)
                 {
                     s[l]='9';s[r]='9';
                     k-=2;
                     cnt--;

                 }
                 else if(s[r]=='9' )
                 {
                     s[l]='9';
                     cnt--;
                     k--;

                 }
                 else if(s[l]=='9')
                 {
                      s[r]='9';
                     cnt--;
                     k--;

                 }
                else
                {
                    char ch ;
                    if(s[l]>s[r])ch= s[l]; else ch = s[r];
                    s[l]=ch;
                    s[r]=ch;
                    k--;
                    cnt--;

                }

             }
             l++; r--;
         }
         if(l==r && k>0) s[l]='9';
      return s;
}

int main()
{



    int n;

    int k;
    cin>>n>>k;
    getchar();
    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    cout << result << "\n";



    return 0;
}

