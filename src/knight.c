#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#include "knight.h"
	
#include "bit_array.h"

#define SIZE 8

typedef struct point_t
{
	int8_t x;
	int8_t y;
	uint8_t available;
	uint64_t next;

}point_t;

typedef struct move_t
{
	int8_t x;
	int8_t y;
}move_t;

static int IsValid(point_t squere, move_t move);

uint64_t knight(uint64_t start_location)
{
	point_t board[SIZE][SIZE] = {{{0}}};
	move_t move[8]	= {{2, 1}, {2, -1},
					   {1, 2}, {1, -2},
					   {-2, 1}, {-2, -1},
					   {-1, 2}, {-1, -2}};


	int row = 0;
	int col = 0;

	int i = 0;

	/* init x y coordinates for each point on the board */
	for(; row < SIZE; ++row)
	{
		for(col = 0; col < SIZE; ++col)
		{
			board[row][col].x = row;
			board[row][col].y = col;

			for(i = 0; i < 8; ++i)
			{
				if(IsValid(board[row][col], move[i]))
				{
					unsigned int index = board[row][col].x + move[i].x +
									   (SIZE * (board[row][col].y + move[i].y));

					board[row][col].next = SetOn(board[row][col].next, index);
				}
			}
			board[row][col].available = CountOn(board[row][col].next);

			printf("[%-1d %-1d %-20lud %d]", board[row][col].x, board[row][col].y ,
										board[row][col].next, board[row][col].available);
		}
		printf("\n");
	}





	/*for(; row < SIZE; ++row)
	{
		for(col = 0; col < SIZE; ++col)
		{
			printf("%i", board[row][col]);
		}
		printf("\n");
	}*/
	return(0);
}

static int IsValid(point_t squere, move_t move)
{
	if((squere.x + move.x < 0) || (squere.y + move.y < 0) ||
	   (squere.x + move.x >= SIZE) || (squere.y + move.y >= SIZE))
	{
		return(0);
	}

	return(1);
}

/*static void PrintBoard(int size)
{
	int i,j,num = size;

		for(i=0;i<num;i++)
		{
			for(j=0;j<num;j++)
			{
				printf("[]");
				printf(" ");
			}
			printf("\n");
			if(i%2==0)
			{
				printf(" ");
			}
		}
		printf("\n");
}*/

/*static void SetRow(char *squere, char num);
static void SetCol(char *squere, char num);*/


/*static void PrintBoard(int size);*/
/*static void SetRow(point_t *p, char num)
{
	(*squere = ((*squere >> 4) & 0) + num);
}

static void SetCol(char *squere, char num)
{
	(*squere =  (*squere & 0) + num);

}*/
