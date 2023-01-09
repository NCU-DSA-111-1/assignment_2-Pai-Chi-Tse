#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_READ "Test03.txt"
#define FILE_WRITE "Test03-out.txt"
void print_usage(char *file)
{
	printf("new board:%s -n -s [new_game_file_name]\n", file);
	printf("old board:%s -l [old_game_file_name]\n", file);
}
int main(int argc, char** argv)
{
    FILE *fp_read, *fp_write;

    if(argc!=3 || argc!=4)
	{
		print_usage(argv[0]);
		return 1;
	}else if(argc == 4 && argv[1][1] == 'n'){
        ////////////new board//////////////
	}else if(argc == 3 && argv[1][1] == 'l'){
        ////////////old board//////////////
	}

    fp_read = fopen(FILE_READ, "r");
    if(fp_read == NULL){
        printf("Can't open file\n");
        return -1;
    }

    fp_write = fopen(FILE_WRITE, "w");
    if(fp_write == NULL){
        printf("Can't create file\n");
        fclose(fp_read);
        return -1;
    }
}
