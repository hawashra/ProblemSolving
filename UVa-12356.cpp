#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define endl "\n"

int left1[100001];
int right1[100001];

int main () {

    int n, q;
    int l, r;
    while (scanf("%d %d", &n, &q), (n||q)) {

        for (int i = 1; i < n; i++) {
            left1[i] = i - 1;
            right1[i] = i + 1;
        }

        left1[1] = -1;
        right1[n] = -1;

        while (q--) {
            scanf("%d %d", &l ,&r);

            left1[right1[r]] = left1[l];
            if (left1[l] != -1) {
                printf("%d", left1[l]);
            }
            else {
                printf("*");
            }

            right1[left1[l]] = right1[r];
            if (right1[r] != -1) {
                printf(" %d\n", right1[r]);
            }
            else {
                printf(" *\n");
            }
        }

        printf("-\n");
    }

}