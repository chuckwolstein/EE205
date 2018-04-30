/* Recursion - when a function calls itself
    it does this without a ‘for loop’.*/

#include <iostream>
using namespace std;

void numberFunction( int i ) {
    cout << "The number is: " << i << endl;
    i++;
    if( i < 10) {
        numberFunction( i );
    }
}

int main() {
    int i =0;
    numberFunction(i);
    return 0;
}
