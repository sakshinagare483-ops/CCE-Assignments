Project Overview:-
1) Project Title:
Develop a Mathematical Expression Converter Using Expression Tree

2) Programming Language:
C++

3) Data Structure:
Expression Tree (Binary Tree)

4) Overview:
The Mathematical Expression Converter is a menu-driven C++ application that builds an expression tree from a prefix expression. It converts the expression into infix and postfix forms and evaluates the mathematical expression.
Each node of the expression tree represents either an operator or an operand. Operators form internal nodes, while operands form leaf nodes.

Features:-
- Accept a prefix mathematical expression.
- Build an expression tree from the prefix expression.
- Convert the expression into infix notation.
- Convert the expression into postfix notation.
- Evaluate the mathematical expression.
- Menu-driven interface.

Technologies Used:-
- Programming Language: C++
- Data Structure: Expression Tree (Binary Tree)
- Concepts: Structures, pointers, dynamic memory allocation, recursion, tree traversal, stack operations, and arithmetic operators.

How to Run:-
1. Download or clone the repository.
2. Open the ".cpp" file in a C++ compiler.
3. Compile and execute the program.
4. Enter a valid prefix expression.
5. Select the required operation from the menu to convert or evaluate the expression.

Problem Statement:-
Develop a Mathematical Expression Converter using an expression tree in C++. The system should accept a prefix mathematical expression and build an expression tree representing the expression.

The system should perform the following operations:
1. Build an expression tree from a prefix expression.
2. Convert the expression into infix notation.
3. Convert the expression into postfix notation.
4. Evaluate the mathematical expression.
5. Exit the program.

The program should be menu-driven, properly tested, and executed without errors. It should handle valid mathematical expressions and avoid division by zero during evaluation.

Algorithm:-
1. Start the program.
2. Accept a valid prefix mathematical expression.
3. Define a node containing an operator or operand and pointers to its left and right children.
4. Build the expression tree by processing the prefix expression from right to left.
5. If the current symbol is an operand, create a leaf node.
6. If the current symbol is an operator, create an operator node and attach the appropriate left and right subtrees.
7. Display the menu of operations.
8. Accept the user's choice.
9. Perform the selected operation:
   - Build: Construct the expression tree from the prefix expression.
   - Infix: Traverse the tree in inorder and display the expression with appropriate parentheses.
   - Postfix: Traverse the tree in postorder and display the postfix expression.
   - Evaluate: Evaluate the expression tree recursively using its operands and operators.
   - Exit: Terminate the program.
10. Repeat the menu until the user chooses Exit.
11. Stop.

Time Complexity:-
Operation| Time Complexity
Build Expression Tree| (O(n))
Convert to Infix| (O(n))
Convert to Postfix| (O(n))
Evaluate Expression| (O(n))
Here, (n) represents the number of symbols or nodes in the expression tree. These complexities assume constant-time processing of each node.


Advantages:-
- Demonstrates the practical use of expression trees.
- Supports conversion between prefix, infix, and postfix notations.
- Makes mathematical expression evaluation easier through tree traversal.
- Provides practical experience with pointers, recursion, and dynamic memory allocation.
- Helps understand binary trees and expression processing.
- Suitable for a menu-driven DSA assignment.


 Output:-
Enter Prefix Expression: + 5 * 3 2
1. Convert to Infix
2. Convert to Postfix
3. Evaluate Expression
4. Exit

Enter your choice: 1
Infix Expression: (5 + (3 * 2))

Enter your choice: 2
Postfix Expression: 5 3 2 * +

Enter your choice: 3
Result: 11

Enter your choice: 4
Program exited successfully!


Conclusion:-
This project demonstrates the implementation of an expression tree in C++ for converting and evaluating mathematical expressions. It provides practical experience with binary trees, pointers, recursion, tree traversal, and arithmetic operations. The project also explains the relationship between prefix, infix, and postfix expression notations.