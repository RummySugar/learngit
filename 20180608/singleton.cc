 ///
 /// @file    singleton.cc
 /// @author  beiun(a308033@163.com)
 /// @date    2018-06-08 14:24:57
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
//在此 
//单例模式Singleton
//
//要求：只能有类创建一个对象
//该对象不能死栈对象和全局对象
//该对象只能是堆对象
//该对象只能有一个
//
//功能：
//  替换全局变量
//
//  应用场景：
//  1.词典类
//  2.配置文件
//
class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(_pInstance == NULL)
		{
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance)
		{
			delete _pInstance;
		}
	}
private:
	Singleton()
	{
		cout << "Singleton()" << endl;
	}

	~Singleton()
	{
		cout << "~Singleton()" << endl;
	}
private:
	static Singleton * _pInstance;	
};

Singleton * Singleton::_pInstance = NULL;
 
int main(void)
{
	Singleton * pSingleton1 = Singleton::getInstance();
	Singleton * pSingleton2 = Singleton::getInstance();

	printf("pSingleton1 = %p\n",pSingleton1);
	printf("pSingleton2 = %p\n",pSingleton2);

	Singleton::destroy();
    return 0;
}
