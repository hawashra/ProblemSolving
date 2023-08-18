#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#include <iostream>


// used dfs to check if there is a cycle and to count of trees and acorns
// if there is a cycle then it is not a tree (nor an acorn)
// if it's just one node then it's an acorn
// if it's more than one node and there is no cycle then it's a tree
// solved at Aug 4, 2023.

// It says that UFDS can be used to solve this problem, but I don't know how to use it for this
// problem, so I used DFS instead.

char G[26][26];
bool visited[26];
bool node_exists[26];
int total;
bool cycle;

char line[120];

void dfs(int nd, int p) {

    visited[nd] = 1;
    total++;

    for (int i = 0; i < 26; i++) {

        if (G[nd][i] and visited[i] and i != p) {
            cycle = true;
            return;
        }

        if (G[nd][i] and not visited[i]) {
            dfs(i, nd);
        }
    }
}

int main () {

    int tc;

    cin >> tc;
    
    bitset<26> connected;
    vector<char> V(26);
    vector<pair<char, char>> E;
    string input;
    char V1, V2;
    while (tc--) {

        memset(line, 0, sizeof(line));
        memset(G, 0, sizeof(G));
        memset(visited, 0, sizeof(visited));
        memset(node_exists, 0, sizeof(node_exists));
        getchar();
        while (getline(cin, input), input[0] != '*') {

            istringstream iss(input);
            iss.ignore(1, '(');
            iss >> V1;
            iss.ignore(1, ',');
            iss >> V2;

            G[V1 - 'A'][V2 - 'A'] = 1;
            G[V2 - 'A'][V1 - 'A'] = 1;
        }

        
        scanf("%s", line);
        
        char node;

        for (int i = 0; line[i]; i += 2) {
            node_exists[line[i] - 'A'] = 1;
        }

        int tree = 0;
        int acorn = 0;

        for (int i = 0; i < 26; i ++) {


            if (node_exists[i] and not visited[i]) {
                total = 0;
                cycle = 0;

                dfs(i, -1);

                if (total > 1 and not cycle)
                    tree++;
            
                if (total == 1)
                    acorn++;
            }
        }

        cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n"; 

    }


    return 0;
}