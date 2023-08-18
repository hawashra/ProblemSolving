#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define vii vector<pair<int,int>>

int main() {

    // first go, no comeback. 

    int n; 
    cin >> n;
    stack<string> stacc;
    string op;
    queue<string> q;
    string trash, name;
    getchar();
    while (n--) {
        getline(cin, op);
        if (op[0] == 'T') {
            if (stacc.empty()) q.push("Not in a dream");

            else q.push(stacc.top());
        }
        else if (op[0] == 'K')  {
            if (stacc.empty()) continue;
            else stacc.pop();
        }
    
        // sleep (input not yet taken)
        else {
            istringstream iss (op);
            iss >> trash >> name;     
            stacc.push(name);
        }
    }

    while (!q.empty()) { cout << q.front() << endl; q.pop(); }

    return 0;
}