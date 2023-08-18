#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
bool has_conflict(int& n, int& m, vector<int>& s, vector<int>& e, vector<int>& T);
bitset<1000000> b;


/* UVa 11926, Multitasking (bitset problem)  */

int main(void) {
    FAST
    b.reset();

    int n, m;

    while (cin >> n >> m, n || m) {

        bool conflict = false;


        vector<int> s(n + m);
        vector<int> e(n+m);
        vector<int> T(m);


        for (int i = 0; i < n; i++) {

            cin >> s[i] >> e[i];
        }

        for (int i = n; i < n+m; i++) {
            cin >> s[i] >> e[i] >> T[i];
        }

        
        if (has_conflict(n, m, s, e, T)) cout << "CONFLICT\n";
        else cout << "NO CONFLICT\n";

    }

    return 0;
}

bool has_conflict(int& n, int& m, vector<int>& s, vector<int>& e, vector<int>& T) {
    
    // one time (no period)
    for (int i = 0; i < n; i++) {

        int start = s[i];
        int end = e[i];

        for (int j = start; j < end; j++) {

            if (b.test(j))
                return true;
            
            b.set(j);
        }

    }

    // periodics 

    for (int i = n; i < n+m; i++) {

        int start = s[i];
        int end = e[i];
        int period = T[n+i];

        while (end < 1000000) {

            for (int j = start; j < end; j++) {
                if (b.test(j))
                    return true;
            
                b.set(j);
            }

            end = min(end + period, 1000000);
            start = start + period;
        }
    }

    return false;      
}

