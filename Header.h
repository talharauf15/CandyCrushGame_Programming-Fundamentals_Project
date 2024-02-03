#include <iostream>
#include <Windows.h>//Including windows library
#include<string>//Including string library
#include <fstream>//Including file input output stream library
using namespace std;
int number, bomb=0;//Declaring integer global variables 
int Bomb (int row, int column, char arr[][12], int size,int& bomb,int& move,int& Score);//Creating a prototype
void change(char arr[][12], int size);//Creating a prototype
int checking(char arr[][12], int size,int row1,int column1, int& score,int& message);//Creating a prototype
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//It is used to handle the output i use it to add colors to screen output
//This Fuction is used to maximize the console output screen 
void conslemaximize() {
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}
/*This is the integer type function which return 1 and 0 and taking character array and size as parameters
This fuction is used to check the cosective three or more then three candies in game board This fuction check the candies of board in rows and columns 
this fucction changes the three or more then three consective candies in columns to 1 and candies in rows to 0 which is easy to replace into candies,First it check candies in columns then in rows*/
int checking2(char arr[][12], int size)
{
	int count = 0;
	int column = 0;
	int row = 0;
	bool found = false;
	while (column < size)
	{
		int temp = row;
		count = 0;
		while (temp < size)
		{
			count = 0;
			if (arr[temp][column] == arr[temp + 1][column])
			{
				while (((arr[temp][column] == arr[temp + 1][column]) && temp < size))
				{
					count = count + 1;
					temp = temp + 1;
				}
				if (count > 1)
				{
					int temp1 = temp;
					while (count >= 0)
					{
						found = true;
						arr[temp1][column] = '1';
						count = count - 1;
						temp1 = temp1 - 1;
					}
				}
			}
			else
				temp = temp + 1;
		}
		column = column + 1;
	}
	column = 0;
	row = 0;
	while (row < size)
	{
		count = 0;
		int temp = column;
		while (temp < size - 1)
		{
			count = 0;
			if (arr[row][temp] == arr[row][temp + 1])
			{
				while (((arr[row][temp] == arr[row][temp + 1]) && temp < size - 1))
				{
					count = count + 1;
					temp = temp + 1;
				}
				if (count > 1)
				{
					int temp1 = temp;
					while (count >= 0)
					{
						found = true;
						arr[row][temp1] = '0';
						count = count - 1;
						temp1 = temp1 - 1;
					}
				}
			}
			else
				temp = temp + 1;
		}
		row = row + 1;
	}
	if (found == false)
		return 1;
	else
		return 0;
}
/*This is the void function which return nothing but take character array,size of array,Time ,move, and score as arguments
This function is used to print the easy bard in game with different colors using textAttribute command*/
void Easy(char arr[][12], int size,int TIME,int MOVE,int Score)
{
	cout << endl;
	SetConsoleTextAttribute(h, 6);
	cout << setw(94) << "<======= EASY MODE =======>" << endl;
	SetConsoleTextAttribute(h, 14);
	for (int i = 1; i < 168; i++)
	{
		cout << "_";
	}
	cout << endl << endl;
	SetConsoleTextAttribute(h, 13);
	cout << setw(85) << "TIME  :   " << TIME << " s" << endl << endl;
	SetConsoleTextAttribute(h, 3);
	cout << setw(85) << "MOVES :   " << MOVE << endl << endl;
	SetConsoleTextAttribute(h, 10);
	cout << setw(85) << "SCORE :   " << Score << endl << endl;
	SetConsoleTextAttribute(h, 14);
	for (int i = 1; i < 168; i++)
	{
		cout << "-";
	}
	cout << endl;
	SetConsoleTextAttribute(h, 15);
	cout << "\t\t\t\t\t\t    1       2       3       4       5       6       7       8   \n";
	cout << "\t\t\t\t\t\t _______________________________________________________________\n";
	for (int i = 0; i < 8; i++)
	{
		cout << "\t\t\t\t\t\t|       |       |       |       |       |       |       |       |";
		cout << "\n";
		cout << "\t\t\t\t\t     "<< i+1 << "  |   ";
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == '@')
				SetConsoleTextAttribute(h, 6);
			if (arr[i][j] == '#')
				SetConsoleTextAttribute(h, 5);
			if (arr[i][j] == '&')
				SetConsoleTextAttribute(h, 12);
			if (arr[i][j] == '$')
				SetConsoleTextAttribute(h, 10);
			if (arr[i][j] == '%')
				SetConsoleTextAttribute(h, 9);
			if (arr[i][j] == 'H')
				SetConsoleTextAttribute(h, 4);
			if (arr[i][j] == 'B')
				SetConsoleTextAttribute(h, 15);
			cout << arr[i][j];
			SetConsoleTextAttribute(h, 15);
			cout << "   |   ";
		}
		cout << endl;
		cout << "\t\t\t\t\t\t|_______|_______|_______|_______|_______|_______|_______|_______|\n";
	}
	SetConsoleTextAttribute(h, 14);
	for (int i = 1; i < 168; i++)
	{
		cout << "_";
	}
	SetConsoleTextAttribute(h, 15);
	cout << endl;
}
/*This is the void function which return nothing but take character array,size of array,Time ,move, and score as arguments
This function is used to print the Hard bard in game with different colors using textAttribute command*/
void Hard(char arr2[][12], int size, int TIME, int MOVE, int Score)
{
	cout << endl;
	SetConsoleTextAttribute(h, 6);
	cout << setw(94) << "<======= HARD MODE =======>" << endl;
	SetConsoleTextAttribute(h, 14);
	for (int i = 1; i < 168; i++)
	{
		cout << "_";
	}
	//SetConsoleTextAttribute(h, 15);
	cout << endl << endl;
	SetConsoleTextAttribute(h, 13);
	cout << setw(85) << "TIME  :   " << TIME << " s" << endl << endl;
	SetConsoleTextAttribute(h, 3);
	cout << setw(85) << "MOVES :   " << MOVE << endl << endl;
	SetConsoleTextAttribute(h, 10);
	cout << setw(85) << "SCORE :   " << Score << endl << endl;
	SetConsoleTextAttribute(h, 14);
	for (int i = 1; i < 168; i++)
	{
		cout << "-";
	}
	cout << endl;
	SetConsoleTextAttribute(h, 15);
	cout << "\t\t\t\t    1       2       3       4       5       6       7       8       9      10      11      12    \n";
	cout << "\t\t\t\t _______________________________________________________________________________________________\n";
	for (int i = 0; i < 12; i++)
	{
		cout << "\t\t\t\t|       |       |       |       |       |       |       |       |       |       |       |       |";
		cout << "\n";
		if (i < 9)
			cout << "\t\t\t    " << i + 1 << "   |   ";
		else
			cout << "\t\t\t    " << i + 1 << "  |   ";
		for (int j = 0; j < 12; j++)
		{
			if (arr2[i][j] == '@')
				SetConsoleTextAttribute(h, 6);
			if (arr2[i][j] == '#')
				SetConsoleTextAttribute(h, 5);
			if (arr2[i][j] == '&')
				SetConsoleTextAttribute(h, 12);
			if (arr2[i][j] == '$')
				SetConsoleTextAttribute(h, 10);
			if (arr2[i][j] == '%')
				SetConsoleTextAttribute(h, 9);
			if (arr2[i][j] == 'H')
				SetConsoleTextAttribute(h, 4);
			if (arr2[i][j] == '!')
				SetConsoleTextAttribute(h, 14);
			if (arr2[i][j] == '0')
				SetConsoleTextAttribute(h, 2);
			if (arr2[i][j] == '?')
				SetConsoleTextAttribute(h, 11);
			if (arr2[i][j] == 'B')
				SetConsoleTextAttribute(h, 15);
			cout << arr2[i][j];
			SetConsoleTextAttribute(h, 15);
			cout << "   |   ";
		}
		cout << endl;
		cout << "\t\t\t\t|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n";
	}
	SetConsoleTextAttribute(h, 14);
	for (int i = 1; i < 168; i++)
	{
		cout << "_";
	}
	SetConsoleTextAttribute(h, 15);
	cout << endl;
}
/*This function is the integer fuction which return 0 and have no arrguments.This function is used to take input 
the movement of candy up, down, right and left*/
int input()
{
	SetConsoleTextAttribute(h, 15);
	cout << "\n\n";
	cout << setw(94) << "* Press 1 to move candy UP:";
	cout << "\n\n";
	cout << setw(96) << "* Press 2 to move candy DOWN:";
	cout << "\n\n";
	cout << setw(96) << "* Press 3 to move candy LEFT:";
	cout << "\n\n";
	cout << setw(98) << "* Press 4 to move candy RIGHT: ";
	cout << "\n\n";
	cout << setw(93) << "Input The Number Here:";
	while (!(cin >> number))//Run loop until user enter correct input
	{
		SetConsoleTextAttribute(h, 4);
		cout << setw(93) << "Input the number Again:";
		cin.clear();//If output is not correct then clear the input 
		cin.ignore();
	}
	return 0;
	SetConsoleTextAttribute(h, 15);
}
/*This the integer function named as swap taking reference integer move,pass by row,column character array and size of array and refernce Score
This function is sued to swap the candy this function first check the That the input is validate means first it check that the the two up and two down 
and two left and two right candies of array if three candies will make then this fuction changes the the candies and swap it and also it 
Check the bomb candy also that is it used or not*/
int swap(int& move, int row, int column, char arr1[][12], int size,int& Score)
{
	SetConsoleTextAttribute(h, 4);
	bomb = 0;
	if (arr1[row-1][column-1] != 'B')
	{
		row = row - 1;
		column = column - 1;
		char ch = arr1[row][column];
		if (number == 1 || number == 2)
		{
			int r1 = 0, r2 = 0, r3 = 0, r4 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0;
			if (number == 1)
			{
				r1 = row - 2, r2 = row - 3, r3 = row - 1;
				c1 = column + 1, c2 = column + 2, c3 = column - 1, c4 = column - 2;
			}
			if (number == 2)
			{
				r1 = row + 2, r2 = row + 3, r3 = row + 1;
				c1 = column + 1, c2 = column + 2, c3 = column - 1, c4 = column - 2;
			}
			if ((arr1[row][column] == arr1[r1][column]) && (arr1[row][column] == arr1[r2][column]))
			{
				if (arr1[r3][column] != 'H')
				{
					arr1[row][column] = arr1[r3][column];
					arr1[r3][column] = ch;
					sndPlaySound(TEXT("candyland.wav"), SND_FILENAME | SND_ASYNC);
				}
				else
				{
					move = move + 1;
					cout << "\n";
					cout << setw(109) << "!!!!!!!!!! You can not swap Candy with Hardles!!!!!!!!!!" << "\n";
					Sleep(2000);
				}
			}
			else if ((arr1[row][column] == arr1[r3][c1]) && (arr1[row][column] == arr1[r3][c2]))
			{
				if (arr1[r3][column] != 'H')
				{
					sndPlaySound(TEXT("candyland.wav"), SND_FILENAME | SND_ASYNC);
					arr1[row][column] = arr1[r3][column];
					arr1[r3][column] = ch;
				}
				else
				{
					move = move + 1;
					cout << "\n";
					cout << setw(109) << "!!!!!!!!!! You can not swap Candy with Hardles!!!!!!!!!!" << "\n";
					Sleep(2000);
				}
			}
			else if (arr1[row][column] == arr1[r3][c3] && arr1[row][column] == arr1[r3][c4])
			{
				if (arr1[r3][column] != 'H')
				{
					sndPlaySound(TEXT("candyland.wav"), SND_FILENAME | SND_ASYNC);
					arr1[row][column] = arr1[r3][column];
					arr1[r3][column] = ch;
				}
				else
				{
					move = move + 1;
					cout << "\n";
					cout << setw(109) << "!!!!!!!!!! You can not swap Candy with Hardles!!!!!!!!!!" << "\n";
					Sleep(2000);
				}
			}
			else if (arr1[row][column] == arr1[r3][c3] && arr1[row][column] == arr1[r3][c1])
			{
				if (arr1[r3][column] != 'H')
				{
					sndPlaySound(TEXT("candyland.wav"), SND_FILENAME | SND_ASYNC);
					arr1[row][column] = arr1[r3][column];
					arr1[r3][column] = ch;
				}
				else
				{
					move = move + 1;
					cout << "\n";
					cout << setw(109) << "!!!!!!!!!! You can not swap Candy with Hardles!!!!!!!!!!" << "\n";
					Sleep(2000);
				}
			}
			else
			{
				move = move + 1;
				cout << "\n";
				if (number == 1)
					cout << setw(109) << "!!!!!!!!!! You can not swap this candy to UP !!!!!!!!!! " << "\n";
				if (number == 2)
					cout << setw(109) << "!!!!!!!!!! You can not swap this candy to DOWN !!!!!!!!!! " << "\n";
				Sleep(2000);
			}
		}
		if (number == 3 || number == 4)
		{
			int r1 = 0, r2 = 0, r3 = 0, r4 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0;
			if (number == 3)
			{
				r1 = row - 1, r2 = row - 2, r3 = row + 1, r4 = row + 2;
				c1 = column - 2, c2 = column - 3, c3 = column - 1;
			}
			if (number == 4)
			{
				r1 = row - 1, r2 = row - 2, r3 = row + 1, r4 = row + 2;
				c1 = column + 2, c2 = column + 3, c3 = column + 1;
			}
			if ((arr1[row][column] == arr1[row][c1]) && (arr1[row][column] == arr1[row][c2]))
			{
				if (arr1[row][c3] != 'H')
				{
					sndPlaySound(TEXT("candyland.wav"), SND_FILENAME | SND_ASYNC);
					arr1[row][column] = arr1[row][c3];
					arr1[row][c3] = ch;
				}
				else
				{
					move = move + 1;
					cout << "\n";
					cout << setw(109) << "!!!!!!!!!! You can not swap Candy with Hardles!!!!!!!!!!" << "\n";
					Sleep(2000);
				}
			}
			else if ((arr1[row][column] == arr1[r1][c3]) && (arr1[row][column] == arr1[r2][c3]))
			{
				if (arr1[row][c3] != 'H')
				{
					sndPlaySound(TEXT("candyland.wav"), SND_FILENAME | SND_ASYNC);
					arr1[row][column] = arr1[row][c3];
					arr1[row][c3] = ch;
				}
				else
				{
					move = move + 1;
					cout << "\n";
					cout << setw(109) << "!!!!!!!!!! You can not swap Candy with Hardles!!!!!!!!!!" << "\n";
					Sleep(2000);
				}
			}
			else if (arr1[row][column] == arr1[r3][c3] && arr1[row][column] == arr1[r4][c3])
			{
				if (arr1[row][c3] != 'H')
				{
					sndPlaySound(TEXT("candyland.wav"), SND_FILENAME | SND_ASYNC);
					arr1[row][column] = arr1[row][c3];
					arr1[row][c3] = ch;
				}
				else
				{
					move = move + 1;
					cout << "\n";
					cout << setw(109) << "!!!!!!!!!! You can not swap Candy with Hardles!!!!!!!!!!" << "\n";
					Sleep(2000);
				}
			}
			else if (arr1[row][column] == arr1[r1][c3] && arr1[row][column] == arr1[r3][c3])
			{
				if (arr1[row][c3] != 'H')
				{
					sndPlaySound(TEXT("candyland.wav"), SND_FILENAME | SND_ASYNC);
					arr1[row][column] = arr1[row][c3];
					arr1[row][c3] = ch;
				}
				else
				{
					move = move + 1;
					cout << "\n";
					cout << setw(109) << "!!!!!!!!!! You can not swap Candy with Hardles!!!!!!!!!!" << "\n";
					Sleep(2000);
				}
			}
			else
			{
				move = move + 1;
				cout << "\n";
				if (number == 3)
					cout << setw(109) << "!!!!!!!!!! You can not swap this candy to LEFT !!!!!!!!!! " << "\n";
				if (number == 4)
					cout << setw(109) << "!!!!!!!!!! You can not swap this candy to Right !!!!!!!!!! " << "\n";
				Sleep(2000);
			}
		}
	}
	else
	{
		Bomb(row, column, arr1, size,bomb,move,Score);
		change(arr1, size);
	}
	return 0;
}
/* This function is the integer function which take move, num1,score,num in refernce and Cahracter array time size as arrguments
This fuction calls another six function easy,hard,swap,checking,change and input
This fuction is the important fucntion beacause it call all fuction and also check borad until three candies are not in row and candies
Also i add sound in with all massages which show on console by sndplaysound function which plays .wav formats sounds*/
int inputchecker(int& move, int& num, int row, int column, char arr1[][12], int size, int& num1, int& score,int Time)
{
	SetConsoleTextAttribute(h, 6);
	num1 = 0;
	num = 1;
	bool found = false;
	int found1 = 0;
	int count1 = 0;
	if (arr1[row - 1][column - 1] != 'H')
	{
		while (!found)
		{
			system("cls");
			if (size == 8)
				Easy(arr1, 8, Time, move, score);
			else
				Hard(arr1, 12, Time, move, score);
			input();
			swap(move,row, column, arr1, size,score);
			Sleep(300);
			found = true;
			int count=0;
			while (found1 == 0)
			{
				int message = 0;
				found1 = checking(arr1, size, row, column, score, message);
				change(arr1, size);
				if (count >= 1)
				{
					sndPlaySound(TEXT("candyland.wav"), SND_FILENAME | SND_ASYNC);
				}
				if (message == 2&& bomb == 0)
				{
					system("cls");
					if (size == 8)
						Easy(arr1, 8, Time, move, score);
					else
						Hard(arr1, 12, Time, move, score);
					Sleep(300);
					cout << endl;
					cout << setw(94) << "<<----- Delicious ----->>";
					sndPlaySound(TEXT("delicious.wav"), SND_FILENAME | SND_ASYNC);
					Sleep(1500);
				}
				else if (message == 1 && bomb == 0)
				{
					system("cls");
					if (size == 8)
						Easy(arr1, 8, Time, move, score);
					else
						Hard(arr1, 12, Time, move, score);
					Sleep(300);
					cout << endl;
					cout << setw(92) << "<<----- SWEET ----->>";
					sndPlaySound(TEXT("sweet.wav"), SND_FILENAME | SND_ASYNC);
					Sleep(1500);
				}
				if (bomb == 1&&count1==0)
				{
					system("cls");
					if (size == 8)
						Easy(arr1, 8, Time, move, score);
					else
						Hard(arr1, 12, Time, move, score);
					Sleep(300);
					cout << endl;
					sndPlaySound(TEXT("divine.wav"), SND_FILENAME | SND_ASYNC);
					cout << setw(92) << " <<----- DIVINE ----->>";
					Sleep(1800);
					count1 = count1 + 1;
				}
				count = count + 1;
			}
		}
		num = -1;
		move = move - 1;
	}
	else
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\n";
		cout << setw(107) << "!!!!!!!!!! You can not swap Hardles Candy !!!!!!!!!!" << "\n";
	}
	SetConsoleTextAttribute(h, 15);
	return 0;
}
/* This function is the integer function which take move, num1,num in refernce and Cahracter array, time,score, size as arrguments
This function check that wheater user enter input is correct or not means row and column*/
int check1(int& num1, int& num, int row, int column, char arr1[][12], int size, int Time,int move, int score)
{
	num1 = 0;
	num = 0;
	system("cls");
	if (size == 8)
		Easy(arr1, 8, Time, move, score);
	else
		Hard(arr1, 12, Time, move, score);
	SetConsoleTextAttribute(h, 4);
	if (row < 1 || row>size)
	{
		cout << setw(118) << "!!!!!!!!!! You enter wrong row of swappable candy so Enter Again !!!!!!!!!!" << "\n";
	}
	if (column < 1 || column>size)
	{
		cout << "\n\n";
		cout << setw(119) << "!!!!!!!!!! You enter wrong column of swappable candy so Enter Again !!!!!!!!!!" << "\n";
	}
	if ((row > 0 && row < size+1) && (column > 0 && column < size+1))
	{
		num = -1;
	}
	SetConsoleTextAttribute(h, 15);
	return 0;
}
/* This function is the integer function which take message,score in refernce and Cahracter array, size,row and column as arrguments
This function check the three or more candies in row and columns and chage them to 0 and 1 also it changes the candies in bomb*/
int checking(char arr[][12], int size,int row1,int column1, int& score,int& message)
{
	int count = 0;
	int column = 0;
	int row = 0;
	bool found = false;
	while (column < size)
	{
		int temp = row;
		count = 0;
		while (temp < size)
		{
			count = 0;
			if (arr[temp][column] == arr[temp + 1][column])
			{
				while (((arr[temp][column] == arr[temp + 1][column]) && temp < size))
				{
					count = count + 1;
					temp = temp + 1;
				}
				if (count > 1)
				{
					if (count == 2 && bomb == 0)
					{
						score = score + 10;
						message = 1;
					}
					else if (count > 2 && bomb == 0)
					{
						sndPlaySound(TEXT("colour_bomb_created.wav"), SND_FILENAME | SND_ASYNC);
						message = 2;
						score = score + 20;
						if (number == 1)
							arr[row1 - 2][column1 - 1] = 'B';
						else if (number == 2)
							arr[row1][column1 - 1] = 'B';
						else if (number == 3)
							arr[row1 - 1][column1 - 2] = 'B';
						else
							arr[row1 - 1][column1] = 'B';
					}
					int temp1 = temp;
					while (count >= 0)
					{
						found = true;
						if (arr[temp1][column] != 'B')
							arr[temp1][column] = '1';
						count = count - 1;
						temp1 = temp1 - 1;
					}
				}
			}
			else
				temp = temp + 1;
		}
		column = column + 1;
	}
	column = 0;
	row = 0;
	while (row < size)
	{
		count = 0;
		int temp = column;
		while (temp < size-1)
		{
			count = 0;
			if (arr[row][temp] == arr[row][temp + 1])
			{
				while (((arr[row][temp] == arr[row][temp + 1]) && temp < size-1))
				{
					count = count + 1;
					temp = temp + 1;
				}
				if (count > 1)
				{
					if (count == 2 && bomb == 0)
					{
						message = 1;
						score = score + 10;
					}
					else if (count > 2 && bomb == 0)
					{
						sndPlaySound(TEXT("colour_bomb_created.wav"), SND_FILENAME | SND_ASYNC);
						message = 2;
						score = score + 20;
						if (number == 1)
						{
							arr[row1 - 2][column1 - 1] = 'B';
						}
						else if (number == 2)
						{
							arr[row1][column1 - 1] = 'B';
						}
						else if (number == 3)
						{
							arr[row1 - 1][column1 - 2] = 'B';
						}
						else
							arr[row1-1][column1] = 'B';
					}
					int temp1 = temp;
					while (count >= 0)
					{
						found = true;
						if (arr[row][temp1] != 'B')
							arr[row][temp1] = '0';
						count = count - 1;
						temp1 = temp1 - 1;
					}
				}
			}
			else
				temp = temp + 1;
		}
		row = row + 1;
	}
	if (found == false)
		return 1;
	else
		return 0;
}
/*This void function only change 0 and 1 candy to speacil character like candy*/
void change(char arr[][12], int size)
{
	char ch;
	int candy;
	srand(time(0));
	if (size == 8)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				candy = rand() % 38 + 35;
				if (candy == 35 || candy == 36 || candy == 37 || candy == 38 || candy == 64)
				{
					if (arr[i][j] == '1' || arr[i][j] == '0')
					{
						ch = static_cast<char>(candy);
						arr[i][j] = ch;
					}
				}
				else
					j--;
			}
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				candy = rand() % 40 + 33;
				if (candy == 33 || candy == 63 || candy == 48 || candy == 35 || candy == 36 || candy == 37 || candy == 38 || candy == 64)
				{
					if (arr[i][j] == '1' || arr[i][j] == '0')
					{
						ch = static_cast<char>(candy);
						arr[i][j] = ch;
					}
				}
				else
					j--;
			}
		}
	}
}
/*This is the integer function named as bomb which take bomb,move and score as reference arrguments androw and column as integer argumentsand return 0
This fuction checks that wheter the user select bomb and swap it on right place means check that is bomb swap with hardles or not
if user select 1 candy it can not swap up and left and so on if bomb is valid then it changes the row in 1 and column in 0*/
int Bomb(int row, int column,char arr[][12],int size,int& bomb,int& move,int& Score)
{
	SetConsoleTextAttribute(h, 4);
	int count=0;
	row = row - 1;
	column = column - 1;
	if (number == 1)
	{
		if(arr[row - 1][column] != 'H'&& row!=0)
		{
			count = 1;
			sndPlaySound(TEXT("colour_bomb1.wav"), SND_FILENAME | SND_ASYNC);
			for (int i = 0; i < size; i++)
			{
				arr[i][column] = '1';
			}
			for (int j = 0; j < size; j++)
			{
				arr[row-1][j] = '0';
			}
			Sleep(600);
			Score = Score + 30;
			bomb = 1;
		}
		else
		{
			cout << "\n";
			cout << setw(108) << "!!!!!!!!!! You can not swap this candy to UP !!!!!!!!!! " << "\n";
			Sleep(800);
			move = move + 1;
		}
	}
	else if (number == 2)
	{
		if(arr[row+1][column] != 'H' && row != size-1)
		{
			count = 1;
			sndPlaySound(TEXT("colour_bomb1.wav"), SND_FILENAME | SND_ASYNC);
			for (int i = 0; i < size; i++)
			{
				arr[i][column] = '1';
			}
			for (int j = 0; j < size; j++)
			{
				arr[row + 1][j] = '0';
			}
			Sleep(600);
			Score = Score + 30;
			bomb = 1;
		}
		else
		{
			cout << "\n";
			cout << setw(109) << "!!!!!!!!!! You can not swap this candy to DOWN !!!!!!!!!! " << "\n";
			Sleep(800);
			move = move + 1;
		}
	}
	else if (number == 3)
	{
		if(arr[row][column - 1] != 'H' && column != 0)
		{
			count = 1;
			sndPlaySound(TEXT("colour_bomb1.wav"), SND_FILENAME | SND_ASYNC);
			for (int i = 0; i < size; i++)
			{
				arr[row][i] = '0';
			}
			for (int j = 0; j < size; j++)
			{
				arr[j][column-1] = '1';
			}
			Sleep(600);
			Score = Score + 30;
			bomb = 1;
		}
		else
		{
			cout << "\n";
			cout << setw(109) << "!!!!!!!!!! You can not swap this candy to LEFT !!!!!!!!!! " << "\n";
			Sleep(800);
			move = move + 1;
		}
	}
	else
		if (arr[row][column + 1] != 'H' && column != size-1)
		{
			count = 1;
			sndPlaySound(TEXT("colour_bomb1.wav"), SND_FILENAME | SND_ASYNC);
			for (int i = 0; i < size; i++)
			{
				arr[row][i] = '0';
			}
			for (int j = 0; j < size; j++)
			{
				arr[j][column + 1] = '1';
			}
			Sleep(600);
			Score = Score + 30;
			bomb = 1;
		}
		else
		{
			cout << "\n";
			cout << setw(109) << "!!!!!!!!!! You can not swap this candy to RIGHT !!!!!!!!!!" << "\n";
			Sleep(800);
			move = move + 1;
		}
	SetConsoleTextAttribute(h, 15);
	return 0;
}
/*This function is the integer which return check or 0 integer and take arguments as integer array,size,Score,string name and string values as reference
This function check that if score is greter or not than other stored three scores in array and change them and also change name according 
to score*/
int scorechecker(int score[], int size, int Score, string name, string& name1, string& name2, string& name3)
{
	int temp, temp2;
	int i, check = 0, sure = 0;
	for (i = 0; i < 3; i++)
	{
		if (Score > score[i])
		{
			temp = score[i];
			score[i] = Score;
			temp2 = score[i + 1];
			score[i + 1] = temp;
			score[i + 2] = temp2;
			check = check + 1;
			i = 3;
			sure = 1;
		}
		else
			check = check + 1;
	}
	if (check == 1 && sure == 1)
	{
		name3 = name2;
		name2 = name1;
		name1 = name;
	}
	if (check == 2 && sure == 1)
	{
		name3 = name2;
		name2 = name;
		name1 = name1;
	}
	if (check == 3 && sure == 1)
	{
		name1 = name1;
		name2 = name2;
		name3 = name;
	}
	if (sure == 0)
	{
		name1 = name1;
		name2 = name2;
		name3 = name3;
	}
	if (sure == 0)
		return 0;
	else
		return check;
}