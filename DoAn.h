#ifndef __DOAN_H__
#define __DOAN_H__
#include<string>
#include<iostream>
#include <conio.h>
#include<math.h>
using namespace std;

string StringPlsString(string a, string b){
	string s; int t = 0;
	int len = (a.length() > b.length()) ? a.length() : b.length();
	
	if (a.length() > b.length())
	{
		b.insert(0, a.length() - b.length(), '0');
	}
	else if(a.length() < b.length()){
		a.insert(0, b.length() - a.length(), '0');
	}
	for (int i = len - 1; i >= 0; i--)
	{
		int a1 = a[i] - '0';
		int b1 = b[i] - '0';
		int num = a1 + b1 + t;
		t = 0;
		if (num > 9)
		{
			t = (a1 + b1) / 10;
		}
		s.insert(0, 1, num % 10 + '0');
	}
	if (t != 0)
	{
		s.insert(0, 1, t + '0');
		t = 0;
	}
	return s;
}

string Add2(string a){
	return  StringPlsString(a, a);
}

string _2Exp(int Exp){
	string s = "1";
	for (int i = 0; i < Exp; i++)
	{
		s = StringPlsString(s,s);
	}
	return s;
}


class QInt{
public:
	unsigned int data[4];

	void ScanQInt();
	void PrintQInt();
	string ToDec();
	string toHex();
	//Qint& operator+(const Qint& x);
};

void QInt::ScanQInt(){
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	data[3] = 0;
	string s;
	s.insert(0, 16, '0');
	s.insert(0, 1, '1');
	cout << s.length() << "\n";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1')
		{
			data[3 - (s.length() - i - 1) / 32] = data[3 - (s.length() - i - 1) / 32] | 1 << (s.length() - i - 1) % 32;
		}
	}
}

void QInt::PrintQInt(){
	int n = 128;
	for (int i = 0; i < n; i++)
	{
		if (i == 32 || i == 64 || i == 96)
			cout << "\n";
		cout << ((data[i / 32] >> (n - 1 - i)) & 1);
	}
}

string QInt::ToDec(){
	int n = 128;
	long int kq = 0;
	string s = "0";
	for (int i = 0; i < n; i++)
	{
		if ((data[i / 32] >> (n - 1 - i)) & 1)
		{
			string kq = _2Exp(128 - 1 - i);
			s = StringPlsString(s, kq);
		}
	}
	return s;
}




#endif