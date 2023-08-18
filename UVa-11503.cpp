#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define vi vector<int>
void solve();



class UnionFind
{ // OOP style
private:
    vi p, rank;
    vi size;
public:
    UnionFind(int N)
    {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
        size.assign(N, 1);
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
                size[x] += size[y];
            }
            // rank keeps the tree short
            else
            {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
                size[y] += size[x];
            }

        }
    }

    int sizeOfSet(int i) {
    
        return size[findSet(i)];
    }
};


int main(void) {
    FAST

    int T;
    cin >> T;
    while (T--) {
        solve();
    }



    // return 0; // it is not necessary to return 0 in C++ main function
}

void solve() {

    // map <string, int> m;
    unordered_map <string, int> m;

    UnionFind UF(100000);
    
    int F;
    cin >> F;
    int count = 0;
    while (F--) {
        string s1, s2;
        cin >> s1 >> s2;

        if (m.find(s1) == m.end()) {
            m[s1] = count++;
        }
        if (m.find(s2) == m.end()) {
            m[s2] = count++;
        }

        UF.unionSet(m[s1], m[s2]);
        cout << UF.sizeOfSet(m[s1]) << "\n";
    }
}