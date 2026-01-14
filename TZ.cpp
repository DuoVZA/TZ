#include <iostream>
#include <fstream>
#include <thread>
#include <Windows.h>
#include <string>
using namespace std;

//void printNumbers()
//{
//	for (int i = 1; i <= 100; i++)
//	{
//		cout << "Number: " << i << endl;
//		Sleep(200);
//	}
//}
//
//void printLetters()
//{
//	for (char i = 'A'; i <= 'Z'; i++)
//	{
//		cout << "Letter: " << i << endl;
//		Sleep(500);
//	}
//}
//
//int main()
//{
//	int a, b;
//	int Sum = 0;
//	cout << "Enter diapazon from 1 to 100: ";
//	cin >> a >> b;
//
//	thread num(printNumbers);
//	thread let(printLetters);
//	num.join();
//	let.join();
//
//	for (int i = a; i <= b; i++)
//	{
//		Sum += i;
//	}
//	cout << "Sum: " << Sum << endl;
//	return 0;
//}

void OutFile()
{
	ofstream outFileNum("numbers.txt");
	ofstream outFileLet("letter.txt");
	if (outFileNum.is_open())
	{
		for (int i = 0; i <= 100; i++)
		{
			outFileNum << i << endl;
		}
	}
	else
	{
		cout << "Cannot open file" << endl;
	}

	if (outFileLet.is_open())
	{
		for (char i = 'A'; i <= 'Z'; i++)
		{
			outFileLet << i << endl;
		}
	}
	else
	{
		cout << "Cannot open file" << endl;
	}

	outFileNum.close();
	outFileLet.close();
}

void ReadNumFile()
{
	ifstream file("numbers.txt");

	if (!file.is_open())
	{
		cout << "Cannot open file" << endl;
	}
	string line;
	while (getline(file, line))
	{
		cout << line << endl;
	}

	file.close();
}

void ReadLetFile()
{
	ifstream file("letter.txt");

	if (!file.is_open())
	{
		cout << "Cannot open file" << endl;
	}
	string line;
	while (getline(file, line))
	{
		cout << line << endl;
	}

	file.close();
}

int main()
{
	OutFile();

	thread t1(ReadNumFile);
	thread t2(ReadLetFile);

	t1.join();
	t2.join();

	cout << "Thread is ended!" << endl;

	return 0;
}