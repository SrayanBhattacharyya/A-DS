//Time Complexity: O(n logn)

#include <bits/stdc++.h>
using namespace std;

vector <int> merge (vector <int> &a, vector <int> &b) {
    int n = a.size(), m = b.size();
    int i = 0, j = 0, k = 0;
    vector <int> c(n + m);
    while (i < n || j < m) {
        if (j = m || (i < n && a[i] < b[j])) {
            c[k++] = a[i++];
        }
        else c[k++] = b[j++];
    }
    return c;
}

vector <int> MergeSort (vector <int> &a) {
    int n = a.size();
    vector <int> b, c;
    for (int i = 0; i < n; i++) {
        if (i <= n / 2) b.emplace_back(a[i]);
        else c.emplace_back(a[i]);
    }
    b = MergeSort(b); c = MergeSort(c);
    return merge(b, c);
}