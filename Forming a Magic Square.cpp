
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



int formingMagicSquare(vector<vector<int>> s) {

    int mask[8][9] = {{6,1,8,7,5,3,2,9,4}, {8,1,6,3,5,7,4,9,2}, {8,3,4,1,5,9,6,7,2}, {4,3,8,9,5,1,2,7,6}, {6,7,2,1,5,9,8,3,4}, {2,7,6,9,5,1,4,3,8}, {2,9,4,7,5,3,6,1,8}, {4,9,2,3,5,7,8,1,6}};
    vector<int> vt;

    int ans=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {

            vt.push_back(s[i][j]);
        }
    }

    int mx=INT_MAX;
    for(int i=0;i<8;i++)
    {
        ans=0;
        for(int j=0;j<9;j++)
        {
            ans+= abs(vt[j]-mask[i][j] );
        }
        mx=min(mx, ans);
    }

    return mx;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

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
