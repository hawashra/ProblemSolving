#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define vii vector<pair<int,int>>
#define ii pair<int, int>
#define ll long long
#define endl '\n'
#define TC int t; cin >> t; while (t--)

void solve() {
    cout << "Hi"; 
}

int main(int argc, char const *argv[])
{
    // supports pop_front and pop_back in constant time.

    deque<int> dq;
    int n;
    string ops; // operations
    bool is_rev = false; // tells us that we got an (odd) number of rev operations. 
    bool err = false;
    int x;
    string str;
    TC {
        is_rev = false;
        err = false;
        cin >> ops;
        cin >> n;
        cin >> str;
        istringstream iss(str);

        iss.ignore();

        for (int i; iss >> i;) {
            dq.push_back(i);
            if (iss.peek() == ',' || iss.peek() == '[')
                iss.ignore();
        }

        
        for (auto chr : ops) {

            if (chr == 'D' && dq.empty()) { err = true; break; }

            else if (chr == 'D' && is_rev) dq.pop_back();

            else if (chr == 'D') dq.pop_front();

            else if (chr == 'R') is_rev = not is_rev;
        }

        if (err) { cout << "error\n"; dq.clear(); continue; }

        if (dq.empty()) { cout << "[]\n"; continue; }

        cout << '['; 
        while (!dq.empty()) {

            if (is_rev) {

                cout << dq.back();
                cout << ((dq.size() > 1) ? "," : "]");
                dq.pop_back();
            }
            else {
                cout << dq.front();
                cout << ((dq.size() > 1) ? "," : "]"); 
                dq.pop_front();
            }
        }
        cout << endl;
        dq.clear();
    }

    return 0;
}