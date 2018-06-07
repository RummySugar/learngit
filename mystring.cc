 ///
 /// @file    mystring.cc
 /// @author  beiun(a308033@163.com)
 /// @date    2018-06-06 23:57:19
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
		String()
		: _pstr(NULL)
		{
			
			cout << "String () " << endl;
		}

		String(const char * pstr)
		: _pstr(new char [strlen(pstr)+1]())
		{
			strcpy(_pstr,pstr);
			cout << "String (const char *)" << endl;
		}

		String(const String &rhs)
		: _pstr(new char[strlen(rhs._pstr)+1]())
		{
			strcpy(_pstr,rhs._pstr);
			cout << "String (const String &)" << endl;
		}
		String & operator=(const String & rhs)
		{
			if(this != &rhs)
			{
				delete [] _pstr;
				_pstr = new char[strlen(rhs._pstr)+1]();
				strcpy(_pstr,rhs._pstr);
				cout << "String & operator = (const String &)" << endl;
			}	
			return *this;
		}
		~String()
		{
			delete [] _pstr;
			_pstr = NULL ;
			cout << "~String ()" << endl;
		}
		void print();
private:
		char *_pstr; 
};

void String::print()
{
	if(_pstr == NULL)
	{
		cout << "空字符串" << endl;
		return;
	}
	int i;
	for(i=0;*(_pstr+i)!='\0';i++)
	{
		cout << *(_pstr+i);
	}
	cout << endl;
}

int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3("wangdao");
	String str4=str2;
	str1 = str3;

	str1.print();
	str2.print();
	str3.print();
	str4.print();
}

