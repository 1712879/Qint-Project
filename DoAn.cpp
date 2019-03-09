#include"DoAn.h"
#define _CRT_SECURE_NO_WARNINGS


int main(){
	QInt a;
	a.ScanQInt();
	a.PrintQInt();
	cout<<"\n"<<a.BinToDec();
	a.operator<<(2);
	cout << "\n";
	a.PrintQInt();
	cout<<"\n"<<a.BinToDec();
	a.operator>>(2);
	cout << "\n";
	a.PrintQInt();
	cout << "\n" << a.BinToDec();
	a.rol(4);
	cout << "\n";
	a.PrintQInt();
	cout << "\n" << a.BinToDec();
	a.ror(4);
	cout << "\n";
	cout << "\n";
	a.PrintQInt();
	cout << "\n" << a.BinToDec();
	_getch();
	return 0;
}