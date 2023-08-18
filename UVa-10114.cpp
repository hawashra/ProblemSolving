#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int months;
    double downPayment, loan;
    int records;

    while (true) {

        cin >> months >> downPayment >> loan >> records;
        vector<pair<int, double>> depreciation(records);


        if (months < 0)
            break;
            
        
        for (int i = 0; i < records; i++) {
            int month;
            double percent;
            cin >> month >> percent;
            depreciation[i]=make_pair(month, percent);
        }

        int idx = 0; // index of the depreciation for the current month.


        double priceNow = loan + downPayment; // the original loan amount, to be reduced by a factor of depreciation factor for each month.
        double owed = loan; // current amount left to be paid (the loan)

        double monthlyPayment = loan/months;

        priceNow = priceNow - (priceNow * depreciation[idx].second); // the car value goes down each month be a factor of depreciation.

        int currentMonth = 0; // current month number, starting from 0

        while (priceNow < owed) {

            currentMonth++;


            if (idx+1 < records && depreciation[idx+1].first == currentMonth) {

                idx = idx + 1;
            }

            priceNow = priceNow - (priceNow * depreciation[idx].second); // the car value goes down each month be a factor of depreciation.

            owed -= monthlyPayment; // subtract the monthly downPayment from the amount owed to the bank.

        }


        cout << currentMonth << " month";
        if (currentMonth != 1) {
            cout << "s";
        }
        cout << endl;

    }


    return 0;
}