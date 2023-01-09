#ifndef _CHESS_H_
#define _CHESS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define COORDINATE_NUM 2
#define COLUMN_NUM 9
#define ROW_NUM 9
#define COOR_X 0
#define COOR_Y 1
#define TRUE 1
#define FALSE 0

//team
#define NONE 0
#define UP 1
#define DOWN -1

#define KRED_L "\x1B[1;31m"

typedef enum shogi Shogi_chess;
enum shogi
{
    none = 0,
    rook = 1,
    horse = 2,
    silver = 3,
    gold = 4,
    general = 5,
    diagonal = 6,
    chariot = 7,
    infantry = 8,
    ////////////////level up /////////////////////
    gold_rook = 9,
    gold_horse = 10,
    gold_silver = 11,
    gold_infantry = 12,
    drag_diagonal = 13,
    drag_chariot = 14,
    //
    die = 15
};

typedef struct coordinate
{
    int x;
    int y;
    int team;
    Shogi_chess chess_type;
}Coor_xy;


typedef struct Node
{
    Coor_xy *value;
    struct Node *previous;
    struct Node *next;
}Node_t;

typedef struct queue_t
{
    Node_t *head;
    Node_t *rear;
    int num;
}Queue_t;

typedef struct Stack
{
    Node_t *top;
    int num;
}Stack_t;

Coor_xy **init_board();
Stack_t *init_stack();
Queue_t *init_queue();
Node_t *init_nodes();
Coor_xy *init_coor();

void push(Stack_t *const, Coor_xy*);
Coor_xy* pop(Stack_t *const, Coor_xy*);
void update_board(Coor_xy **const, Queue_t *const, Queue_t *const);
void display_die(Coor_xy **const, Stack_t *const, Stack_t *const);
void display(Node_t *);
void chess_printing(Shogi_chess, int);
int chess_def(Coor_xy **const, int*, int*, int, Stack_t *const, Queue_t *const, Queue_t *const,  Queue_t *const, int);

//queue
Coor_xy* queue_remove_head(Queue_t *const, Coor_xy*);
Coor_xy* queue_remove_rear(Queue_t *const, Coor_xy*);
void queue_insert(Queue_t *const, Coor_xy*);

#endif // _CHESS_H_
