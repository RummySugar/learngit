 ///
 /// @file    singleton1.cc
 /// @author  beiun(a308033@163.com)
 /// @date    2018-06-09 00:06:25
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
 
class Singleton
{
public:

	static Singleton *getInstance()
	{
		if(_pInstance == NULL)
		{
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

	static void destory()
	{
		if(_pInstance)
		{
			delete _pInstance;
		}
	}

private:
	
	Singleton()
	{
		cout << "heiheihie" << endl;
	}
	
	~Singleton()
	{
		cout << "hahaha" << endl;
	}

private:
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = NULL; 

int main(void)
{
	
	Singleton * pStr = Singleton::getInstance();
	
	Singleton * pStr1 = Singleton::getInstance();

	Singleton::destory(); 
    
	return 0;
}
