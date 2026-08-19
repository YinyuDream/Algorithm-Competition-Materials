# Nene and the Card Game

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of test cases follows.

The first line contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of cards you and Nene receive in the beginning of the game.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$) — the integers on the cards in your hand. It is guaranteed that each integer from $1$ through $n$ appears in the sequence $a_1, a_2, \ldots, a_n$ at most $2$ times.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output one integer: the maximum number of points you can get.

## Example

### Input
```
5
4
1 1 2 3
8
7 4 1 2 8 8 5 5
8
7 1 4 5 3 4 2 6
3
1 2 3
1
1
```

### Output
```
1
2
1
0
0
```

## Note

In the first test case, the integers written on your cards are $1$, $1$, $2$ and $3$. The integers written on Nene's cards are $2$, $3$, $4$ and $4$. The game may proceed as follows:

1. You select one of the cards with an integer $1$ written on it and place it on the table.  
2. Nene selects one of the cards with an integer $4$ written on it and places it on the table.  
3. You select the card with an integer $1$ written on it, receive $1$ point, and place the selected card on the table.  
4. Nene selects the card with an integer $4$ written on it, receive $1$ point, and places the selected card on the table.  
5. You select the card with an integer $2$ written on it and place it on the table.  
6. Nene selects the card with an integer $2$ written on it, receive $1$ point, and places the selected card on the table.  
7. You select the card with an integer $3$ written on it and place it on the table.  
8. Nene selects the card with an integer $3$ written on it, receive $1$ point, and places the selected card on the table.  

At the end of the game, you scored $1$ point, and Nene scored $3$. It can be shown that you cannot score more than $1$ point if Nene plays optimally, so the answer is $1$.

In the second test case, if both players play optimally, you score $2$ points and Nene scores $6$ points.