#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;

const int MAXN = 200 + 4;

int n, m, t, a[MAXN][MAXN], b[MAXN][MAXN];
string s[MAXN];

bool fit(int x, int y){return 0 <= x && x < n && 0 <= y && y < m;};

void f(int z){
    memcpy(b, a, sizeof(a));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int ii = -1; ii <= 1; ii++)
                for (int jj = -1; jj <= 1; jj++)
                    if (abs(ii) + abs(jj) <= 1 && fit(i + ii, j + jj) && a[i + ii][j + jj] == z - 3)
                        b[i][j] = -1;
    memcpy(a, b, sizeof(b));
}

int main() {  
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++){
        cin >> s[i];
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'O')
                a[i][j] = 0;
            else
                a[i][j] = -1;
    }
    t--;
    t %= 24;
    for (int i = 2; i <= t+1; i++){
        if (i % 2 == 0){
            for (int ii = 0; ii < n; ii++)
                for (int jj = 0; jj < m; jj++)
                    if (a[ii][jj] == -1)    
                        a[ii][jj] = i;
        }
        else{
            f(i);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            if (a[i][j] != -1)
                cout << 'O';
            else
                cout << '.';
        cout << "\n";
    }
    return 0;
}