/*
    Contents:
        13:  Move constructor simplest form
        36:  Small and simple move constructor example
        57:  Move assignment operator signature
        78:  Move assignment operator definition
        105:  Swapping objects using move
*/

/*
Move Constructor

In its the simplest form, a move constructor looks like this:
*/

A(A&& other) noexcept {    // C++11 - specifying non-exception throwing functions
    mData =  other.mData;  // shallow copy or referential copy
    other.mData = nullptr;
}

/*
 Note that it doesn't allocate any new resources and contents are moved not
 copied: what was in other moved to a new member, and what was in other
 disappeared. It pilfers other's resources and then sets other to its
 default-constructed state. The most critical fact is that there's no
 additional memory allocation. We just assign an address which only requires
 couple of machine instructions.

 Suppose that address is pointing to an array which has millions of integer.
 We do not copy the elements. We do not create anything. We just move it. If we
 use old copy constructor for a class which has an 1-million element array
 member, we may have that many assignment operations, which is costly. Now, with
 the move constructor, we can save a lot.
*/

// Move constructor.
A(A&& other) : mData(NULL), mLength(0) {
    // Copy the data pointer and its length from the
    // source object.
    mData = other.mData;
    mLength = other.mLength;

    // Release the data pointer from the source object so that
    // the destructor does not free the memory multiple times.
    other.mData = NULL;
    other.mLength = 0;
}

/*
The move constructor is much faster than a copy constructor because it doesn't
allocate memory nor does it copy memory blocks.
*/

/*
Move Assignment Operator

A move assignment operator has the following signature:
*/

A& operator=(A&& other) noexcept {
  mData =  other.mData;
  other.mData = nullptr;
  return *this;
}

/*
 Note: non-cppying move assignment and rhs destroyed.

 A move assignment operator is similar to a copy constructor except that before
 pilfering the source object, it releases any resources that its object may own.
 The move assignment operator takes the following steps:

 1. Release any resources that *this currently owns.
 2. Pilfer other's resource.
 3. Set other to a default state.
 4. Return *this.

 Here's a definition for the move assignment operator:
*/

// Move assignment operator.
A& operator=(A&& other)
{
    std::cout << "operator=(A&&). length = "
             << other.mLength << "." << std::endl;

    if (this != &other;) {
      // Free the existing resource.
      delete[] mData;

      // Copy the data pointer and its length from the
      // source object.
      mData = other.mData;
      mLength = other.mLength;

      // Release the data pointer from the source object so that
      // the destructor does not free the memory multiple times.
      other.mData = NULL;
      other.mLength = 0;
   }
   return *this;
}

/*
 Swapping objects using move()

 The following code shows how we can use move() to swap objects:
*/

/* move.cpp */
#include <iostream>
using namespace std;

class A {
  public:
    // constructor
    explicit A(size_t length)
        : mLength(length), mData(new int[length]) {}

    // move constructor
    A(A&& other) {
      mData = other.mData;
      mLength = other.mLength;
      other.mData = nullptr;
      other.mLength = 0;
    }

    // move assignment
    A& operator=(A&& other) noexcept {
      mData =  other.mData;
      mLength = other.mLength;
      other.mData = nullptr;
      other.mLength = 0;
      return *this;
    }

    size_t getLength() {
        return mLength;
    }


    void swap(A& other) {
      A temp = move(other);
      other = move(*this);
      *this = move(temp);
    }

    int* get_mData() {
        return mData;
    }

  private:
    int *mData;
    size_t mLength;
};

int main() {
  A a(11), b(22);
  cout << a.getLength() << ' ' << b.getLength() << endl;
  cout << a.get_mData() << ' ' << b.get_mData() << endl;
  swap(a,b);
  cout << a.getLength() << ' ' << b.getLength() << endl;
  cout << a.get_mData() << ' ' << b.get_mData() << endl;
  return 0;
}

/*
Output:

$ g++ -std=c++11 -o move move.cpp
$ ./move
11 22
0x1870010 0x1870050
22 11
0x1870050 0x1870010
*/
