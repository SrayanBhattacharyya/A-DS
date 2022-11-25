/*
T(n) = O(n)
DP (memoisation)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 50;
int dp[N], pfx[N];

int jumps (int n, int k) {
    dp[1] = 1; pfx[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        if (i <= k + 1) { 
            dp[i] = pfx[i - 1];
            pfx[i] = 2 * dp[i];
        }
        else {  
            dp[i] = pfx[i - 1] - pfx[i - (k + 1)];
            pfx[i] = dp[i] + pfx[i - 1];
        }
    }
    return dp[n];
    //Alternatively 
    //dp[i] = 2 * dp[i  - 1] upto kth
    //for (k + 1 th ele & after) dp[i] = 2*dp[i - 1] - dp[i - (k + 1)]
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    cout << jumps(n, k) << "\n";
    return 0;
}