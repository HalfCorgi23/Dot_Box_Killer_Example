#ifndef H_evaluation_
#define H_evaluation_
#define random(x) (rand()%x)
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include"data_2.h"

/****************************************************************************/

typedef struct {
	int edgekind;      //储存值为horizon或vertice
	int x;         //边的横坐标
	int y;         //边的纵坐标
}nextmove;

/*************************************************************************/

nextmove bestsearch(int depth, int beta, int turn, int round);
int makemove(nextmove move, int turn);

/**************************************估值函数*************************************/

/**************************************搜索算法************************************/

/********************************************************************************/

nextmove bestsearch(int depth, int beta, int turn, int round)
{
	nextmove move;
	int randed = random(1);	
	if (randed == horizon)
	{
		int randx_h = random(5);
		int randy_h = random(4);
		if (horiz[randx_h][randy_h] == 0)
		{
			move.edgekind = randed;
			move.x = randx_h;
			move.y = randy_h;
			return move;
		}
		else
		{
			return bestsearch(depth, beta, turn, round);
		}
	}
	else
	{
		int randx_v = random(4);
		int randy_v = random(5);
		if (horiz[randx_v][randy_v] == 0)
		{
			move.edgekind = randed;
			move.x = randx_v;
			move.y = randy_v;
			return move;
		}
		else
		{
			return bestsearch(depth, beta, turn, round);
		}
	}
}
int makemove(nextmove move, int turn)
{
	
	if (move.edgekind == horizon)
	{
		horiz[move.x][move.y] = 1;
		choriz[move.x][move.y] = '-';
		if (move.x == 0)
		{
			if (boxs[move.x][move.y].neighbornum == 0)
			{
				return 1;
			}
			else
			{

				return 0;
			}
		}
		if (move.x == 5)
		{
			if (boxs[move.x][move.y-1].neighbornum == 0)
			{
				return 1;
			}
			else
			{

				return 0;
			}
		}
		else
		{
			if (boxs[move.x][move.y].neighbornum == 0)
			{
				return 1;
			}
			else if (boxs[move.x][move.y - 1].neighbornum == 0)
			{
				return 1;
			}
			else
			{

				return 0;
			}
		}
	}
	if (move.edgekind == vertice)
	{
		vertic[move.x][move.y] = 1;
		cvertic[move.x][move.y] = '|';
		if (move.y == 0)
		{
			if (boxs[move.x][move.y].neighbornum == 0)
			{
				return 1;
			}
			else
			{

				return 0;
			}
		}
		if (move.y == 5)
		{
			if (boxs[move.x - 1][move.y].neighbornum == 0)
			{
				return 1;
			}
			else
			{

				return 0;
			}
		}
		else
		{
			if (boxs[move.x][move.y].neighbornum == 0)
			{
				return 1;
			}
			else if (boxs[move.x - 1][move.y].neighbornum == 0)
			{
				return 1;
			}
			else
			{

				return 0;
			}
		}
	}
}

#endif