Box BoxReturn(void){
  Box b;
  return b;
}
int IntReturn(Box b) {
  return b.x;
}

class IDisplayable{
public:
virtual void DisplayMe() = 0;
};

class Sbox: public Box , public IDisplayable { //interfacing example
private:
  Pos position;
public:
  SBox(){
  cout<<"SBox constructor"<< endl;
  }
  void DisplayMe(){}
}

int main*() {

}
