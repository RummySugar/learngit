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

private:
		~Student()
		{
			delete [] _name;
			cout << "~Student () " << endl;
		}

public:
		void * operator new(size_t sz)
		{
			cout << "void * operator new (size_t)" << endl;
			void * ret = malloc(sz);
			return ret;
		}

		void operator delete(void * ret)
		{
			free(ret);
			cout << "Student::operator delete(void *)" << endl;
		}

		void destory()
		{
			cout << "Student::destory()" << endl;
			delete this;
		}

		void print() const
		{
			cout << "id: " << _id << endl;
			cout << "name: " << _name << endl;
		}
private:
	int _id;
	char * _name;
};
 
int main(void)
{

#if 0
	Student s1(101,"Alice");
	s1.print();
#endif

	Student * pstu = new Student(100,"jack");
	pstu->print();

	Student * pstu2 = new Student(102,"Pual");
	pstu2 -> print();

	pstu->destory();
	pstu2->destory();

	return 0;
}
