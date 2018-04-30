#include<iostream>
#include<cstddef>
#include<string>
using namespace std;

class Box {
    int width, height; int * array;
public:
    int x=0;
    Box(): width(), height() {
    array = new int[200];
    cout<<"constructor"<<endl;
    }
    Box(const Box& b) : width (b.width ), height(b.height){
        array = new int[200];
        std::copy (b.array, b.array+200, array );
        cout<<"copy constructor"<<endl;
    }
    Box(Box&& b): width(std::move(b.width)), height(std::move(b.height)) {
        array = b.array;
        b.array = nullptr;
        cout<<"move constructor"<<endl;
    }
    ~Box() {
        delete[] array;
        cout<<"destructor"<<endl;
    }
    Box& operator = (const Box& b) {
        width = b.width; height = b.height;
        std::copy(b.array, b.array+200, array );
        cout<<"copy assignment"<<endl;
        return * this;
    }
    Box & operator = (Box&& b) {
        width = b.width; height = b.height;
        delete[] array;
        array = b.array;
        b.array = nullptr;
        cout<<"move assignment"<<endl;
        return *this;
    }
};

Box BoxReturn(void) { // This is a function that returns a Box
    Box b;
    return b;
}

int IntReturn(Box b) { //This is a function that takes a Box as a parameter
    return b.x;
}

//What is the output of this program?
int main() {
    Box bl, b2; // constructor, constructor
    Box b3 = bl; // copy constructor
    b2=bl; // copy assignment
    Box b4 = std::move(b2); // move constructor
    b4 = std::move(b3); // move assignment
    b4 = BoxReturn(); // constructor, move assignment, destructor
    int x = IntReturn (bl); // copy constructor, destructor
    return 0; // destructor, destructor, destructor, destructor
}
