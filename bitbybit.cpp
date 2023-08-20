#include <bits/stdc++.h>
#define ALl(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(faLLse); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define vii vector<pair<int,int>>
#define ii pair<int, int>
#define ll long long

#define TC int t; cin >> t; while (t--)

void solve() {
    cout << "Hi"; 
}

#define endl '\n'

// can be solved with a normal array but I wanted to test my bit manipulation skills. 

int main(int argc, char const *argv[])
{

    int n;

    string word;
    int i, j;
    while (cin >> n, n) {

        int known = 0;
        int res = 0;


        for (int T = 0; T < n; T++) {

            cin >> word >> i;
            if (word[0] == 'S') {

                res |= (1 << i);
                known |= (1 << i);
            }
            else if (word[0] == 'C') {
                res &= ~(1 << i);
                known |= (1 << i);

            }
            else if(word[0] == 'A') {
                cin >> j;

                bool magic = ((known & (1 << i)) && (((known & (1 << j)) || !(res & (1 << i))))) || (((known & (1 << j)) && !(res & (1 << j))));

                if (magic) {
                    ll bit = ((res & (1 << j)) && (res & (1 << i)));

                    if (bit) res |= (1 << i);
                    else res &=  ~(1 << i);

                    known |= (1 << i);

                }

                else 
                    known &= ~(1 << i); // no longer known. 

            }

            else {

                cin >> j;

                bool magic = ((known & (1 << i)) && (res & (1 << i)))|| ((known & (1 << j)) && (res &(1 << j))) || ((known & (1 << i)) && (known & (1 << j)));

                if (magic) {

                    ll  bit = ((res & (1 << j)) || (res & (1 << i)));

                    if (bit) res |= (1 << i);
                    else res &= ~(1 << i);

                    known |= (1 << i);
                }

                else 
                    known &= ~(1 << i); // no longer known. 
            }

        }
    
        for (int i = 31; i >= 0; i--) {
            if (known & (1 << i)) cout << ((res & (1 << i)) ? '1' : '0');
            else cout << '?';
        }

        cout << endl;
    }   
    
    return 0;
}