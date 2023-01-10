#include "chess.h"
#include <windows.h>

void setcolor(int color)
{
    HANDLE
    hc = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hc,0|color);
}

Stack_t *init_stack()
{
    Stack_t *stk = (Stack_t*) malloc(sizeof(Stack_t));
    if(!stk)
    {
        printf("\nAllocation Error! (stk)\n");
        return stk;
    }
    stk->top = NULL;
    stk->num = 0;
    return stk;
}

Queue_t *init_queue()
{
    Queue_t *que = (Queue_t*) malloc(sizeof(Queue_t));
    if(!que)
    {
        printf("\nAllocation Error! (que)\n");
        return que;
    }
    que->head = NULL;
    que->rear = NULL;
    que->num = 0;
    return que;
}

Node_t *init_nodes()
{
    Node_t *node = (Node_t*) malloc(sizeof(Node_t));
    if(!node)
    {
        printf("\nAllocation Error! (node)\n");
        return node;
    }
    node->next = NULL;
    node->previous = NULL;
    node->value = init_coor();
    return node;
}

Coor_xy *init_coor()
{
    Coor_xy *coor = (Coor_xy*) malloc(sizeof(Coor_xy));
    if(!coor)
    {
        printf("\nAllocation Error! (coor)\n");
        return coor;
    }
    coor->chess_type = none;
    coor->team = NONE;
    coor->x = 0;
    coor->y = 0;
    return coor;
}

Coor_xy **init_board()
{
    //up:香馬銀金將金銀馬香"角飛"兵兵兵兵兵兵兵兵兵
    //down:香馬銀金將金銀馬香"角飛"兵兵兵兵兵兵兵兵兵
    //setup two-dimensional dynamic vector as a checkerboard nodes2
    Coor_xy **nodes2D;
    nodes2D = (Coor_xy**) malloc(ROW_NUM*sizeof(Coor_xy*));
    for(int i=0;i<ROW_NUM;i++)
    {
        nodes2D[i] = (Coor_xy*) malloc(COLUMN_NUM*sizeof(Coor_xy));
    }
    ////////initialize xy values of checkerboard//////////
    for(int i=0;i<ROW_NUM;i++)
    {
        for(int j=0;j<COLUMN_NUM;j++)
        {
            nodes2D[i][j].x = i;
            nodes2D[i][j].y = j;
            nodes2D[i][j].chess_type = none;
            nodes2D[i][j].team = NONE;
        }
    }
    ////////initialize chess type of checkerboard//////////
    nodes2D[0][0].chess_type = rook; nodes2D[8][0].chess_type = rook;
    nodes2D[0][1].chess_type = horse; nodes2D[8][1].chess_type = horse;
    nodes2D[0][2].chess_type = silver; nodes2D[8][2].chess_type = silver;
    nodes2D[0][3].chess_type = gold; nodes2D[8][3].chess_type = gold;
    nodes2D[0][4].chess_type = general;nodes2D[8][4].chess_type = general;
    nodes2D[0][5].chess_type = gold; nodes2D[8][5].chess_type = gold;
    nodes2D[0][6].chess_type = silver; nodes2D[8][6].chess_type = silver;
    nodes2D[0][7].chess_type = horse; nodes2D[8][7].chess_type = horse;
    nodes2D[0][8].chess_type = rook; nodes2D[8][8].chess_type = rook;
    //
    nodes2D[1][1].chess_type = chariot; nodes2D[7][7].chess_type = chariot;
    nodes2D[1][7].chess_type = diagonal; nodes2D[7][1].chess_type = diagonal;
    //
    for(int i=0;i<COLUMN_NUM;i++)
    {
        nodes2D[2][i].chess_type = infantry; nodes2D[6][i].chess_type = infantry;
        //nodes2D[0][i].chess_type = die; nodes2D[10][i].chess_type = die;
    }
    //initialize team of chess
    for(int i=0;i<COLUMN_NUM;i++)
    {
        nodes2D[0][i].team = UP;
        nodes2D[2][i].team = UP;
        nodes2D[8][i].team = DOWN;
        nodes2D[6][i].team = DOWN;
    }
    nodes2D[1][1].team = UP; nodes2D[1][7].team = UP;
    nodes2D[7][1].team = DOWN; nodes2D[7][7].team = DOWN;
    //

    return nodes2D;
}

void push(Stack_t *const stk, Coor_xy *src)
{
    Node_t *node = (Node_t*) malloc(sizeof(Node_t));
    if(node==NULL)
    {
        printf("\nAllocation Error! (node)\n");
        return;
    }

    node->value = src;
    node->next = NULL;

    if(stk->top)
    {
        stk->top->next = node;
        node->previous = stk->top;
    }
    stk->top = node;
    stk->num++;

    //printf("\n%d\n",stk->num);

    return;
}

Coor_xy* pop(Stack_t *const stk, Coor_xy *des)
{
    if(!stk)
    {
        printf("Stack is empty!\n");
        return des;
    }

    Node_t *temp = (Node_t*) malloc(sizeof(Node_t));
    if(temp==NULL)
    {
        printf("\nAllocation Error! (temp)\n");
        return des;
    }

    temp = stk->top;
    des = temp->value;
    stk->top = temp->previous;
    stk->num--;

    //memcpy(des, temp->value, size);
    free(temp);
    //printf("%d %d %d",des->x, des->y, des->team);

    return des;
}

void chess_printing(Shogi_chess type, int team)
{
    if(team == UP) setcolor(4);
    else if(team == DOWN) setcolor(1);

    switch(type)
           {
                case none:
                    {
                        printf("十");
                        break;
                    }
                case rook:
                    {
                        printf("香");
                        break;
                    }
                case horse:
                    {
                        printf("馬");
                        break;
                    }
                case silver:
                    {
                        printf("銀");
                        break;
                    }
                case gold:
                    {
                        printf("金");
                        break;
                    }
                case general:
                    {
                        printf("將");
                        break;
                    }
                case diagonal:
                    {
                        printf("角");
                        break;
                    }
                case chariot:
                    {
                        printf("飛");
                        break;
                    }
                case infantry:
                    {
                        printf("兵");
                        break;
                    }
                case gold_horse:
                    {
                        printf("桂");
                        break;
                    }
                case gold_infantry:
                    {
                        printf("步");
                        break;
                    }
                case gold_rook:
                    {
                        printf("杏");
                        break;
                    }
                case gold_silver:
                    {
                        printf("全");
                        break;
                    }
                case die:
                    {
                        printf("--");
                        break;
                    }
                default:
                    {
                        printf("?");
                        break;
                    }
           }
    setcolor(7);  //white text
}

Coor_xy* queue_remove_head(Queue_t *const que, Coor_xy *removed)
{
    assert(que);
    Node_t *tmp = (Node_t*) malloc(sizeof(Node_t));
    if(!tmp)
    {
        printf("\nAllocation Error! (tmp)\n");
        return removed;
    }else if(que->head == que->rear){
        printf("\nNothing exists in this queue!");
        return removed;
    }else{
        tmp = que->head;
        que->head = tmp->next;
        removed = tmp->value;
        que->num--;
        free(tmp);
    }
    return removed;
}

Coor_xy* queue_remove_rear(Queue_t *const que, Coor_xy *removed)
{
    assert(que);
    Node_t *tmp = (Node_t*) malloc(sizeof(Node_t));
    if(!tmp)
    {
        printf("\nAllocation Error! (tmp)\n");
        return removed;
    }else if(!(que->head)){
        printf("\nNothing exists in this queue!");
        return removed;
    }else if(que->head == que->rear){
        que->head = NULL;
        tmp = que->rear;
        que->rear = NULL;
    }else{
        tmp = que->rear;
        que->rear = tmp->previous;
        que->rear->next = NULL;
    }

    removed = tmp->value;
    que->num--;
    free(tmp);

    //printf("\nhhhh%d %d %d", removed->x, removed->y, removed->team);
    return removed;
}

void queue_insert(Queue_t *const que, Coor_xy* src)
{
    assert(que);
    assert(src);
    Node_t *tmp = init_nodes();
    if(!tmp)
    {
        printf("\nAllocation Error! (tmp)\n");
        return;
    }else{
        tmp->value = src;
    }

    if(!(que->head))
    {
        que->head = tmp;
        que->rear = tmp;
        que->num++;
        return;
    }

    que->rear->next = tmp;
    tmp->previous = que->rear;
    que->rear = tmp;
    que->num++;
    return;
}

