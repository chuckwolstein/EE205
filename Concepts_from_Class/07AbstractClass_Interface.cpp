/*
 Abstract Class

 An abstract class is a class that is designed to be specifically used as a
 base class. An abstract class contains at least one pure virtual function. You
 declare a pure virtual function by using a pure specifier (= 0) in the
 declaration of a virtual member function in the class declaration.

 The following is an example of an abstract class:
*/

class AB {
    public:
        virtual void f() = 0;
};

/*
 Function AB::f is a pure virtual function. A function declaration cannot have
 both a pure specifier and a definition. For example, the compiler will not
 allow the following:
*/

struct A {
  virtual void g() { } = 0;
};

/*
You cannot use an abstract class as a parameter type, a function return type,
or the type of an explicit conversion, nor can you declare an object of an
abstract class. You can, however, declare pointers and references to an
abstract class. The following example demonstrates this:
*/

struct A {
  virtual void f() = 0;
};

struct B : A {
  virtual void f() { }
};

// Error:
// Class A is an abstract class
// A g();

// Error:
// Class A is an abstract class
// void h(A);
A& i(A&);

int main() {

// Error:
// Class A is an abstract class
//   A a;

   A* pa;
   B b;

// Error:
// Class A is an abstract class
//   static_cast<A>(b);
}

/*
 Class A is an abstract class. The compiler would not allow the function
 declarations A g() or void h(A), declaration of object a, nor the static cast
 of b to type A.

 Virtual member functions are inherited. A class derived from an abstract base
 class will also be abstract unless you override each pure virtual function in
 the derived class.

 For example:
*/

class AB {
    public:
        virtual void f() = 0;
};

class D2 : public AB {
    void g();
};

int main() {
    D2 d;
}

/*
 The compiler will not allow the declaration of object d because D2 is an
 abstract class; it inherited the pure virtual function f()from AB. The
 compiler will allow the declaration of object d if you define function D2::f(),
 as this overrides the inherited pure virtual function AB::f(). Function AB::f()
 needs to be overridden if you want to avoid the abstraction of D2.

 Note that you can derive an abstract class from a nonabstract class, and you
 can override a non-pure virtual function with a pure virtual function.

 You can call member functions from a constructor or destructor of an abstract
 class. However, the results of calling (directly or indirectly) a pure virtual
 function from its constructor are undefined. The following example demonstrates
 this:
*/

struct A {
  A() {
    direct();
    indirect();
  }

  virtual void direct() = 0;

  virtual void indirect() {
      direct();
  }

};

/*
 The default constructor of A calls the pure virtual function direct() both
 directly and indirectly (through indirect()).
*/



/*
-----------------------------Interfaces---------------------------------
*/

/*
 A good way to think of Interfaces
 An interface defines how an object will be used.


 An interface describes the behavior or capabilities of a C++ class without
 committing to a particular implementation of that class.

 The C++ interfaces are implemented using abstract classes and these abstract
 classes should not be confused with data abstraction which is a concept of
 keeping implementation details separate from associated data.

 A class is made abstract by declaring at least one of its functions as pure
 virtual function. A pure virtual function is specified by placing "= 0" in its
 declaration as follows −
*/

class Box {
   public:
      virtual double getVolume() = 0; // pure virtual function

   private:
      double length; // Length of a box
      double breadth; // Breadth of a box
      double height; // Height of a box
};

/*
 The purpose of an abstract class (often referred to as an ABC) is to provide
 an appropriate base class from which other classes can inherit. Abstract
 classes cannot be used to instantiate objects and serves only as an interface.
 Attempting to instantiate an object of an abstract class causes a compilation
 error.

 Thus, if a subclass of an ABC needs to be instantiated, it has to implement
 each of the virtual functions, which means that it supports the interface
 declared by the ABC. Failure to override a pure virtual function in a derived
 class, then attempting to instantiate objects of that class, is a compilation
 error.

 Classes that can be used to instantiate objects are called concrete classes.


 Abstract Class Example

 Consider the following example where parent class provides an interface to the
 base class to implement a function called getArea() −
*/

#include <iostream>
using namespace std;

class Shape { // Base class
   public:
      // pure virtual function providing interface framework.
      virtual int getArea() = 0;

      void setWidth(int w) {
         width = w;
      }

      void setHeight(int h) {
         height = h;
      }

   protected:
      int width;
      int height;
};

class Rectangle: public Shape { // Derived class
    public:
        int getArea() {
            return (width * height);
        }
};

class Triangle: public Shape { // Derived class
    public:
        int getArea() {
            return (width * height)/2;
        }
};

int main(void) {
    Rectangle Rect;
    Triangle  Tri;

    Rect.setWidth(5);
    Rect.setHeight(7);

    // Print the area of the object.
    cout << "Total Rectangle area: " << Rect.getArea() << endl;

    Tri.setWidth(5);
    Tri.setHeight(7);

    // Print the area of the object.
    cout << "Total Triangle area: " << Tri.getArea() << endl;

    return 0;
}

/*
 When the above code is compiled and executed, it produces the following
 result −
*/

/*
 Total Rectangle area: 35
 Total Triangle area: 17
*/

/*
 You can see how an abstract class defined an interface in terms of getArea()
 and two other classes implemented same function but with different algorithm
 to calculate the area specific to the shape.
*/

/*
 Designing Strategy

 An object-oriented system might use an abstract base class to provide a common
 and standardized interface appropriate for all the external applications.
 Then, through inheritance from that abstract base class, derived classes are
 formed that operate similarly.

 The capabilities (i.e., the public functions) offered by the external
 applications are provided as pure virtual functions in the abstract base class.
 The implementations of these pure virtual functions are provided in the derived
 classes that correspond to the specific types of the application.

 This architecture also allows new applications to be added to a system easily,
 even after the system has been defined.
*/
