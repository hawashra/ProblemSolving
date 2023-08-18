#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define endl "\n"

int main() {
    FAST
    int n;
    cin >> n;

    vector<int> GIS;
    int num;
    cin >> num;
    GIS.emplace_back(num);
    int idx = 0;
    for (int i = 1; i < n; i++) {
        cin >> num;
        
        if (num > GIS[idx]) {
            ++idx;
            GIS.emplace_back(num);
        }

    }

    cout << idx+1 << endl;
    for (int i = 0; i < idx; i++) cout << GIS[i] << " ";
    cout << GIS[idx] << endl;
}