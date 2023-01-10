#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "chess.h"

#define FILE_READ "oldboard.txt"
#define FILE_WRITE "newboard.txt"

Stack_t *save_chess;
Queue_t *die_chess_up;
Queue_t *die_chess_down;
Queue_t *procedure;
Node_t *read;
Coor_xy *step;
Queue_t *save_step;
int turn;
int regret;

void print_usage(char *file)
{
	printf("new board:%s -n -s [new_game_file_name]\n", file);
	printf("old board:%s -l [old_game_file_name]\n", file);
}

int main()
{
    save_chess = init_stack();
    die_chess_up = init_queue();
    die_chess_down = init_queue();
    procedure = init_queue();
    read = init_nodes();
    ////
    save_step = init_queue();
    step = init_coor();

    turn = DOWN;  //team 2 first
    regret = FALSE;
    /*
    printf("   0 1 2 3 4 5 6 7 8\n");
    printf("0 一一一一一一一一一\n");
    printf("1 香馬銀金將金銀馬香\n");
    printf("2 十飛十十十十十角十\n");
    printf("3 兵兵兵兵兵兵兵兵兵\n");
    printf("4 十十十十十十十十十\n");
    printf("5 十十十十十十十十十\n");
    printf("6 兵兵兵兵兵兵兵兵兵\n");
    printf("7 十角十十十十十飛十\n");
    printf("8 十角十十十十十飛十\n");
    printf("9 香馬銀金將金銀馬香\n");
    printf("10一一一一一一一一一\n");
    */
    Coor_xy **chess = init_board();
    update_board(chess, die_chess_up, die_chess_down);


    int end = 0;  //General is killed.

    int temp_choose[COORDINATE_NUM] = {0,0};
    int temp_place[COORDINATE_NUM] = {0,0};
    ////////////////////////////////////////////////////////
    FILE *fp_read, *fp_write;
    fp_read = fopen(FILE_READ, "r");
    if(fp_read == NULL)
    {
        printf("Can't open file\n");
        return -1;
    }

    fp_write = fopen(FILE_WRITE, "w");
    if(fp_write == NULL)
    {
        printf("Can't create file\n");
        fclose(fp_read);
        return -1;
    }


    do
    {
        int redo = 0;

        do
        {
            if(end)
            {
                printf("Game over!\n");
                break;
            }
            //printf("%d\n", end);
            printf("The chess you want to move(input coordinate):\n");

            for(int i=0; i<COORDINATE_NUM; i++)
            {
                scanf("%d", &temp_choose[i]);
                //step->x = temp_choose[i];
                //queue_insert(save_step, step);
                fprintf(fp_write, "%d ", temp_choose[i]);   //write to the file

                //first time regretting
                if(temp_choose[i] == 11)
                {
                    printf("The chess board is saved.\n");
                    break;
                }
                else if(temp_choose[i]==0)
                {
                    //regret more than one time
                    if(regret == 1)
                    {
                        read = procedure->rear->previous;

                        printf("\nRegret......");
                        break;
                    }
                    read = procedure->rear;
                    regret = TRUE;

                    printf("\nRegret......");
                    break;
                }

                temp_choose[i] = temp_choose[i] - 1;
                regret = FALSE;
            }
            if(!regret)
            {
                //printf("%d %d", temp_choose[COOR_X], temp_choose[COOR_Y]);  //test xy cooredinate

                if(chess[temp_choose[COOR_X]][temp_choose[COOR_Y]].chess_type == none)
                {
                    printf("\nThere is no chess in (%d,%d).\n", temp_choose[COOR_X]+1, temp_choose[COOR_Y]+1);
                    redo = TRUE;
                }
                else if(chess[temp_choose[COOR_X]][temp_choose[COOR_Y]].team != turn)
                {
                    printf("\nThat's not your chess! Please reselect one.\n");
                    redo = TRUE;
                }
                else break;
            }
            else break;


        }while(redo && !end);
        if(end)
        {
            break;
        }

        /*
        //test initial coordinate values
        printf("\nInitial coordinate values:\n");
        for(int i=0;i<ROW_NUM;i++)
        {
            for(int j=0;j<COLUMN_NUM;j++)
            {
                printf("Chess[%d][%d] = (%d,%d)\n", i, j, chess[i][j].x, chess[i][j].y);
                printf("Team:%d\n", chess[i][j].team);
            }
        }
        */
        do
        {
            if(!regret)
            {
                printf("\nSelect the coordinates to place:\n");
                for(int i=0; i<COORDINATE_NUM; i++)
                {
                    scanf("%d", &temp_place[i]);
                    //step->x = temp_place[i];
                    //queue_insert(save_step, step);
                    fprintf(fp_write, "%d ", temp_place[i]);   //write to the file
                    temp_place[i] = temp_place[i] - 1;
                }
                //printf("%d %d", temp_place[COOR_X], temp_place[COOR_Y]);  //test xy cooredinate

                ///////////////decide whether the chosen chess can be moved///////////////
                if(!chess_def(chess, temp_choose, temp_place, turn, save_chess, die_chess_up, die_chess_down, procedure, &end))
                {
                    printf("\nYou can't place the chess here! Please reposition it.\n");
                    redo = TRUE;
                }
                else   break;
            }
            else break;


        }
        while(redo);
        //printf("%d %d", temp_place[COOR_X], temp_place[COOR_Y]);
        //display_die(chess, die_chess_up, die_chess_down);
        //display(save_chess);
        ///////////////update the checkerboard/////////////////
        printf("\n");
        if(regret)
        {
            Coor_xy *des = init_coor();
            des = queue_remove_rear(procedure,des);
            //printf("\ntttt%d %d %d", des->x, des->y, des->team);
            chess[des->x][des->y].chess_type = des->chess_type;
            chess[des->x][des->y].team = des->team;
            //printf("\nremove\n");
            ////for died chess regretting////
            des = pop(save_chess, des);
            chess[des->x][des->y].chess_type = des->chess_type;
            chess[des->x][des->y].team = des->team;
            //printf("\npop\n");
        }

        //display(procedure->head);
        turn = -turn;
        update_board(chess, die_chess_up, die_chess_down);
        //display(procedure->head);
    }
    while(TRUE);

    ///////////////free the malloc///////////////////
    free(save_chess);
    free(die_chess_up);
    free(die_chess_down);
    for(int i=0; i<ROW_NUM; i++)
        free(chess[i]);
    free(chess);
    ///////////////close file//////////////////
    if(feof(fp_read)){
        printf("End of file\n");
    }
    else if(ferror(fp_read)){
        printf("Error\n");
    }

    fclose(fp_read);
    fclose(fp_write);
    ////////////////////////////////////////////////////////


    return 0;
}

///////////////////place the chosen chess and update////////////////////
void update_board(Coor_xy **const nodes, Queue_t *const up, Queue_t *const down)
{
    printf("\n    1 2 3 4 5 6 7 8 9\n");
    printf("-1 ");
    display(up->head);
    printf("\n0  ------------------\n");

    for(int i=0;i<ROW_NUM;i++)
    {
        printf("%d  ", i+1);

        for(int j=0;j<COLUMN_NUM;j++)
        {

           chess_printing(nodes[i][j].chess_type, nodes[i][j].team);
        }
        printf("\n");
    }
    printf("10 ------------------\n");
    printf("11 ");
    display(down->head);
    printf("\n");

    return;
}

int chess_def(Coor_xy **const nodes, int *choose, int *place, int turn, Stack_t *const save_chess, Queue_t *const up, Queue_t *const down, Queue_t *const proc, int* end)
{
    //get the value
    Shogi_chess type = nodes[choose[COOR_X]][choose[COOR_Y]].chess_type;

    int cx = choose[COOR_X];
    int cy = choose[COOR_Y];
    int px = place[COOR_X];
    int py = place[COOR_Y];

    //decide which type
    switch(type)
    {
        case none:
            {
                break;
            }
        case rook:
            {
                /////////////test feasibility of the movement//////////////
                if((cy==py))
                {
                    ///////////test for obstacle/////////////
                    for(int i=1;i<abs(px-cx);i++)
                    {
                        if(nodes[cx+turn*i][cy].chess_type != none)
                                return FALSE;
                    }

                }else return FALSE;
                break;
            }
        case horse:
            {
                if(!((abs(py-cy)==1)&&(turn*(px-cx)==2)))
                    return FALSE;

                break;
            }
        case silver:
            {
                ///////////four corner///////////////////////////forward//////////////////
                if(!(((abs(px-cx)==1)&&(abs(py-cy)==1)) || ((cy==py)&&(turn*(px-cx)==1))))
                    return FALSE;

                break;
            }
        case gold: case gold_horse: case gold_infantry: case gold_rook: case gold_silver:
            {
                //////left and right/////////////////up and down////////////////////forward corner//////////////
                if(!(((cx==px)&&abs(py-cy)==1) || ((cy==py)&&abs(px-cx)==1) || (abs(py-cy)==1&&(turn*(px-cx)==1))))
                    return FALSE;

                break;
            }
        case general:
            {
                if(!((abs(px-cx)<=1) && (abs(py-cy)<=1)))
                    return FALSE;

                break;
            }
        case diagonal:
            {
                if(turn*(px-cx) == abs(py-cy))
                {
                    if(py-cy>0)
                    {
                        for(int i=1;i<abs(px-cx);i++)
                        {
                            if(nodes[cx+turn*i][cy+turn*i].chess_type != none)
                                return FALSE;
                        }
                    }else if(py-cy<0){
                        for(int i=1;i<abs(px-cx);i++)
                        {
                            if(nodes[cx+turn*i][cy-turn*i].chess_type != none)
                                return FALSE;
                        }
                    }else return FALSE;

                }else return FALSE;
                break;
            }
        case chariot:
            {
                if(cx==px && cy!=py)  //row
                {
                    for(int i=1;i<abs((py-cy));i++)
                    {
                        if((py-cy) < 0)
                        {
                            if(nodes[cx][cy-i].chess_type != none)
                                return FALSE;
                        }else{  //(py-cy)>0
                            if(nodes[cx][cy+i].chess_type != none)
                                return FALSE;
                        }
                    }
                }else if(cy==py && cx!=px){  //column
                    for(int i=1;i<abs((px-cx));i++)
                    {
                        if((px-cx) < 0)
                        {
                            if(nodes[cx-i][cy].chess_type != none)
                                return FALSE;
                        }else{  //(px-cx)>0
                            if(nodes[cx+i][cy].chess_type != none)
                                return FALSE;
                        }
                    }
                }else   return FALSE;
                break;
            }
        case infantry:
            {
                if(cy==py)
                {
                    if(!(turn*(px-cx)==1))
                        return FALSE;
                }else return FALSE;

                break;
            }
        case drag_chariot:
            {
                if((abs(px-cx)<=1) && (abs(py-cy)<=1))  //general
                    break;
                //chariot
                else if(cx==px && cy!=py)  //row
                {
                    for(int i=1;i<abs((py-cy));i++)
                    {
                        if((py-cy) < 0)
                        {
                            if(nodes[cx][cy-i].chess_type != none)
                                return FALSE;
                        }else{  //(py-cy)>0
                            if(nodes[cx][cy+i].chess_type != none)
                                return FALSE;
                        }
                    }

                }else if(cy==py && cx!=px){  //column
                    for(int i=1;i<abs((px-cx));i++)
                    {
                        if((px-cx) < 0)
                        {
                            if(nodes[cx-i][cy].chess_type != none)
                                return FALSE;
                        }else{  //(px-cx)>0
                            if(nodes[cx+i][cy].chess_type != none)
                                return FALSE;
                        }
                    }
                }else   return FALSE;
                break;
            }
        case drag_diagonal:
            {
                if((abs(px-cx)<=1) && (abs(py-cy)<=1))  //general
                    break;
                else if(turn*(px-cx) == abs(py-cy))  //diagonal
                {
                    if(py-cy>0)
                    {
                        for(int i=1;i<abs(px-cx);i++)
                        {
                            if(nodes[cx+turn*i][cy+turn*i].chess_type != none)
                                return FALSE;
                        }
                    }else if(py-cy<0){
                        for(int i=1;i<abs(px-cx);i++)
                        {
                            if(nodes[cx+turn*i][cy-turn*i].chess_type != none)
                                return FALSE;
                        }
                    }else return FALSE;

                }else return FALSE;
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
    ////////////////test whether there exists chess at (px,py)////////////////////
    Coor_xy *dc = init_coor();
    *dc = nodes[cx][cy];
    Coor_xy *dp = init_coor();
    *dp = nodes[px][py];
    //printf("\ndc!!!!%d %d %d",dc->x, dc->y, dc->team);
    //printf("\ndp!!!!%d %d %d",dp->x, dp->y, dp->team);
    //////////////////////////////////////////////////////////////////////////////
    int change = 0;
    if(nodes[px][py].chess_type!=none && nodes[px][py].team==-turn)  //kill enemy
    {
        change = TRUE;

        if(turn==1)
            queue_insert(up, dp);
        else if(turn==-1)
            queue_insert(down, dp);


        //display(up->head);
        //printf("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww ");
        //display(down->head);
    }
    else if(nodes[px][py].chess_type==none)  //just move
        change = TRUE;
    else
        return FALSE;
    ////////////////swap//////////////////
    if(change)
    {
        //judge if the game is over when the general is killed
        if(dp->chess_type==general) (*end) = TRUE;

        //stack and queue
        push(save_chess, dp);
        queue_insert(proc, dc);
        //
        //printf("\nccccType:%d Team:%d\n",nodes[cx][cy].chess_type, nodes[cx][cy].team);
        //printf("\nppppType:%d Team:%d\n",nodes[px][py].chess_type, nodes[px][py].team);
        //printf("\nThe number of queue is %d\n", proc->num);
        //printf("\nThe number of died chess is %d\n", save_chess->num);
        nodes[px][py].chess_type = nodes[cx][cy].chess_type;
        nodes[px][py].team = nodes[cx][cy].team;
        nodes[cx][cy].chess_type = none;
        nodes[cx][cy].team = NONE;
        //printf("\nccccType:%d Team:%d\n",nodes[cx][cy].chess_type, nodes[cx][cy].team);
        //printf("\nppppType:%d Team:%d\n",nodes[px][py].chess_type, nodes[px][py].team);
        return TRUE;
    }else return FALSE;

}

void display(Node_t *node)
{
    if(!node)
    {
        //printf("\nNULL!");
        return;
    }
    while(node != NULL)
    {
        chess_printing(node->value->chess_type, node->value->team);
        //printf("\nTeam:%d, Type:%d, (x,y)=(%d,%d)", node->value->team, node->value->chess_type, (node->value->x)+1, (node->value->y)+1);
        node = node->next;
    }
    return;
}

