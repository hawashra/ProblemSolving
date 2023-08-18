#include <iostream>
#include <cstdio>
using namespace std;


#define FAST cin.tie(0); ios::sync_with_stdio(false); cout.tie(0); 
int main () {

    FAST

    double H, U, D, F;

    while (scanf("%lf %lf %lf %lf", &H, &U, &D, &F) != EOF) {

        double currHeight = 0;
        int day = 1;

        if (H == 0)
            break;
        

        double factor = U*F/100.0;
        
        int L = U;
        while (true) {

            currHeight = currHeight + U;

            if (currHeight > H)
                break;
            
            currHeight -= D;

            if (U > 0)
                U -= factor;

            if (currHeight < 0)
                break;
            
            day++;
        }

        if (currHeight >= H) {
            printf("success on day %d\n", day);
        }
        else {
            printf("failure on day %d\n", day);
        }

    }

    return 0;
}