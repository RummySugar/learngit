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
			cout << "该对象的地址为:" << this << endl;
			cout << "id: " << _id << endl;
			cout << "name: " << _name << endl;
		}

		~Student()
		{
			delete [] _name;
			cout << "~Student () " << endl;
		}

private:
		//重载
		void * operator new(size_t sz);
#if 0
		{

			cout << "void * operator new (size_t)" << endl;
			void * ret = malloc(sz);
			return ret;
		}
#endif
		void operator delete(void * ret);
#if 0
		{
			free(ret);
			cout << "void operator delete(void *)" << endl;
		}
#endif
private:
	int _id;
	char * _name;
};
 
int main(void)
{
	Student s1(101,"Alice");
	s1.print();
	cout << "sizeof(Student) = " << sizeof(Student) << endl;

	cout << "sizeof(address) = " << sizeof(int *) << endl;
	Student s2(102,"Pual");
	s2.print();
	cout << "sizeof(Student) = " << sizeof(s2) << endl;
#if 0
	Student * pstu = new Student(100,"jack");
	pstu->print();
	delete pstu;
#endif
    return 0;
}
