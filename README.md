# Towers of Hanoi Implementation in C++

## Overview
This C++ program simulates the **Towers of Hanoi**, a classic problem in recursion and algorithm design. The program allows the user to interact with the game through a menu-driven interface. It enables users to set up the initial game state, transfer disks between towers following the game rules, and visualize the current state of the towers.

## About Towers of Hanoi
The **Towers of Hanoi** is a mathematical puzzle that consists of three rods (towers) and a number of disks of varying sizes that can slide onto any rod. The puzzle begins with the disks stacked in ascending order of size on one rod (smallest on top). The goal is to move the entire stack to another rod, following these rules:

1. Only one disk can be moved at a time.
2. Each move consists of taking the top disk from one rod and placing it on top of another rod.
3. No disk may be placed on top of a smaller disk.

The minimum number of moves required to solve the puzzle is \( 2^n - 1 \), where \( n \) is the number of disks.

## Features
- Set the initial number of disks on the first tower.
- Move disks between towers while ensuring the rules of the game are followed.
- Display the current state of the towers at any time.

## How to Use the Program
### 1. Compile the Program
Use a C++ compiler like `g++` to compile the program:
```bash
 g++ -o towers_of_hanoi towers_of_hanoi.cpp
```

### 2. Run the Program
Execute the compiled file:
```bash
 ./towers_of_hanoi
```

### 3. Interact with the Menu
Upon running, you will be presented with the following menu:
```
1) Set initial state of the game.
2) Move the top disk from tower X to tower Y.
3) Display towers.
Choice:
```

#### Menu Options
1. **Set Initial State:**
   - Define the number of disks to initialize on the first tower.
   - The program will automatically arrange the disks in descending size order (largest at the bottom, smallest at the top).

2. **Move Disks:**
   - Specify the source tower (1, 2, or 3) and the destination tower (1, 2, or 3).
   - The program ensures no larger disk is placed on a smaller disk and provides error messages for invalid moves.

3. **Display Towers:**
   - Visualize the current state of all three towers, showing the disks stacked on each rod.

### 4. Example Usage
#### Initializing the Game:
- Select **1** and enter the number of disks to stack on the first tower.

#### Moving Disks:
- Select **2** and specify the source and destination towers.
  - Example:
    ```
    From: 1
    To: 2
    ```
  - The program checks for rule violations (e.g., placing a larger disk on a smaller disk).

#### Displaying Towers:
- Select **3** to view the current arrangement of disks on all three towers.

### 5. Exit the Program
To exit, simply close the console or terminate the program manually.

## Code Highlights
### Core Functions
1. **Setting Initial State:**
   ```cpp
   int setInitialState(int& top1, int& top2, int& top3, int*& tower1, int*& tower2, int*& tower3);
   ```
   Initializes the first tower with the specified number of disks and prepares the other two towers.

2. **Transferring Disks:**
   ```cpp
   void transferDisk(int max, int& top1, int& top2, int& top3, int*& tower1, int*& tower2, int*& tower3);
   ```
   Moves a disk from one tower to another, ensuring the game rules are respected.

3. **Displaying Towers:**
   ```cpp
   void displayTowers(int top1, int top2, int top3, int* tower1, int* tower2, int* tower3);
   ```
   Prints the current state of all three towers.

### Supporting Functions
- **Push:**
  Adds a disk to a tower.
  ```cpp
  void push(int* tower, int value, int& top, int max);
  ```

- **Pop:**
  Removes and returns the top disk from a tower.
  ```cpp
  int pop(int* stack, int& top);
  ```

### Example Game Flow
1. Initialize the game with 3 disks.
2. Move disks between towers:
   - Move disk from Tower 1 to Tower 3.
   - Move disk from Tower 1 to Tower 2.
   - Move disk from Tower 3 to Tower 2.
3. Display the towers to verify the current state.
4. Continue until all disks are moved to the target tower.

## Theory and Applications
The Towers of Hanoi demonstrates key algorithmic concepts:
- **Recursion:** The optimal solution uses recursive calls to move \( n-1 \) disks before handling the largest disk.
- **Algorithm Design:** The problem is a classic example of divide-and-conquer.

### Applications
- Problem-solving exercises in computer science.
- Demonstration of recursion in programming.
- Modeling real-world problems such as multi-threaded task scheduling and resource allocation.

## Limitations
- Fixed tower sizes based on the initial number of disks.
- Manual termination required to end the program.
- Minimal input validation for non-numeric values.

