#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define endl "\n"

int main() {

    int n, s, m;
    scanf("%d %d %d\n", &n, &s, &m);
    int arr[n];

    bitset<200> visited;

    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    bool win, outLeft,outRight, cycle;
    win = outLeft = outRight = cycle = false;
    int currPos = s-1;
    int h = 0;
    int ph = 0;
    visited.reset();

    while (not (win or outLeft or outRight or cycle)) {
    
        if (currPos + ph < 0 ) {
            outLeft = true;
            break;
        }
        else if (currPos + ph >= n) {
            outRight = true;
            break;
        }

        else if (arr[currPos + ph] == m) {
            win = true;
            break;
        }

        else if (visited.test(currPos + ph)) {
            cycle = true;
            break;
        }
        ++h;
        int temp = ph;
        ph += arr[currPos+ph];
        visited.set(currPos+temp);
    
    }

    if (outLeft) cout << "left\n" << h << endl;
    else if (outRight) cout << "right\n" << h << endl;
    else if (cycle) cout << "cycle\n" << h<< endl;
    else cout << "magic\n" << h << endl;
}