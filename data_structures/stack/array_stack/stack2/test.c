#include <stdio.h>
#include <string.h>  /* for strlen() */
#include "stack.h"

int main(void)
{
  t_stack *stack;    /* A stack to hold characters. */
  char str[101];   /* String entered by user. */
  char *traverse;  /* Pointer used to traverse the string. */

  /*
   * Get a string from the user--don't enter more
   * than 100 characters!
   */
  printf("Enter a string: ");

  gets(str);  /* Read line, discard newline. */

  /*
   * Initialize the stack.  Make it at least
   * big enough to hold the string we read in.
   */
  stack = init_stack(strlen(str));

  /*
   * Traverse the string and put each
   * character on the stack.
   */

  for (traverse = str; *traverse != '\0'; traverse++) {
    push(stack, *traverse);
  }

  push(stack, '1');
  push(stack, '2');
  push(stack, '3');
  /*
   * Pop each of the characters off of
   * the stack and print them out.
   */

  printf("\nPopped characters are: ");

  while (!is_empty(stack)) {
    printf("%c", pop(stack));
  }

  printf("\n");

  destroy_stack(stack);
  printf("destroyed the stack! \n");

  stack = init_stack(-1);
  peek(stack);
  return 0;
}
