#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#include <iostream>


// this problem is easy but it gets a runtime error, even the online solutions get RTE. 
// it's based on the idea of the UFDS (union find disjoin set) 
class UnionFind
{ // OOP style
private:
    vi p, rank;

public:
    UnionFind(int N)
    {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
                p[y] = x;
            // rank keeps the tree short
            else
            {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;

            }
        }
    }
};

int main() {
    string s;

    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        int n;
        scanf("\n%d\n", &n);
        int i, j;
        //cout << n; // worked

        UnionFind union_find(n);
        int con, dis;
        con = dis = 0;
        char op;
        while (getline(cin, s) && not s.empty()) {
            
            istringstream iss(s);
            iss >> op >> i >> j;
            
            if (op == 'q') {
    
                union_find.isSameSet(i, j) ? con++ : dis++;
            }

            else {
                union_find.unionSet(i, j);
            }
        }

        if (t != 1)
            printf("\n");
        
        printf("%d,%d\n",con, dis);

    }
}