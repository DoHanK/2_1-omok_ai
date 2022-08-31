#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>
#include "Judgment.h"
//커밋확인

#define limit 19
#define BLACK -1
#define WHITE 1



struct stonetrait {
	int user1 = 0;
	int user2 = 0;


	char shape = 'x';


	int count = 0;
	int x = 0;
	int y = 0;
	int vx = 0;
	int vy = 0;
	char trait = 's';
	int vnum = 0;
	stonetrait* next = nullptr;
	double  weight = 0;
};
struct stone {
	int x = 0;
	int y = 0;
	char shape = '+';
	stone* next = nullptr;
};
struct AI
{
	int x = 0;
	int y = 0;
	int dir = 0;
	int select_dir = 1;
	int count_dir = 0;
	int attack = 0;
	int out = 0;
};




vector<pair<int, int>> positions;
Judgment judgment;





char board[19][19];
double fboard[19][19];
int order=0;
int in_x, in_y;
int user1_cnt(0);
int user2_cnt(0);
int board_2019180006[19][19];
void valueboard2(stonetrait* a);
void valueboard(stonetrait* a);
bool determine;


AI dohan;
AI dohan2;
stone* stack = nullptr;
stone* istack = nullptr;
stonetrait* advstack = nullptr;
void setb() {


	for (int i = 0; i < limit; ++i)
		for (int j = 0; j < limit; ++j)
			board[i][j] = '+';
}
void prtb() {


	for (int i = 0; i < limit; ++i)
	{
		for (int j = 0; j < limit; ++j)
			std::cout << board[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl << "player1 놓은수-" << user1_cnt << "    " << "player2 놓은수-" << user2_cnt << std::endl;

}
void fprtb()
{

	for (int i = 0; i < limit; ++i)
	{
		for (int j = 0; j < limit; ++j)
		{
			if (fboard[i][j] > 0 && board[i][j] == '+')
			{
				std::cout << fboard[i][j] << " ";
			}
			else
			{
				std::cout << board[i][j] << " ";
				fboard[i][j] = 0;
			}
		}
		std::cout << std::endl;
	}

}
void squence()
{
	stonetrait temp;
	stonetrait max;
	stonetrait* move = nullptr;
	char prev = '+';
	int vcheck = 0;
	int vpflag = 0;
	int block = 0;

	//힌트 삭제


	//가로 연속인경우
	for (int y = 0; y < limit; ++y)
	{
		for (int x = 0; x < limit; ++x)
		{
			switch (board[y][x])
			{
			case '+':

				if (prev == '+')
				{

					prev = '+';
					vcheck = 0;
					temp.vnum = 0;
					block = 1;
				}
				else {

					if (vcheck == 0)
					{


						block = 0;
						vcheck++;

						temp.vx = x;
						temp.vy = y;
						temp.vnum = 1;

					}
					else if (vcheck == 1)
					{
						x = temp.vx;
						y = temp.vy;
						temp.vnum = 0;
						temp.count = 0;
						temp.x = 0;
						temp.y = 0;
						temp.shape = '+';
						vcheck = 0;
						prev = '+';
						block = 1;

					}
				}

				break;
			case'@':
				if (prev == board[y][x])
				{
					temp.count++;
					temp.shape = '@';
					temp.x = x;
					temp.y = y;
				}
				else {

					temp.count = 1;
					temp.shape = '@';
					temp.x = x;
					temp.y = y;
				}
				prev = '@';
				block = 1;
				break;
			case'0':
				if (prev == board[y][x])
				{
					temp.count++;
					temp.shape = '0';
					temp.x = x;
					temp.y = y;
				}
				else {
					temp.count = 1;
					temp.shape = '0';
					temp.x = x;
					temp.y = y;
				}
				prev = '0';
				block = 1;
				break;
			}

			if (((temp.count > 2) && (temp.vnum == 0)) || ((temp.count > 1) && (temp.vnum == 1)))
			{
				if (block) {
					if (advstack == nullptr)
					{
						move = new stonetrait;
						move->count = temp.count;
						move->x = temp.x;
						move->y = temp.y;
						move->count = temp.count;
						move->trait = 'r';
						move->shape = temp.shape;
						move->vnum = temp.vnum;
						advstack = move;
						advstack->next = nullptr;
					}
					else
					{
						move = new stonetrait;
						move->count = temp.count;
						move->x = temp.x;
						move->y = temp.y;
						move->count = temp.count;
						move->trait = 'r';
						move->shape = temp.shape;
						move->vnum = temp.vnum;
						move->next = advstack;
						advstack = move;

					}
				}
			}

			if (temp.count > max.count)
			{
				max.count = temp.count;
				max.x = temp.x;
				max.y = temp.y;
				max.count = temp.count;
				max.trait = 'r';
				max.shape = temp.shape;
				max.vnum = temp.vnum;
			}
		}


		temp.count = 0;
		temp.x = 0;
		temp.y = 0;
		temp.shape = '+';
		prev = '+';
		temp.vx = 0;
		temp.vy = 0;
		temp.vnum = 0;
	}
	//세로 연속인경우
	for (int x = 0; x < limit; ++x)
	{
		for (int y = 0; y < limit; ++y)
		{
			switch (board[y][x])
			{
			case '+':

				if (prev == '+')
				{
					prev = '+';
					vcheck = 0;
					block = 1;
				}
				else {

					if (vcheck == 0)
					{

						temp.vx = x;
						temp.vy = y;

						vcheck++;
						block = 0;
						temp.vnum = 1;

					}
					else if (vcheck == 1)
					{
						x = temp.vx;
						y = temp.vy;
						temp.count = 0;
						temp.x = 0;
						temp.y = 0;
						temp.shape = '+';
						temp.vnum = 0;
						vcheck = 0;
						prev = '+';
						block = 1;
					}
				}

				break;
			case'@':
				if (prev == board[y][x])
				{
					temp.count++;
					temp.shape = '@';
					temp.x = x;
					temp.y = y;
				}
				else {

					temp.count = 1;
					temp.shape = '@';
					temp.x = x;
					temp.y = y;
				}
				prev = '@';
				block = 1;
				break;
			case'0':
				if (prev == board[y][x])
				{
					temp.count++;
					temp.shape = '0';
					temp.x = x;
					temp.y = y;
				}
				else {
					temp.count = 1;
					temp.shape = '0';
					temp.x = x;
					temp.y = y;
				}
				prev = '0';
				block = 1;
				break;
			}

			if (((temp.count > 2) && (temp.vnum == 0)) || ((temp.count > 1) && (temp.vnum == 1)))
			{
				if (block)
				{
					if (advstack == nullptr)
					{
						move = new stonetrait;
						move->count = temp.count;
						move->x = temp.x;
						move->y = temp.y;
						move->count = temp.count;
						move->trait = 'c';
						move->shape = temp.shape;
						move->vnum = temp.vnum;
						advstack = move;
						advstack->next = nullptr;
					}
					else
					{
						move = new stonetrait;
						move->count = temp.count;
						move->x = temp.x;
						move->y = temp.y;
						move->count = temp.count;
						move->trait = 'c';
						move->shape = temp.shape;
						move->vnum = temp.vnum;
						move->next = advstack;
						advstack = move;

					}
				}
			}




			if (temp.count > max.count)
			{
				max.count = temp.count;
				max.x = temp.x;
				max.y = temp.y;
				max.count = temp.count;
				max.trait = 'c';
				max.shape = temp.shape;
				max.vnum = temp.vnum;
			}
		}
		temp.count = 0;
		temp.x = 0;
		temp.y = 0;
		temp.shape = '+';
		prev = '+';
		temp.vx = 0;
		temp.vy = 0;
		temp.vnum = 0;
	}
	// 대각선
	for (int i = 0; i < 37; ++i)
	{
		for (int y = 0; y < limit; ++y)
		{
			for (int x = 0; x < limit; ++x)
			{
				if (x == y - 18 + i)
				{
					switch (board[y][x])
					{
					case '+':

						if (prev == '+')
						{
							prev = '+';
							vcheck = 0;
							block = 1;
						}
						else {

							if (vcheck == 0)
							{

								temp.vx = x;
								temp.vy = y;



								vcheck++;


								temp.vnum = 1;
								block = 0;
							}
							else if (vcheck == 1)
							{
								x = temp.vx;
								y = temp.vy;
								temp.vnum = 0;
								temp.count = 0;
								temp.x = 0;
								temp.y = 0;
								temp.shape = '+';
								vcheck = 0;
								prev = '+';
								block = 1;
							}
						}

						break;
					case'@':
						if (prev == board[y][x])
						{
							temp.count++;
							temp.shape = '@';
							temp.x = x;
							temp.y = y;
						}
						else {

							temp.count = 1;
							temp.shape = '@';
							temp.x = x;
							temp.y = y;
						}
						prev = '@';
						block = 1;
						break;
					case'0':
						if (prev == board[y][x])
						{
							temp.count++;
							temp.shape = '0';
							temp.x = x;
							temp.y = y;
						}
						else {
							temp.count = 1;
							temp.shape = '0';
							temp.x = x;
							temp.y = y;
						}
						prev = '0';
						block = 1;
						break;
					}

					if (((temp.count > 2) && (temp.vnum == 0)) || ((temp.count > 1) && (temp.vnum == 1)))
					{
						if (block) {
							if (advstack == nullptr)
							{
								move = new stonetrait;
								move->count = temp.count;
								move->x = temp.x;
								move->y = temp.y;
								move->count = temp.count;
								move->trait = 'x';
								move->shape = temp.shape;
								move->vnum = temp.vnum;
								advstack = move;
								advstack->next = nullptr;
							}
							else
							{
								move = new stonetrait;
								move->count = temp.count;
								move->x = temp.x;
								move->y = temp.y;
								move->count = temp.count;
								move->trait = 'x';
								move->shape = temp.shape;
								move->vnum = temp.vnum;
								move->next = advstack;
								advstack = move;

							}
						}
					}


					if (temp.count > max.count)
					{
						max.count = temp.count;
						max.x = temp.x;
						max.y = temp.y;
						max.count = temp.count;
						max.trait = 'x';
						max.shape = temp.shape;
						max.vnum = temp.vnum;
					}
				}
			}



		}
		temp.count = 0;
		temp.x = 0;
		temp.y = 0;
		temp.shape = '+';
		prev = '+';
		temp.vx = 0;
		temp.vy = 0;
		temp.vnum = 0;
	}
	// 역대각선
	for (int i = 0; i < 37; ++i)
	{
		for (int y = 0; y < limit; ++y)
		{
			for (int x = 0; x < limit; ++x)
			{
				if (x + y == 36 - i)
				{
					switch (board[y][x])
					{
					case '+':

						if (prev == '+')
						{
							prev = '+';
							vcheck = 0;
							block = 1;
						}
						else {

							if (vcheck == 0)
							{

								temp.vx = x;
								temp.vy = y;


								vcheck++;
								block = 0;


								temp.vnum = 1;

							}
							else if (vcheck == 1)
							{
								x = temp.vx;
								y = temp.vy;
								temp.vnum = 0;
								temp.count = 0;
								temp.x = 0;
								temp.y = 0;
								temp.shape = '+';
								vcheck = 0;
								prev = '+';
								block = 1;
							}
						}

						break;
					case'@':
						if (prev == board[y][x])
						{
							temp.count++;
							temp.shape = '@';
							temp.x = x;
							temp.y = y;
						}
						else {

							temp.count = 1;
							temp.shape = '@';
							temp.x = x;
							temp.y = y;
						}
						prev = '@';
						block = 1;
						break;
					case'0':
						if (prev == board[y][x])
						{
							temp.count++;
							temp.shape = '0';
							temp.x = x;
							temp.y = y;
						}
						else {
							temp.count = 1;
							temp.shape = '0';
							temp.x = x;
							temp.y = y;
						}
						prev = '0';
						block = 1;
						break;
					}


					if (((temp.count > 2) && (temp.vnum == 0)) || ((temp.count > 1) && (temp.vnum == 1)))
					{
						if (block) {
							if (advstack == nullptr)
							{
								move = new stonetrait;
								move->count = temp.count;
								move->x = temp.x;
								move->y = temp.y;
								move->count = temp.count;
								move->trait = 's';
								move->shape = temp.shape;
								move->vnum = temp.vnum;
								advstack = move;
								advstack->next = nullptr;
							}
							else
							{
								move = new stonetrait;
								move->count = temp.count;
								move->x = temp.x;
								move->y = temp.y;
								move->count = temp.count;
								move->trait = 's';
								move->shape = temp.shape;
								move->vnum = temp.vnum;
								move->next = advstack;
								advstack = move;

							}
						}
					}


					if (temp.count > max.count)
					{
						max.count = temp.count;
						max.x = temp.x;
						max.y = temp.y;
						max.count = temp.count;
						max.trait = 's';
						max.shape = temp.shape;
						max.vnum = temp.vnum;
					}
				}
			}



		}
		temp.count = 0;
		temp.x = 0;
		temp.y = 0;
		temp.shape = '+';
		prev = '+';
		temp.vx = 0;
		temp.vy = 0;
		temp.vnum = 0;
	}

}
void searchvacumn()
{
	int start = 0;
	int target = rand() % 10+1;
	for (int i = 0; i < limit; ++i)
	{
		if (target == start)
		{
			break;
		}
		for (int j = 0; j < limit; ++j)
		{


			if (board[i][j] == '+')
			{
				in_y = i;
				in_x = j;
				start++;
				break;
			}

		}
	}
}

//백돌
void valueboard(stonetrait* a) {
	stonetrait* move = a;
	int weight = 10;
	for (int i = 0; i < limit; ++i)
	{
		for (int j = 0; j < limit; ++j)
		{
			fboard[i][j] = 0;



		}
	}

	
	//수 알려주는 알고리즘
	if (move != nullptr)
	{
		while (advstack != nullptr)
		{
			advstack = advstack->next;
		

			if (move->shape == '0')
			{
				weight = 5;
			}
			else if (move->shape == '@')
			{
				weight = 6;
			}
			//연속이 아닌거
			if (move->count == 4 && move->vnum)
			{
				weight += 10;
			}
			// 
			else if (move->count == 3 && move->vnum)
			{
				weight += 8;
			}
			/////////////////////
			//연속이고 3이상
			else if (move->count > 2 && !(move->vnum))
			{

				weight += 8;
			}



			if (move->vnum)
			{

				for (int i = move->count; i > 0; --i)
				{
					switch (move->trait)
					{
					case 'r':
					{

						if (board[move->y][move->x - i] == '+')
						{
							fboard[move->y][move->x - i] += move->count * weight;
						}

					}
					case 'c':
					{

						if (board[move->y - i][move->x] == '+')
						{
							fboard[move->y - i][move->x] += move->count * weight;
						}

						break;
					}
					case 'x':
					{


						if (board[move->y - i][move->x - i] == '+')
						{
							fboard[move->y - i][move->x - i] += move->count * weight;

						}


						break;
					}
					case 's':
					{

						if (board[move->y - i][move->x + i] == '+')
						{
							fboard[move->y - i][move->x + i] += move->count * weight;

						}

						break;
					}

					}

				}

			}
			//계속연속인경우
			else
			{


				switch (move->trait)
				{
				case 'r':
				{

					if (move->x + 1 < limit + 1)
					{
						if (board[move->y][move->x + 1] == '+')
							fboard[move->y][move->x + 1] += move->count * weight;

					}
					if (move->x - move->count > -1)
					{
						if (board[move->y][move->x - move->count] == '+')
							fboard[move->y][move->x - move->count] += move->count * weight;
					}
					break;
				}
				case 'c':
				{
					if (move->y + 1 < 19)
					{
						if (board[move->y + 1][move->x] == '+')
							fboard[move->y + 1][move->x] += move->count * weight;
					}
					if (move->y - move->count > -1)
					{
						if (board[move->y - move->count][move->x] == '+')
							fboard[move->y - move->count][move->x] += move->count * weight;
					}
					break;
				}
				case 'x':
				{
					if (move->y + 1 < 19 && move->x + 1 < 19)
					{
						if (board[move->y + 1][move->x + 1] == '+')
							fboard[move->y + 1][move->x + 1] += move->count * weight;
					}
					if (move->y - move->count > -1 && move->x - move->count > -1)
					{
						if (board[move->y - move->count][move->x - move->count] == '+')
							fboard[move->y - move->count][move->x - move->count] += move->count * weight;
					}
					break;
				}
				case 's':
				{
					if (move->y + 1 < 19 && move->x > -1)
					{
						if (board[move->y + 1][move->x - 1] == '+')
							fboard[move->y + 1][move->x - 1] += move->count * weight;
					}
					if (move->y - move->count > -1 && move->x + move->count < 19)
					{
						if (board[move->y - move->count][move->x + move->count] == '+')
							fboard[move->y - move->count][move->x + move->count] += move->count * weight;
					}

					break;
				}
				}


			}

			delete move;
			move = advstack;
		}

	}





}
void valueboard2(stonetrait* a) {

	stonetrait* move = a;
	double weight = 10;
	for (int i = 0; i < limit; ++i)
	{
		for (int j = 0; j < limit; ++j)
		{
			fboard[i][j] = 0;



		}
	}
	//수 알려주는 알고리즘
	if (move != nullptr)
	{
		while (advstack != nullptr)
		{
			advstack = advstack->next;

		


			if (move->shape == '0')
			{
				weight = 6;
			}
			else if (move->shape == '@')
			{
				weight = 5;
			}
			//연속이 아닌거
			if (move->count==4 && move->vnum)
			{
				if (move->shape == '0')
				weight += 10;
			}
			// 
			else if (move->count == 3 && move->vnum)
			{
				if (move->shape == '0')
				weight += 8;
			}
			/////////////////////
			//연속이고 3이상
			else if (move->count > 2 && !(move->vnum))
			{
				if (move->shape == '0')
				weight += 8;
			}


			if (move->vnum)
			{
				

				for (int i = move->count; i > 0; --i)
				{
					switch (move->trait)
					{
					case 'r':
					{

						if (board[move->y][move->x - i] == '+')
						{
							fboard[move->y][move->x - i] += move->count * weight;
						}

					}
					case 'c':
					{

						if (board[move->y - i][move->x] == '+')
						{
							fboard[move->y - i][move->x] += move->count * weight;
						}

						break;
					}
					case 'x':
					{


						if (board[move->y - i][move->x - i] == '+')
						{
							fboard[move->y - i][move->x - i] += move->count * weight;

						}


						break;
					}
					case 's':
					{

						if (board[move->y - i][move->x + i] == '+')
						{
							fboard[move->y - i][move->x + i] += move->count * weight;

						}

						break;
					}

					}

				}

			}
			//계속연속인경우
			else
			{
			

				switch (move->trait)
				{
				case 'r':
				{

					if (move->x + 1 < limit + 1)
					{
						if (board[move->y][move->x + 1] == '+')
							fboard[move->y][move->x + 1] += move->count * weight;

					}
					if (move->x - move->count > -1)
					{
						if (board[move->y][move->x - move->count] == '+')
							fboard[move->y][move->x - move->count] += move->count * weight;
					}
					break;
				}
				case 'c':
				{
					if (move->y + 1 < 19)
					{
						if (board[move->y + 1][move->x] == '+')
							fboard[move->y + 1][move->x] += move->count * weight;
					}
					if (move->y - move->count > -1)
					{
						if (board[move->y - move->count][move->x] == '+')
							fboard[move->y - move->count][move->x] += move->count * weight;
					}
					break;
				}
				case 'x':
				{
					if (move->y + 1 < 19 && move->x + 1 < 19)
					{
						if (board[move->y + 1][move->x + 1] == '+')
							fboard[move->y + 1][move->x + 1] += move->count * weight;
					}
					if (move->y - move->count > -1 && move->x - move->count > -1)
					{
						if (board[move->y - move->count][move->x - move->count] == '+')
							fboard[move->y - move->count][move->x - move->count] += move->count * weight;
					}
					break;
				}
				case 's':
				{
					if (move->y + 1 < 19 && move->x > -1)
					{
						if (board[move->y + 1][move->x - 1] == '+')
							fboard[move->y + 1][move->x - 1] += move->count * weight;
					}
					if (move->y - move->count > -1 && move->x + move->count < 19)
					{
						if (board[move->y - move->count][move->x + move->count] == '+')
							fboard[move->y - move->count][move->x + move->count] += move->count * weight;
					}

					break;
				}
				}


			}

			delete move;
			move = advstack;
		}

	}





}
void Initial_AI(stonetrait* value)
{
	static int seed = 0;
	seed++;
	if (seed == 327000)
	{
		seed = 0;
	}
	srand(unsigned int(time(NULL) % 327 + seed));
	double maxvalue = 0;
	valueboard(value);
	int oneplay = 1;
	while ((!(in_x > -1 && in_x < 19) || !(in_y > -1 && in_y < 19)) ||oneplay)
	{
		if (!(in_x>-1&&in_x<19)||! (in_y>-1 && in_y < 19))
		{

			searchvacumn();
			dohan.x = in_x;
			dohan.y = in_y;

		}



		for (int y = 0; y < limit; ++y)
		{

			for (int x = 0; x < limit; ++x)
			{
				if (fboard[y][x] != 1000)
				{
					if (fboard[y][x] > maxvalue)
					{
						maxvalue = fboard[y][x];
					}
				}
			}
		}
		


			if (maxvalue > 13)
			{ 	//방어

				for (int y = 0; y < limit; ++y)
				{
					for (int x = 0; x < limit; ++x)
					{
						if (fboard[y][x] != 0)
						{
							if (fboard[y][x] == maxvalue)
							{
								if (board[y][x] == '+')
								{
									in_y = y;
									in_x = x;
									break;
								}
							}
						}
					}

				}
				dohan.attack = 0;
			}
			else
			{
				
				
				 if (dohan.select_dir == 1)
				{
					if (order == 0 || order == 1)
					{
						if (rand() % 2 == 0)
						{
							in_x = 9 + 1;
							in_y = 9 + 1;
						}
						else
						{
							in_x = 9 - 1;
							in_y = 9 - 1;
						}
						dohan.x = in_x;
						dohan.y = in_y;

						while (dohan.dir == 0)
						{
							dohan.dir = rand() % 10;
							if ((dohan.dir == 5))
							{
								dohan.dir -= (rand() % 2 + 1);
							}
						}
					}
					else {

					
						dohan.x -= rand() % 3;
						dohan.y -= rand() % 3;

						in_y = dohan.y;
						in_x = dohan.x;


						while (dohan.dir == 0)
						{
							dohan.dir = rand() % 10;
							if ((dohan.dir == 5))
							{
								dohan.dir -= (rand() % 2 + 1);
							}
						}


					}
					dohan.select_dir = 0;
				}
				else {

					while (dohan.dir == 0)
					{
						dohan.dir = rand() % 9+1;
						if ((dohan.dir == 5))
						{
							dohan.dir -= (rand() % 2 + 1);
						}
					}

					in_y = dohan.y;
					in_x = dohan.x;
					switch (dohan.dir)
					{
					case 1:
						in_y++;
						in_x--;
						break;
					case 2:
						in_y++;
						break;
					case 3:
						in_y++;
						in_x++;
						break;
					case 4:
						in_x--;
						break;
					case 6:
						in_x++;
						break;
					case 7:
						in_x--;
						in_y--;
						break;
					case 8:
						in_y--;
						break;
					case 9:
						in_x++;
						in_y--;
						break;
					}


				}
				dohan.attack = 1;
			}

		
		oneplay = 0;
	}
}
void Initial_AI2(stonetrait* value)
{

	static int seed2 = 0;
	seed2++;
	if (seed2 == 327000)
	{
		seed2 = 0;
	}
	srand(unsigned int(time(NULL) %327+seed2));
	double maxvalue = 0;
	valueboard2(value);
	pair<int, int> mTestPosition;
	int oneplay = 1;
	for (int y = 0; y < limit; ++y)
	{

		for (int x = 0; x < limit; ++x)
		{
			if (fboard[y][x] != 1000)
			{
				if (fboard[y][x] > maxvalue)
				{
					maxvalue = fboard[y][x];
				}
			}
		}
	}
	
	while ((!(in_x > -1 && in_x < 19) || !(in_y > -1 && in_y < 19)) || oneplay)
	{
		
	

		if (!(in_x > -1 && in_x < 19) || !(in_y > -1 && in_y < 19))
		{

			searchvacumn();
			dohan2.x = in_x;
			dohan2.y = in_y;

		}
	
		if (maxvalue > 13)
		{ 	//방어

			for (int y = 0; y < limit; ++y) {
				for (int x = 0; x < limit; ++x)
				{
					if (fboard[y][x] != 0)
					{
						if (fboard[y][x] == maxvalue)
						{
							
							in_y = y;
							in_x = x;
							
							break;
						}
					}
				}
			}
			dohan2.attack = 0;

		}
		else
		{
			

			 if (dohan2.select_dir == 1)
			{   //아예 선택될 길이 없을때
				if (order == 0 || order == 1)
				{
					if (rand() % 3 == 0)
					{
						in_x = 9 -1;
						
					}
					else if (rand() % 3 == 1)
					{
						in_x = 9 ;
					
					}
					else
					{
						in_x = 9+1;
					
					}
					if (rand() % 3 == 0)
					{
						in_y = 9 - 1;

					}
					else if (rand() % 3 == 1)
					{
						in_y = 9;

					}
					else
					{
						in_y = 9 + 1;

					}
					dohan2.x = in_x;
					dohan2.y = in_y;

					while (dohan2.dir == 0)
					{
						dohan2.dir = rand() % 9 + 1;
						if ((dohan2.dir == 5))
						{
							if (rand() % 2 == 0)
							{
								dohan2.dir -= (rand() % 2 + 1);
							}
							else
							{
								dohan2.dir += (rand() % 2 + 1);
							}
						}
					}
				}
				else
				{
					if (rand() % 2 == 0)
					{
						dohan2.x += rand() % 4;

					}
					else
					{
						dohan2.x -= rand() % 4;
					
					}
					if (rand() % 2 == 0)
					{

						dohan2.y += rand() % 4;
					}
					else
					{
						
						dohan2.y -= rand() % 4;
					}
					in_x = dohan2.x;
					in_y = dohan2.y;

					while (dohan2.dir == 0)
					{
						dohan2.dir = rand() % 9 + 1;
						if ((dohan2.dir == 5))
						{
							if (rand() % 2 == 0)
							{
								dohan2.dir -= (rand() % 2 + 1);
							}
							else
							{
								dohan2.dir += (rand() % 2 + 1);
							}
						}
					}
				}
				dohan2.select_dir = 0;
			}
			//공격
			else {

				if(dohan2.dir == 0)
				{
					dohan2.dir = rand() % 9+1;
					if ((dohan2.dir == 5))
					{
						if (rand() % 2 == 0)
						{
							dohan2.dir -= (rand() % 2 + 1);
						}
						else
						{
							dohan2.dir += (rand() % 2 + 1);
						}
					}
				}

				in_y = dohan2.y;
				in_x = dohan2.x;
				switch (dohan2.dir)
				{
				case 1:
					in_y++;
					in_x--;
					break;
				case 2:
					in_y++;
					break;
				case 3:
					in_y++;
					in_x++;
					break;
				case 4:
					in_x--;
					break;
				case 6:
					in_x++;
					break;
				case 7:
					in_x--;
					in_y--;
					break;
				case 8:
					in_y--;
					break;
				case 9:
					in_x++;
					in_y--;
					break;
				}


			}
			 dohan2.attack = 1;

		

			
		}

	
	

	oneplay = 0;
	
	}

}



//흰돌		1
//검은돌	-1





//white
void play() {



	while (true)
	{
	
		
			squence();
			Initial_AI(advstack);
			if (board[in_y][in_x] == '0' || board[in_y][in_x] == '@')
			{
				//std::cout << "이미 놓여진 돌입니다. 다시입력해주세요" << std::endl;
				dohan.dir = 0;

				dohan.count_dir++;
				if (dohan.count_dir == 2)
				{
					dohan.select_dir = 1;
					dohan.count_dir = 0;
				}
			}
			
			else {

				if (order % 2 == 0)
				{
					board[in_y][in_x] = '@';
				}
				else
				{
					board[in_y][in_x] = '0';
				}

				if (dohan.attack == 1)
				{
					dohan.x = in_x;
					dohan.y = in_y;
				}
				user1_cnt++;
				++order;
				break;
			}


		
	}


}
//black
void play2() {
	

	while (true)
	{

	
		//1플레이어
		
			squence();
			Initial_AI2(advstack);
			if (board[in_y][in_x] == '0' || board[in_y][in_x] == '@')
			{
				//std::cout << "이미 놓여진 돌입니다. 다시입력해주세요" << std::endl;
				dohan2.dir = 0;
				dohan2.count_dir++;
				if (dohan2.count_dir == 2)
				{

					

					dohan2.select_dir = 1;
					dohan2.count_dir = 0;
				}
			}
			else {

				if (order % 2 == 0)
				{
					board[in_y][in_x] = '@';
				}
				else
				{
					board[in_y][in_x] = '0';
				}

				if (dohan2.attack == 1)
				{
					dohan2.x = in_x;
					dohan2.y = in_y;
				}
				user2_cnt++;
				++order;
				break;
			}


		
	}


}


//화이트
void WhiteAttack_2019180006(int* x, int* y)
{
	// 직접 구현하신 돌 놓기 로직을 넣어주세요
	/*if (order ==1)
	{
		setb();
	}*/

	play();

	// 예시로 항상 [5,5]에만 돌을 두게함
	*x = in_x;
	*y = in_y;

	board_2019180006[*y][*x] = WHITE;
}
void WhiteDefence_2019180006(int x, int y)
{
	// 상대가 놓은 돌의 위치를 전달받아서 저장합니다
	if (order ==0)
	{
		setb();
	}
	board[y][x] = '@';
	order++;
	
	board_2019180006[y][x] = BLACK;
}
//블랙
void BlackAttack_2019180006(int* x, int* y)
{
	
	// 직접 구현하신 돌 놓기 로직을 넣어주세요
	if (order == 0)
	{
		setb();
	}
	play2();
	
	// 예시로 항상 [5,5]에만 돌을 두게함
	*x = in_x;
	*y = in_y;

	board_2019180006[*y][*x] = BLACK;
}
void BlackDefence_2019180006(int x, int y)
{
	if (order == 0)
	{
		setb();
	}

	in_x = x;
	in_y = y;
	board[y][x] = '0';
	order++;
	
	// 상대가 놓은 돌의 위치를 전달받아서 저장합니다
	board_2019180006[y][x] = WHITE;
}