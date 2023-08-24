#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define vii vector<pair<int,int>>
#define ii pair<int, int>
#define ll long long
#define TC int t; cin >> t; while (t--)
#include <bits/stdc++.h>
#define vi vector<int>
#define endl "\n"

class UnionFind
{ // OOP style
private:
    vi p, rank, setSize;
    // vi p is the key part
    int numSets;

public:
    UnionFind(int N)
    {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i)
            p[i] = i;
        rank.assign(N, 0);
        // optional speedup
        setSize.assign(N, 1);
        // optional feature
        numSets = N;
        // optional feature
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    int numDisjointSets() { return numSets; }
    // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional
    void unionSet(int i, int j)
    {
        if (isSameSet(i, j))
            return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y])
            swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y])
            ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
    // i and j are in same set
    // find both rep items
    // keep x ’shorter’ than y
    // set x under y
    // optional speedup
    // combine set sizes at y
    // a union reduces numSets
};

int main(int argc, char const *argv[])
{
    FAST
    int N, Q;
    cin >> N >> Q;
    
    UnionFind uf(N);
    char op;
    int a, b;

    for (int i = 0; i < Q; i++) {
        cin >> op >> a >> b;
        
        if (op == '=') uf.unionSet(a, b);

        else cout << ((uf.isSameSet(a, b)) ? "yes" : "no") << endl;
    }

    return 0;
}
