/* Assert */

void assert (int expression); //Evaluate assertion

/*
If the argument expression of this macro with functional form compares equal to
zero (i.e., the expression is false), a message is written to the standard error
device and abort is called, terminating the program execution.
*/

/*
The specifics of the message shown depend on the particular library
implementation, but it shall at least include: the expression whose assertion
failed, the name of the source file, and the line number where it happened. A
usual expression format is:

Assertion failed: expression, file filename, line line number

*/

/*
This macro is disabled if, at the moment of including <assert.h>, a macro with
the name NDEBUG has already been defined. This allows for a coder to include as
many assert calls as needed in a source code while debugging the program and
then disable all of them for the production version by simply including a line
like the following at the beginning of the code, before the inclusion of
<assert.h>
*/

#define NDEBUG

/*
Therefore, this macro is designed to capture programming errors, not user or
run-time errors, since it is generally disabled after a program exits its
debugging phase.
*/

/*
PARAMETERS
Assert takes an expression to be evaluated. If this expression evaluates to 0,
this causes an assertion failure that terminates the program.
*/

/* assert example */
#include <stdio.h>      /* printf */
#include <assert.h>     /* assert */

void print_number(int* myInt) {
  assert (myInt!=NULL);
  printf ("%d\n",*myInt);
}

int main ()
{
  int a=10;
  int * b = NULL;
  int * c = NULL;

  b=&a;

  print_number (b);
  print_number (c);

  return 0;
}
