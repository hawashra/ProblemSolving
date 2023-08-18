#include <iostream>
#include <cstdio>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream

#define ALL(x) x.begin(), x.end()

#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);

int main(void) {

    FAST

    int N;

    cin >> N;
    int K;
    while (N--) {
        
        cin >> K;
        unordered_map<char, int> m;
        char c;
        int v;
        while (K--) {
            cin >> c >> v;
            m[c] = v;
        }

        int M;
        cin >> M;
        string line;
        cin.ignore();
        int total = 0;
        while (M--) {
            getline(cin, line);
            for (int i = 0; i < line.size(); i++) {
                if (m.find(line[i]) != m.end()) {
                    total += m[line[i]];
                }
            }
        }

        cout << total / 100 << "." << setw(2) << setfill('0') << total % 100 << "$" << endl;
    }



    return 0;
}