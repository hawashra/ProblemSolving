#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;

int arr[30];
int end1[30];
int main() {
    int N;
    int i, j, k;
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < N; i++) {
            cin >> end1[i];
        }
        // loop until you find the index of the element you are at. 
        // change arr[k] to arr[k-1] for all k from j: (index of element in end1) to k > i.  
        // each time you change a value => increment ans.
        // that's how you find how many swaps it will take so that arr becomes end1 or the opposite.

        int ans = 0;
        for (i = 0; i < N; i++) {
            for (j = i; j < N; j++) {
                if (arr[j] == end1[i])
                    break;
            }


            for (k = j; k > i; k--) {
                arr[k] = arr[k-1];
                ans++;
            }
        }


        printf("%d\n", ans);
    }

}