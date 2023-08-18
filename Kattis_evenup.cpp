#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define endl "\n"

int main() {

    int n;
    cin >> n;
    stack<int> cards;
    int arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];


    for (int i = 0; i < n; i++) {

        if (! cards.empty() && cards.top() % 2 == arr[i] % 2) cards.pop();
        else cards.push(arr[i]);
    }

    printf("%d\n", (int)cards.size());

}
