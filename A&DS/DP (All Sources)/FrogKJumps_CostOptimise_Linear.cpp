#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 50;
int dp[N];
 
class MinQueue {
public:
    queue <int> Q;
    deque <int> D;
    void push(int element) {
        if (Q.size() == 0) {
            Q.push(element);
            D.push_back(element);
        }
        else {
            Q.push(element);
            while (!D.empty() && D.back() > element) {
                D.pop_back();
            }
            D.push_back(element);
        }
    }
    void remove() {
        if (Q.front() == D.front()) {
            Q.pop();
            D.pop_front();
        }
        else Q.pop();
    }
    int getMin() {return D.front();}
};

int jumps (int k, vector <int> c) {  // O (c.size())
    int n = c.size();
    dp[0] = 0;
    MinQueue q; q.push(dp[0]);
    for (int i = 1; i < n; i++) {
        dp[i] = q.getMin() + c[i];
        q.push(dp[i]);
        if (i >= k) q.remove();
    }
    return dp[n - 1];
}

int main() {
    vector <int> c = {0, 3, 5, 6, 7, 1, 5, 4, 3, 0};
    cout << jumps(2, c);
}