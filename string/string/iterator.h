#ifndef __ITERATOR_H__
#define __ITERATOR_H__
#include <iostream>
template <class T>
class input_iterator
{
	T* m_value;
public:
	input_iterator(T* value)
	{
		m_value = value;
	}
	input_iterator operator=(const input_iterator& input)
	{
		m_value = input.m_value;
	}
	input_iterator operator++()
	{
		m_value++;
		return *this;
	}
	input_iterator operator+(int add)
	{
		m_value += add;
		return *this;
	}
	bool operator==(const input_iterator & compare)
	{
		return m_value == compare.m_value;
	}
	bool operator!=(const input_iterator & compare)
	{
		return m_value != compare.m_value;
	}
	T& operator*()
	{
		return *m_value;
	}
};
template <class T>
class output_iterator
{
	T* m_value;
public:
	output_iterator(T* value)
	{
		m_value = value;
	}
	output_iterator(const output_iterator& output)
	{ 
		m_value=output
	}
	output_iterator operator++()
	{
		m_value++;
		return *this;
	}
	output_iterator operator++(int value)
	{
		m_value += value;
		return *this;
	}
	output_iterator operator=(int m_value)
	{ 
		*m_value = value;
	}
};
template <class T>
class forward_itorator:public input_iterator<T>
{
public:
	forward_itorator(T *value) :input_iterator(value){};
	forward_itorator(const forward_itorator& input) :input_iterator(input);
	forward_iterotor operator=(int value)
	{
		*m_value = value;
		return *this;
	}
};
template <class T>
class bidirectional_iterator :public forward_itorator<T>
{
public:
	//bidirectional_itorater(T* value) :input_iterator(value);
	bidirectional_iterator(const bidirectional_iterator& clone) :input_iterator(clone);
	bidirectional_iterator operator--()
	{ 
		m_value--;
		return *this;
	}
	bidirectional_iterator operator--(int reduce)
	{
		m_value -= reduce;
		return *this;
	}
};
template <class T>
class random_iterator :public forward_itorator<T>
{
public:
	random_iterator(T* value) :input_iterator(value);
	random_iterator(const ramdom_iterator& iter) :input_iterator(iter);
	bool operator<(const ramdom_iterator &iter)
	{
		return *m_value < *iter.m_value;
	}
	bool operator>(const random_iterator &iter)
	{
		return *m_value > *iter.m_value;
	}
	bool operator<=(const random_iterator &iter)
	{
		return *m_value <= *iter.m_value;
	}
	bool operator>=(const random_iterator& iter)
	{
		return *m_value >= *iter.m_value;
	}
};
#endif