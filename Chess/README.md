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