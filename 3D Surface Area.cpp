
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'surfaceArea' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY A as parameter.
 */

int surfaceArea(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();

    int tusum = (n*m)*2;
    int fsum =0, bsum=0, lsum=0, rsum=0;
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j==0) fsum+=a[i][j];
            else fsum+= max(0, a[i][j]-a[i][j-1]);
        }
    }

    for(int i = 0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==0) lsum+=a[j][i];
            else lsum+= max(0, a[j][i]-a[j-1][i]);
        }
    }

    for(int i = n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(j==m-1) bsum+= a[i][j];
            else bsum+= max(0,a[i][j]-a[i][j+1]);
        }
    }


     for(int i = m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(j==n-1) bsum+= a[j][i];
            else bsum+= max(0,a[j][i]-a[j+1][i]);
        }
    }
    return tusum + fsum + bsum+ lsum+rsum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int H = stoi(first_multiple_input[0]);

    int W = stoi(first_multiple_input[1]);

    vector<vector<int>> A(H);

    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        string A_row_temp_temp;
        getline(cin, A_row_temp_temp);

        vector<string> A_row_temp = split(rtrim(A_row_temp_temp));

        for (int j = 0; j < W; j++) {
            int A_row_item = stoi(A_row_temp[j]);

            A[i][j] = A_row_item;
        }
    }

    int result = surfaceArea(A);

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
