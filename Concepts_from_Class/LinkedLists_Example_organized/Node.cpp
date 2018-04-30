#include "Node.h"

Node::Node()//used for when root is allocated memory in the Folder class constructor
{

}

Node::Node(string& n,int& a,int& i,double& g)
{
	name = n;
	age = a;
	ID = i;
	GPA = g;
  /*
  Below, the pointer next is initialzed to NULL.
  -Referring back to the picture of a linked list, the last node always
  points to NULL, this is how the program will be able to tell when it's at
  the last node.
  -As the program runs and the user creates more and more nodes, a nodes next
  will be reinitialzed to point to another node.
  -However, the last node will not be reinitialzed, thus remain pointing
  at NULL. */
  next = NULL;
}
