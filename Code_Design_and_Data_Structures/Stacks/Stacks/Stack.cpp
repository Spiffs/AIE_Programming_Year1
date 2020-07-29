#include "Stack.h"
#include <iostream>

int Stack::getarray(int position)
{
	return m_array[position];
}

void Stack::setarray(int position, int value)
{
	m_array[position] = value;
}

bool Stack::empty()
{
	if (size() == 0)
		return true;
	else
		return false;
}

int Stack::size()
{
	return m_arraylength;
}

void Stack::push(int newvalue)
{
	setarray(m_arraylength, newvalue);
	m_arraylength++;
}

void Stack::pop()
{
	m_arraylength--;
	setarray(m_arraylength, NULL);
}

int Stack::top()
{
	return getarray(m_arraylength - 1);
}

