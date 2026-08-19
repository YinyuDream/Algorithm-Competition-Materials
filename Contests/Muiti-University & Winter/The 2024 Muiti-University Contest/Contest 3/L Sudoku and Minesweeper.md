# Sudoku and Minesweeper

## 题目描述

Sudoku is a logic-based, combinatorial number-placement puzzle. In classic Sudoku, the objective is to fill a 9 × 9 grid with digits so that each column, each row, and each of the nine 3 × 3 subgrids that compose the grid contains all of the digits from 1 to 9. The puzzle setter provides a partially completed grid, which for a well-posed puzzle has a single solution.

Minesweeper is a logic puzzle video game. The game features a grid of clickable tiles, with hidden mines scattered throughout the board. The objective is to clear the board without detonating any mines, with help from clues about the number of neighboring mines in each field.

You are given a solved classic Sudoku. You are asked to replace some numbers with mines so that the remaining numbers equal the number of neighboring mines. You can't replace all the numbers with mines.

## 输入描述

The input contains 9 lines. Each line contains 9 characters. Each character is a number between 1 and 9.
The input describes the solved classic Sudoku.

## 输出描述

Output 9 lines, denoting the answer. Each line contains 9 characters. Each character is either a number between 1 and 9 or ‘*’(which represents a mine).

## 样例输入

```
123647859
648295317
795831642
436578921
981462573
257913486
319754268
572386194
864129735
```

## 样例输出

```
123******
*4*******
**5***642
**65***21
****6*5*3
*****34**
****54*6*
*****6**4
*********
```