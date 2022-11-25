//Time Complexity: O(n^2) (Worst Case)

#include <bits/stdc++.h>
using namespace std;

void InsertionSort (vector <int> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j > 0 && (a[j] < a[j - 1])) {
            swap (a[j], a[j - 1]);
            j--;
        }
        // Prefix a[0 to i] is sorted 
    }
}