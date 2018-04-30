/*
Vector

 The vector container can be thought of as an array class template that has an
 expandable capacity and a large set of built-in operations. Many of these
 operations are powerful and useful to a c++ programmer.

 A simplified form of vector's declaration as a class template in the standard
 library might look something like the following:

*/

template <typename T>
class vector {
    public:
        // A large collection of useful function members
    private:
        // Data members, one of which is a dynamic array
        T * myArray;
};

/*
Here, T is a parameter for the type of values to be stored in the container.
In order to use vector in our programs we must use the following:
*/

#include <vector>

/*
This will allow us to make declarations in our code, for example:
*/

vector<double> vectorOfDoubles;
vector<int> vectorOfInts;
vector<string> vectorOfStrings;

/*
 Vector Constructors:
*/

vector<ElementType> objectName; // Construct an empty vector

vector<ElementType> objectName(initCap);    //  Construct a vector with
                                            // capacity = initCap and elements
                                            // initialized by the default
                                            // constructor for ElementType

vector<ElementType> objectName(initCap, initVal);   // Like the preceding but
                                                    // initializes each element
                                                    // with initVal

 vector<ElementType> objectName(firstPtr, lastPtr); // Construct a vector
                                                    // initialized with the
                                                    // contents of the memory
                                                    // location pointed to by
                                                    // firtPtr up to (but not
                                                    // including) that pointed
                                                    // to by lastPtr.

/*
Vector Operations (given a vector v)
*/

v.capacity() // Return the number of locations v currently has
v.size() // Return the number of values currently stored in v
v.max_size() // Return the maximum number of locations v can ever have
v.empty() // Return true if and only if v contains no values (ie, v's size is 0)
v.reserve(n); // Grow v so that it's capacity is n (does not affect v's size)
v.push_back(value); // Append value at v's end
v.pop_back(); // Erase v's last element
v.front() // Return a reference to v's first element
v.back() // Return a reference to v's last element
v[i]    //  Access the element of v whose index is i - no bounds checking of
        // index is done
ti v.at(i)  // Access the element of v whose index is i - bounds checking is
            // done- throws out-of-range exception if index is out of range.
v1 = v2 // Assign a copy of v2 to v1
v1.swap(v2) // Swap v1's contents with v2's
v1 == v2    // Return true if and only if v1 has the same values as v2, in the
            // same order
v1 < v2 // Return true if and only if v1 is lexicographically less than v2

/*
 Some basic examples:
*/

vector<double> v(3);
cout << v.capacity() << ' ' << v.size();

/*
 OUTPUT:
 3 3
*/

vector<double> v(3,4.0);
cout << v.capactiy() << ' ' << v.size() << endl
     << v.reserve(6)
     << v.capacity() << ' ' << v.size() << endl

/*
 OUTPUT:
 3 3
 6 3
*/

/*
 An Example using push and pop:
*/

vector<double> v;
v.push_back(1.1); v.push_back(2.2); v.push_back(3.3);
cout << v.front() << ' ' << v.back() << endl;
v.pop_back();
cout << v.front() << ' ' << v.back() << endl;
v.front() = 4.4; v.back = 5.5;
cout << v.front() << ' ' << v.back() << endl;

/*
 OUTPUT:
 1.1 3.3
 1.1 2.2
 4.4 5.5
*/

/*
 Vectors vs Arrays
    - The capacity of a vector can increase during execution; the capacity of an array is
        fixed and cannot be changed during execution.

    - A vector is a self-contained object; and array is not.

    - A vector is a class template and is thus not bound to a specific type of the elements;
        the compiler will generate whatever instances are needed.

    - vectors' function members provide ready-to-use implementations fo many common operations.

    - Arrays require us to reinvent the wheel for most operations.

*/
