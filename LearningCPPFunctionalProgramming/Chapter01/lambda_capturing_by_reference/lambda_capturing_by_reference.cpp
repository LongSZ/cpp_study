/* lambda_capturing_by_reference.cpp */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

auto main() -> int {
    cout << "[lambda_capturing_by_reference.cpp]" << endl;

    // Initializing a vector containing integer element
    vector<int> vect;
    for (int i = 0; i < 10; ++i) vect.push_back(i);

    // Displaying the elements of vect
    cout << "Original Data:" << endl;
    for_each(begin(vect), end(vect),
            [](int n){
                cout << n << " ";
            });
    cout << endl;

    // Initializing two variables
    int a = 1;
    int b = 1;

    // Capturing value from the two variables and mutate them
    for_each(begin(vect), end(vect),
            [&a, &b](int& x){
                const int old = x;
                x *= 2;
                a = b;
                b = old;
            });

    // Displaying the elements of vect
    cout << "Squared Data:" << endl;
    for_each(begin(vect), end(vect),
            [](int n) {
                cout << n << " ";
            });
    cout << endl << endl;

    // Displaying value of variable a and b
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
root@longsz-VirtualBox:~/Desktop# g++ -std=c++20 -o test.out test.cpp
root@longsz-VirtualBox:~/Desktop# ./test.out 
[lambda_capturing_by_reference.cpp]
Original Data:
0 1 2 3 4 5 6 7 8 9 
Squared Data:
0 2 4 6 8 10 12 14 16 18 

a = 8
b = 9
