/*
 Iterators

 Iterators are a generalization of pointers that allow a C++ program to work
 with different data structures (containers) in a uniform manner.

 Each STL container provides an iterator type and (at least) two methods that
 return iterators:
*/

begin() // returns an iterator positioned at the first element in the container.
end() // returns an iterator positioned past the last element in the container.

/*
 A short example:
*/

vector<int> v;    //empty vector
v.push_back(5);   //append 5
v.push_back(4);   //append 4
v.push_back(8);   //append 8

/*
then,

v.begin() points to 5 and v.end() points to the space after 8.

Iterators are defined inside a container class so it must be preceded by the
name of the class and the cope operator(::) when it's used outside the
container class declaration. For example:
*/

vector<int>::iterator vecIter = v.begin();

/*
Using the above short example and the above iterator declaration vecIter will
be an iterator pointing at the number 5.
*/

/*
You can apply the following iterator operations:
 _______________________________________________________________________________
 Increment(++)

 Moves the iterator from its current position to
 the next element of the container, may be applied
 either as a prefix or postfix operator.
 _______________________________________________________________________________
 Decrement(--)

 Moves the iterator from its current position to
 the preceding element of the container; may be
 applied either as a prefix or a postfix operator.
 _______________________________________________________________________________
 Dereferencing(*)

 Accesses the value stored at the position to which
 the iterator points; applied as a prefix operator.
================================================================================
For random-access iterators such as those in vector:
================================================================================
 Assignment(=)

 For iterators of the same type,
 it1 = it2 sets it1's position to it2's position.
 _______________________________________________________________________________
 Equality comparisons (== and !=)

 For iterations of the same type, == returns true
 if both are positioned at the same element
 _______________________________________________________________________________
 Addition(+), Subtraction(-)

 For iterator it and integer n, it+/- n returns an
 iterator positioned n elements from it's current
 position.
 _______________________________________________________________________________
 Subscript operator[]

 For iterator it and integer n, it[n] returns
 a reference to the nth element from it's current
 position.
*/

/*
An vector and iterator example:
*/

vector<double> v;
for (int i = 2; i <= 5; i++)
    v.push_back(2.2 * i);

vector<double>::iterator it, it1, it2;

for (it = v.begin(); it !=  v.end(); it++)
    cout << *it << '  ';
cout <<  "<--- Original Vector \n";

it1 = v. begin(), it2 = v.end();
*it1 = 1.1;
*(it2 - 1) = 9.9;
for (it - v.begin(); it != v.end(); it++)
    cout << *it << '  ';
cout <<  " <---- modify first & last via iterators \n";

it1 += 3;
it2 -= 3;
cout << *it1 << '   ' << *it2 << " <--- jump \n";
it1--;
++it2;
cout << *it1 << '  ' << *it2 << " <----inc & dec\n";
cout << it1[1] << ' ' << it1[-1] << " <---- subscript \n";

/*
OUTPUT:
4.4 6.6 8.8 11 <---- Original Vector
1.1 6.6 8.8 9.9 <---- modify first & last via iterators
9.9 6.6 <--- jump
8.8 8.8 <---inc & dec
9.9 6.6 <---- subscript
*/
