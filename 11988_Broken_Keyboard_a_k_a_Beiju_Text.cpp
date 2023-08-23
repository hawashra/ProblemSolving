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

    deque<char> dq;
    stack<char> store;

    string line;   
    int mode = 0;
    
    while (cin >> line) {

        int i = 0;

        while (i < line.size()) {

            // push to the end of the queue (Home not pressed)
            while (i < line.size() && line[i] != '[' && mode == 0) {
                if (line[i] != ']') 
                    dq.push_back(line[i]);

                i++;
            }

            // pressed home, mode = 1 to push chars to front (but in reverse order..)
            if (i < line.size() && line[i] == '[') {
                mode = 1;
                i++;
            }

            // push chars to stack to reverse the order when popping out. 
            while(i < line.size() && line[i] != ']' && mode == 1 && line[i] != '[') {
                store.push(line[i]);
                i++;
            }
            // pop from stack and push to the front of the dequeue.
            while(!store.empty()) {
                dq.push_front(store.top());
                store.pop();
            }
            // switch mode 
            if (i < line.size() && line[i] == ']') {
                mode = 0;
                i++;
            }
            // switch mode
            if (i < line.size() && line[i] == '[' ) {
                mode = 1;
                i++;
            }

        }

        while(!dq.empty()) {
            cout << dq.front();
            dq.pop_front();
        }
        cout << endl;
    }


    return 0;
}
