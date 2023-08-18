#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define vii vector<pair<int,int>>

// why it gives WA, it's the same fucking code on github. 

void solve(int tc);
int main() {

    FAST
    int T;
    scanf("%d", &T);
    
    int i = 0;
    while (T--) {
        ++i;
        solve(i);
    }
}

void solve(int tc) {

    string input;
    cin >> input;
    
    int len = input.length();
    int ans = 0;

    input = "-" + input;
    input = input + "--";

    for (int i = 1; i <= len; i++) {

        char obj = input[i];

        if (obj == '-' && input[i+1] != 'B' && input[i+2] != 'B' 
        && input[i+1] != 'S' && input[i-1] != 'S') ans++; 

    }
    cout << "Case " << tc << ": " << ans << endl;
    
}