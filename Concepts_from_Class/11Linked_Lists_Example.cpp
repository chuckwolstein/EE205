#include <cstdlib> //this contains the protype for 'system'
#include <string>
#include <iostream>
using namespace std;

class Node  {//Individual Student Records are stored as nodes
    friend class Folder;  // friend benifits by being allowed access to class
                      // Nodes private members

    private:
	    string name;
	    int age,ID;
	    double GPA;
	    Node *next;

    public:
	    Node() {} //used for when root is allocated memory in the Folder class
                  //constructor
	    Node(string& n,int& a,int& i,double& g) {
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
};

class Folder {
    private:
	       Node *root;

       public:
	          Folder() {
                  //allocate memory for root
                  	root = new Node();
                  	root = NULL;
              }
	            ~Folder(){ /*    A destructior is declared here because we will
                                need to free memory that the Folder class will
                                allocate once it goes out of scope. */

                                //free memory once Folder class has gone out of
                                //scope
                                 	delete root;
                }

/* takes in four parameters and immediately creates a new node
with those four variables.

Therefore, it's necessary to have four variable to give whenever creating
a new node.
*/
	void addNode (string& name, int &age, int &ID, double &GPA){
        Node *new_student = new Node (name,age,ID,GPA);//create a new node

        if (root == NULL)/* empty link list.  Note that the 'if' statement is
                            used to check for an empty linked list */

        {
            root = new_student;
            return;
        }

        else  /* but we're gonna do this other stuff if it's not actually empty
         */
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

	void traverseList() { /* function is used just to print out all the
                                     nodes (or students) in the linked list */
    	Node *temp_node = root;  //creates the familiar temp_node pointer like
                                //before

      /* temporary pointer is again used to traverse through a linked list the
        same way it did in the addNode funciton with only a few differences:

         1.  the while condition is a little different than the one in the
             addNode
             function.
             -Instead of the conditon being temp_node->next != NULL it's just
             temp_node != NULL. The former condition will break the while loop
            out too quickly and the last node (or student) will not be printed
            out.
     */
    	while (temp_node != NULL)
    	{
        /* notice how only the name of a node is printed out in the cout
        statement.
          This is simply because we are not able to just simple print out an
          object like this.  The WRONG way would be:
          cout<<temp_node<<endl; */
    		cout<<temp_node->name<<endl;
    		temp_node = temp_node->next;
    	}

    }
};

/*
At last a linked list has been constructed, in your compiler simple create
a Node.h, Folder.h, Node.cpp, Folder.cpp, and main.cpp. Theres always ways
 to improve the code, and this linked list is no exception, happy coding!
*/

int main() {
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
