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
    int n; 
    while (cin >> n, n) {
        int a = 0, b = 0;
        int m = 0;
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {

                if (m % 2 == 0) b |= (1 << i);
                else a |= (1 << i);
                m++;
            }

        }
        cout << b << " " << a << endl;
    }  

    return 0;
}