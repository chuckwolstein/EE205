/* The .h files are sometimes called the INTERFACE */

#pragma once  //keeps the compiler from including the header file more than
              //it should be used with every .h file

#include <string>  //has to be included if we want to use string data types
#include <iostream>
using namespace std;


class Node  //Individual Student Records are stored as nodes
{
friend class Folder;  // friend benifits by being allowed access to class
                      // Nodes private members

private:
	string name;
	int age,ID;
	double GPA;
	Node *next;

public:
	Node();
	Node(string&,int&,int&,double&);
};
