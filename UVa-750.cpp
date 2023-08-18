#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
void search (int c, int a, int b);
bitset<8> rw;
bitset<15> rd;
bitset<15> ld;
int linecounter = 0;
int row[8];

int main() {

    int tc;

    scanf("%d\n\n", &tc);
    int a, b;

    while (tc--) {

        printf("SOLN    COLUMN\n");
        printf(" #   1 2 3 4 5 6 7 8\n\n");
        linecounter = 0;
        rw.reset();
        rd.reset();
        ld.reset();
        memset(row, 0, sizeof(row));
        scanf("%d %d", &a, &b);
        search(0, a-1, b-1);
        if (tc) printf("\n");
    }
}


void search (int c, int a, int b) {
    
    if (c == 8 and row[b] == a) {
        
        printf("%2d     %d", ++linecounter, row[0]+1);
        for (int j = 1; j < 8; ++j) printf(" %d", row[j]+1);
        printf("\n");
        return;
    }

    for (int r = 0; r < 8; r++) {

        if (c == b && r != a) continue;

        if (!rw[r] && !rd[r+c] && !ld[r-c+8-1]) {

            rw[r] = rd[r+c] = ld[r-c+8-1] = 1; 
            row[c] = r, search(c+1,a,b);
            rw[r] = rd[r+c] = ld[r-c+8-1] = 0;
        } 
    }
}
