/*
At last a linked list has been constructed, in your compiler simple create
a Node.h, Folder.h, Node.cpp, Folder.cpp, and main.cpp. Theres always ways
 to improve the code, and this linked list is no exception, happy coding!
*/

#include <iostream>

//must include header files
#include "Folder.h"
#include "Node.h"

using namespace std;

int main()
{
//declare variables
	Folder rec;
	string name;
	int age,ID;
	double GPA;

	while (true)
	{
//input name, age, ID, and GPA and then send these variables to the addNode function
		cout<<"Enter name (or quit to exit)"<<endl;
		cin>>name;
		if (name == "quit") break;
		cout<<"Enter age"<<endl;
		cin>>age;
		cout<<"Enter ID number"<<endl;
		cin>>ID;
		cout<<"Enter GPA"<<endl;
		cin>>GPA;
		rec.addNode(name,age,ID,GPA);  //remember that addNode is a member function
                                   //of class Folder..... traverseList() is too.
}
	rec.traverseList();//Print out the linked list members

system ("pause");
return 0;
}
