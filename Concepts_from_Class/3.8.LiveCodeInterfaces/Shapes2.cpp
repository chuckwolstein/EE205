#include <iostream>
using namespace std;

/*
class IAreaCalculation {
    //puttint the I in front is convention for flagging it as an interface
public:
    virtual void CalcArea()=0;
}
*/

class Shape {
    public:
        float area;
        //all the shapes that dont have area overridden will now just take 1
        //for their area since CalcArea is no longer purely virtual
        virtual void CalcArea() { area = -1;};
    private:
};

class Rectangle : public Shape {
    public:
        Rectangle(int w, int h) {
            width = w; height = h;
        }
        void CalcArea(){
            area = width*height;
        }
    private:
        int width, height;
};

void PrintArea(Shape * shapeObj) {
shapeObj->CalcArea();
cout<<shapeObj->area<<endl;
}

int main() {
    Rectangle rect1(5,10);
    Rectangle *r;
    //rect1.CalcArea();
    r = &rect1;
// Everything above this code could be a UI
    PrintArea(r);
}
