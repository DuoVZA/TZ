#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <random>
#include <Windows.h>
using namespace std;

mutex m;
int arr[100];

void WriteInFile()
{
	m.lock();
	ofstream fout("array.txt");
	if (!fout.is_open())
	{
		cout << "Error!" << endl;
	}
	for (size_t i = 0; i < 100; i++)
	{
		arr[i] = rand() % 101;
		fout << "Array[" << i << "]: " << arr[i] << endl;
	}
	fout.close();
	m.unlock();
}

void ReadFromFile()
{
	m.lock();
	ifstream fin("array.txt");
	if (!fin.is_open())
	{
		cout << "Error!" << endl;
	}
	for (size_t i = 0; i < 100; i++)
	{
		cout << "Array[" << i << "]: " << arr[i] << endl;
	}
	fin.close();
	m.unlock();
}

int main()
{
	thread t1(WriteInFile);
	Sleep(100);
	thread t2(ReadFromFile);

	t1.join();
	t2.join();
}