#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

int legoBlocks(int n, int m) {
      const int MOD = 1e9 + 7;
    vector<int> row_combinations(m + 1, 0);
    row_combinations[0] = 1;
    for (int i = 1; i <= m; ++i) {
        if (i >= 1) row_combinations[i] = (row_combinations[i] + row_combinations[i - 1]) % MOD;
        if (i >= 2) row_combinations[i] = (row_combinations[i] + row_combinations[i - 2]) % MOD;
        if (i >= 3) row_combinations[i] = (row_combinations[i] + row_combinations[i - 3]) % MOD;
        if (i >= 4) row_combinations[i] = (row_combinations[i] + row_combinations[i - 4]) % MOD;
    }

    vector<int> total(m + 1, 0);
    for (int i = 0; i <= m; ++i) {
        long long res = 1, base = row_combinations[i];
        int exp = n;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        total[i] = (int)res;
    }

    vector<int> unstable(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        long long sum = 0;
        for (int j = 1; j < i; ++j) {
            long long left = (total[j] - unstable[j] + MOD) % MOD;
            long long right = total[i - j];
            sum = (sum + (left * right) % MOD) % MOD;
        }
        unstable[i] = (int)sum;
    }

    return (total[m] - unstable[m] + MOD) % MOD;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = legoBlocks(n, m);

        fout << result << "\n";
    }

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
