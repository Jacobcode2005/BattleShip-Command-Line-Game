Battleship Console Game

Overview

This project is a console-based Battleship game written in C++ for a programming course assignment.

The player attempts to sink all ships on a hidden 25×25 board by entering row and column coordinates. The program tracks hits and misses, displays the player's progress, and ends when all ships have been sunk or the player chooses to quit.

Technologies Used

C++

File I/O

2D Arrays

Features

Loads ship locations from an external board.txt file

Uses two 25×25 arrays to maintain the hidden ship locations and the player's visible board

Allows players to enter coordinates to attack ships

Displays hits (H), misses (M), and unexplored water (~)

Detects and notifies players when they select previously targeted coordinates

Validates that coordinates are within the board boundaries

Automatically detects when all ships have been sunk

Allows the player to exit by entering -1 for the row number

How to Run

Download the C++ source file and board.txt.

Place both files in the same working directory.

Compile the C++ source file using a C++ compiler.

Run the compiled program.

Enter row and column coordinates between 0 and 24 to attack.

Continue until all ships are sunk, or enter -1 when prompted for a row to quit.

The board.txt file must contain a 25×25 grid using # for ship locations and ~ for water.

What I Learned

Using multidimensional arrays to represent and manage game boards

Reading data from external files using fstream

Breaking a program into smaller functions with specific responsibilities

Using nested loops to process two-dimensional data

Implementing conditional logic to track hits, misses, and previously selected positions

Validating user input and managing game state

Checking win conditions by searching an array

This project was completed as part of a C++ programming course. It demonstrates foundational programming concepts, including arrays, functions, loops, conditional statements, and file handling.