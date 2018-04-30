#include "Folder.h"
#include "Node.h"



Folder::Folder()
{
//allocate memory for root
	root = new Node();
	root = NULL;
}

Folder::~Folder()
{
//free memory once Folder class has gone out of scope
 	delete root;
}

/* takes in four parameters and immediately creates a new node
      with those four variables.

  Therefore, it's necessary to have four variable to give whenever creating
      a new node.
*/
void Folder::addNode(string& name, int &age, int &ID, double &GPA) {
	Node *new_student = new Node (name,age,ID,GPA);//create a new node

	if (root == NULL)/* empty link list.  Note that the 'if' statement is used to
                      check for an empty linked list */

	{
		root = new_student;
		return;
	}

	else  /* but we're gonna do this other stuff if it's not actually empty */
	{
/* - create a temporary pointer that points to Node values and assign
    it to roots value
   - This temp_node will act as roots decoy, temp_node has the same value
     as root and if we so happen to change temp_node we won't directly
     change root.
  */
	Node *temp_node = root;//declares a Node data type to start at root node

  /* traverses all the way down the linked list, if temp_node->next doesn't
     equal NULL then temp_node moves over to its neighbor node this is done
     with temp_node = temp_node->next. */
	while (temp_node->next != NULL)//traverses to the end of the link list
		{
			temp_node = temp_node->next;
		}
  /* when the while loop has successfully traversed all the way down
     the linked list, temp_node->next (which at this instant equals NULL)
     is intialized to the new node that was created at the beginning of the
     addNode function, new_student. */
	temp_node->next = new_student;
	}
}

void Folder::traverseList() { /* function is used just to print out all the
                                 nodes (or students) in the linked list */
	Node *temp_node = root;  //creates the familiar temp_node pointer like before

  /* temporary pointer is again used to traverse through a linked list the same
     way it did in the addNode funciton with only a few differences:

     1.  the while condition is a little different than the one in the addNode
         function.
         -Instead of the conditon being temp_node->next != NULL it's just
         temp_node != NULL. The former condition will break the while loop out
         too quickly and the last node (or student) will not be printed out.
 */
	while (temp_node != NULL)
	{
    /* notice how only the name of a node is printed out in the cout statement.
      This is simply because we are not able to just simple print out an
      object like this.  The WRONG way would be:
      cout<<temp_node<<endl; */
		cout<<temp_node->name<<endl;
		temp_node = temp_node->next;
	}
}

/* Now all we need to do is set up main to instantiate the classes */
