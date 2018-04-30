/*
    Contents:
        13:  Move constructor simplest form
        36:  Small and simple move constructor example
        57:  Move assignment operator signature
        78:  Move assignment operator definition
        105:  Swapping objects using move
*/

/*
Move Example
*/

class Data {
    int a, b, c;
    int* array;
public:
    Data() : a(), b(), c() {
        array = new int[200];       // this object allocates and owns this
                                    // buffer
    }

    Data(const Data& d) : a(d.a), b(d.b), c(d.c) {
        array = new int[200];                   // this object allocates and
                                                // owns this buffer
        std::copy(d.array, d.array+200, array); // <- copy data for that buffer
                                                // from 'd's buffer
    }

    // the std::moves here aren't really necessary because they are basic types.
    //  but whatever.

    Data(Data&& d) : a(std::move(d.a)), b(std::move(d.b)), c(std::move(d.c)) {
        array = d.array;        // we are not allocating an buffer, but are
                                // merely taking ownership of 'd's buffer
        d.array = nullptr;      // <- have 'd' release it so that it no longer
                                // owns it.
    }

    ~Data() { // destructor --> delete whatever array we own
        delete[] array;
    }

    Data& operator = (const Data& d) { // copy assignment
        // no need to reallocate, because this object already owns a buffer.
        // Simply copy the data over
        a = d.a;
        b = d.b;
        c = d.c;
        std::copy(d.array, d.array+200, array);
        return *this;
    }

    Data& operator = (Data&& d) { // move assignment
        // no need to reallocate -- or even to copy.  We just want to move
        // ownership of d's buffer to this object.
        a = d.a;
        b = d.b;
        c = d.c;

        delete[] array;     // unallocate the buffer we currently own
        array = d.array;    // take ownership of d's buffer
        d.array = nullptr;  // have d release ownership of the buffer

        return *this;
    }
};

int main() {
    Data t1, t2;
    t2 = t1;  // calls assignment operator, same as "t2.operator=(t1);"
    Data t3 = t1;  // calls copy constructor, same as "Data t3(t1);"

    Data t4 = std::move(t2); // construction, invokes move constructor
    t4 = std::move(t3); // assignment, invokes move assignment operator
}

/*
 Or say we have a function return Data with a given prototype
*/

Data function1(int x);

/*
then the function is called in main
*/

int main() {
    t4 = function1(5); // What does this call or invoke?
    Data t5 = function1(5); // What does this call or invoke?
}
