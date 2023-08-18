#include <iostream>
#include <cstdio>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream

#define ALL(x) x.begin(), x.end()

#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);

int main(void) {

    FAST

    vector<pair<string, string>> books_and_authors;

    string s;

    map<string, int> book_to_index;

    
    while (getline(cin, s), s != "END") {

        istringstream iss(s);

        iss.ignore(1, '\"');

        string book;

        getline(iss, book, '\"');

        string author;

        // ignore " by "
        iss.ignore(4, ' ');

        getline(iss, author);


        books_and_authors.emplace_back(author, book);
    }

    sort(ALL(books_and_authors));

    for (int i = 0; i < books_and_authors.size(); i++) {
        book_to_index[books_and_authors[i].second] = i;
    }


    vector<bool> isborrowed(books_and_authors.size(), false);
    vector<bool> isreturned(books_and_authors.size(), false);


    while (getline(cin, s), s != "END") {

        
        istringstream iss(s);

        string command;

        iss >> command;

        string book;

        if (command != "SHELVE") {
            iss.ignore(8, '\"');
            getline(iss, book, '\"');
        }

        if (command == "BORROW") {
            isborrowed[book_to_index[book]] = true;
            isreturned[book_to_index[book]] = false;
        } else if (command == "RETURN") {
            isreturned[book_to_index[book]] = true;
        } else if (command == "SHELVE") {
            int last = -1;
            for (int i = 0; i < books_and_authors.size(); i++) {
                if (isreturned[i]) {
                    isborrowed[i] = false;
                    isreturned[i] = false;
                    if (last == -1) {
                        cout << "Put \"" << books_and_authors[i].second << "\" first\n";
                    } else {
                        cout << "Put \"" << books_and_authors[i].second << "\" after \"" << books_and_authors[last].second << "\"\n";
                    }
                    last = i;
                }

                else if (not isborrowed[i]) {
                    last = i;
                }
            }
            cout << "END\n";
        }

    }
    return 0;
}