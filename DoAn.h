#ifndef __DOAN_H__
#define __DOAN_H__
#define _CRT_SECURE_NO_WARNINGS
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
	QInt();
	~QInt();
	void ScanQInt();
	void PrintQInt();
	string BinToDec();
	string BintoHex();
	QInt& operator<<(int n);
	QInt& operator>>(int n);
	QInt& rol(int n);
	QInt& ror(int n);
	//Qint& operator+(const Qint& x);
};

QInt::QInt(){
	data[0] = { 0 };
	data[1] = { 0 };
	data[2] = { 0 };
	data[3] = { 0 };
}

QInt::~QInt(){

}

void QInt::ScanQInt(){
	string s;
	s.insert(0, 125, '0');
	s.insert(3, 1, '1');
	s.insert(126, 2, '1');
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

string QInt::BinToDec(){
	string s = "0";
	for (int i = 0; i < 128; i++)
	{
		if ((data[i / 32] >> (128 - 1 - i)) & 1)
		{
			string tmp = _2Exp(128 - 1 - i);
			s = StringPlsString(s, tmp);
		}
	}
	return s;
}

string QInt::BintoHex(){
	string s, tmp;
	for (int i = 0; i < 128 / 4; i++)
	{
		tmp = "0"; int k = 3;
		for (int j = i * 4; j < i * 4 + 4; j++)
		{
			if ((data[j / 32] >> (128 - 1 - j)) & 1)
			{
				tmp = StringPlsString(_2Exp(k), tmp);
			}
			k--;
		}
		int x = atoi(tmp.c_str());
		if (x > 0 && x < 9)
		{
			s.insert(s.end(), x + '0');
		}
		else if (x > 9)
		{
			char c;
			switch (x)
			{
			case 10:
				c = 'A';
				break;
			case 11:
				c = 'B';
				break;
			case 12:
				c = 'C';
				break;
			case 13:
				c = 'D';
			case 14:
				c = 'E';
				break;
			case 15:
				c = 'F';
				break;
				break;
			default:
				break;
			}
			s.insert(s.end(), c);
		}
	}
	return s;
}

QInt& QInt::operator<<(int n){
	string s;
	for (int i = 0; i < 128; i++)
	{
		s.insert(s.end(), ((data[i / 32] >> (128 - 1 - i)) & 1) + '0');
	}
	s.insert(s.end(), n, '0');
	s.erase(s.begin(), s.begin() + n);
	int len = s.length();
	data[0] = { 0 };
	data[1] = { 0 };
	data[2] = { 0 };
	data[3] = { 0 };
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '1')
		{
			data[3 - (len - i - 1) / 32] = data[3 - (len - i - 1) / 32] | 1 << (len - i - 1) % 32;
		}
	}
	/*for (int i = 128 - n; i < 128; i++)
	{
		data[3 - (len - i - 1) / 32] = ~(1 << 128 - 1 - i) & data[3 - (len - i - 1) / 32];
	}*/
	return *this;
}

QInt& QInt::operator>>(int n){
	string s;
	for (int i = 0; i < 128; i++)
	{
		s.insert(s.end(), ((data[i / 32] >> (128 - 1 - i)) & 1) + '0');
	}
	s.insert(s.begin(), n, '0');
	s.erase(s.begin() + s.length() - n, s.end());
	int len = s.length();
	data[0] = { 0 };
	data[1] = { 0 };
	data[2] = { 0 };
	data[3] = { 0 };
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '1')
		{
			data[3 - (len - i - 1) / 32] = data[3 - (len - i - 1) / 32] | 1 << (len - i - 1) % 32;
		}
	}
	return *this;
}

QInt& QInt::rol(int n){
	string s;
	for (int i = 0; i < 128; i++)
	{
		s.insert(s.end(), ((data[i / 32] >> (128 - 1 - i)) & 1) + '0');
	}
	
	string t = s.substr(0, n);
	s.insert(s.length(), t);
	s.erase(s.begin(), s.begin() + n);
	int len = s.length();
	data[0] = { 0 };
	data[1] = { 0 };
	data[2] = { 0 };
	data[3] = { 0 };
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '1')
		{
			data[3 - (len - i - 1) / 32] = data[3 - (len - i - 1) / 32] | 1 << (len - i - 1) % 32;
		}
	}
	return *this;
}

QInt& QInt::ror(int n){
	string s;
	for (int i = 0; i < 128; i++)
	{
		s.insert(s.end(), ((data[i / 32] >> (128 - 1 - i)) & 1) + '0');
	}

	string t = s.substr(s.length() - n, n);
	s.erase(s.begin() + 128 - n, s.end());
	s.insert(0, t);
	int len = s.length();
	data[0] = { 0 };
	data[1] = { 0 };
	data[2] = { 0 };
	data[3] = { 0 };
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '1')
		{
			data[3 - (len - i - 1) / 32] = data[3 - (len - i - 1) / 32] | 1 << (len - i - 1) % 32;
		}
	}
	return *this;
}

#endif