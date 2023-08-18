#include <iostream>
//#define FAST cin.tie(0); ios::sync_with_stdio(false); cout.tie(0);
#include <string>
using namespace std;
// GETS TLE not sure why

int main() {

    

    int i = 0;

    int n, p;
    string s;
    while (1) {

        cin >> n >> p;

        if (n == 0 && p == 0)
            break;

        i++;

        int req_met = -1;
        double min_price = 2000000000;

        string best = "";

    

        for (int i = 0; i < n; i++) {
        
            cin.ignore();
            getline(cin, s);
            
        }


        while (p--) {

            getline(cin, s);
        
            double d;
            int r;
            scanf("%lf %d", &d, &r);

            
            if (r > req_met || (r == req_met && d < min_price)) {
                req_met = r;
                best = s;
                min_price = d;
            }

            for (int j = 0; j < r; j++) {
                getline(cin, s);
            }
        }

        if (i > 1)
            printf("\n");
        printf("RFP #%d\n", i);
        cout << best << endl;
        i++;
    }



    return 0;
}