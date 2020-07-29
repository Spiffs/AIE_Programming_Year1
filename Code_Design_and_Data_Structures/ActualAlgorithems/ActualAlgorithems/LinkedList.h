#pragma once
#include <iostream>
#include <Windows.h>

// a_value is the specific value of data of the object 
// a_location is the location of the specific value in the list

class LinkedList
{
public:
	LinkedList();

	~LinkedList();

	void PushFront(int a_value);

	void PushBack(int a_value);

	void Insert(int a_location, int a_value);

	int Count();

	void PopFront();

	void PopBack();

	void Remove(int a_value);

	void Erase(int a_location);

	void Remove(int a_value);

	int First();

	int Last();

	void Begin();

	void End();

	bool Empty();

	void Clear();

	void CheckLength();

	void ChangeLength(int a_length);

private:
	int m_allocatedlength = 5;
	int m_usedlength = 0;
	LinkedListObject* m_list;

};

class LinkedListObject
{
public:
	LinkedListObject()
	{

	}

	LinkedListObject(int a_previous, int a_data, int a_next)
	{
		m_previous = a_previous;
		m_data = a_data;
		m_next = a_next;
	}

	~LinkedListObject()
	{

	}

	int GetPrevious()
	{
		return m_previous;
	}

	void SetPrevious(int a_value)
	{
		m_previous = a_value;
	}

	int GetData()
	{
		return m_data;
	}

	void SetData(int a_value)
	{
		m_data = a_value;
	}

	int GetNext()
	{
		return m_next;
	}

	void SetNext(int a_value)
	{
		m_next = a_value;
	}

private:
	int m_previous = NULL;
	int m_data;
	int m_next = NULL;
};