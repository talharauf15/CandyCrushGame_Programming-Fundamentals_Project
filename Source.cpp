#include <iostream>
#include <Windows.h> // including windows library
#include <iomanip> // Including manipulator library
#include <ctime> // to include time library
#include "Header.h" // to include header file 
#include <limits> // provides information about the properties of arithmetic types
#include <fstream> //  Adding the input output library
#include <string> // to include string library 
# pragma comment(lib, "winmm.lib")// to add music library
using namespace std;
int main()
{
	conslemaximize(); // calling a function conslemaximixe to maximimize console window
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);// Retrieves a handle to the specified standard device
	int num = 0, mod, candy, count = 0, num1 = -1, row, column, row1, column1, num2 = 0, num3 = 0, move = 15, Score = 0, inTime, TIME;//Declaring integer variables 
	int Max, FOUND;
	ifstream DATA2;//Declaring input file variable
	ofstream Redata;//Declaring output file variable
	ifstream DATA3;//Declaring input file variable
	srand(time(0));
	int score2[5] = { 0 };//Declaring score array of size 5 and inilize it to 0
	char ch;
	string name, name1 = "---------------", name2 = "---------------", name3 = "---------------";// Declaring string variables 
	char Board[12][12]; // Declaring 2D character array of size 12 * 12
	SetConsoleTextAttribute(h, 6);
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
	cout << setw(95) << "      *** **       **        ***       **    ** **      **      ** \n";
	cout << setw(95) << "    **          **    **     ** **     **    **    **    **    **  \n";
	cout << setw(95) << "   **          **      **    **  **    **    **     **    **  **   \n";
	cout << setw(95) << "   **          **********    **   **   **    **     **      **     \n";
	cout << setw(95) << "    **         **      **    **     ** **    **    **       **     \n";
	cout << setw(95) << "      *** **   **      **    **       ***    ** **          **     \n";
	cout << "\n\n\n\n\n";
	SetConsoleTextAttribute(h, 6);
	cout << setw(115) << "       *** **    *** **       **        **      ***       **      **  \n";
	cout << setw(115) << "    ***         **     **     **        **   ***    ***   **      **  \n";
	cout << setw(115) << "   ***          **     **     **        **   ***          **      **  \n";
	cout << setw(115) << "   ***          ** ****       **        **      ***       **********  \n";
	cout << setw(115) << "   ***          **    **      **        **          ***   **      **  \n";
	cout << setw(115) << "    ***         **     **      **      **    ***    ***   **      **  \n";
	cout << setw(115) << "       *** **   **     **        **  **         ***       **      **  \n";
	Sleep(4000);
	do
	{
		sndPlaySound(TEXT("Candy Crush Intro2.wav"), SND_FILENAME | SND_ASYNC | SND_LOOP);// plays a waveform sound specified either by a file name
		num = 0;
		system("cls");// to clear the screen
		cout << "\n";
		SetConsoleTextAttribute(h, 9);// To change console application text color
		cout << setw(96) << "<---(*CANDY CRUSH GAME*)--->";
		cout << endl;
		SetConsoleTextAttribute(h, 14);// To change console application text color
		for (int i = 1; i < 168; i++)// loop to print a line
		{
			cout << "_";
		}
		cout << endl << endl;
		SetConsoleTextAttribute(h, 6);// To change console application text color
		cout << setw(91) << "<---MAIN MENU--->" << endl;
		cout << endl;
		SetConsoleTextAttribute(h, 13); //To change console application text color
		cout << setw(87) << "1 ---  PLAY GAME" << endl << endl;
		if (num == 1)
		{
			SetConsoleTextAttribute(h, 11);// To change console application text color
			cout << setw(92) << "1 --  EASY MODE" << endl;
			cout << setw(92) << "2 --  HARD MODE" << endl << endl;
		}
		SetConsoleTextAttribute(h, 14);// To change console application text color
		cout << setw(85) << "2 ---  CREDITS" << endl << endl;
		SetConsoleTextAttribute(h, 12);// To change console application text color
		cout << setw(96) << "3 ---  INSTRUCTIONS/RULES" << endl << endl;
		SetConsoleTextAttribute(h, 10);// To change console application text color
		cout << setw(83) << "4 ---  SCORE" << endl << endl;
		SetConsoleTextAttribute(h, 4);// To change console application text color
		cout << setw(82) << "5 ---  EXIT" << endl << endl;
		SetConsoleTextAttribute(h, 14);// To change console application text color
		for (int i = 1; i < 168; i++)// loop to print a line
		{
			cout << "-";
		}
		cout << endl << endl;
		SetConsoleTextAttribute(h, 3);// To change console application text color
		cout << setw(90) << "Input the number here:";
		while (!(cin >> num))// Checking that input is valid or not
		{
			SetConsoleTextAttribute(h, 4);// To change console application text color
			cout << setw(90) << "Input the number Again:";
			cin.clear();// clears the error flag on cin 
			cin.ignore();//  to ignore or clear one or more characters 
		}
		SetConsoleTextAttribute(h, 15);// To change console application text color
		cout << endl;
		switch (num) // used this to outcome the possible casses of num
		{
		case 1:
		{
			system("cls");// to clear the screen
			cout << endl;
			SetConsoleTextAttribute(h, 6);// To change console application text color
			for (int i = 1; i < 168; i++)// loop to print a line
			{
				cout << "*";
			}
			cout << endl << endl;
			cin.ignore();//  to ignore or clear one or more characters 
			SetConsoleTextAttribute(h, 14);// To change console application text color
			cout << setw(84) << "ENTER YOUR NAME :";
			getline(cin, name);
			system("cls"); // to clear the screen
			cout << endl;
			SetConsoleTextAttribute(h, 9);// To change console application text color
			cout << setw(96) << "<---(*CANDY CRUSH GAME*)--->" << endl;
			cout << endl;
			SetConsoleTextAttribute(h, 14);// To change console application text color
			for (int i = 1; i < 168; i++)// loop to print a line
			{
				cout << "_";
			}
			cout << endl << endl;
			SetConsoleTextAttribute(h, 6);// To change console application text color
			cout << setw(91) << "<---MAIN MENU--->" << endl;
			cout << endl;
			SetConsoleTextAttribute(h, 13);// To change console application text color
			cout << setw(87) << "1 ---  PLAY GAME" << endl << endl;
			if (num == 1)
			{
				SetConsoleTextAttribute(h, 11);
				cout << setw(92) << "1 --  EASY MODE" << endl;
				cout << setw(92) << "2 --  HARD MODE" << endl << endl;
			}
			SetConsoleTextAttribute(h, 14);
			cout << setw(85) << "2 ---  CREDITS" << endl << endl;
			SetConsoleTextAttribute(h, 12);// To change console application text color
			cout << setw(96) << "3 ---  INSTRUCTIONS/RULES" << endl << endl;
			SetConsoleTextAttribute(h, 10);// To change console application text color
			cout << setw(83) << "4 ---  SCORE" << endl << endl;
			SetConsoleTextAttribute(h, 4);// To change console application text color
			cout << setw(82) << "5 ---  EXIT" << endl << endl;
			SetConsoleTextAttribute(h, 14);// To change console application text color
			for (int i = 1; i < 168; i++)// loop to print a line
			{
				cout << "-";
			}
			cout << endl << endl;
			SetConsoleTextAttribute(h, 3);// To change console application text color
			cout << setw(90) << "Input the Mod number here:";
			while (!(cin >> mod))// Checking that input is valid or not
			{
				SetConsoleTextAttribute(h, 4);// to ignore or clear one or more characters 
				cout << setw(90) << "Input the Mod number again:";
				cin.clear();// to clear the screen
				cin.ignore();//  to ignore or clear one or more characters 
			}
			SetConsoleTextAttribute(h, 15);// to ignore or clear one or more characters 
			cout << endl;
			switch (mod)// Use this to outcome the possible casses of mod
			{
			case 1:
				sndPlaySound(TEXT("Candy Crush Loop5.wav"), SND_FILENAME | SND_ASYNC | SND_LOOP);//plays a waveform sound specified either by a file nam
				count = 0, num1 = -1, num2 = 0, num3 = 0, move = 15, Score = 0;
				for (int i = 0; i < 8; i++)// using loop to to fill the character array
				{
					for (int j = 0; j < 8; j++)
					{
						candy = rand() % 38 + 35;
						if (candy == 35 || candy == 36 || candy == 37 || candy == 38 || candy == 64 || candy == 72)// making decision
						{
							if (count == 6)
							{
								if (candy == 35 || candy == 36 || candy == 37 || candy == 38 || candy == 64)// making decision
								{
									Board[i][j] = candy;
								}
								else// if upper condition dosenot satisfied
									j--;// decrement
							}
							else if (candy == 35 || candy == 36 || candy == 37 || candy == 38 || candy == 64 || candy == 72) //if upper condition dosenot satisfied
							{
								ch = static_cast<char>(candy);
								Board[i][j] = ch;
								if (Board[i][j] == 'H')
									count = count + 1;// increment 
							}
						}
						else// upper condition is not satisfied
							j--;// decrement 
					}
				}
				FOUND = 0;
				while (FOUND == 0)
				{
					FOUND = checking2(Board, 8);//Calling the checking2 function to check candies 
					change(Board, 8);//Calling the change function to change 0 and 1 into candies
				}
				system("cls");// to clear the screen
				cout << "\n\n";
				TIME = 60;
				do {
					do
					{
						cout << "\n\n";
						SetConsoleTextAttribute(h, 15);// To change console application text color
						if (num1 == -1)
						{
							system("cls");// to clear screen
							Easy(Board, 8, TIME, move, Score);//Calling the easy function to display easy board
						}
						if (num2 == 0)
						{
							cout << "\n";
							SetConsoleTextAttribute(h, 6);// To change console application text color
							cout << setw(116) << "<----Input the Row and column of candy which you want to swap---->\n\n";
							SetConsoleTextAttribute(h, 3);// To change console application text color
							cout << setw(88) << "Input the Row no:";
							inTime = clock();// returns the approximate processor time that is consumed by the program.
							while (!(cin >> row))
							{
								SetConsoleTextAttribute(h, 4);// To change console application text color
								cout << setw(89) << "Input the Row again:";
								cin.clear();
								cin.ignore();
							}
							SetConsoleTextAttribute(h, 3);
							cout << "\n" << setw(90) << "Input the Column no:";
							while (!(cin >> column))
							{
								SetConsoleTextAttribute(h, 4);
								cout << "\n" << setw(91) << "Input the Column again:";
								cin.clear();// clears the error flag on cin 
								cin.ignore();// to ignore or clear one or more character
							}
							SetConsoleTextAttribute(h, 15);// To change console application text color
							inTime = clock() - inTime;
							inTime = inTime / CLOCKS_PER_SEC;//Caluating elapse time in seconds
							TIME = TIME - inTime;
							if (TIME <= 0)
								num2 = -1;
						}
						cout << "\n";
						check1(num1, num2, row, column, Board, 8, TIME, move, Score);// calling check1 function to check input of candies
					} while (num2 != -1);
					if (TIME > 0)
					{
						cout << "\n";
						inTime = clock();
						inputchecker(move, num1, row, column, Board, 8, num2, Score, TIME);//Calling inputchecker function to check input of user to swap candy
						inTime = clock() - inTime;
						inTime = inTime / CLOCKS_PER_SEC;
						TIME = TIME - inTime;
						sndPlaySound(TEXT("Candy Crush Loop5.wav"), SND_FILENAME | SND_ASYNC | SND_LOOP);// plays a waveform sound specified either by a file name
					}
				} while (move > 0 && TIME > 0);
				system("cls");// to clear the screen
				sndPlaySound(TEXT("Candy Crush Outro1.wav"), SND_FILENAME | SND_ASYNC | SND_LOOP);// plays a waveform sound specified either by a file name
				cout << endl;
				SetConsoleTextAttribute(h, 6);// To change console application text color
				for (int i = 1; i < 168; i++)
				{
					cout << "&";
				}
				cout << endl << endl;
				if (TIME <= 0)
					cout << setw(93) << "----TIMES UP!---- " << endl << endl;
				else
					cout << setw(93) << "----MOVES END!----" << endl << endl;
				for (int i = 1; i < 168; i++)
				{
					cout << "&";
				}
				cout << endl << endl;
				SetConsoleTextAttribute(h, 3);// To change console application text color
				DATA2.open("DATA.txt");
				if (DATA2.is_open())//Checking that file open or not
				{
					getline(DATA2, name1);//used to read a string or a line from an file
					DATA2 >> score2[0];
					DATA2.ignore();
					getline(DATA2, name2);//used to read a string or a line from an file
					DATA2 >> score2[1];
					DATA2.ignore();
					getline(DATA2, name3);//used to read a string or a line from an file
					DATA2 >> score2[2];
					DATA2.ignore();
				}
				DATA2.close();
				Max = scorechecker(score2, 5, Score, name, name1, name2, name3);//Calling scorechecker function to check maximum score
				if (Max > 0)// making decision
				{
					cout << setw(103) << "<<<<<<<<<< Congratulation >>>>>>>>>>" << endl << endl;
					cout << setw(103) << "<<< YOU GOT A SCORE IN TOP THREE >>>" << endl << endl;
				}
				cout << setw(90) << "YOUR SCORE IS: " << Score << "\n\n\n\n" << endl;
				SetConsoleTextAttribute(h, 14);// To change console application text color
				for (int i = 1; i < 168; i++)
				{
					cout << "-";
				}
				cout << endl;
				SetConsoleTextAttribute(h, 15);// To change console application text color
				Redata.open("DATA.txt", ios::out);
				if (Redata.is_open())
				{
					Redata << name1 << endl << score2[0] << endl;//Giving data to file
					Redata << name2 << endl << score2[1] << endl;
					Redata << name3 << endl << score2[2] << endl;
				}
				Redata.close();
				system("pause");
				break;
			case 2:
				sndPlaySound(TEXT("Candy Crush Loop5.wav"), SND_FILENAME | SND_ASYNC | SND_LOOP);// plays a waveform sound specified either by a file name
				count = 0, num1 = -1, num2 = 0, num3 = 0, move = 15, Score = 0;
				for (int i = 0; i < 12; i++)// using for loop
				{
					for (int j = 0; j < 12; j++)// using nested for loop 
					{
						candy = rand() % 40 + 33;
						if (candy == 33 || candy == 63 || candy == 48 || candy == 35 || candy == 36 || candy == 37 || candy == 38 || candy == 64 || candy == 72)
						{
							if (count == 11)// making decision
							{
								if (candy == 33 || candy == 63 || candy == 48 || candy == 35 || candy == 36 || candy == 37 || candy == 38 || candy == 64)// makjing decision
								{
									Board[i][j] = candy;
								}
								else// if upper condition dosenot satisfied
									j--;
							}
							else if (candy == 33 || candy == 63 || candy == 48 || candy == 35 || candy == 36 || candy == 37 || candy == 38 || candy == 64 || candy == 72)// using else if 
							{
								ch = static_cast<char>(candy);
								Board[i][j] = ch;
								if (Board[i][j] == 'H')// making decision
									count = count + 1;// increment
							}
						}
						else// upper condition dosenot satisfied
							j--;
					}
				}
				FOUND = 0;
				while (FOUND == 0)// using while loop
				{
					FOUND = checking2(Board, 12);//Clling checking2 function to check candies
					change(Board, 12);//Calling function to change 1 and 0 in candies
				}
				system("cls");// used to clear screen
				TIME = 40;
				do {
					do
					{
						cout << "\n\n";
						SetConsoleTextAttribute(h, 15);// To change console application text color
						if (num1 == -1)
						{
							system("cls");// to clear screen
							Hard(Board, 12, TIME, move, Score);
						}
						if (num2 == 0)// making decision
						{
							cout << "\n";
							SetConsoleTextAttribute(h, 6);// To change console application text color
							cout << setw(116) << "<----Input the Row and column of candy which you want to swap---->\n\n";
							SetConsoleTextAttribute(h, 3);// To change console application text color
							cout << setw(88) << "Input the Row no:";
							inTime = clock();
							while (!(cin >> row))
							{
								SetConsoleTextAttribute(h, 4);// To change console application text color
								cout << setw(89) << "Input the Row again:";
								cin.clear();
								cin.ignore();
							}
							SetConsoleTextAttribute(h, 3);// To change console application text color
							cout << "\n" << setw(90) << "Input the Column no:";
							while (!(cin >> column))
							{
								SetConsoleTextAttribute(h, 4);// To change console application text color
								cout << "\n" << setw(91) << "Input the Column again:";
								cin.clear();// clear the screen
								cin.ignore();// to ignore or clear one or more character
							}
							SetConsoleTextAttribute(h, 15);// To change console application text color
							inTime = clock() - inTime;
							inTime = inTime / CLOCKS_PER_SEC;
							TIME = TIME - inTime;
							if (TIME <= 0)// making decision
								num2 = -1;
						}
						cout << "\n";
						check1(num1, num2, row, column, Board, 12, TIME, move, Score);//Calling check1 function to check the input
					} while (num2 != -1);
					if (TIME > 0)
					{
						inTime = clock();
						cout << "\n";
						inputchecker(move, num1, row, column, Board, 12, num2, Score, TIME);
						inTime = clock() - inTime;
						inTime = inTime / CLOCKS_PER_SEC;
						TIME = TIME - inTime;
						sndPlaySound(TEXT("Candy Crush Loop5.wav"), SND_FILENAME | SND_ASYNC | SND_LOOP);// plays a waveform sound specified either by a file name
					}
				} while (move > 0 && TIME > 0);
				system("cls");
				sndPlaySound(TEXT("Candy Crush Outro1.wav"), SND_FILENAME | SND_ASYNC | SND_LOOP);// plays a waveform sound specified either by a file name
				cout << endl;
				SetConsoleTextAttribute(h, 6);// To change console application text color
				for (int i = 1; i < 168; i++)
				{
					cout << "&";
				}
				cout << endl << endl;
				if (TIME <= 0)// making decision
					cout << setw(93) << "----TIMES UP!---- " << endl << endl;
				else// if upper condition is  not satisfied
					cout << setw(93) << "----MOVES END!----" << endl << endl;
				for (int i = 1; i < 168; i++)// using for loop
				{
					cout << "&";
				}
				cout << endl << endl;
				SetConsoleTextAttribute(h, 3);// To change console application text color
				ifstream DATA1;
				DATA1.open("DATA.txt");
				int counter = 0;
				if (DATA1.is_open())
				{
					getline(DATA1, name1);//used to read a string or a line from file
					DATA1 >> score2[0];
					DATA1.ignore();
					getline(DATA1, name2);//used to read a string or a line from file
					DATA1 >> score2[1];
					DATA1.ignore();
					getline(DATA1, name3);//used to read a string or a line from file
					DATA1 >> score2[2];
					DATA1.ignore();
				}
				DATA1.close();
				Max = scorechecker(score2, 5, Score, name, name1, name2, name3);//Calling scorechecker function to check maximum score
				if (Max > 0)// makilng decision
				{
					cout << setw(103) << "<<<<<<<<<< Congratulation >>>>>>>>>>" << endl << endl;
					cout << setw(103) << "<<< YOU GOT A SCORE IN TOP THREE >>>" << endl << endl;
				}
				cout << setw(90) << "YOUR SCORE IS: " << Score << "\n\n\n\n" << endl;
				SetConsoleTextAttribute(h, 14);
				for (int i = 1; i < 168; i++)
				{
					cout << "-";
				}
				cout << endl;
				SetConsoleTextAttribute(h, 15);// To change console application text color
				ofstream Redata2;
				Redata2.open("DATA.txt", ios::out);
				if (Redata2.is_open())
				{
					Redata2 << name1 << endl << score2[0] << endl;
					Redata2 << name2 << endl << score2[1] << endl;
					Redata2 << name3 << endl << score2[2] << endl;
				}
				Redata2.close();
				system("pause");
				break;
			}
		}
		break;
		case 2:
			system("cls");// to clear the screen
			sndPlaySound(TEXT("credit2.wav"), SND_FILENAME | SND_ASYNC | SND_LOOP);
			cout << endl;
			SetConsoleTextAttribute(h, 6);// To change console application text color
			cout << "\n";
			for (int i = 1; i < 168; i++)// usimg for loop
			{
				cout << "&";
			}
			cout << endl << endl;
			cout << setw(100) << "<<<==----- CREDITS -----==>>>" << endl << endl;
			for (int i = 1; i < 168; i++)
			{
				cout << "&";
			}
			SetConsoleTextAttribute(h, 7);// To change console application text color
			cout << endl << endl;
			Sleep(3000);// to suspend its execution temporarily for a period of time in seconds specified by the function 
			sndPlaySound(TEXT("credit.wav"), SND_FILENAME | SND_ASYNC);// plays a waveform sound specified either by a file name
			Sleep(1200);
			cout << setw(79); cout << "M", Sleep(150), cout << "U", Sleep(150), cout << "H", Sleep(150), cout << "A", Sleep(150);
			cout << "M", Sleep(150), cout << "M", Sleep(150), cout << "A", Sleep(150), cout << "D", Sleep(150), cout << " ", Sleep(150);
			cout << "A", Sleep(150), cout << "H", Sleep(150), cout << "M", Sleep(150), cout << "A", Sleep(150), cout << "D";
			cout << endl << endl;
			sndPlaySound(TEXT("credit.wav"), SND_FILENAME | SND_ASYNC);// plays a waveform sound specified either by a file name
			Sleep(1200);
			cout << setw(78); cout << "M", Sleep(130), cout << "U", Sleep(130), cout << "H", Sleep(130), cout << "A", Sleep(130);
			cout << "M", Sleep(130), cout << "M", Sleep(130), cout << "A", Sleep(130), cout << "D", Sleep(130), cout << " ", Sleep(130);
			cout << "H", Sleep(130), cout << "U", Sleep(130), cout << "Z", Sleep(130), cout << "A", Sleep(130), cout << "I", Sleep(130), cout << "F", Sleep(130), cout << "A";
			Sleep(1000);
			sndPlaySound(TEXT("credit2.wav"), SND_FILENAME | SND_ASYNC | SND_LOOP);// plays a waveform sound specified either by a file name
			cout << endl << endl;
			system("pause");
			break;
		case 3:
			sndPlaySound(TEXT("rules.wav"), SND_FILENAME | SND_ASYNC | SND_LOOP);// plays a waveform sound specified either by a file name
			system("cls");
			SetConsoleTextAttribute(h, 6);// To change console application text color
			cout << "\n";
			for (int i = 1; i < 168; i++)// using for loop
			{
				cout << "&";
			}
			cout << endl << endl;
			cout << setw(107) << "<<<==----- RULES AND INSTRUCTIONS -----==>>>" << endl << endl;
			for (int i = 1; i < 168; i++)// using for loop
			{
				cout << "&";
			}
			SetConsoleTextAttribute(h, 11);// To change console application text color
			cout << "\n\n\n";
			cout << "==> 1.  There   are   two   types   of   boards   in   this   Game,   one   is   easy   and   second   is   hard\n\n";
			cout << "==> 2.  The  Easy  board  contain  8x8  candies  means  64  candies  and  a  timer  of  60  seconds  and  15 moves\n\n";
			cout << "==> 3.  The  Hard  board  contain  12x12  candies  means 144 candies  and  a  timer  of  40  seconds  and 15 moves\n\n";
			cout << "==> 4.  The  Easy  board  contain  6 Hardles  candies  Which  are  not  swappable  and  the  player  can  not  swap\n        other  candies  with  Hurdles  Candies\n\n";
			cout << "==> 5.  The  Hard  board  contain 11 Hardles  candies  Which  are  not  swappable  and  the  player  can  not  swap\n        other  candies  with  Hurdles  Candies\n\n";
			cout << "==> 6.  The  Player  have  to  swap  the  candies  with  other  candies  only  and  only  if  three  or  more  than\n        three  candies  become  in  consective  row  or  column\n\n";
			cout << "==> 7.  In  this  game  Player  have  to  enter  the  row  and  column  number  of  candy  which  he  want  to  swap\n\n";
			cout << "==> 8.  When  the  player  matches  three  candies  then  he / she  get  10  points  and  moves  decreased  by  1\n\n";
			cout << "==> 9.  When  the  player  matches  more  than  three  candies  then  he / she  get  20  points  and  a  candy (B)\n        called  BOMB  come  to  swapplable  candy  place  and  moves  decreased  by  1\n\n";
			cout << "==> 10. When  the  player  swap  bomb  with  any  candy  except  Hardles  then  he / she  get  30  points  and  a \n        whole  row  and  column  of  swappable  candy  will  removed  and  new  candies  come  on  that  place  and\n        moves  decreased  by  1\n\n";
			cout << "==> 11. When  Time  or  Moves  end  then  game  End  and  if  he / she  have  more  score  then  top  three  then \n        he / she  get  score  in  top  three\n\n";
			SetConsoleTextAttribute(h, 14);// To change console application text color
			cout << "\n\n" << setw(100) << "Hope you Enjoy the game :):)\n\n";
			SetConsoleTextAttribute(h, 6);// To change console application text color
			for (int i = 1; i < 168; i++)// using for loop
			{
				cout << "=";
			}
			cout << endl;
			SetConsoleTextAttribute(h, 7);// To change console application text color
			system("pause");
			break;
		case 4:
			system("cls");
			SetConsoleTextAttribute(h, 6);// To change console application text color
			cout << "\n";
			for (int i = 1; i < 168; i++)
			{
				cout << "&";
			}
			cout << endl << endl;
			cout << setw(103) << "<<<=----TOP THREE HIGH SCORES----=>>>" << endl << endl;
			for (int i = 1; i < 168; i++)// using for loop
			{
				cout << "&";
			}
			cout << "\n\n\n\n";
			DATA3.open("DATA.txt");
			if (DATA3.is_open())
			{
				getline(DATA3, name1);//used to read a string or a line from an file
				DATA3 >> score2[0];
				DATA3.ignore();//clear one or more characters from the input
				getline(DATA3, name2);//used to read a string or a line from an file
				DATA3 >> score2[1];
				DATA3.ignore();//clear one or more characters from the input
				getline(DATA3, name3);//used to read a string or a line from an file
				DATA3 >> score2[2];
				DATA3.ignore();//clear one or more characters from the input
				SetConsoleTextAttribute(h, 4);// To change console application text color
				cout << setw(85) << "NAME OF PLAYERS" << "  :   " << "SCORES" << endl << endl;
				SetConsoleTextAttribute(h, 9);
				cout << setw(85) << name1 << "  :   " << score2[0] << endl;
				cout << setw(85) << name2 << "  :   " << score2[1] << endl;
				cout << setw(85) << name3 << "  :   " << score2[2] << endl;
				SetConsoleTextAttribute(h, 6);// To change console application text color
				cout << "\n\n\n\n";
				for (int i = 1; i < 168; i++)// using for loop
				{
					cout << "=";
				}
				cout << endl;
				system("pause");
				SetConsoleTextAttribute(h, 15);// To change console application text color
			}
			else
			{
				SetConsoleTextAttribute(h, 4);// To change console application text color
				cout << setw(103) << "<<<<<<<<< NO HIGH SCORE YET >>>>>>>>>" << endl << endl;
				cout << "\n\n\n\n";
				SetConsoleTextAttribute(h, 6);// To change console application text color
				for (int i = 1; i < 168; i++)// using for loop
				{
					cout << "=";
				}
				cout << endl;
				system("pause");
				SetConsoleTextAttribute(h, 15);// To change console application text color
			}
			break;
		case 5:
			break;
		}
	} while (num != 5);
	system("pause");
	return 0;
}