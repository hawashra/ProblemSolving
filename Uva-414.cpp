#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define endl "\n"
int countSpace(char s[]);
// WA. 

// www

int counts[13];
char temp[30];
int main() {

    int n;
    int k;
    int low = 0;
    int curr = 0;
    int cnt = 0;
    while (scanf("%d", &n) && n) {
        cnt++;
        k = n;
        int i = 0;
        memset(counts, 0, n);
        low = INT_MAX;
        while (k--) {
            scanf("%s", temp);
            curr = countSpace(temp);
            counts[i++] = curr;
            low = min(low, curr);
        }

        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            ans += (counts[i] - low);
        } 
        printf("%d\n", ans);
    }
}

int countSpace(char s[]) {
    int cnt = 0;
    for (int i = 0; i < 25; i++)
        if (s[i] != 'X')
            cnt++;

    //printf("%dcoooooooo", cnt);

    return cnt;
}