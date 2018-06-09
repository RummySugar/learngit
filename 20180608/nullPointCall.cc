 ///
 /// @file    nullPointCall.cc
 /// @author  beiun(a308033@163.com)
 /// @date    2018-06-08 10:38:16
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class NullPointCall
{

public:
		void test0()
		{
			cout << "NullPointCall::test0()" << endl;
		}
		
		void test1(int x)
		{
			cout << "NullPointCall::test2 x = " << x << endl;
		}
		static void test2()
		// 静态函数只能调用静态成员
		{
			cout << "NullPointCall::test3() _iy = " << _iy <<  endl;
		}
		
		void test3()
		//bug : 原因是this为NULL，怎么会有this->_ix 这种东西存在呢
		{
			cout << "NullPointCall::test3() _ix" << this->_ix << endl;
			cout << "test2()" << endl;
		}

private:
		int _ix;
		static int _iy;
};

//静态数据成员只能够在类外部定义，不属于扣个类，而是属于类
//每一个由该类创建的对象共享该全局变量
int NullPointCall::_iy = 0;

int main(void)
{
	NullPointCall *pNull = NULL;
	pNull->test0();
	pNull->test1(10);
	pNull->test2();
	pNull->test3();
    return 0;
}
