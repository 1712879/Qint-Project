#ifndef __DOAN_H__
#define __DOAN_H__
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include <conio.h>
#include<fstream>
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
			t = num / 10;
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

string StringsubString(string x, string y){
	if (x.length() > y.length())
	{
		while (x.length() != y.length())
			y = "0" + y;
	}
	else if (x.length() < y.length())
	{
		while (x.length() != y.length())
			x = "0" + x;
	}
	bool flag = false;
	if (x < y)
	{
		string str = x;
		x = y;
		y = str;
		flag = true;
	}
	string s;
	int temp;
	int nho = 0;
	for (int i = x.length() - 1; i >= 0; i--)
	{
		temp = x[i] - (y[i] + nho);
		if (temp >= 0)
		{
			s.insert(s.begin(), temp + '0');
			nho = 0;
		}
		else {
			s.insert(s.begin(), temp + 10 + '0');
			nho = 1;
		}
	}
	int i = 0;
	while (s[i] == '0')
	{
		s.erase(0, 1);
	}
	if (flag)
	{
		s.insert(0, 1, '-');
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

string Div(string s){
	int t = 0; string kq;
	for (int i = 0; i < s.length(); i++)
	{
		t = t * 10 + (s[i] - '0');
		if (i > 0 || (i == 0 && t >= 2))
		{	
			kq.insert(kq.end(), 1, (t / 2) + '0');
		}
		t %= 2;
	}
	return kq;
}

class QInt{
protected:
	unsigned int data[4];
public:
	QInt();
	QInt(string s);
	string convertToString();
	void ScanQInt(string s);
	void PrintQInt();
	string BinToDec();
	string BintoHex();
	QInt& operator<<(int n);
	QInt& operator>>(int n);
	QInt& rol(int n);
	QInt& ror(int n);
// Vi'Code
	bool operator ==(const QInt);
	QInt operator=(const QInt);
	bool operator != (const QInt);
	bool operator > (QInt);
	bool operator <=(QInt);
	bool operator < (QInt);
	bool operator >= (QInt);

	QInt operator &(QInt);
	QInt operator ^(const QInt);
	QInt operator |(const QInt);
	QInt operator ~();

	QInt operator +(QInt);
	QInt operator *(QInt);
	QInt operator -(QInt);
	QInt operator /(QInt);
	QInt operator % (const QInt qint);
	bool iNegative();
	QInt bu2();
	void Func();
};

QInt::QInt(){
	data[0] = { 0 };
	data[1] = { 0 };
	data[2] = { 0 };
	data[3] = { 0 };
}

QInt::QInt(string s){
	*this = QInt();
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1')
		{
			data[3 - (s.length() - i - 1) / 32] = data[3 - (s.length() - i - 1) / 32] | 1 << (s.length() - i - 1) % 32;
		}
	}
}

void QInt::ScanQInt(string s){
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

string QInt::convertToString(){
	int n = 128; string s = "";
	for (int i = 0; i < n; i++)
	{
		s.append(to_string((data[i / 32] >> (n - 1 - i)) & 1));
	}
	return s;
}

string QInt::BinToDec(){
	string s1 = "0";
	int n = 128;
	for (int i = 1; i < 128; i++)
	{
		if (((data[i / 32] >> (n - 1 - i)) & 1))
		{
			string tmp = _2Exp(127 - i);
			s1 = StringPlsString(s1, tmp);
		}
	}

	if ((data[0] >> 31) & 1)
	{
		string s = _2Exp(127);
		return StringsubString(s, s1).insert(0, 1, '-');
	}
	else
	{
		return s1;
	}
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
	QInt temp = *this;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp.data[j] = temp.data[j] << 1;
			if (((temp.data[j + 1] >> 31) & 1) && j < 3)
			{
				temp.data[j] = temp.data[j] | 1;
			}
		}
	}
	return temp;
}

QInt& QInt::operator>>(int n){
	QInt temp = *this;
	for (int i = 0; i < n; i++)
	{
		for (int j = 3; j >= 0; j--)
		{
			temp.data[j] = temp.data[j] >> 1;
			if ((temp.data[j - 1] & 1) && j > 0)
			{
				temp.data[j] = temp.data[j] | 1 << 31;
			}
		}
	}
	return temp;
}

QInt& QInt::rol(int n){	
	bool flag;
	for (int i = 0; i < n; i++)
	{
		flag = false;
		if (((data[0] >> 31) & 1))
		{
			flag = true;
		}
		this->operator<<(1);
		if (flag)
		{
			data[3] = data[3] | 1;
		}
	}
	return *this;
}

QInt& QInt::ror(int n){
	bool flag;
	for (int i = 0; i < n; i++)
	{
		flag = false;
		if (data[3] & 1)
		{
			flag = true;
		}
		this->operator>>(1);
		if (flag)
		{
			data[0] = data[0] | 1 << 31;
		}
	}

	return *this;
}

string DectoBin(string s){
	string kq; bool flag = false;
	if (s[0] == '-')
	{
		s.erase(0, 1);
		flag = true;
	}
	while (s != "")
	{
		kq.insert(kq.begin(), 1, ((s[s.length() - 1] - '0') % 2) + '0');
		s = Div(s);
	}
	if (flag)
	{
		QInt a;
		a.ScanQInt(kq);
		QInt kq = a.bu2();
		return kq.convertToString();
	}
	return kq;
}

string DectoHex(string s){
	QInt a;
	a.ScanQInt(DectoBin(s));
	a.PrintQInt();
	return a.BintoHex();
}

string HextoBin(string s){
	string kq = "";
	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case '0':
			kq.append("0000");
			break;
		case '1':
			kq.append("0001");
			break;
		case '2':
			kq.append("0010");
			break;
		case '3':
			kq.append("0011");
			break;
		case '4':
			kq.append("0100");
			break;
		case '5':
			kq.append("0101");
			break;
		case '6':
			kq.append("0110");
			break;
		case '7':
			kq.append("0111");
			break;
		case '8':
			kq.append("1000");
			break;
		case '9':
			kq.append("1001");
			break;
		case 'A':
			kq.append("1010");
			break;
		case 'B':
			kq.append("1011");
			break;
		case 'C':
			kq.append("1100");
			break;
		case 'D':
			kq.append("1101");
			break;
		case 'E':
			kq.append("1110");
			break;
		case 'F':
			kq.append("1111");
			break;
		}
	}
	return kq;
	
}

string HextoDec(string s){
	string kq;
	kq = HextoBin(s);
	QInt a;
	a.ScanQInt(kq);
	return a.BinToDec();
}

bool QInt::operator==(const QInt  qInt)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->data[i] != qInt.data[i])
			return false;
	}
	return true;
}

bool QInt::operator!=(const QInt  qInt)
{
	return !this->operator==(qInt);
}

QInt QInt::operator=(const QInt qInt)
{
	for (int i = 0; i<4; i++)
	{
		this->data[i] = qInt.data[i];
	}
	return*this;
}

bool QInt::operator >(QInt  qInt)
{
	bool iNeThis, iNeQi;
	iNeThis = this->iNegative();
	iNeQi = this->iNegative();
	if (iNeQi && !iNeQi)
	{
		return false;
	}
	else if (!iNeQi && iNeQi)
	{
		return true;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->data[i] > qInt.data[i])
				return true;
			else if (this->data[i] < qInt.data[i])
			{
				return false;
			}
		}
		return false;
	}
}

bool QInt::operator < (QInt qInt)
{
	return !((this->operator==(qInt) | this->operator>(qInt)));
}

bool QInt::operator <=(QInt qInt)
{
	return !this->operator>(qInt);
}

bool QInt::operator >= (QInt qInt)
{
	return !this->operator<(qInt);
}

QInt QInt::operator&(QInt  qInt)
{
	QInt result;
	for (int i = 0; i < 4; i++)
	{
		result.data[i] = this->data[i] & qInt.data[i];
	}
	return result;
}

QInt QInt::operator ^(const QInt qInt)
{
	QInt result;
	for (int i = 0; i < 4; i++)
	{
		result.data[i] = this->data[i] ^ qInt.data[i];
	}
	return result;
}

QInt QInt::operator |(const QInt qInt)
{
	QInt result;
	for (int i = 0; i < 4; i++)
	{
		result.data[i] = this->data[i] | qInt.data[i];
	}
	return result;
}

QInt QInt:: operator ~()
{
	QInt result;
	for (int i = 0; i < 4; i++)
	{
		result.data[i] = ~this->data[i];
	}
	return result;
}

QInt QInt::operator +(QInt qint)
{
	QInt result = *this;
	QInt temp;
	while (qint!=QInt("0"))
	{
		temp = result & qint;

		//Tổng các bit khác nhau của hai số (0 + 1 = 1).
		result = result ^ qint;

		//Đưa các bit cùng là 1 bên 1 bit để tiếp tục phép cộng cần thực hiện.
		qint = temp << 1;
	}
	return result;
}

QInt QInt::operator *(QInt qint)
{
	QInt result;
	int i = 0;
	while (qint != QInt("0"))
	{
		if ((qint&QInt("1")) == QInt("1"))
		{
			result = result + (*this << i);
		}
		qint = qint >> 1;
		i++;
	}
	return result;
}

QInt QInt::operator -(QInt qint)
{
	QInt temp = qint.bu2();
	return *this + temp;
}

QInt QInt::operator /(QInt qint)
{
	QInt result;
	QInt tempThis = *this;
	QInt tempQint = qint;
	QInt One("1");
	int k = 0;
	bool flag = false;// xét tính âm dương của biến kết quả result

	if (tempThis.iNegative())
	{
		tempThis = tempThis.bu2();
		flag = true;
	}
	if (tempQint.iNegative())
	{
		flag = !(flag);
		tempQint = tempQint.bu2();
	}
	while ((tempThis & One) == QInt("0") && (tempQint & One) == QInt("0"))//cả 2 đều là số chẵn
	{
		//rút gọn
		tempThis = tempThis >> 1;
		tempQint = tempQint >> 1;
	}
	if (tempQint == One)
	{//chia cho 1
		return (flag == true ? tempThis.bu2() : tempThis);
	}
	// vd : 15/3=(3*2^2 + 3*2^0)/3=2^2+2^0
	while (tempThis >= tempQint)
	{
		k = 0;
		while ((tempQint*(One << (k + 1))) < tempThis)
		{
			k++;
		}
		result = result + (One << k);
		tempThis = tempThis - (tempQint << k);
	}
	return (flag == true ? result.bu2() : result);
}

QInt QInt::operator %(const QInt qint)
{
	return *this - (*this / qint)*(qint);
}

bool QInt::iNegative()
{
	QInt x("1");
	x = x << 127;
	if (((*this)& x) == QInt("0"))
		return false;
	return true;
}

QInt QInt::bu2()
{
	QInt temp;
	temp = ~(*this);
	temp = temp + QInt("1");
	return temp;
}

void DocFile(string HeChuyenDoi[20], int PhepToan[20], string Chuoi01[20], string Chuoi02[20], int &CountLine)
{
	fstream FileIn("Input.txt");
	string Line[100];
	while (!FileIn.eof())
	{
		int Flag = -1; //Vi tri cua phep toan 
		char *temp = new char[255];
		FileIn.getline(temp, 255);
		Line[CountLine] = temp;
		cout << "Dong Thu 1: " << Line[CountLine] << endl;
		Flag = Line[CountLine].find(" + ");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 1;
			goto next; // di toi buoc ke tiep
		}
		Flag = Line[CountLine].find(" - ");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 2;
			goto next;
		}
		Flag = Line[CountLine].find("*");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 3;
			goto next;
		}
		Flag = Line[CountLine].find("/");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 4;
			goto next;
		}
		Flag = Line[CountLine].find(">>");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 5;
			goto next;
		}
		Flag = Line[CountLine].find("<<");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 6;
			goto next;
		}
		Flag = Line[CountLine].find("rol");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 7;
			goto next;
		}
		Flag = Line[CountLine].find("ror");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 8;
			goto next;
		}

		Flag = Line[CountLine].find("&");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 9;
			goto next;
		}
		Flag = Line[CountLine].find("|");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 10;
			goto next;
		}
		Flag = Line[CountLine].find("^");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 11;
			goto next;
		}
		Flag = Line[CountLine].find("~");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 12;
			goto next;
		}
		Flag = Line[CountLine].find("<");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 13;
			goto next;
		}
		Flag = Line[CountLine].find(">");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 14;
			goto next;
		}
		Flag = Line[CountLine].find("==");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 15;
			goto next;
		}
		Flag = Line[CountLine].find("<=");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 16;
			goto next;
		}
		Flag = Line[CountLine].find(">=");
		if (Flag != -1)
		{
			PhepToan[CountLine] = 17;
			goto next;
		}
	next:  // buoc ke tiep
		int VitriDauCach1 = -1;
		VitriDauCach1 = Line[CountLine].find_first_of(" ");
		int VitriDauCach2 = -1;
		VitriDauCach2 = Line[CountLine].find(" ", VitriDauCach1 + 1);
		int VitriDauCach3 = -1;
		VitriDauCach3 = Line[CountLine].find_last_of(" ");
		if (Flag != -1)
		{
			HeChuyenDoi[CountLine].assign(Line[CountLine], 0, VitriDauCach1);
			Chuoi01[CountLine].assign(Line[CountLine], VitriDauCach1 + 1, VitriDauCach2 - VitriDauCach1 - 1);
			Chuoi02[CountLine].assign(Line[CountLine], VitriDauCach3 + 1, Line[CountLine].size() - VitriDauCach3);
		}
		else{
			PhepToan[CountLine] = -1;
			Chuoi02[CountLine] = "NULL";
			HeChuyenDoi[CountLine].assign(Line[CountLine], 0, VitriDauCach1);
			string HeChuyen;  //Chuyen Sang he nao.
			HeChuyen.assign(Line[CountLine], VitriDauCach1 + 1, VitriDauCach2 - VitriDauCach1 - 1);
			HeChuyenDoi[CountLine].append(HeChuyen);
			Chuoi01[CountLine].assign(Line[CountLine], VitriDauCach3 + 1, Line[CountLine].size() - VitriDauCach3);
		}
		CountLine++;
	}
	FileIn.close();
}

void GhiFile(string output[20],int N)
{
	ofstream FileOut("Output.txt");
	for (int i = 0; i < N; i++)
	{
		FileOut << output[i] << endl;
	}
	FileOut.close();
}

void QInt::Func(){
	string HeChuyenDoi[20];
	int PhepToan[20];
	string Chuoi01[20];
	string Chuoi02[20];
	string output[20];
	int CountLine = 0;
	DocFile(HeChuyenDoi, PhepToan, Chuoi01, Chuoi02, CountLine);
	QInt kq;
	for (int i = 0; i < CountLine; i++)
	{
		QInt a, b;
		if (HeChuyenDoi[i].length() < 3)
		{
			if (HeChuyenDoi[i] == "10")
			{
				a.ScanQInt(DectoBin(Chuoi01[i]));
				b.ScanQInt(DectoBin(Chuoi02[i]));
				
			}
			else if (HeChuyenDoi[i] == "16")
			{
				a.ScanQInt(HextoBin(Chuoi01[i]));
				b.ScanQInt(HextoBin(Chuoi02[i]));
			}
			else if (HeChuyenDoi[i] == "2")
			{
				a.ScanQInt(Chuoi01[i]);
				b.ScanQInt(Chuoi02[i]);
			}

			switch (PhepToan[i])
			{
			case 1:
				kq = a+b;
				break;
			case 2:
				kq = a-b;
				break;
			case 3:
				kq = a*b;
				break;
			case 4:
				kq = a/b;
				break;
			case 5:
				kq = a >> atoi(Chuoi02[i].c_str());
				break;
			case 6:
				kq = a << atoi(Chuoi02[i].c_str());
				break;
			case 7:
				kq = a.rol(atoi(Chuoi02[i].c_str()));
				break;
			case 8:
				kq = a.ror(atoi(Chuoi02[i].c_str()));
				break;
			case 9:
				kq = a&b;
				break;
			case 10:
				kq = a|b;
				break;
			case 11:
				kq = a^b;
				break;
			case 12:
				kq = a.operator~();
				break;
			case 13:
				if (a < b)
				{
					output[i] = "TRUE";
				}
				else
				{
					output[i] = "FALSE";
				}
				break;
			case 14:
				if (a > b)
				{
					output[i] = "TRUE";
				}
				else
				{
					output[i] = "FALSE";
				}
				break;
			case 15:
				if (a == b)
				{
					output[i] = "TRUE";
				}
				else
				{
					output[i] = "FALSE";
				}
				break;
			case 16:
				if (a <= b)
				{
					output[i] = "TRUE";
				}
				else
				{
					output[i] = "FALSE";
				}
				break;
			case 17:
				if (a >= b)
				{
					output[i] = "TRUE";
				}
				else
				{
					output[i] = "FALSE";
				}
				break;
			default:
				output[i] = "ERROR!";
				break;
			}
			if (PhepToan[i] != -1)
			{
				if (HeChuyenDoi[i] == "10")
				{
					output[i] = kq.BinToDec();

				}
				else if (HeChuyenDoi[i] == "16")
				{
					output[i] = kq.BintoHex();
				}
				else if (HeChuyenDoi[i] == "2")
				{
					string result = kq.convertToString();
					while (result[0] == '0')
					{
						result.erase(0, 1);
					}
					output[i] = result;
				}
			}
		}

		if (HeChuyenDoi[i].length() > 2)
		{
			string tmp = "0";
			int t = atoi(HeChuyenDoi[i].c_str());
			switch (t)
			{
			case 210:
				a.ScanQInt(Chuoi01[i]);
				tmp = a.BinToDec();
				break;
			case 216:
				a.ScanQInt(Chuoi01[i]);
				tmp = a.BintoHex();
				break;
			case 102:
				tmp = DectoBin(Chuoi01[i]);
				break;
			case 1016:
				tmp = DectoHex(Chuoi01[i]);
				break;
			case 162:
				tmp = HextoBin(Chuoi01[i]);
				break;
			case 1610:
				tmp = HextoDec(Chuoi01[i]);
				break;
			default:
				tmp = "ERROR!";
				break;
			}
			output[i] = tmp;
		}

	}

	GhiFile(output, CountLine);
	
}

void NgatChuoi(string chuoivao, string &PhanThuc, string &PhanAo)
{
	int vitri = chuoivao.find(".");
	PhanThuc.assign(chuoivao, 0, vitri);
	PhanAo.assign(chuoivao, vitri + 1, chuoivao.size() - vitri - 1);
}

string Ham(string a)
{
	string SoTru = "1";
	SoTru.insert(SoTru.end(), a.size(), '0');
	int Sotru = stoi(SoTru);
	int PhanThuc = stoi(a);
	string Bin;
	int dem = 0;
	while (PhanThuc != Sotru && dem < 112)
	{
		PhanThuc = PhanThuc * 2;
		if (PhanThuc < Sotru)
		{
			Bin.append("0");
		}
		if (PhanThuc > Sotru)
		{
			Bin.append("1");
			PhanThuc = PhanThuc - Sotru;
		}
		if (PhanThuc == Sotru)
		{
			Bin.append("1");
		}
		dem++;
	}
	return Bin;
}

string phanThuc(QInt tu, QInt mau) // tử luôn nhỏ hơn mẫu
{
	string kq = "";
	while ((tu % mau) != QInt("0"))
	{
		tu = (tu % mau) * QInt("1010");
		QInt t = (tu / mau);
		kq.append(t.BinToDec());
		cout << kq << endl;
	}
	return kq;
}

class QFloat : public QInt{
public:
	string DectoFloat(string s);
	string FLoattoDec();

};

string QFloat::FLoattoDec()
{
	int n = 128; string s, kq = "";
	s = convertToString();
	// Xac dinh dau
	if (s[0] == '1')
		kq += '-';
	else
		kq += '+';
	//----- Tinh Mu E
	string Exp = s.substr(1, 15);
	int t = 0;
	for (int i = 0; i < 15; i++)
	{
		if (Exp[i] == '1')
			t += pow(2, 14 - i);
	}
	int E = t - pow(2, 14) + 1;
	string phannguyen = "0";
	if (E >= 0)
	{
		QInt phanNguyen("1" + s.substr(16, E));
		phannguyen = phanNguyen.BinToDec();
		s.erase(0, 16 + E);
	}
	else
	{
		s.erase(0, 16);
		s.insert(0, 1, '1');
		s.insert(0, - E - 1, '0');
	}
	//----------------------
	
	int pos = s.find_last_of('1');
	/*Chuyen nhi phan chuoi s sang phan thuc */
	QInt tu("0"), mau("1");
	for (int i = 0; i < pos + 1; i++)
	{
		if (s[i] == '1')
		{
			QInt temp = QInt("1") << (i + 1);
			tu = tu*(temp/mau) + QInt("1");
			mau = QInt("1") << (i + 1);
		}
	}
	string phanthuc = phanThuc(tu, mau);
	kq += phannguyen + "." + phanthuc;
	return kq;
}

string QFloat::DectoFloat(string s)
{
	string kq = "";
	if (s[0] == '-')
		kq += '1';
	else
		kq += '0';
	s = s.erase(0, 1);
	string PhanNguyen = "NULL";
	string PhanThuc = "NULL";
	NgatChuoi(s, PhanNguyen, PhanThuc);
	string Bin_Nguyen, Bin_Thuc;
	Bin_Nguyen = DectoBin(PhanNguyen);
	Bin_Thuc = Ham(PhanThuc);
	int Exp; string Bin_F;
	int pos = Bin_Nguyen.find("1", 0);
	if (pos != -1)
	{
		Exp = (Bin_Nguyen.length() - 1 - pos);
		Bin_F = Bin_Nguyen.substr(pos + 1);
		Bin_F.append(Bin_Thuc);
	}
	else if (Bin_Thuc.find("1", 0) != 0){
		pos = Bin_Thuc.find("1", 0);
		Exp = -(pos + 1);
		Bin_F = Bin_Thuc.substr(pos + 1);
	}
	Exp += pow(2, 14) - 1;
	string Bin_E = DectoBin(to_string(Exp));
	if (Bin_E.length() < 15)
	{
		Bin_E.insert(0, 15 - Bin_E.length(), '0');
	}
	kq.append(Bin_E);
	if (Bin_F.length() < 112)
	{
		Bin_F.insert(Bin_F.end(), 112 - Bin_F.length(), '0');
	}
	else if (Bin_F.length() > 112)
	{
		Bin_F.erase(112);
	}
	kq.append(Bin_F);
	return kq;
}

void Menu_QInt(){
	int c;
	do
	{
		int nBit;
		string s, s1, s2;
		QInt a, b, kq;
		cout << "-Chuyen Doi Co So\n";
		cout << "\t01. 2 -> 10\n\t02. 2 -> 16\n\t03. 10 -> 2\n\t04. 10 -> 16\n\t05. 16 -> 2\n\t06. 16 -> 10\n";
		cout << "-Operator +, -, *, /\n";
		cout << "\t07. +\n\t08. -\n\t09. *\n\t10. /\n";
		cout << "-Toan Tu So Sanh\n";
		cout << "\t11. <\n\t12. >\n\t13. <=\n\t14. >=\n";
		cout << "-Toan Tu AND, OR, XOR, NOT\n";
		cout << "\t15. AND\n\t16. OR\n\t17. XOR\n\t18. NOT\n";
		cout << "-Toan Tu >>, <<, rol, ror\n";
		cout << "\t19. >>\n\t20. <<\n\t21. rol\n\t22. ror\n";
		cout << "00. Thoat\n";
		cout << "\n Nhap Lua Chon:  ";
		cin >> c;
		fflush(stdin);
		if (c == 0)
		{
			return;
		}
		system("cls");
		switch (c)
		{
		case 1:
			cout << "Nhap Chuoi So: ";
			getline(cin, s);
			a.ScanQInt(s);
			cout << "Ket Qua: \n" << a.BinToDec() << "\n";
			break;
		case 2:
			cout << "Nhap Chuoi So: ";
			getline(cin, s);
			a.ScanQInt(s);
			cout << "Ket Qua: \n" << a.BintoHex() << "\n";
			break;
		case 3:
			cout << "Nhap Chuoi So: ";
			getline(cin, s);
			cout << "Ket Qua: \n" << DectoBin(s) << "\n";
			break;
		case 4:
			cout << "Nhap Chuoi So: ";
			getline(cin, s);
			cout << "Ket Qua: \n" << DectoHex(s) << "\n";
			break;
		case 5:
			cout << "Nhap Chuoi So: ";
			getline(cin, s);
			cout << "Ket Qua: \n" << HextoBin(s) << "\n";
			break;
		case 6:
			cout << "Nhap Chuoi So: ";
			getline(cin, s);
			cout << "Ket Qua: \n" << HextoDec(s) << "\n";
			break;
		case 7:
			cout << "Nhap Chuoi So 1: ";
			getline(cin, s1);
			cout << "Nhap Chuoi So 2: ";
			getline(cin, s2);
			a.ScanQInt(s1);
			b.ScanQInt(s2);
			kq = a + b;
			cout << "Ket Qua(Co So 2): \n" << kq.convertToString() << "\n";
			cout << "Ket Qua(Co So 10): \n" << kq.BinToDec() << "\n\n";
			break;
		case 8:
			cout << "Nhap Chuoi So 1: ";
			getline(cin, s1);
			cout << "Nhap Chuoi So 2: ";
			getline(cin, s2);
			a.ScanQInt(s1);
			b.ScanQInt(s2);
			kq = a - b;
			cout << "Ket Qua(Co So 2): \n" << kq.convertToString() << "\n";
			cout << "Ket Qua(Co So 10): \n" << kq.BinToDec() << "\n\n";
			break;
		case 9:
			cout << "Nhap Chuoi So 1: ";
			getline(cin, s1);
			cout << "Nhap Chuoi So 2: ";
			getline(cin, s2);
			a.ScanQInt(s1);
			b.ScanQInt(s2);
			kq = a * b;
			cout << "Ket Qua(Co So 2): \n" << kq.convertToString() << "\n";
			cout << "Ket Qua(Co So 10): \n" << kq.BinToDec() << "\n\n";
			break;
		case 10:
			cout << "Nhap Chuoi So 1: ";
			getline(cin, s1);
			cout << "Nhap Chuoi So 2: ";
			getline(cin, s2);
			a.ScanQInt(s1);
			b.ScanQInt(s2);
			kq = a / b;
			cout << "Ket Qua(Co So 2): \n" << kq.convertToString() << "\n";
			cout << "Ket Qua(Co So 10): \n" << kq.BinToDec() << "\n\n";
			break;
		case 11:
			cout << "Nhap Chuoi So 1: ";
			getline(cin, s1);
			cout << "Nhap Chuoi So 2: ";
			getline(cin, s2);
			a.ScanQInt(s1);
			b.ScanQInt(s2);
			if (a < b)
			{
				cout << "Ket Qua: TRUE\n";
			}
			else
			{
				cout << "Ket Qua: FALSE\n";
			}
			break;
		case 12:
			cout << "Nhap Chuoi So 1: ";
			getline(cin, s1);
			cout << "Nhap Chuoi So 2: ";
			getline(cin, s2);
			a.ScanQInt(s1);
			b.ScanQInt(s2);
			if (a > b)
			{
				cout << "Ket Qua: TRUE\n";
			}
			else
			{
				cout << "Ket Qua: FALSE\n";
			}
			break;
		case 13:
			cout << "Nhap Chuoi So 1: ";
			getline(cin, s1);
			cout << "Nhap Chuoi So 2: ";
			getline(cin, s2);
			a.ScanQInt(s1);
			b.ScanQInt(s2);
			if (a <= b)
			{
				cout << "Ket Qua: TRUE\n";
			}
			else
			{
				cout << "Ket Qua: FALSE\n";
			}
			break;
		case 14:
			cout << "Nhap Chuoi So 1: ";
			getline(cin, s1);
			cout << "Nhap Chuoi So 2: ";
			getline(cin, s2);
			a.ScanQInt(s1);
			b.ScanQInt(s2);
			if (a >= b)
			{
				cout << "Ket Qua: TRUE\n";
			}
			else
			{
				cout << "Ket Qua: FALSE\n";
			}
			break;
		case 15:
			cout << "Nhap Chuoi So 1: ";
			getline(cin, s1);
			cout << "Nhap Chuoi So 2: ";
			getline(cin, s2);
			a.ScanQInt(s1);
			b.ScanQInt(s2);
			kq = a.operator&(b);
			cout << "Ket Qua: \n " << kq.convertToString() << "\n";
			break;
		case 16:
			cout << "Nhap Chuoi So 1: ";
			getline(cin, s1);
			cout << "Nhap Chuoi So 2: ";
			getline(cin, s2);
			a.ScanQInt(s1);
			b.ScanQInt(s2);
			kq = a.operator|(b);
			cout << "Ket Qua: \n " << kq.convertToString() << "\n";
			break;
		case 17:
			cout << "Nhap Chuoi So 1: ";
			getline(cin, s1);
			cout << "Nhap Chuoi So 2: ";
			getline(cin, s2);
			a.ScanQInt(s1);
			b.ScanQInt(s2);
			kq = a.operator^(b);
			cout << "Ket Qua: \n " << kq.convertToString() << "\n";
			break;
		case 18:
			cout << "Nhap Chuoi So: ";
			getline(cin, s);
			a.ScanQInt(s);
			cout << "Ket Qua: \n" << a.operator~().convertToString() << "\n";
			break;
		case 19:
			cout << "Nhap Chuoi So: ";
			getline(cin, s);
			cout << "So Luong Bit(s): ";
			cin >> nBit;
			a.ScanQInt(s);
			cout << "Ket Qua: \n" << a.operator>>(nBit).convertToString() << "\n";
			break;
		case 20:
			cout << "Nhap Chuoi So: ";
			getline(cin, s);
			cout << "So Luong Bit(s): ";
			cin >> nBit;
			a.ScanQInt(s);
			cout << "Ket Qua: \n" << a.operator<<(nBit).convertToString() << "\n";
			break;
		case 21:
			cout << "Nhap Chuoi So: ";
			getline(cin, s);
			cout << "So Luong Bit(s): ";
			cin >> nBit;
			a.ScanQInt(s);
			cout << "Ket Qua: \n" << a.rol(nBit).convertToString() << "\n";
			break;
		case 22:
			cout << "Nhap Chuoi So: ";
			getline(cin, s);
			cout << "So Luong Bit(s): ";
			cin >> nBit;
			a.ScanQInt(s);
			cout << "Ket Qua: \n" << a.ror(nBit).convertToString() << "\n";
			break;
		}
		cout << "0. Thoat\n1. Tiep Tuc\n\nChon:  ";
		cin >> c;
		fflush(stdin);
		system("cls");
	} while (c != 0);
}

void Menu_QFLoat(){
	int c;
	do
	{
		QFloat a; string s;
		cout << "-Chuyen Doi Co So\n";
		cout << "\t01. 2 -> 10\n\t02. 10 -2\n";
		cout << "00. Thoat\n\nNhap Lua Chonn:  ";
		cin >> c;
		fflush(stdin);
		if (c == 0)
		{
			return;
		}
		system("cls");
		cout << "Nhap Chuoi So: ";
		getline(cin, s);
		switch (c)
		{
		case 1:
			a.ScanQInt(s);
			cout << "Ket Qua: \n" << a.FLoattoDec() << "\n";
			break;
		case 2:
			cout << "Ket Qua: \n" << a.DectoFloat(s) << "\n";
			break;
		}
		cout << "0. Thoat\n1. Tiep Tuc\n\nChon:  ";
		cin >> c;
		fflush(stdin);
		system("cls");
	} while (c != 0);
}

void Menu(){
	int c;
	do
	{
		QInt a; QFloat b;
		cout << "1. Chuc Nang QInt.\n2. Chuc Nang QFloat\n";
		cout << "3. Doc File Test QInt\n4. Doc File Test QFLoat\n";
		cout << "0. Thoat\n\nNhap Lua Chon:  ";
		cin >> c;
		if (c == 0)
		{
			return;
		}
		fflush(stdin);
		system("cls");
		switch (c)
		{
		case 0:
			break;
		case 1:
			Menu_QInt();
			break;
		case 2:
			Menu_QFLoat();
			break;
		case 3:
			a.Func();
			cout << "Thanh Cong,Mo File Output.txt kiem tra\n";
			break;
		case 4:
			break;
		}
		cout << "1: Continue, 0: Exit\n";
		cin >> c;
		fflush(stdin);
		system("cls");
	} while (c != 0);
}

#endif
