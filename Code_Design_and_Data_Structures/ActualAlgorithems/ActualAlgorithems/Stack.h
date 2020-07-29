#pragma once

#ifndef _STACK_
#define _STACK_

// stack class creates a stack class 
class Stack
{
public:
	Stack();

	~Stack();

	int getarray(int position);

	void setarray(int position, int value);

	bool empty();

	int size();

	void push(int newvalue);

	void pop();

	int top();

private:
	int m_arraylength = 0;
	int m_array[100];

};

#endif