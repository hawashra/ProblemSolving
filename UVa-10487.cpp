#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
unordered_set<int> s;
int arr[1000000];
int findClosest(int arr[], int n, int target);
#define min(a,b) (a < b) ? (a) : (b)


// can be solved in a more efficent way. (try it again when you are stronger). 
int main() {

    int n;
    int num;
    int m;
    int tc = 1;

    while (scanf("%d", &n) && n) {
        s.clear();
        memset(arr, 2147483646, sizeof(arr));
        while (n--) {
            scanf("%d", &num);
            s.insert(num);
        }
        int i = 0;


        for (auto y : s) {
            for (auto t : s) {
                if (y != t) {
                    arr[i++] = y + t;
                }
            }
        }

        sort(arr, arr+1000000);

        scanf("%d", &m);
        int lower, low1, low2;
        printf("Case %d:\n", tc);
        while (m--) { 
            scanf("%d", &num);

            int o = findClosest(arr, 1000000, num);
            printf("Closest sum to %d is %d.\n", num, o);

        }
        tc++;
    }

}

int findClosest(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left < right) {
        if (abs(arr[left] - target)
            <= abs(arr[right] - target)) {
            right--;
        }
        else {
            left++;
        }
    }
    return arr[left];
}