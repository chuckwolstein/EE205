/*
Subjects covered / demonstrated:
    -copy constructor defined in lines 32, 111
        -called in lines 40, 82, 163, 170, 180
    -assignment operator
        -called in lines 83, 181


*/

/*
What is a copy constructor?
 A copy constructor is a member function which initializes an object using
 another object of the same class. A copy constructor has the following general
 function prototype:
*/

ClassName (const ClassName &old_obj);

/* example 1: */

#include<iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x1, int y1) { x = x1; y = y1; }

    // Copy constructor
    Point(const Point &p2) {x = p2.x; y = p2.y; }

    int getX()            {  return x; }
    int getY()            {  return y; }
};

int main() {
    Point p1(10, 15); // Normal constructor is called here
    Point p2 = p1; // Copy constructor is called here

    // Let us access values assigned by constructors
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
    cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY();

    return 0;
}

/*
p1.x = 10, p1.y = 15
p2.x = 10, p2.y = 15
*/

/*
Copy Constructor may be called in following cases:
1. When an object of the class is returned by value.
2. When an object of the class is passed (to a function) by value as an argument.
3. When an object is constructed based on another object of the same class.
4. When compiler generates a temporary object.

When is user defined copy constructor needed?

If we don’t define our own copy constructor, the C++ compiler creates a default
    -copy constructor for each class which does a member wise copy between
    objects.

    -The compiler created copy constructor works fine in general. We need to
    define our own copy constructor only if an object has pointers or any run
    time allocation of resource like file handle, a network connection..etc.

   Default constructor does only shallow copy.

    -Deep copy is possible only with user defined copy constructor.
        -In user defined copy constructor, we make sure that pointers
        (or references) of copied object point to new memory locations.

    ---Copy constructor vs Assignment Operator---
        Which of the following two statements call copy constructor and which
        one calls assignment operator?

        MyClass t1, t2;
        MyClass t3 = t1;  // ----> calls copy constrictor
        t2 = t1;          // -----> calls assignment operator

        Copy constructor is called when a new object is created from an
        existing object, as a copy of the existing object.
        Assignment operator is called when an already initialized object is
        assigned a new value from another existing object.


        Write an example class where copy constructor is needed?
        Following is a complete C++ program to demonstrate use of Copy constructor. In the following String class, we must write copy constructor.
*/

/* example 2: */

#include<iostream>
#include<cstring>
using std::cin; // didn't write 'using namespace std' because we may not want
using std::cout; // to default to std.  We might just want cin, cout, and endl
using std::endl;

class Point {
    private:
        int x, y;
    public:
        Point(int x1, int y1) {
            x = x1; y = y1;
        }

        Point(const Point &p2) { // Copy constructor
            // copy p2's members into the new Point
            x = p2.x;
            y = p2.y;
        }

        int getX() { // getter for x
            return x;
        }

        int getY() { // getter for y
            return y;
        }
};

class String {
    private:
        char *s; //character pointer (AKA string)
        int size;
    public:
        String(const char *str = NULL) {
            size = strlen(str);
            s = new char[size+1]; //the +1 is to leave room for the nullptr
            strcpy(s, str); //s is the original string and str is the destination
                //of the copy
        }

        ~String() { // destructor
            delete [] s; //makes sure we're deleting all the cells allocated to
                        //the entire string
        }

        String(const String& old_str){ // copy constructor
            size = old_str.size;
            s = new char[size+1];
            strcpy(s, old_str.s);
        }

        void print() {  // Function to print string
            cout << s << endl;
        }

        void change(const char *str) { // Function to change
            delete [] s;
            size = strlen(str);
            s = new char[size+1];
            strcpy(s, str);
            }
};

int main() {
    Point p1(10, 15); // parameterized constructor is called here
    Point p2 = p1; // Copy constructor is called here

    // Let us access values assigned by constructors
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
    cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY();

    String str1("GeeksQuiz");
    String str2 = str1;  // Copy constructor is called here

    str1.print(); // what is printed ?
    str2.print();

    str2.change("GeeksforGeeks");

    str1.print(); // what is printed now ?
    str2.print();

    String str3 = str2;  // Copy constructor is called here
    //str1 = str2; // assignment operator would be called here
                   // but it somehow results in a double free
    str1.print();
    str3.print();

    return 0;
}
