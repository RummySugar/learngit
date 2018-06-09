 ///
 /// @file    io1.cc
 /// @author  beiun(a308033@163.com)
 /// @date    2018-06-08 15:44:24
 ///
//c++的输入输出包含3方面
//1.标准I/O；对系统指定的标准设备的输入和输出。即从键盘输入，输出到显示器
//2.文件I/O，从磁盘文件输入数据，数据输出到磁盘文件，对外存文件的输入和输出
//3.串I/O,对内存中指定的空间进行输入和输出。通常指定一个字符串数组作为存储空间（实际上
//可以利用该空间存储任何信息）。这种输入和输出称为：字符串I/O

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <limits>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

void printcin(void)
{
	//c++的流都有四个转台位
	//good位。bad位。fail位。eof位
	cout << "cin.goodbit = " << cin.good() << endl;
	cout << "cin.badbit = " << cin.bad() << endl;
	cout << "cin.failbit = " << cin.fail() << endl;
	cout << "cin.eofbit = " << cin.eof() << endl;
}
 
void test(void)
{
	cout << "sizeof(cout) = " << sizeof(cout) << endl;
	cout << "sizeof(cin) = " << sizeof(cin) << endl;
	printcin();
	int number;

	while(cin)
	//判断六状态是不是有效状态
	{
		cin >> number;
		cout << " number = " << number;
	}
	cout << endl;
	printcin();
	cin.clear(); //重置留的状态，但是会有缓存区，需要清空缓存区
	//cin.ignore(1024,'\n'); //通过该方法清空缓存区
    //写死要抛弃的缓存区的数据大小（字符个数）并不是很好，
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	//调用此方法和参数比较好
	


	cout << endl;
	printcin(); 
	string str;
	cin >> str;
	cout << "str= " << str << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	string line;
	while(std::getline(cin, line))
	{
		cout << "line = " << line << endl;
	}
	//尽量避免使用c的风格
	//比如 char buf[1024]这是写死的，用string比较好这是c++的风格
}

void test1(void)
{
	int number;
	while(cin >> number,!cin.eof())
	{
		if(cin.bad())
		{
			cout << "string has corrupted" << endl;
			return ;
		}
		else if(cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout << "输入整数" << endl;
			continue;
		}
		else{
			cout << "number = " << number << endl;
		}
	}
}
int main(void)
{
	test1();
    return 0;
}
