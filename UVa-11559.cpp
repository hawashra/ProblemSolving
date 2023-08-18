#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int N, B, H, W;

    // N: number of people 
    // B: budget
    // H: number of hotels
    // W: number of weeks

    while (cin >> N >> B >> H >> W) {
        int mini = B+1;

        for (int i = 0; i < H; i++) {
            
            int unit_cost; // p
            cin >> unit_cost;


            for (int i = 0; i < W; i++) {

                int bed; // a
                cin >> bed;

                int tot = N*unit_cost; // p*N
                if (bed >= N && tot <= mini) {
                    mini = tot;
                }
                
            }
        }

        
        if (mini <= B) {
            cout << mini << endl;
        }
        else
            cout << "stay home" << endl;       
    }
    return 0;
}