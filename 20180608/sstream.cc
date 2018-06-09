 ///
 /// @file    sstream.cc
 /// @author  beiun(a308033@163.com)
 /// @date    2018-06-08 23:14:00
 ///
 
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;
 
void test0(void)
{
	int number1 = 10;
	int number2 = 20;

	//把非字符串数据装换成字符串】
	//ssprintf
	stringstream ss;
	ss << "number1= " << number1 << "number2= " << number2 << endl;
	cout << ss.str() << endl;

	string word;
	int value;
	//当我们格式确定的时候，可以使用输入流的方式完成数据的输入
	while(ss >> word >> value)
	{
		cout << word << " " << value << endl;
	}

}

string int2str(int number)
{
	ostringstream oss;
	oss << number;
	return oss.str();
}

void readConfiguration()
{
	ifstream ifs;
	ifs.open("server.conf");
	if(!ifs)
	{
		cout << "ifstream open fail" << endl;
		return ;
	}
	
	string line;
	string key;
	string value;
	while(getline(ifs,line))
	{
		istringstream iss(line);
		iss >> key >> value;
		cout << key << " ---> " << value <<endl;
	}
	ifs.close();

}
int main(void)
{
  //  string num= int2str(100);
//	cout << num << endl;
	test0();
//	readConfiguration();
    return 0;
}
