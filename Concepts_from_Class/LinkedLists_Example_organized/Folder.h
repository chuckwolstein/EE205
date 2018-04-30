/* The .h files are sometimes called the INTERFACE */

#pragma once
#include <string>
using namespace std;

class Node;  /* it's required to pre-define class Node since we are declaring
               a pointer called root that points to Node values. By
               pre-defining the class Node we are essentially telling the
               compiler that there is a class called Node so let us declare
               variables that hold Nodes */
class Folder
{
private:
	Node *root;

public:
	Folder();
	~Folder();/* A destructior is declared here because we will need to free
               memory that the Folder class will allocate once it goes out
               of scope. */
	void addNode (string&,int&,int&,double&);
	void traverseList();
};
