#include <bits/stdc++.h>
using namespace std;

int n; vector <int> rep(n);

/*
* vector rep contains representative element of the set 
* to which the element belongs
*/

int find (int x) {  //O(1)
    return rep[x];
}

void join (int x, int y) {    //O(n) per call
    x = find(x); y = find(y);
    for (int i = 0; i < n; i++) 
        if (rep[i] = x) rep[i] = y; 
}

/*
* For (n - 1) unions, Time : O(n^2)
*/