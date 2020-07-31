#pragma once
#include <iostream>
#include <Windows.h>

// a_value is the specific value of data of the object 
// a_location is the location of the specific value in the list
template<class TNodeData, class TEdgeData>
class LinkedListObject;


template<class TNodeData, class TEdgeData>
class LinkedList
{
protected:
	int m_allocatedlength = 10;
	int m_usedlength = 0;
	LinkedListObject* m_list;


public:
	LinkedList();

	~LinkedList();

	void PushFront(TNodeData a_value);

	void PushBack(TNodeData a_value);

	void Insert(int a_location, TNodeData a_value);

	int Count();

	void PopFront();

	void PopBack();

	void Remove(TNodeData a_value);

	void Erase(int a_location);

	Node* First();

	Node* Last();

	int Begin();

	int End();

	bool Empty();

	void Clear();

	void CheckLength();

	void ChangeLength(int a_length);

	int Search(TNodeData a_value);


};

template<class TNodeData, class TEdgeData>
class LinkedListObject
{
public:
	struct Node;
	struct Edge;


	struct Node
	{
		TNodeData data;
		std::vector<Edge> connections;
	};

	struct Edge
	{
		Node* to;
		TEdgeData data;
	};


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

	void Delete()
	{
		m_previous = NULL;
		m_data = NULL;
		m_next = NULL;
	}

private:
	int m_previous = NULL;
	int m_data = NULL;
	int m_next = NULL;
};