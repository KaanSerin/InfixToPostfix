# InfixToPostfix
A C program for converting an infix expression to a postfix expression
To complete this project, I utilized the Stack data structure. The stack has a 'top' variable for
indicating the 'top' of the stack and a character pointer which is resized to avoid unnecessary memory usage.

The rest of the programming was implementing the algorithm which boils down to this:
Step 1: Add '')" to the end of the infix expression
Step 2: Push(o nto the stack
Step 3: Repeat until each character in the infix notation is scanned
IF a(is encountered, push it on the stack
IF an operand (whetheradigit oracharacter) is encountered, add it postfix expression.
IF a ")" is encountered, then
a. Repeatedly pop from stack and add it to the postfix expression until a "(" is encountered.
b. Discard the "(".That is, remove the(from stack and do not add it to the postfix expression
IF an operator O is encountered, then
a. Repeatedly pop from stack and add each operator ( popped from the stack) to the postfix expression which has the same precedence orahigher precedence than O
b. Push the operator to the stack
[END OF IF]
Step 4: Repeatedly pop from the stack and add it to the postfix expression until the stack is empty
Step 5: EXIT
