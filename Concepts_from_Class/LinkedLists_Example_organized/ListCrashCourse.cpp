#include <iostream>
using namespace std;

/*
A linked list is a sequence of items that can only be accessed in order
(that is, from first to last). Each data item is stored in a node which
also contains a pointer to the next node. Thus, a linked list can be
pictured as shown below. Note that each node is pictured as a box, while
each pointer is drawn as an arrow. A NULL pointer is used to mark the end
of the list.
*/

/*
A linked list gives only sequential access to the data, so that only sequential
search is available.  Note that Arrays are more accessible than lists, because
they provide RANDOM ACCESS to member
*/

/* The problem is that is no room in arrays to insert new items */

/* But a linked list solves this problem by just changing a few pointers */

/* Deletion of an item from an ordered list is also a simple matter of
changing a pointer */

/* A linked list is one example of a dynamic data structure. This means that
it can easily grow, contract, and change as needed. An array is a static data
structure. */

/* A linked list is one example of a DYNAMIC DATA STRUCTURE.
 This means that it can easily grow, contract, and change as needed.
  An array is a STATIC DATA STRUCTURE. */

/* In a more technical explanation of a linked lists each node is an object
 of the Node class */

/* here is an example below */


class Folder {  //now let's make a list called "Folder" that will
                //contain them all
private:
	Node *root; //this is pointing to the very first node in the list
              // it is a single variable that will hold all of the
              //nodes together

public:
	Folder();
	void addNode (string&,int&,int&,double&);  /* takes in the associated data
                                                that a node will hold; name,
                                                age, ID, and GPA to then be
                                                given to the Node constructor */

  void traverseList();  /* used to iterate through a link list. */
};
