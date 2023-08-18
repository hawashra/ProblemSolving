#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define vii vector<pair<int,int>>
#define ii pair<int, int>
#define ll long long

#define TC int t; cin >> t; while (t--)

void solve() {
    int B, SG, SB;

    cin >> B >> SG >> SB;

    priority_queue<int> greens;
    priority_queue<int> blues;
    int num;

    while (SG--) {
        cin >> num;
        greens.emplace(num);
    }
    while (SB--) {
        cin >> num;
        blues.emplace(num);
    }
    stack<int> blueStack;
    stack<int> greenStack;

    while (!greens.empty() && !blues.empty()) {
        int bt = B;
        while(bt && !greens.empty() && !blues.empty()) {
            bt--;
            int b = blues.top();
            int g = greens.top();

            blues.pop();
            greens.pop();

            if (b > g) blueStack.push(b - g);
            else if (g > b) greenStack.push(g - b);
        }

        while (!blueStack.empty()) {
            blues.push(blueStack.top());
            blueStack.pop();
        }

        while (!greenStack.empty()) {
            greens.push(greenStack.top());
            greenStack.pop();
        }
    }

    if (greens.empty() && blues.empty()) cout << "green and blue died" << endl;
    
    else if (blues.empty()) {
        cout << "green wins" << endl;
        while (!greens.empty()) {
            cout << greens.top() << endl;
            greens.pop();
        }
    }

    else {
        cout << "blue wins" << endl;
        while (!blues.empty()) {
            cout << blues.top() << endl;
            blues.pop();
        }

    }
}


int main(int argc, char const *argv[])
{
    TC {
        solve();
        if (t) cout << endl;
    }
    return 0;
}
