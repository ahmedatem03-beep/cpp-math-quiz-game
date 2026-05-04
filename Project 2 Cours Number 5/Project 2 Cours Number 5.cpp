#include <iostream>
#include <string>
#include <cmath>
using namespace std;
enum enLevevl { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enType { Add = 1, Sup = 2, Mul = 3, Div = 4, Mix2 = 5 };

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

int HowMany()
{
	int Many = 0;
	cout << "How Many Questions Do You Want To Answer ? ";
	cin >> Many;
	return Many;
}
int EnterLevel()
{
	int Level = 0;
	do
	{
		cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> Level;
	} while (Level < 1 || Level > 4);
	return Level;
}
int EnterType()
{
	int Type = 0;
	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> Type;
	} while (Type < 1 || Type > 5);
	return Type;
}

int RandomMixType()
{
	return RandomNumber(1, 4);
}
char CheckMixType(enType Type)
{
	if (Type == 1)
		return '+';
	else if (Type == 2)
		return '-';
	else if (Type == 3)
		return '*';
	else if (Type == 4)
		return '/';
}
char MixType()
{
	char Mix = CheckMixType((enType)RandomMixType());
	return Mix;
}

int CheckLevel(enLevevl Level)
{
	switch (Level)
	{
	case enLevevl::Easy:
		return RandomNumber(1, 10);
	case enLevevl::Med:
		return RandomNumber(10, 50);
	case enLevevl::Hard:
		return RandomNumber(50, 100);
	case enLevevl::Mix:
		return RandomNumber(1, 100);
	}
}
char CheckType(enType Type)
{
	switch (Type)
	{
	case enType::Add:
		return '+';
	case enType::Sup:
		return '-';
	case enType::Mul:
		return '*';
	case enType::Div:
		return '/';
	case enType::Mix2:
		return MixType();
	}
}

int CheckMixResult(int Num1, int Num2, int Type)
{
	int Reslut = 0;

	if (Type == enType::Add)
	{
		Reslut = Num1 + Num2;
		return Reslut;
	}
	else if (Type == enType::Sup)
	{
		Reslut = Num1 - Num2;
		return Reslut;
	}
	else if (Type == enType::Mul)
	{
		Reslut = Num1 * Num2;
		return Reslut;
	}
	else if (Type == enType::Div)
	{
		Reslut = Num1 / Num2;
		return Reslut;
	}
	
}
int CheckResult(int Num1, int Num2, int Type)
{
	if (Type == enType::Mix2)
		return CheckMixResult(Num1, Num2,RandomNumber(1,5));
	else
		return CheckMixResult(Num1, Num2, Type);
}


void PassOrFail(short RightAnswer, short WrongAnswer)
{
	cout << "_________________________________\n\n";
	if (RightAnswer >= WrongAnswer)
		cout<< " Final Results Is PASS :-)\n";
	else
		cout<< " Final Results Is Fail :-(\n";
	
	cout << "_________________________________\n\n";
}

string QuestionsLevel(int Level)
{
	if (Level == enLevevl::Easy)
		return "Eaey";
	else if (Level == enLevevl::Med)
		return "Med";
	else if (Level == enLevevl::Hard)
		return "Hard";
	else
		return "Mix";
}
string OpType(int Type)
{
	
	if (Type == enType::Add)
		return "+";
	else if (Type == enType::Sup)
		return "-";
	else if (Type == enType::Mul)
		return "*";
	else if (Type == enType::Div)
		return "/";
	else

		return "Mix";
	
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}


void PlayGame(int length)
{
	int Level = 0, Type = 0, Result = 0;
	int Num1 = 0, Num2 = 0, CheckReslut2 = 0;
	char Op;
	short Countr = 0, RightAnswer = 0, WrongAnswer = 0;
	Level = EnterLevel();
	Type = EnterType();
	for (int i = 1; i <= length; i++)
	{
		Countr++;
		cout << "\n\nQuestion  [" << i << "/" << length << "]\n\n";
		Num1 = CheckLevel((enLevevl)Level);
		cout << Num1 << endl;
		Op = CheckType((enType)Type);
		cout <<"   "<< Op << endl;
		Num2 = CheckLevel((enLevevl)Level);
		cout << Num2 << endl;
		cout << "____________\n";
		cin >> Result;
		CheckReslut2 = CheckResult(Num1, Num2, Type);
		if (Result == CheckReslut2)
		{
			system("color 2F");
			cout << "Right Answer :-)\n\n";
			RightAnswer++;
		}
		else
		{
			system("color 4F");
			cout << "Wrong Answer :-(\n";
			cout << "The Rhight Answer Is: " << CheckReslut2 << endl << endl;
			WrongAnswer++;
		}
		
	}
	 PassOrFail(RightAnswer, WrongAnswer);
	 cout << "Number Of Questions: " << Countr << endl;
	 cout << "Questions Level    : " << QuestionsLevel(Level) << endl;
	 cout << " Op Type           : " << OpType(Type) << endl;
	 cout << "Number Of Right Answers: " << RightAnswer << endl;
	 cout << "Nomber Of Wrong Answers: " << WrongAnswer << endl;
	 cout << "_________________________________\n\n";
}
void PrintFinalGame()
{
	char Again ;
	do
	{
		ResetScreen();
		PlayGame(HowMany());
		cout << "Do You Want To Play Again? Y/N? ";
		cin >> Again;
	} while (Again == 'Y' || Again == 'y');
}




int main()
{
	srand((unsigned)time(NULL));
	PrintFinalGame();
}
