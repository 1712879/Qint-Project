#ifndef __DOAN_H__
#define __DOAN_H__
#include<string>
#include<iostream>
#include <conio.h>
#include<math.h>
using namespace std;

class Qint{
public:
	unsigned int data[4];

	string convert();
	void Nhap();
	void Xuat();
	string ToDec();

	Qint& operator+(const Qint& x);
};

string Qint::convert(){
	return "";
}

void Qint::Nhap(){
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	data[3] = 0;
	string s = "10110111000111001100111001110011001110001100111000111000111100110011110011";
	cout << s.length() << "\n";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1')
		{
			data[3 - (s.length() - i - 1) / 32] = data[3 - (s.length() - i - 1) / 32] | 1 << (s.length() - i - 1) % 32;
		}
	}
}

void Qint::Xuat(){
	int n = 128;
	for (int i = 0; i < n; i++)
	{
		if (i == 32 || i == 64 || i == 96)
			cout << "\n";
		cout << ((data[i / 32] >> (n - 1 - i)) & 1);
	}
}

string Qint::ToDec(){
	int n = 128;
	long int kq = 0;
	string s = "0";
	for (int i = 0; i < n; i++)
	{
		if ((data[i / 32] >> (n - 1 - i)) & 1)
		{
			kq += pow(2,n - i - 1);
		}
	}
	cout << "\n" <<kq;
	return "";
}

Qint &Qint::operator+(const Qint &x){
	int i = 0, kq[10], a = 0;
	while ((data[i / 32] >> (128 - i - 1) & 1 != 0){

	}
		
}

#endif