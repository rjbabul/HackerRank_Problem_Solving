#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'authEvents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_STRING_ARRAY events as parameter.
 */
 long long int md = 1000000007;
 long long int bigMod(int n, int p)
 {
     long long int num;
     if(p==0) return 1%md;
     if(p%2==0)
     {
         num = bigMod(n, p/2);
         return ((num% md)*(num% md))%md;
     }
     else
     {
         return ((n%md)*bigMod(n,p-1)%md)%md;
     }
 }

 long long int  toInt(string str)
 {
     long long int sum=0;
    int n = str.length();
    for(int i=0;i<n; i++)
    {
        sum+= ((int)(str[i])*bigMod(131,n-i-1))%md;
    }
    sum= sum%md;
     return sum;
 }

vector< long long int  > setPass(string str)
{
    long long int sum=0;
    vector<long long int  > vt;
    //reverse(str.begin(), str.end());
    int n = str.length();
    for(int i=0;i<n; i++)
    {
        sum+=(long long int ) ((int)(str[i])*bigMod(131,n-i-1));
        sum=sum%md;

    }

    sum= sum%md;

    vt.push_back(sum);

    sum=0;

      for(int i=0;i<n; i++)
    {
        sum+=(long long int ) ((int)(str[i])*bigMod(131,n-i))%md;

    }

    sum= sum%md;

    vt.push_back(sum);

    return vt;
}
int check(vector<long long int > pass, string str)
{
    long long int s= stoi(str);


    if(s==pass[0] || (llabs(s-pass[1])>=48 && llabs(s-pass[1])<=57) || (labs(s-pass[1])>=65 && llabs(s-pass[1])<=90) || (labs(s-pass[1])>=97 && llabs(s-pass[1])<=122))return 1;
    else return 0;

}
vector<int> authEvents(vector<vector<string>> events) {
      vector<int > vt;
      vector<long long int > pass;
      for(int i=0;i<events.size();i++)
      {
          if(events[i][0]=="setPassword")
          {
              pass = setPass(events[i][1]);
          }
          else
          {
              vt.push_back(check(pass,events[i][1]));
          }
      }

      return vt;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string events_rows_temp;
    getline(cin, events_rows_temp);

    int events_rows = stoi(ltrim(rtrim(events_rows_temp)));

    string events_columns_temp;
    getline(cin, events_columns_temp);

    int events_columns = stoi(ltrim(rtrim(events_columns_temp)));

    vector<vector<string>> events(events_rows);

    for (int i = 0; i < events_rows; i++) {
        events[i].resize(events_columns);

        string events_row_temp_temp;
        getline(cin, events_row_temp_temp);

        vector<string> events_row_temp = split(rtrim(events_row_temp_temp));

        for (int j = 0; j < events_columns; j++) {
            string events_row_item = events_row_temp[j];

            events[i][j] = events_row_item;
        }
    }

    vector<int> result = authEvents(events);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
