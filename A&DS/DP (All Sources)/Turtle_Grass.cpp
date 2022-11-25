#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 50;
int dp[N][N], grass[N][N];

int main () {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grass[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grass[i][j];
        }
    }
    cout << dp[n][m] << "\n";
}