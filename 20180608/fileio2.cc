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
using std::fstream;

void test0(void)
{
	//文件输入流必须打开一个存在的存在的文件
	ifstream ifs("io1.cc");
	if(!ifs)
	{
		cout << "ifstream open fail" << endl;
		return ;
	}

	vector<string> file;
	string line; //从一定程度来说string就是char的容器
	while(getline(ifs,line))
	{
		file.push_back(line);
	}

	ofstream ofs("code.txt");
	if(!ofs)
	{
		cout << "ofstream open fail" << endl;
		return ;
	}
	//输出流并不要求文件存在，不存在可以自己创建一个
	//注意ofstream的模式，默认out模式，清空该文件
	//还有其他模式 app模式每次写都会找到文件尾
	for(auto & line : file)
	{
		cout << line << endl;
		ofs << line << endl;
	}
	ifs.close();
	ofs.close();
}
 
void test1(void)
{
	ofstream ofs("text.txt",std::ios::app);
	if(!ofs)
	{
		cout << "ofstream open fail" << endl;
		return ;
	}

	cout << "文件游标当前位置：" << ofs.tellp() << endl;

	ofs << "this is test\n";

	ofs.close();
}

void test2(void)
{
	//文件输入输出流需要文件存在
	string filename = "test2.txt";
	fstream fs(filename);
	if(!fs)
	{
		cout << "fstream open fail " << endl;
		return ;
	}
	
	int number;

	for(int idx = 0; idx != 10; ++idx)
	{
		cin >> number; // 相对于程序，这是输出流
		fs << number << " ";  //把数据输出到文件
	}
	
	cout << "fs indicator position " << fs.tellp() << endl;
	fs.seekg(std::ios::beg);

	cout << "fs indicator position " << fs.tellp() << endl;
	for(int idx = 0; idx != 10; ++idx)
	{
		fs >> number;  // 相对于程序，这是输入流
		cout << number << " ";  //把数据输入到number
	}
	cout <<  endl;
	fs.close();
}

int main(void)
{
	test2();
    return 0;
}
