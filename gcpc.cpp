#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#include <bits/extc++.h>

using namespace __gnu_pbds;

#define vii vector<pair<int,int>>
#define ii pair<int, int>
#define ll long long
#define iii tuple<int, int, int>

#define TC int t; cin >> t; while (t--)


typedef struct {
    int score = 0;
    int penalty = 0;
    int team = 0;
}tup;

bool operator< (const tup& lhs, const tup& rhs) {
    if(lhs.score == rhs.score) {
        if(lhs.penalty == rhs.penalty) {
            return lhs.team < rhs.team;
        }
        return lhs.penalty < rhs.penalty;
    }
    return lhs.score > rhs.score;
}


// pbds
typedef tree<tup, null_type, less<tup>, rb_tree_tag,
            tree_order_statistics_node_update>
    ost;


int wins[100001];
int p[100001];
int main()
{
    memset(wins, 0, 100001);
    memset(p, 0, 100001);

    // so basically, order is the order in the sorted array.
    // find_by_order(0) returns the minimum element in the tree (in logN time).
    // we can find the maximum element in the tree with find_by_order(n-1) (also logN time).

    int n, m;
    cin >> n >> m;

    ost tree;

    for (int i = 0; i < n; ++i) {
        tup top;
        top.penalty = 0;
        top.score = 0;
        top.team = i+1;

        tree.insert(top);
    }

    for (int i = 0; i < m; i++) {
        
        int pl, pn;
        cin >> pl >> pn;
        tup top;
        top.penalty = p[pl];
        top.score = wins[pl];
        top.team = pl;

        tree.erase(tree.find(top));

        wins[pl] += 1;
        p[pl] += pn;
        top.penalty += pn;
        top.score += 1;
        tree.insert(top);

        cout << tree.order_of_key({wins[1], p[1], 1})+1 << endl;
    }

    return 0;
}

