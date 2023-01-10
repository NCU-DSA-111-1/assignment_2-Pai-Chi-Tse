# DataStructure
 my learning program
-------------------------------------
# Japanese chess shogi

This is assignment 2

## Compile & Run

```sh
# Compile in codeblocks
##There is "segmentation fault" with loading and storing .txt when compiling in linux.
##So I compile assignment 2 in codeblocks.

#Compile in linux
cd src/
gcc -o main main.c chess.h chess.c
# Run
./main
```

## Display

```sh
    1 2 3 4 5 6 7 8 9
-1
0  ------------------
1  香馬銀金將金銀馬香
2  十飛十十十十十角十
3  兵兵兵兵兵兵兵兵兵
4  十十十十十十十十十
5  十十十十十十十十十
6  十十十十十十十十十
7  兵兵兵兵兵兵兵兵兵
8  十角十十十十十飛十
9  香馬銀金將金銀馬香
10 ------------------
11
The chess you want to move(input coordinate):
7
5

Select the coordinates to place:
6
5
    1 2 3 4 5 6 7 8 9
-1
0  ------------------
1  香馬銀金將金銀馬香
2  十飛十十十十十角十
3  兵兵兵兵兵兵兵兵兵
4  十十十十十十十十十
5  十十十十十十十十十
6  十十十十兵十十十十
7  兵兵兵兵十兵兵兵兵
8  十角十十十十十飛十
9  香馬銀金將金銀馬香
10 ------------------
11
The chess you want to move(input coordinate):
0                                                  //regret

Regret......

    1 2 3 4 5 6 7 8 9
-1
0  ------------------
1  香馬銀金將金銀馬香
2  十飛十十十十十角十
3  兵兵兵兵兵兵兵兵兵
4  十十十十十十十十十
5  十十十十十十十十十
6  十十十十十十十十十
7  兵兵兵兵兵兵兵兵兵
8  十角十十十十十飛十
9  香馬銀金將金銀馬香
10 ------------------
11
The chess you want to move(input coordinate):
7
5

Select the coordinates to place:
6
5


    1 2 3 4 5 6 7 8 9
-1
0  ------------------
1  香馬銀金將金銀馬香
2  十飛十十十十十角十
3  兵兵兵兵兵兵兵兵兵
4  十十十十十十十十十
5  十十十十十十十十十
6  十十十十兵十十十十
7  兵兵兵兵十兵兵兵兵
8  十角十十十十十飛十
9  香馬銀金將金銀馬香
10 ------------------
11
The chess you want to move(input coordinate):
3
5

Select the coordinates to place:
4
5


    1 2 3 4 5 6 7 8 9
-1
0  ------------------
1  香馬銀金將金銀馬香
2  十飛十十十十十角十
3  兵兵兵兵十兵兵兵兵
4  十十十十兵十十十十
5  十十十十十十十十十
6  十十十十兵十十十十
7  兵兵兵兵十兵兵兵兵
8  十角十十十十十飛十
9  香馬銀金將金銀馬香
10 ------------------
11
The chess you want to move(input coordinate):
6
5

Select the coordinates to place:
5
5


    1 2 3 4 5 6 7 8 9
-1
0  ------------------
1  香馬銀金將金銀馬香
2  十飛十十十十十角十
3  兵兵兵兵十兵兵兵兵
4  十十十十兵十十十十
5  十十十十兵十十十十
6  十十十十十十十十十
7  兵兵兵兵十兵兵兵兵
8  十角十十十十十飛十
9  香馬銀金將金銀馬香
10 ------------------
11
The chess you want to move(input coordinate):
4
5

Select the coordinates to place:
5
5


    1 2 3 4 5 6 7 8 9
-1 兵
0  ------------------
1  香馬銀金將金銀馬香
2  十飛十十十十十角十
3  兵兵兵兵十兵兵兵兵
4  十十十十十十十十十
5  十十十十兵十十十十
6  十十十十十十十十十
7  兵兵兵兵十兵兵兵兵
8  十角十十十十十飛十
9  香馬銀金將金銀馬香
10 ------------------
11
The chess you want to move(input coordinate):
8
8

Select the coordinates to place:
8
5


    1 2 3 4 5 6 7 8 9
-1 兵
0  ------------------
1  香馬銀金將金銀馬香
2  十飛十十十十十角十
3  兵兵兵兵十兵兵兵兵
4  十十十十十十十十十
5  十十十十兵十十十十
6  十十十十十十十十十
7  兵兵兵兵十兵兵兵兵
8  十角十十飛十十十十
9  香馬銀金將金銀馬香
10 ------------------
11
The chess you want to move(input coordinate):
3
7

Select the coordinates to place:
4
7


    1 2 3 4 5 6 7 8 9
-1 兵
0  ------------------
1  香馬銀金將金銀馬香
2  十飛十十十十十角十
3  兵兵兵兵十兵十兵兵
4  十十十十十十兵十十
5  十十十十兵十十十十
6  十十十十十十十十十
7  兵兵兵兵十兵兵兵兵
8  十角十十飛十十十十
9  香馬銀金將金銀馬香
10 ------------------
11
The chess you want to move(input coordinate):
8
5

Select the coordinates to place:
5
5


    1 2 3 4 5 6 7 8 9
-1 兵
0  ------------------
1  香馬銀金將金銀馬香
2  十飛十十十十十角十
3  兵兵兵兵十兵十兵兵
4  十十十十十十兵十十
5  十十十十飛十十十十
6  十十十十十十十十十
7  兵兵兵兵十兵兵兵兵
8  十角十十十十十十十
9  香馬銀金將金銀馬香
10 ------------------
11 兵
The chess you want to move(input coordinate):
2
8

Select the coordinates to place:
4
8

You can't place the chess here! Please reposition it.          //detect error

Select the coordinates to place:
5
5


    1 2 3 4 5 6 7 8 9
-1 兵飛
0  ------------------
1  香馬銀金將金銀馬香
2  十飛十十十十十十十
3  兵兵兵兵十兵十兵兵
4  十十十十十十兵十十
5  十十十十角十十十十
6  十十十十十十十十十
7  兵兵兵兵十兵兵兵兵
8  十角十十十十十十十
9  香馬銀金將金銀馬香
10 ------------------
11 兵
The chess you want to move(input coordinate):
1
5

That's not your chess! Please reselect one.          //detect error
The chess you want to move(input coordinate):
0

Regret......                                       //regret

    1 2 3 4 5 6 7 8 9
-1 兵飛
0  ------------------
1  香馬銀金將金銀馬香
2  十飛十十十十十角十
3  兵兵兵兵十兵十兵兵
4  十十十十十十兵十十
5  十十十十飛十十十十
6  十十十十十十十十十
7  兵兵兵兵十兵兵兵兵
8  十角十十十十十十十
9  香馬銀金將金銀馬香
10 ------------------
11 兵
The chess you want to move(input coordinate):
5
5

That's not your chess! Please reselect one.          //detect error
The chess you want to move(input coordinate):
2
8

Select the coordinates to place:
4
8

You can't place the chess here! Please reposition it.          //detect error

Select the coordinates to place:
4
7

You can't place the chess here! Please reposition it.          //detect error

Select the coordinates to place:
4
6


    1 2 3 4 5 6 7 8 9
-1 兵飛
0  ------------------
1  香馬銀金將金銀馬香
2  十飛十十十十十十十
3  兵兵兵兵十兵十兵兵
4  十十十十十角兵十十
5  十十十十飛十十十十
6  十十十十十十十十十
7  兵兵兵兵十兵兵兵兵
8  十角十十十十十十十
9  香馬銀金將金銀馬香
10 ------------------
11 兵
The chess you want to move(input coordinate):
5
5

Select the coordinates to place:
1
5


    1 2 3 4 5 6 7 8 9
-1 兵飛
0  ------------------
1  香馬銀金飛金銀馬香
2  十飛十十十十十十十
3  兵兵兵兵十兵十兵兵
4  十十十十十角兵十十
5  十十十十十十十十十
6  十十十十十十十十十
7  兵兵兵兵十兵兵兵兵
8  十角十十十十十十十
9  香馬銀金將金銀馬香
10 ------------------
11 兵將
Game over!                         //the general is dead

##save the process in the fp_write
```sh
7 5 6 5 0 7 5 6 5 3 5 4 5 6 5 5 5 4 5 5 5 8 8 8 5 3 7 4 7 8 5 5 5 2 8 4 8 5 5 1 5 0 5 5 2 8 4 8 4 7 4 6 5 5 1 5 
