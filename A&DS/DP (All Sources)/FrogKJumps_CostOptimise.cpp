#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 50;
int dp[N];

int jumps (int k, vector <int> &c) {  // O (k * c.size())
    int n = c.size();
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = INT32_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) dp[i] = min(dp[i], dp[i - j]) + c[i];
        }
    }
    return dp[n - 1];
}

int main() {
    vector <int> c = {0, 3, 5, 6, 7, 1, 5, 4, 3, 0};
    cout << jumps(2, c);
}