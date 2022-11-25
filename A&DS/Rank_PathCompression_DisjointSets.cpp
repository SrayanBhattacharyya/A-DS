/*
* Disjoint Set data structure implentation with Rank heuristics and Path compression
* After m calls of union / find function 
* Time complexity = $O(\alpha(m, n))$ = O(log * n)
*/

#include <bits/stdc++.h>
using namespace std;

int n; vector <int> parent(n);
vector <int> ranks(n, 0); vector <int> sizes(n, 1);

/*
* Find searches for the root / representative element of the set
* to which x belongs. 
*/
int find (int x) {
    //Finding Root 
    int r = x;
    while (r != parent[r])  r = parent[r];

    //Path Compression
    while (x != parent[x])  {
        int tmp = parent[x];
        parent[x] = r;
        x = tmp;
    }
    return r;
}

int findRecursive (int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

/* 
* join (x, y) -
* Unites the dynamic sets that contain x and y into a new set 
* x should be different than y.
* Uses union-by-rank policy: it makes the node whose set rank is smaller point to
* the node whose set size is bigger, breaking ties arbitrarily. In case of tie,
* the resulting set's rank is increased by 1.
*/


// Given x != y

void join_ranks (int x, int y) {
    x = find(x); y = find(y);
    if (ranks[x] > ranks[y]) swap (x, y);
    parent[x] = y;
    if (ranks[x] == ranks[y]) ranks[y]++;
}

void join_size (int x, int y) {
    x = find(x); y = find(y);
    if (sizes[x] > sizes[y]) swap (x, y);
    parent[x] = y;
    sizes[y] += sizes[x];
}