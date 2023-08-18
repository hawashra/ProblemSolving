#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define FAST                     \
    std::cin.tie(0);             \
    ios::sync_with_stdio(false); \
    std::cout.tie(0);
using namespace std;
#define min(a, b) (a < b) ? (a) : (b)
#define max(a, b) (a > b) ? (a) : (b)
#define vii vector<pair<int, int>>
#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define pb push_back
#define emp emplace

#define TC    \
    int t;    \
    cin >> t; \
    while (t--)
#define MAX 1024000

ll a[MAX], st[4 * MAX];
char lazy[4 * MAX];


void changeState(ll p)
{

    if (lazy[p] == 'I')
    {
        lazy[p] = 'X';
    }
    else if (lazy[p] == 'E')
    {
        lazy[p] = 'F';
    }
    else if (lazy[p] == 'F')
    {
        lazy[p] = 'E';
    }
    else if (lazy[p] == 'X')
    {
        lazy[p] = 'I';
    }
}
// copied

void propagate(ll p, ll R, ll L)
{
    if (lazy[p] == 'E')
    {
        st[p] = 0;
    }
    if (lazy[p] == 'F')
    {
        st[p] = (R - L + 1);
    }
    if (lazy[p] == 'I')
    {
        st[p] = R - L + 1 - st[p];
    }
    if (L != R)
    {
        if (lazy[p] == 'I')
        {
            changeState(p * 2);
            changeState((p * 2) + 1);
        }
        else
        {
            lazy[(p * 2) + 1] = lazy[p];
            lazy[p * 2] = lazy[p];
        }
    }
    lazy[p] = 'X';
}

// copied

void update(ll p, ll L, ll R, ll a, ll b, char v){
    // we update the node
    if(lazy[p] != 'X'){
        propagate(p, R, L);
    }
    if(L > b || R < a) return;
    if(L >= a && R <= b){
        // we update segment cause it belongs to general solution.
        if(v == 'E'){
            st[p] = 0;
        }
        if(v == 'F'){
            st[p] = (R - L + 1);
        }
        if(v == 'I'){
            ll len = R - L + 1;
            st[p] = len - st[p];
        }
        if(L != R){
            if(v == 'I'){
                changeState((2*p)+1);
                changeState(2*p);
            }else{
                lazy[2*p] = v;
                lazy[(2*p)+1] = v;
            }
        }
        return;
    }
    ll m = (L + R) >> 1;
    update(p*2, L, m, a , b, v);
    update(p*2 + 1, m + 1, R, a , b, v);
    st[p] = st[2*p]+ st[(2*p) + 1];
}
// copied
ll query(ll p, ll L, ll R, ll i, ll j){
    if(lazy[p] != 'X') {
        propagate(p, R, L);
    }
    if( R < i || L > j) return 0;
    if( L >= i && R <=j) return st[p];
    ll a = query(p * 2, L , (L + R) >> 1, i , j);
    ll b = query(p * 2 + 1, ((L + R) >> 1) + 1, R, i , j);
    /*if(a == -1) return b;
    if(b == -1) return a;*/
    return (a + b);
}
// copied

void build(ll p, ll L, ll R){
    lazy[p] = 'X';
    st[p]   =  0;
    if(L == R)
        st[p] = a[L];
    else{
        build( (2 * p), L, (L + R) >> 1);
        build( (2 * p) + 1, ((L + R) >> 1) + 1, R);
        ll dx = st[2 * p], dy = st[2 * p + 1];
        st[p] = dx + dy;
    }
}
// copied
void solve()
{

    int M;
    cin >> M;

    int T;
    string chrs;
    int idx = 0;
    while (M--)
    {
        cin >> T;
        cin >> chrs;
        while (T--)
        {
            for (auto c : chrs)
            {
                a[idx++] = c - '0';
            }
        }
    } // reading first part of the input.

    build(1, 0, idx - 1);
    int Q, a, b;
    cin >> Q;
    char q;
    int i = 0;
    while (Q--)
    {
        cin >> q >> a >> b;

        // TODO
        if (q == 'F')
        {
            update(1,0, idx-1, a, b, 'F');
        }
        // TODO
        else if (q == 'E')
        {
            update(1,0, idx-1, a, b, 'E');
        }
        // TODO
        else if (q == 'I')
        {
            update(1,0, idx-1, a, b, 'I');
        }
        // TODO (q == 'S')
        else
        {
            ++i;
            printf("Q%d: %lld\n", i, query(1,0,  idx - 1, a, b));
        }
    }
}

int main(int argc, char const *argv[])
{
    int cas = 0;
    TC
    {
        printf("Case %d:\n", ++cas);
        solve();
    }

    return 0;
}