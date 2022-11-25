#include <bits/stdc++.h>
using namespace std;

int cube (int x) {return x * x * x;}

int minbadness (vector <int> &w, int L) {
    int n = w.size();
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
        dp[i] = INT32_MAX;
        int s = 0;
        for (int k = 1; k <= i; k++) {
            s += w[i - k];
            if (s > L) break;
            dp[i] = min (dp[i], dp[i - k] + cube(L - s));
        }
    }
    return dp[n];
}