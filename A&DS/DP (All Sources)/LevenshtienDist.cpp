#include <bits/stdc++.h>
using namespace std;

int LevenshtienDistance (string a, string b) {
    int n = a.size(), m = b.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = i + j;
                continue;
            }
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = min (min (dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
            }
        }
    }
    return dp[n][m];
}

int main() {
    string a = "apple", b = "alpine";
    cout << LevenshtienDistance(a, b);
}