#include <utility>

// In the diagram, insert(0, 1)
void List::insert(int index, int num) {
  if (index == 0) {
    // Allocate a new ListNode
    ListNode * temp = new ListNode(num);
    // Save the address of the old head
    Listnode * old_head = this->head;
    // Set head to be the address of
    // the new Listnode
    this->head = temp;
    // Set our new ListNode.next to be
    // the address of our saved head
    temp->next = old_head;
    ++this->length;
  }
}




// Default constructor
List::List() :
  head(nullptr),
  length(0) {}

// Copy constructor
List::List(const List& other) {
  // If the list is not empty,
  // start the copying loop.
  if (other.head != nullptr) {
    ListNode* curr_other = other.head;
    // Create the new element
    ListNode* new_head = new ListNode();
    ListNode* curr_node = new_head;

    //For each item in the list...
    while (curr_other != nullptr) {
      // Copy the value into the new element
      curr_node->set_data(curr_other->get_data());
      // Make sure I have a next to go into.
      curr_node->next = new ListNode(-1);
      // Setup the curr_other pointer for the
      // next step/loop iteration
      curr_other = curr_other->next;
      curr_node = curr_node->next;
    }
  }
}






int List::get(int index) const {
  // It's valid if index >= 0 AND index <= length-1
  if (index >= 0 && index <= length-1) {
    // Starting from the front,
    // get the Nth index element
    // by doing this loop (index) times
    ListNode* curr_node = this->head;
    for (int i=0;
    i < index;
    ++i) {
        //Look at the next item
        curr_node = curr_node->next;
        // Iterate/continue
    }
    // Now, curr_node is pointing to
    // the correct node, but we need
    // to get the data and return it.
    return curr_node->get_data();
  }
  // Access mempory outside the bounds of the List
  else {
    throw "hello world"
  }
}
