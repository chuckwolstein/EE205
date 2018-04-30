#include <iostream>
using namespace std;

class IAreaCalculation {
    //putting the I in front is convention for flagging it as an interface
public:
    virtual void CalcArea()=0;

}

class Shape {
    public:
        float area;
    private:
};

class Rectangle : public Shape, IAreaCalculation {
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
cout<<shapeObj->area<<endl;
}

int main() {
    Rectangle rect1(5,10);
    Rectangle *r;
    rect1.CalcArea();
    r = &rect1;
// Everything above this code could be a UI
    PrintArea(r);
}
