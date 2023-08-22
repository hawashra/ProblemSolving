#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define ii pair<int, int>
#define vii vector<ii>

#define ll long long
#define endl '\n'
#define TC int t; cin >> t; while (t--)

void solve() {
    cout << "Hi"; 
}

int main(int argc, char const *argv[])
{   
    FAST
    int N;
    cin >> N;
    int arr[N];
    for (int i=0; i<N;i++) cin >> arr[i];
    
    int first = arr[0];
    int mini = 1000000001;
    int ans = 0;
    int i;

    for (i = 1; i < N; i++) {

        if (arr[i] >= first) {

            if ( first - mini > ans) {
                ans = first - mini;
            }

            first = arr[i];
            mini=1000000001;
        }

        else {
            mini = min(mini, arr[i]);
        }
    }

    
    first = arr[N-1];
    mini=1000000001;

    for (i = N-2; i >= 0; i--) {

        if (arr[i] >= first) {

            if ( first - mini > ans) {
                ans = first - mini;
            }

            first = arr[i];
            mini=1000000001;
        }

        else {
            mini = min(mini, arr[i]);
        }
    }

    cout << ans << endl;

    return 0;
}