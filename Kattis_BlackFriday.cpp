#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;

int main() {

    int N;
    scanf("%d", &N);
    unordered_map<int, int> counts;
    int arr[N];

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (counts.find(num) != counts.end()) {
            counts[num]++;
        }
        else {
            counts[num] = 1;
        }

        arr[i] = num;
    }
    int ans = 0;

    for (int i = 0; i < N; i++) {

        if (ans == 0 and counts[arr[i]] == 1  or (counts[arr[i]] == 1 and ans != 0 and arr[i] > arr[ans-1])) {
            ans = i + 1;
        }
    }

    if (ans == 0) cout << "none";
    else cout << ans;

}