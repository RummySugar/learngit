 ///
 /// @file    student.cc
 /// @author  beiun(a308033@163.com)
 /// @date    2018-06-08 19:27:22
 ///
 
#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
 
class Student
{
public:
		Student(int id, const char * name)
		: _id(id)
		, _name(new char[strlen(name)+1]())
		{
			cout << "Student (int, const char *)" << endl;
			strcpy(_name, name);
		}

		void print() const
		{
			cout << "id: " << _id << endl;
			cout << "name: " << _name << endl;
		}

		~Student()
		{
			delete [] _name;
			cout << "~Student () " << endl;
		}

		//重载
		void * operator new(size_t sz)
		{
			cout << "void * operator new (size_t)" << endl;
			void * ret = malloc(sz);
			return ret;
		}

		void operator delete(void * ret)
		{
			free(ret);
			cout << "void operator delete(void *)" << endl;
		}
private:
	int _id;
	char * _name;
};
 
int main(void)
{
	Student * pstu = new Student(100,"jack");
	pstu->print();
	delete pstu;

    return 0;
}
