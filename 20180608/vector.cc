 ///
 /// @file    vector.cc
 /// @author  beiun(a308033@163.com)
 /// @date    2018-06-08 22:05:07
 ///
 
// 动态数组vector
// vector的实现步骤，动态扩容
// 有很大的开销，如果一开始知道放多少，一开始就设定capacity，预先申请空间
// 当size== capacity时，进行扩容
// 1.先申请2*capacity的空间
// 2.旧的cope到新的
// 3.返回新的空间位置
// 4.释放旧的空间
//每个企业开发的API底层实现会有所不同，但是接口是一样的
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using std::vector; //动态数组

int arr[10];  //空间不能扩展

void dispalyCapacity(vector<int> & vec)
{
	cout << "vector size =  " << vec.size() << endl;
	cout << "vector capacity = " << vec.capacity() << endl;
}

void test0(void)
{
	vector<int> numbers;
	numbers.reserve(100); //预先申请空间，。减少开销

	dispalyCapacity(numbers);
	numbers.push_back(1);
	dispalyCapacity(numbers);
	numbers.push_back(2);
	dispalyCapacity(numbers);
	numbers.push_back(3);
	dispalyCapacity(numbers);
	numbers.push_back(4);
	dispalyCapacity(numbers);
	numbers.push_back(5);
	dispalyCapacity(numbers);
	numbers.push_back(6);
	dispalyCapacity(numbers);
	numbers.push_back(7);
	dispalyCapacity(numbers);
	numbers.push_back(8);
	dispalyCapacity(numbers);
	numbers.push_back(9);
	dispalyCapacity(numbers);
	
	for(size_t idx = 0; idx != numbers.size(); idx++)
	{
		cout << numbers[idx] << " ";
	}
	cout << endl;
	
	for(auto & number : numbers)
	{
		cout << number << " ";
	}
	cout << endl;
}

void test(void)
{

}

int main(void)
{
	test0();
    return 0;
}
