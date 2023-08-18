#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#include <iostream>

// notice here I made a vector of 1M vectors and it didn't cause space limit to be exceeded. 

//my first idea was to make mapping for the element and its index in the vector of vectors, 
// this idea worked with the sample test case but gave me a WA for some reason.

// this problem was classified as a graph problem, seems misleading, but this is maybe because we used 
// the idea of an AdjList. 

// solved Aug 4 - 2023 at 7:15 PM.

int main() {
    int n, m;
    int k, v;

    vector<vector<int>> lists;

    while (cin >> n >> m) {
        int x;
        // note that .assign(1000000, vector<int>) doesn't work here, we must put the (). 
        lists.assign(1000000, vector<int>());

        for (int i = 0; i <n; i++) {
            cin >> x;
            lists[x].push_back(i+1);             
        }

        while (m--) {
            cin >> k >> v; // k-th occurrence and element v. 
            
            if (lists[v].size() < k) cout << "0";
            else cout << lists[v][k-1];
            cout << endl;
        }
    }
}