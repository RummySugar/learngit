 ///
 /// @file    fileio.cc
 /// @author  beiun(a308033@163.com)
 /// @date    2018-06-08 21:34:55
 ///
 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;

void test0(void)
{
	//文件输入流必须打开一个存在的存在的文件
	ifstream ifs("io1.cc");
	if(!ifs)
	{
		cout << "ifstream open fail" << endl;
		return ;
	}
//	string word;
	string line;
	while(getline(ifs,line))
	{
		cout << line << endl;
	}
	ifs.close();
}
 
int main(void)
{
	test0();
    return 0;
}
