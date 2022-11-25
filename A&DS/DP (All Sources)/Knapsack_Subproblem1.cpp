//Find the maximum possible sum of subset weights if the sum <= S

#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main () {
    ll n, s; cin >> n >> s;
    vector <ll> w(n);
    for (auto &x : w) cin >> x;

    // dp[i][j] = is it possible to have subsets of elements [0 to i - 1] with sum (weights) = j

    bool dp[n + 5][s + 5];
    memset(dp, false, sizeof(dp));
    for (ll i = 0; i <= n; i++) dp[i][0] = true;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= s; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - w[i - 1] >= 0) dp[i][j] =  dp[i - 1][j - w[i - 1]] or dp[i - 1][j];
        }
    }
    for (ll i = s; i >= 0; i--) {
        if (dp[n][i] == true) {
            cout << i << "\n";
            return 0;
        }
    }
}