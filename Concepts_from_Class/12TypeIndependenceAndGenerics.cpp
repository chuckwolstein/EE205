/*
Type - Dependant/Independent Code
*/

/*
Type-Dependent Code

Type dependence means changing a type declaration requires changing the code
using that type.


Example:

Suppose arrays provide these behaviors: printArray, addArrayElement,
                                        getNthArrayElement,
                                        and setNthArrayElement.

Suppose lists provide these behaviors:  printList, addListElement,
                                        getNthListElement,
                                        and setNthListElement.
If we have code that looks like:
-apply printArray to X (where X is an array).
-we have to change the code if we change X's type:
    -apply printList to X (where X is a list).

We want to avoid type-dependent code.
*/

/*
Type-Independent Code

Type independence means we change type declarations without changing the code
using those types.


Example:
Suppose arrays provide these behaviors:     print, addElement, getNthElement,
                                            and setNthElement.

Suppose lists provide these behaviors:  print, addElement, getNthElement,
                                        and setNthElement.

If we have code that looks like:
-apply print to X (where X is an array).
-we do not have to change it if we change X's type:
-apply print to X (where X is a list).

We want our code to be as type-independent as possible.
*/


/* Generics */

/*
Generic classes or functions can be used to solve the problems with Type
Dependent code. Take the following template as an example.
*/

template <typename T> T sum(T a, T b) {
    return a + b;
}
