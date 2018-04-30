/*
RValues & RValue References
Pass by value
What's the implication of passing a variable by value?

When a function gets its parameter as by value, it does copy. Compiler knows
 how to copy it. If it's a user defined type, we may need to provide copy
 constructor, and probably assignment operator as well to be able to do a deep
 copy. However, copying is expensive. Actually, there are bunch of copying going
 on when we use STL containers. When an object tossed in by value, since it's a
 temporary object (rvalue), we're really wasting our precious resources
 including CPU as well as memory and so on.

Rvalue references enable us to distinguish an lvalue from an rvalue.

The C++11 Standard introduces rvalue references which bind only to rvalues.
They are declared with two ampersands rather than one ampersand:
*/

int&& rvalue_ref = 99;

/*
Note that only an lvalue can be assigned to a normal reference, so if we do the
following:

int& ref = 9;

we get an error: "invalid initialization of non-const reference of type int&
from an rvalue of type int.  We can only do:
*/

int nine = 9;
int& ref = nine;

/*
 Here is an example of rvalue reference. We have two functions: one that's
 taking an lvalue reference and the other one taking an rvalue:
*/

#include <iostream>

void f(int& i) {
    std::cout << "lvalue ref: " << i << "\n";
}

void f(int&& i) {
    std::cout << "rvalue ref: " << i << "\n";
}

int main() {
    int i = 77;
    f(i);    // lvalue ref called
    f(99);   // rvalue ref called
    return 0;
}

/*
 An expression is an rvalue if it results in a temporary object as shown in the
 example below.
*/

#include <iostream>

int getValue () {
    int ii = 10;
    return ii;
}

int main() {
    std::cout << getValue();
    return 0;
}

/*
 The getValue() is an rvalue.
 Note that the value being returned is not a reference to ii, but it's just a
 temporary value.

 In C++11, the rvalue reference lets us bind a mutable reference to an rvalue,
 but not an lvalue. In other words, rvalue references are perfect for detecting
 whether a value is a temporary object or not.
*/

const int&& val = getValue(); // OK
int&& val = getValue(); //  OK

/*
 Let's compare both references:
*/

void printReference (const int& value) {
        cout << value;
}

void printReference (int&& value) {
        cout << value;
}

/*
 The printReference() function taking a const lvalue reference will accept any
 argument whether it be an lvalue or an rvalue. However, the second overloaded
 printReference*() taking only an rvalue reference.

 In other words, by using the rvalue references, we can use function overloading
 to determine whether function parameters are lvalues or rvalues by having one
 overloaded function taking an lvalue reference and another taking an rvalue
 reference. In other words, C++11 introduces a new non-const reference type
 called an rvalue reference, identified by T&&. This refers to temporaries that
 are permitted to be modified after they are initialized, which is the
 cornerstone of move semantics.
*/

#include <iostream>
using namespace std;

void printReference (int& value) {
    cout << "lvalue: value = " << value << endl;
}

void printReference (int&& value) {
    cout << "rvalue: value = " << value << endl;
}

int getValue () {
    int temp_ii = 99;
    return temp_ii;
}

int main() {
	int ii = 11;
	printReference(ii);
	printReference(getValue());  //  printReference(99);
	return 0;
}

/*
With the output:

lvalue: value = 11
rvalue: value = 99
*/

/*
Note that we took out const from the void printReference (int& value) so that
it can take only the lvalue.

Now, we have two distinct functions that can be overloaded: one taking only
lvalue and the other one only taking rvalue. So, what?

It gives us a way to write more efficient program with less coding!
*/

/*
rvalue summary:

1.  int &&a; - declaration rvalue reference.
2.  non-const lvalue reference binds to an object.
3.  rvalue reference binds to a temporary object which typically will not be
    used again.
*/
