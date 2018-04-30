/*
 Linked List

 What Is a Linked List?

 A linked list is a sequence of items that can only be accessed in order
 (that is, from first to last). Each data item is stored in a node which also
 contains a pointer to the next node. Thus, a linked list can be pictured as
 shown below. Note that each node is pictured as a box, while each pointer is
 drawn as an arrow. A NULL pointer is used to mark the end of the list.
*/

/*
 Working with linked lists can be fun because they are easy to draw, yet give a
 useful way to organize data. In certain places lists can be tricky, but a good
 drawing can go a long way toward clarifying such a situation.

 Notice that the above list gives the names of people in alphabetical order.
 You might wonder how this compares with storing an ordered list of names in an
 array. The key difference is that an array gives "random access" in that you
 can directly access any data item by its index number. This allows one to use
 binary search instead of the slower sequential search, for example. A linked
 list gives only sequential access to the data, so that only sequential search
 is available.
*/

/*
 However, there are other comparisons that could be made between the two.
 Although, the array method allows the faster search to be used, if we want to
 insert a new item after the one found, we are in trouble! There is probably no
 room in the array to insert a new item at this point. Instead, all items to the
 right of this location have to be slid over to the next array location. This is
 a slow process but does make room to insert the new item. As we will see more
 clearly when we code linked lists later, it is fairly easy to insert a new item
 into an ordered linked list. In fact, it is just a matter of changing a couple
 of pointers.
*/

/*
 Deletion of an item from an ordered list is also a simple matter of changing a
 pointer, whereas in an ordered array, all of the data to the right has to be
 shifted left to fill in the hole left upon deletion. Thus, once again, the
 linked list is faster and more flexible. In general, a linked list is probably
 the better method if you are going to dynamically insert and delete items a
 lot. (A linked list is one example of a dynamic data structure. This means that
 it can easily grow, contract, and change as needed. An array is a static data
 structure.)
*/

/*
 Another comparison could be made based on the amount of space that the two
 methods use. With the array scheme, you would need to set the size of the array
 in advance, overestimating the amount of space needed. However, the linked list
 method also wastes space, in that it needs room in each node for a pointer. In
 general it is not possible to say which method wastes more space.
*/

/*
 In a more technical explanation of a linked lists each node is an object of the
 Node class. Just to point out, node is something that this object is commonly
 named it is not a keyword. The Node class of the above analogy would look
 something like this.
*/

class Node {
    private:
	    string name;
	    int age;
	    string fav_color;
        Node *next;
};

/*
 This class is straight forward, the name of the class is Node, each object or
 instance of the Node class holds a name, age, favorite color, and next pointer
 just like in the envelope analogy. Notice how the next pointer points to a
 Node type, remember a class is just a user defined data type, once a class is
 made it can be used just as a normal data type such as int or double. For
 example, int *p; is a pointer named 'p' that points to an address that holds
 data of integer type. Node *next; is no different, 'next' is a pointer that
 points to an address that holds data of Node type.
*/
