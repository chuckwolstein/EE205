/* Vector, List, Queue, Stack */

/*
We have already looked at Vector and Iterators. You can go back to review those
if you are still unfamiliar with them. This lecture will discuss 3 more similar
containers List, Queue, and Stack
*/

/* List */

/*
List implements the following member functions. This is not the complete list,
you will need to look up other functions for different uses.
*/

assign //- Assign new content to container (public member function )
emplace_front //  -Construct and insert element at beginning (public member function )
push_front //-Insert element at beginning (public member function )
pop_front //- Delete first element (public member function )
emplace_back  //- Construct and insert element at the end (public member function )
push_back //- Add element at the end (public member function )
pop_back //- Delete last element (public member function )
emplace  //- Construct and insert element (public member function )
insert //- Insert elements (public member function )
erase //- Erase elements (public member function )
swap //- Swap content (public member function )
resize //- Change size (public member function )
clear //- Clear content (public member function )

/*
Example:
*/

// constructing lists
#include <iostream>
#include <list>

int main ()
{
  // constructors used in the same order as described above:
  std::list<int> first;                                // empty list of ints
  std::list<int> second (4,100);                       // four ints with value 100
  std::list<int> third (second.begin(),second.end());  // iterating through second
  std::list<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are: ";
  for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
    std::cout << *it << ' ';

  std::cout << '\n';

  return 0;
}

/*
The Output of this program is

The contents of fifth are: 16 2 77 29
*/

/* Queue (First-In First-Out)*/

/*
queues are a type of container adaptor, specifically designed to operate in a
FIFO context (first-in first-out), where elements are inserted into one end of
the container and extracted from the other.

queues are implemented as containers adaptors, which are classes that use an
encapsulated object of a specific container class as its underlying container,
providing a specific set of member functions to access its elements. Elements
are pushed into the "back" of the specific container and popped from its
"front".

The underlying container may be one of the standard container class template or
some other specifically designed container class. This underlying container
shall support at least the following operations:
*/

empty() //– Returns whether the queue is empty
size() //– Returns the size of the queue
front() //– Returns a reference to the first element of the queue
back() //– Returns a reference to the last element of the queue
push(g) //– Adds the element ‘g’ at the end of the queue
pop() //– Deletes the first element of the queue

/*
Example:
*/

#include <iostream>
#include <queue>

using namespace std;

void showq(queue <int> gq)
{
    queue <int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

int main()
{
    queue <int> gquiz;
    gquiz.push(10);
    gquiz.push(20);

    cout << "The queue gquiz is : ";
    showq(gquiz);

    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back() : " << gquiz.back();

    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showq(gquiz);

    return 0;
}

/*
The Output of the Program is:

The queue gquiz is : 	10	20

gquiz.size() : 2
gquiz.front() : 10
gquiz.back() : 20
gquiz.pop() : 	20
*/

/* Stack(Last-In First-Out) */

/*
Stacks are a type of container adaptor, specifically designed to operate in a
LIFO context (last-in first-out), where elements are inserted and extracted only
from one end of the container.

stacks are implemented as containers adaptors, which are classes that use an
encapsulated object of a specific container class as its underlying container,
providing a specific set of member functions to access its elements. Elements
are pushed/popped from the "back" of the specific container, which is known as
the top of the stack.

The underlying container may be any of the standard container class templates
or some other specifically designed container class. The container shall support
the following operations:
*/

empty() //– Returns whether the stack is empty
size() //– Returns the size of the stack
top() //– Returns a reference to the top most element of the stack
push(g) //– Adds the element ‘g’ at the top of the stack
pop() //– Deletes the top most element of the stack

/*
Example:
*/

#include <iostream>
#include <stack>

using namespace std;

void showstack(stack <int> gq)
{
    stack <int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

int main ()
{
    stack <int> gquiz;
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);

    cout << "The stack gquiz is : ";
    showstack(gquiz);

    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.top() : " << gquiz.top();


    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showstack(gquiz);

    return 0;
}

/*
The Output of the following program is

The stack gquiz is : 	1	5	20	30	10

gquiz.size() : 5
gquiz.top() : 1
gquiz.pop() : 	5	20	30	10
*/
