#include <iostream>
#include <cstdio>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 

#define ALL(x) x.begin(), x.end()

#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);

int main(void) {

    FAST

    int n;
    unordered_set<int> s;

    while (cin >> n) {

        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        s.clear();

        for (int i = 0; i < n - 1; i++) {
            s.insert(abs(v[i] - v[i + 1]));
        }

        bool is_jolly = true;

        for (int i = 1; i < n; i++) {
            if (s.find(i) == s.end()) {
                is_jolly = false;
                break;
            }
        }

        if (is_jolly) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }

    return 0;
}