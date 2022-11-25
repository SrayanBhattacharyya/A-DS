/*

In this case the sum of costs/ values is small
but the maximum weight (s) of the knapsack is very large
so we will instead use sum of costs as a state of dp and 
try to minimise the weight of the chosen subset for a particular
sum of subset costs.

Constraints -
1 <= n <= 1e2
1 <= cost[i] <= 1e
1 <= s <= 1e9

Here sum of ci over all elements won't exceed 1e5
but s (max. knapsack weight is 1e7)

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const ll MAX = 1e18;
const ll C = 1e5 + 2;

int main () {
    ll n, s;
    cin >> n >> s;
    vector <ll> w(n), v(n);
    for (auto &x : w) cin >> x;
    for (auto &x : v) cin >> x;
    vector <vector<ll>> dp(n + 1, vector<ll> (100001, 1e18));
    for (ll i = 0; i <= n; i++) dp[i][0] = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= (ll)1e5; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i - 1] >= 0) dp[i][j] = min(dp[i][j], w[i - 1] + dp[i - 1][j - v[i - 1]]);
        }
    }
    for (ll i = 1e5; i >= 0; i--) {
        if (dp[n][i] <= s) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
}