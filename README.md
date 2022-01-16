# Introduction-to-Computers1
Language: C++

## Homework 1
Output a card about youself

## Homework 2
Ask user to enter 0~5
Requirements:
1. Fool proof design
2. Enter 0: print a card
3. Enter 1~5: print stars

## Homework 3
Compute the Fibonacci numbers
Requirements:
1. Fool proof design
2. Input : N
3. Output: Fibonacci numbers from F0 to Fn

## Homework 4
Number Guessing
Requirements:
1. Fool proof design
2. Basic Rules: 
    1. System generates an initial 4-digit number from 1 to 9 as Code
    2. 4 digits cannot be the same
    3. If the digit of the guessed number is at the **same position** and with the **same value** with the code, mark 1A.
    4. If the digit of the guessed number is at the **wrong position** and with the **same value** with the code, mark 1B.
    5. When the result is 4A0B, the program outputs "You Win." and asks the user whether it wants to continue or not.

For example: 
System generate code: 4681
Input: 7639     Output: 1A
Input: 1284     Output: 1A2B

## Homework 5
Tower of Honoi
Requirements:
1. User input numbers of disks at the beginning.
2. Show the initial setting on the screen.
3. Function 1: Show all the move on the screen
   Function 2: Let user moves the disks, when all the disks are on Tower 3, print "You win."

## Homework 6
Coloretto
Rules: <http://goo.gl/YusIhT>
Play online: <http://www.marquand.net/coloretto/>

Requirements:
1. Write a program lets the users play Coloretto
2. Use only basic rules
3. Write an AI to play Coloretto as a phantom user
4. Number of players: 4

## Midterm


## Homework 7
Maximum sum sub-matrix in a matrix
Requirements:
1. Let user input the size of a matrix (m x n)
2. Let user input numbers in the matrix or randomly generate numbers
3. Output the original matrix.
4. Compute and output the maximum sum of numbers in a sub-matrix and the submatrix

## Homework 8
On a 7 x 7 matrix, there are 7 dwarfs are going to search for Snow White
Rules: 
1. Dwarf cannot see each other on any direction, row, column, or diagonal.
Requirements:
1. Let user input the initial position of the first dwarf
    (the index starts at (0,0) )
2. Place the rest 6 dwarf on the map if possible
3. Bonus: Show all 6 funtamental solutions without symmetry operations, i.e. rotations or reflections.(total 40 solutions)

## Homework 9
Basket Analysis
Requirements:
1. First, let users input the file name of the input DataBase.
2. Second, let users input min_supp and min_conf.
3. Read the DataBase and compute the strong association rules.
4. Output all strong association rules.

## Homework 10
Longest common sequences problem
Requirements:
1. The input sequences are given in a input file
2. Read two sequences at a time and find longest common sequences.
3. Output the longest common sequences together with the lengths of them.

## Homework 11
Connect four
Rules:
Play online: <https://connect4.gamesolver.org/en/>
1. 6 rows, 7columns
2. 2 players
3. 21 red discs and 21 yellow discs
4. Every round, players drop on of their discs into an unfilled column
5. The player whe achieves "4 in a row" first is the winner
6. If the board fills before any player wins, the game is a draw
Requirements:
1.  Write a program letting 2 users play Connect Four
2. Use only basic rules
3. Update and show the game board after each move
4. When the game ends, determine and show which player is the winner or the game is a draw
5. Bonus: write an AI  to play with the user.
