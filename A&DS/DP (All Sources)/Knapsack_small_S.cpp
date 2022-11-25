#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main () {
    ll n, s; cin >> n >> s;
    vector <ll> w(n), v(n);
    for (ll i = 0; i < n; i++) cin >> w[i] >> v[i];

    //dp[i][j] = max sum of subset cost for subsets of elements [0 to i - 1] with total weight j

    ll dp[n + 2][s + 2];
    memset(dp, 0, sizeof(dp));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= s; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - w[i - 1] >= 0) dp[i][j] = max(dp[i][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
        }
    }
    cout << dp[n][s];
}