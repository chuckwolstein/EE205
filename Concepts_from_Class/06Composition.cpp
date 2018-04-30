//remember to compile this with c++11 by using:
//g++ MT2Prep_1.cpp -std=c++11

#include <string>
#include <iostream>
using namespace std;

class Parachute {
private:  //just defining 2 member variables here, to keep things simple
  int surface_area;
  int safety_rating;
public:
  Parachute() { //default constructor
  surface_area = 0;
  safety_rating = 0;
  }

  ~Parachute() {} //destructor

  int getArea() { //returns the area of the parachute
    return surface_area;
  }

  int getSafe() { //returns the safety safety_rating
    return safety_rating;
  }

  void setArea(int a) { //setter for area
    surface_area = a;
  }

  void setSafe(int s){  //setter for safety_rating
    safety_rating = s;
  }
};



class Helmet {
private:
  float hardness; //reflects how hard the helmet is
  int comfort_rating; //reflects the comfort level of the helmet
public:
  Helmet(); //constructor
  ~Helmet(); //destructor
  float getHardness(); //getter for getHardness
  int getComfort(); //getter for comfort_rating
  void setHardness(float);
  void setComfort(int);
};

Helmet::Helmet() { //constructor

}

Helmet::~Helmet() { } //destructor

float Helmet::getHardness() { //getter for Hardness
  return hardness;
}

int Helmet::getComfort() { //getter for comfort_rating
  return comfort_rating;
}

void Helmet::setHardness(float h) {
  hardness = h;
}

void Helmet::setComfort(int c) {
  comfort_rating = c;
}

// Object composition is the process of creating more complex
// objects from simple ones.  Below is an example.
class Skydiver {
private: //whatever we want to be directly editable in this class

  string name;
public: // Skydiver HAS several objects we made earlier
  Parachute para;
  Helmet helm;
};
