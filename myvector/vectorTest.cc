 ///
 /// @file    vectorTest.cc
 /// @author  RummySugar(317704430qq.com)
 /// @date    2018-06-20 18:04:54
 ///
 
#include "vector"

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{ cout << "Point(int, int)" << endl;}

	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{ cout << "Point(const Point &)" << endl; }

	~Point()
	{
		cout << "~Point" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
		<< "," << rhs._iy
		<< ")";
	return os;
}

template<typename T>
void display(T & c)
{
	cout << "vector size = " << c.size() << endl;
	cout << "vector capacity = " << c.capacity() << endl;
}

int main(void)
{
	Vector<Point> points;
	display(points);

	points.push_back(Point(1, 2));
	display(points);

	points.push_back(Point(3, 4));
	display(points);

	points.push_back(Point(5, 6));
	display(points);
//下面是迭代器的使用
	Vector<Point>::iterator it = points.begin(); 
	while(it != points.end())
	{
		cout << *it << endl;
		++it;
	}
	return 0;
}
