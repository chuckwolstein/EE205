/*
Subjects covered / demonstrated:
   -31: iostream
   -32: namespace
   -34: MACROS
     (referenced in line: 210)
   -260: try
     -46: throw
     -270: catch
   -51: classes
          -188: private
               -52: protected
               -55: public
          -56:  default constructors (called in line: 284)
          -57:  paramerized constructors (called in line: 275)
          -58:  destructors (called whenever going out of scope)
          -59:  getters (called in line: 277)
          -62:  setters (called in line: 292)
          -187: Inheritance from multiple parent classes (in class RV)

   -67: Operator Overload (called in line: 285)
   -69: The this-> pointer
   -199: inline functions
   -227: initializing Arrays with a for loop
   -243: new and delete for dynamic memory allocation
*/

 //remember to compile this with c++11 by using:
 //g++ MT1Prep.cpp -std=c++11

#include <iostream>
using namespace std;

#define ARRAY_CEILING 10

//Try, throw, and catch
//These are used to tell your program how to handle
//invalid input or other errors you want to catch
float Check(float x){
      if(x < 0){ //in this case, we don't want a negative
                //number for the integer we're checking
                //look in the main() of this particular
                //file to find where I've implemented
                //try and catch

        throw 0;  //throw control of the program to our
                //exception handler
      }
}

class Home {
protected:
  int numBed, numBath;
  float sqFt;
public:
  Home(); //default constructor for Home
  Home(int, int, float);  //parameterized constructor for Home
  ~Home();  // destructor for Home
  int getBeds();  //getter for Number of bedrooms
  int getBaths();  //getter for Number of bathrooms
  float getArea();  //getter for living area
  void setBeds(int);  //setter for Number of bedrooms
  void setBaths(int);  //setter for Number of bedrooms
  void setArea(float);  //setter for living area

  // Overload * operator to combine two Home objects.
  Home operator*(const Home& h) {
    Home house;
    house.numBed = this->numBed + h.numBed;
    house.numBath = this->numBath + h.numBath;
    house.sqFt = this->sqFt + h.sqFt;
    return house;
    }
  };

 //default constructor for Home
Home::Home() {
  numBed = 0;
  numBath = 0;
  sqFt = 0.0;
}

//parameterized constructor for Home
Home::Home(int beds, int baths, float area) {
  numBed = beds;
  numBath = baths;
  sqFt = area;
}

// destructor for Home
Home::~Home() {}

//getter for Number of bedrooms
int Home::getBeds() {
  return numBed;
}

//getter for Number of bathrooms
int Home::getBaths() {
  return numBath;
}

//getter for living area
float Home::getArea() {
  return sqFt;
}

//setter for Number of bedrooms
void Home::setBeds(int beds) {
  numBed = beds;
}

//setter for Number of bathrooms
void Home::setBaths(int baths) {
  numBath = baths;
}

//setter for living area
void Home::setArea(float area) {
  sqFt = area;
}

class Vehicle {
protected:
  int numWheels, numSeats;
  float fuelCap;
public:
  Vehicle(); //default constructor for Vehicle
  Vehicle(int, int, float);  //parameterized constructor for Vehicle
  ~Vehicle();  // destructor for Vehicle
  int getWheels();  //getter for Number of wheels
  int getSeats();  //getter for Number of seats
  float getFuel();  //getter for fuel capacity
  void setWheels(int);  //setter for Number of wheels
  void setSeats(int);  //setter for Number of seats
  void setFuel(float);  //setter for fuel capacity
};

//default constructor for Vehicle
Vehicle::Vehicle() {
  numWheels = 0;
  numSeats = 0;
  fuelCap = 0.0;
}

//parameterized constructor for Vehicle
Vehicle::Vehicle(int wheelz, int seatz, float tank) {
  numWheels = wheelz;
  numSeats = seatz;
  fuelCap = tank;
}

// destructor for Vehicle
Vehicle::~Vehicle() {}

//getter for Number of wheels
int Vehicle::getWheels()   {
  return numWheels;
}

//getter for Number of seats
int Vehicle::getSeats()   {
  return numSeats;
}

//getter for fuel capacity
float Vehicle::getFuel() {
  return fuelCap;
}

//setter for Number of wheels
void Vehicle::setWheels(int wheelz) {
  numWheels = wheelz;
}

//setter for Number of seats
void Vehicle::setSeats(int seatz)  {
  numSeats = seatz;
}

//setter for fuel capacity
void Vehicle::setFuel(float tank) {
  fuelCap = tank;
}

//RV is a class with two parent classes
class RV: public Home, public Vehicle {
private:
  int * rv_array;    //this array LITERALLY has no purpose but
                     //to help demonstrate the usefulness of the move
                     //contructor in the code below
public:
  RV(); //default constructor for RV

 //parameterized constructor for RV
  RV(int beds, int baths, float area, int wheels, int seats, float tank);
  ~RV();  // destructor for RV

  inline int example(int, int);
};

//default constructor for RV
RV::RV() {
  numBed = 0;
  numBath = 0;
  sqFt = 0.0;
  numWheels = 0;
  numSeats = 0;
  fuelCap = 0.0;
  rv_array = new int[ARRAY_CEILING]; //this object allocates and
                                     //owns this buffer
  }

//parameterized constructor for RV
RV::RV(int beds, int baths, float area, int wheelz, int seatz, float tank) {
  numBed = beds;
  numBath = baths;
  sqFt = area;
  numWheels = wheelz;
  numSeats = seatz;
  fuelCap = tank;
  rv_array = new int[ARRAY_CEILING]; //this object allocates and
                                     //owns this buffer

  //initialize the rv_array with some values, just so we have something
  //to copy and move later
  for (int i=0; i<ARRAY_CEILING; i++) {//cycle through the array for initialization
    int val = i + 1;
    rv_array[i] = val; //initialize each cell in the array with increasing values
  }
}

RV::~RV() {  // destructor for RV
  delete[] rv_array;  //need to specifically delete the array since we
                      //dynamically allocated memory for it before
}

// define our example inline function
inline int RV::example(int x, int y) {
  return (x + y);
}

int * dynMemAllocate(){ //Using new and delete to dynamically allocate memory
  int * ptr1 = new int;
  * ptr1 = 7;
  delete ptr1;
  return ptr1;
}

int main() {

  //demo for dynamic memory allocation in C++
  cout << "demo for dynamic allocation.  ptr1 = " << dynMemAllocate() <<endl << endl << endl;

  //Here, I demonstrate use of try and catch.  Note that throw was
  //used in a function at the very top of the program
  float input=0;
  cout << "Enter a positive number:";
  cin >> input;
  try
    {
        Check(input);   //note that throw is inside Check()
                        //that means (in my particular Check() function
                        //that if our check function  realizes it has
                        //been passed a negative value, then it will ignore
                        //the rest of the stuff in this try block
                        //and immidiately pass control to the 'catch' section
        cout << "You entered:  " << input << endl << endl;
    }
    catch (int i) {
     cout << "Error:  You entered a negative number." << endl << endl;
    }

  //Calling a parameterized constructor
  Home home1(1,2,3.0);
  //note that we need to use our getters to access the protected variables
  cout << "home1's Number of bedrooms : " << home1.getBeds() <<endl;
  cout << "home1's Number of bathrooms : " << home1.getBaths() <<endl;
  cout << "home1's Living area : " << home1.getArea() <<endl << endl;
  Home home2(6,7,12.3);
  cout << "home2's Number of bedrooms : " << home2.getBeds() <<endl;
  cout << "home2's Number of bathrooms : " << home2.getBaths() <<endl;
  cout << "home2's Living area : " << home2.getArea() <<endl << endl;
  Home home3; //calling the default constructor for home 3
  home3 = home1 * home2; //using our overloaded * operator
  cout << "home3 results from combining home1 and home2" << endl << endl;
  cout << "home3's Number of bedrooms : " << home3.getBeds() <<endl;
  cout << "home3's Number of bathrooms : " << home3.getBaths() <<endl;
  cout << "home3's Living area : " << home3.getArea() <<endl << endl;

  RV rv1(1,2,3.0,4,5,6.0); //parameterized constructor for our child class
  rv1.setBeds(2);//we need to use our setters to change the protected variables
  cout << "rv1's Number of bedrooms : " << rv1.getBeds() <<endl;
  cout << "rv1's Number of bathrooms : " << rv1.getBaths() <<endl;
  cout << "rv1's Living area : " << rv1.getArea() <<endl;
  cout << "rv1's Number of wheels : " << rv1.getWheels() <<endl;
  cout << "rv1's Number of seats : " << rv1.getSeats() <<endl;
  cout << "rv1's Fuel Capacity : " << rv1.getFuel() <<endl << endl << endl;


  RV rv2 = rv1;  //invoking the copy constructor here
  cout << "We just copied rv1 into a new RV called rv2" << endl;
  cout << "let's check rv2 to make sure its member variables" << endl;
  cout << " are the same values" << endl << endl;

  //print rv2's values
  cout << "rv2's Number of bedrooms : " << rv2.getBeds() <<endl;
  cout << "rv2's Number of bathrooms : " << rv2.getBaths() <<endl;
  cout << "rv2's Living area : " << rv2.getArea() <<endl;
  cout << "rv2's Number of wheels : " << rv2.getWheels() <<endl;
  cout << "rv2's Number of seats : " << rv2.getSeats() <<endl;
  cout << "rv2's Fuel Capacity : " << rv2.getFuel() <<endl << endl << endl;

  RV rv3 = std::move(rv2); // here's how to invoke the move constructor

  cout << "We just moved rv2 into a new RV called rv3" << endl;
  cout << "let's check rv3 to make sure its member variables" << endl;
  cout << " are the same values" << endl << endl;

  //print rv3's values
  cout << "rv3's Number of bedrooms : " << rv3.getBeds() <<endl;
  cout << "rv3's Number of bathrooms : " << rv3.getBaths() <<endl;
  cout << "rv3's Living area : " << rv3.getArea() <<endl;
  cout << "rv3's Number of wheels : " << rv3.getWheels() <<endl;
  cout << "rv3's Number of seats : " << rv3.getSeats() <<endl;
  cout << "rv3's Fuel Capacity : " << rv3.getFuel() <<endl << endl << endl;

  //re-print rv2's values to see what happened to them
  cout << "Here's what happened to rv2:" << endl << endl;
  cout << "rv2's Number of bedrooms : " << rv2.getBeds() <<endl;
  cout << "rv2's Number of bathrooms : " << rv2.getBaths() <<endl;
  cout << "rv2's Living area : " << rv2.getArea() <<endl;
  cout << "rv2's Number of wheels : " << rv2.getWheels() <<endl;
  cout << "rv2's Number of seats : " << rv2.getSeats() <<endl;
  cout << "rv2's Fuel Capacity : " << rv2.getFuel() <<endl << endl << endl;

  return 0;
}
