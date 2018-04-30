#include <iostream>
#include <string>
using namespace std;

/*
Desired Features:
-add items
-delete items
-check items off the list
-change items
-exit the program
-display the list
*/



class Item {
private:
  string description;
  bool isComplete;
public:
  Item() { }
  void ChangeDescription(string s) {
    this->description = s;
  }
};

class List { //today's list is going to be managing its own members itself
private:
  int selection;
  vector<Item> //incomplete
  void HandleSelection(){
    cout << selection << endl;
    switch(selection){
      case 1:
        AddItem();
        break;
      case 2:
        break;
      default:
        break;
    }
  }
public:
  void WelcomeMessage(void) {
    cout << "Welcome to all the work you have to do"<<endl;
  }
  int Selection(void) {
    cout << "Please select an option." << endl;
    cin >> this->selection;
    this->HandleSelection();
    return selection;
  }
  void AddItem(){
    Item newItem = new Item();
    string s;
    cout<<"Please Enter Your Description"<<endl;
    cin>>s;
    newItem.ChangeDescription(s);
    itemVect.push_back(newItem);
    for(it = itemVect.begin(); it!=itemVect.end();it++) {
      //it is the iterator
      cout<<*it->description<<endl;
    }
  }
};


int main() {
int s;
List list1; //maybe we want a list for each of the classes we are taking
list1.WelcomeMessage();
list1.Selection();

while(s!=0) {
  s = list1.Selection();
}

cout <<"Goodbye" << endl;
}
