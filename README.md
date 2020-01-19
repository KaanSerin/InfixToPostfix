# InfixToPostfix
A C program for converting an infix expression to a postfix expression
To complete this project, I utilized the Stack data structure. The stack has a 'top' variable for
indicating the 'top' of the stack and a character pointer which is resized to avoid unnecessary memory usage.

<b>The rest of the programming was implementing the algorithm which boils down to this:</b>
> <br>Step 1: Add '')" to the end of the infix expression<br>
Step 2: Push(o nto the stack<br>
Step 3: Repeat until each character in the infix notation is scanned<br>
IF a(is encountered, push it on the stack<br>
IF an operand (whetheradigit oracharacter) is encountered, add it postfix expression.<br>
IF a ")" is encountered, then<br>
a. Repeatedly pop from stack and add it to the postfix expression until a "(" is encountered.<br>
b. Discard the "(".That is, remove the(from stack and do not add it to the postfix expression<br>
IF an operator O is encountered, then<br>
a. Repeatedly pop from stack and add each operator ( popped from the stack) to the postfix expression which has the same precedence orahigher precedence than O<br>
b. Push the operator to the stack<br>
[END OF IF]<br>
Step 4: Repeatedly pop from the stack and add it to the postfix expression until the stack is empty<br>
Step 5: EXIT

For Ex
> Input: A+B/C*(D-A)^F^H
> Output: ABC/DA-FH^^*+
