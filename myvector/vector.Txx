 ///
 /// @file    vector.cc
 /// @author  RummySugar(317704430qq.com)
 /// @date    2018-06-20 16:58:15
 ///
 
#include "vector"

//静态成员的初始化，初始化空间配装器_alloc
template<typename T>
allocator<T> Vector<T>::_alloc;

// vector的构造函数，采用无参的构造函数
// 对于vector的三个广义指针初始化为0
template <typename T>
Vector<T>::Vector()
: _start(0)
, _finish(0)
, _end_of_storage(0)
{ cout << "Vector()" << endl; }

//vector的析构函数，不仅要把vector的对象析构，还要将每个元素析构
//对于每个元素，是任何类型，可能是内置类型，也可能是自定义类型
//while调用空间置配器的destroy方法析构每个元素
//每个元素析构完，再释放vector申请的堆空间，调用allocator的deallocate
//具体方法和实现看源码
template <typename T>
Vector<T>::~Vector()
{
	while(_start != _finish)
	{
		_alloc.destroy(--_finish);
	}
	if(_start)
	{
		_alloc.deallocate(_start, capacity());
	}
}

//vector的size()方法，可以类比数组
template <typename T>
size_t Vector<T>::size()const
{
	return _finish - _start;
}

//vector的capacity()方法, 可以类比数组
template <typename T>
size_t Vector<T>::capacity()
{
	return _end_of_storage - _start;
}

//插入操作，有点复杂。主要在于扩容方面的操作
template <typename T>
void Vector<T>::push_back(const T & t)
{
	if(size() == capacity())
	{
		//size=capacity,需要动态扩容
		reallocator();
	}
	//在此调用空间配置器的construct，
	//比如：你的这块内存要将对象才上来，总得construct吧
	//具体查文档，看源码
	_alloc.construct(_finish++, t); 
}
//退出操作，有点复杂。只要在于扩容方面的操作
template <typename T>
void Vector<T>::pop_back()
{
	//注意左闭右开，所以是--_finssh,上面有体现
	if(_start != _finish)
	{
		_alloc.destroy(--_finish);
	}
}

//动态扩容
template<typename T>
void Vector<T>::reallocator()
{
	size_t oldCapacity = capacity(); //原来的capacity
	size_t newCapacity = oldCapacity ? 2 * oldCapacity : 1;
	//vector的增长方式2的指数增长
	T * tmp = _alloc.allocate(newCapacity);//配置器的开空间方法
	if(_start)
	{
		//在此要进行整体搬迁，方案一memcpy，方案二：调用
		//STL的算法部件中的copy算法
		//在此都不好用，memcpy针对内置类型，而这有你自定义的类型
		//copy前提条件是=2边都要先有对象，但是新开出来的空间没有初始化
		std::uninitialized_copy(_start, _finish, tmp);
		while(_start != _finish)
		{
			_alloc.destroy(--_finish);
		}
		_alloc.deallocate(_start, oldCapacity);
		//在此是要进行深拷贝的
	}
	_start = tmp;
	_finish = _start + oldCapacity;
	_end_of_storage = _start + newCapacity;
}
