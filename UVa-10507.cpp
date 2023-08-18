#include <iostream>
#include <cstdio>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream


/*In this problem, it's mentioned in the book that Union find disjoin set can 
make solving this problem easier, but I prefer using a hashmap of sets, I could have used a normal array though, 
there is no need for the hashmap, the array can be of size 26 and indexed with character - 'A'  */


#define ALL(x) x.begin(), x.end()

#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);

bool woke[26];

unordered_map<char, unordered_set<char>> adj_list(26);

int main() {


    int n; 
    int m;
    string woke_str;
    string s;
    while(scanf("%d\n", &n) != EOF) {

        memset(woke, false, sizeof(woke));
        adj_list.clear();


        scanf("%d\n", &m);
        cin >> woke_str;
        vector<pair<char, char>> connections(m);


        getchar();
        for (int i = 0; i < m; i++) {
            cin >> s;
            connections[i] = make_pair(s[0], s[1]);
        }

        
        for (int i = 0; i < woke_str.length(); i++) {
            woke[woke_str[i]-'A'] = true;
        }
        bool cont = false; // means we can wake some area in the brain, will be set to false if we can't, 
                            // and that way the loop exits.  
        int ans = 0;
        char A1, A2;

        int slp = n - 3;
        
        do {

            // we need to add the list of woke areas connected to each non-woke area.

            cont = false;
        
            for (int j = 0; j < connections.size(); j++) {

                A1 = connections[j].first;
                A2 = connections[j].second;

                if (not woke[A1 - 'A'] and woke[A2 - 'A']) {
                    adj_list[A1].insert(A2);
                }

                if (woke[A1 - 'A'] and not woke[A2 - 'A']) {
                    adj_list[A2].insert(A1);
                }

            } 

            for (int i = 0; i < 26; i++) {

                if (not woke[i] && adj_list[i+'A'].size() >= 3) {
                    woke[i] = true;
                    slp--;
                    cont = true;
                }

            }

            // if one or more areas woke up at this moment, we add 1 only because it takes 1 year to wake up
            if (cont)
                ans += 1;

        } while (slp > 0 && cont);


        if (slp > 0) cout << "THIS BRAIN NEVER WAKES UP\n";
        else cout << "WAKE UP IN, " << ans << ", YEARS\n";

        getchar();
    }
}