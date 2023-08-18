#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
void solve();
#define vi vector<int>

// 11235 - Frequent values
class SegmentTree
{
    // the segment tree is stored like a heap array
private:
    vi st, A;
    // recall that vi is: typedef vector<int> vi;
    int n;
    int left(int p) { return p << 1; }
    // same as binary heap operations
    int right(int p) { return (p << 1) + 1; }
    void build(int p, int L, int R)
    {
        // O(n)
        if (L == R)
            // as L == R, either one is fine
            st[p] = L;
        // store the index
        else
        {
            // recursively compute the values
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }
    int rmq(int p, int L, int R, int i, int j)
    {
        // O(log n)
        if (i > R || j < L)
            return -1; // current segment outside query range
        if (L >= i && R <= j)
            return st[p];
        // inside query range
        // compute the min position in the left and right part of the interval
        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
        if (p1 == -1)
            return p2;
        // if we try to access segment outside query
        if (p2 == -1)
            return p1;
        // same as above
        return (A[p1] <= A[p2]) ? p1 : p2;
        // as in build routine
    }

public:
    SegmentTree(const vi &_A)
    {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    // copy content for local usage
    // create large enough vector of zeroes
    // recursive build

    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); } // overloading
};




int main () {

    int n, q;

    while (scanf("%d", &n), n) {

        scanf("%d\n", &q);
    
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int occ[n];

        occ[0] = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                occ[i] = occ[i - 1] + 1;
            } else {
                occ[i] = 1;
            }
        }



        vi A(occ, occ + n);
        SegmentTree st(A);

        while (q--) {
            int i, j;
            cin >> i >> j;
            i--; j--;
            int ans = 0;
            if (arr[i] == arr[j]) {
                ans = j - i + 1;
            } else {

    
            }
            cout << "\n" << ans;
        }

    }

}