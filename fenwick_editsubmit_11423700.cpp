#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define vii vector<pair<int,int>>
#define ii pair<int, int>
#define ll long long

#define TC int t; cin >> t; while (t--)

#define LSOne(S) ((S) & -(S)) // the key operation
typedef vector<ll> vll;
typedef vector<int> vi; // for extra flexibility
class FenwickTree
{
private:
    vll ft;

public:
    FenwickTree(int m) { ft.assign(m + 1, 0); } // index 0 is not used
    void build(const vll &f)
    {
        int m = (int)f.size() - 1;
        ft.assign(m + 1, 0);
        for (int i = 1; i <= m; ++i)
        {
            ft[i] += f[i];
            if (i + LSOne(i) <= m)
                ft[i + LSOne(i)] += ft[i];
        }
    }
    // internal FT is an array
    // create an empty FT
    // note f[0] is always 0
    // O(m)
    // add this value
    // i has parent
    // add to that parent
    FenwickTree(const vll &f) { build(f); } // create FT based on f
    FenwickTree(int m, const vi &s)
    {
        vll f(m + 1, 0);
        for (int i = 0; i < (int)s.size(); ++i)
            ++f[s[i]];
        build(f);
    } // create FT based on s
    ll rsq(int j)
    {
        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }
    // do the conversion first
    // in O(n)
    // in O(m)
    // returns RSQ(1, j)
    ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); } // inc/exclusion
    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    void update(int i, ll v)
    {
        for (; i < (int)ft.size(); i += LSOne(i))
            ft[i] += v;
    }
    int select(ll k)
    {
        int lo = 1, hi = ft.size() - 1;
        for (int i = 0; i < 30; ++i)
        {
            int mid = (lo + hi) / 2;
            (rsq(1, mid) < k) ? lo = mid : hi = mid;
        }
        return hi;
    }
    // O(log^2 m)
    // 2^30 > 10^9; usually ok
    // BSTA
    // See Section 3.3.1
};

int main(int argc, char const *argv[])
{
    int N, Q;
    scanf("%d %d\n", &N, &Q);
    vector<ll> v(N+1);
    v.assign(v.size(), 0);

    char op;
    int i;
    int s;

    FenwickTree FT(v);

    while(Q--) {
        scanf("%c ", &op);

        if (op == '+') {
            scanf("%d %d\n", &i, &s);
            FT.update(i+1, (ll)s);
        }
        else {
            scanf("%d\n", &i);
            if (i == 0) cout << "0\n";
            else printf("%lld\n", FT.rsq(i));
        }
    }
}


