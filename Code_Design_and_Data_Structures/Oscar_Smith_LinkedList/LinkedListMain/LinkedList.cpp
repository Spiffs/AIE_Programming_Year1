#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
	m_list = new LinkedListObject[m_allocatedlength];
}

LinkedList::~LinkedList()
{
	delete[] m_list;
}

// inserts an object to the FRONT of the list 
void LinkedList::PushFront(int a_value)
{
	// creating variables to hold new values
	int a_previous = NULL;
	int a_data = a_value;
	int a_next = NULL;

	// if the array equals zero then the function will make the next and pervious to equal NULL
	if (m_usedlength == 0)
	{
		a_previous = NULL;
		a_next = NULL;
	}
	// else, it can fetch those values
	else
	{
		for (int i = m_usedlength; i > 0; i--)
		{
			m_list[i] = m_list[i - 1];
		}
		a_next = m_list[1].GetData();
		m_list[1].SetPrevious(a_value);
	}

	LinkedListObject newobj(a_previous, a_data, a_next);
	m_list[0] = newobj;
	m_usedlength++;

	CheckLength();
}

// inserts an object to the BACK of the list
void LinkedList::PushBack(int a_value)
{
	// creating variables to hold new values
		// gets the pervious value to input into the new variable 
	int a_previous = m_list[m_usedlength - 1].GetData();
	// gets value of the functions input 
	int a_data = a_value;
	int a_next = NULL;

	// sets the pervious last variables next value to the new value
	m_list[m_usedlength].SetNext(a_value);


	LinkedListObject newobj(a_previous, a_data, a_next);
	m_list[m_usedlength] = newobj;
	m_usedlength++;

	CheckLength();
}

// inserts a value to a certain point in the list
void LinkedList::Insert(int a_location, int a_value)
{
	// moving list values up to counter for the new value
	for (int i = m_usedlength; i > a_location - 1; i--)
	{
		m_list[i] = m_list[i - 1];
	}

	// creating newvalue 
	int a_previous = m_list[a_location - 2].GetData();
	int a_data = a_value;
	int a_next = m_list[a_location].GetData();

	LinkedListObject newobj(a_previous, a_data, a_next);
	m_list[a_location - 1] = newobj;
	m_usedlength++;

	// fixing surrounding values
	m_list[a_location - 2].SetNext(a_value);
	m_list[a_location].SetPrevious(a_value);

	CheckLength();
}

// returns the value of numbers in the list 
int LinkedList::Count()
{
	return m_usedlength;
}

// removes the first number off the list
void LinkedList::PopFront()
{
	// all variables are replaced by their postdecessor
	for (int i = 0; i < m_usedlength; i++)
	{
		m_list[i] = m_list[i + 1];
	}

	// deleting the last variable after replacement
	m_list[m_usedlength - 1].Delete();
	m_usedlength--;

	// fixing the pervious value of the new first value
	m_list[0].SetPrevious(NULL);

	// check list for length fixes
	CheckLength();
}

// removes the last value of the list 
void LinkedList::PopBack()
{
	// deleting last value
	m_list[m_usedlength - 1].Delete();
	m_usedlength--;

	// replacing next value for previous node
	m_list[m_usedlength - 1].SetPrevious(NULL);

	// checking for length fixes
	CheckLength();
}

// removes value witha  certain value
void LinkedList::Remove(int a_value)
{
	int a_location = Search(a_value);

	// cycling through editing positions of list values to counter for the removed value
	for (int i = a_location; i < m_usedlength; i++)
	{
		m_list[i] = m_list[i + 1];
	}
	m_usedlength--;
	//m_list[m_usedlength].Delete();																								HAXXOR

	// fixing surrounding values
	m_list[a_location - 1].SetNext(m_list[a_location].GetData());
	m_list[a_location].SetPrevious(m_list[a_location - 1].GetData());

	// checking for length fixes
	CheckLength();
}

// removes value at a certain point
void LinkedList::Erase(int a_location)
{
	// cycling through editing positions of list values to counter for the removed value
	for (int i = a_location - 1; i < m_usedlength; i++)
	{
		m_list[i] = m_list[i + 1];
	}
	m_usedlength--;
	//m_list[m_usedlength].Delete();																								HAXXOR

	// fixing surrounding values
	m_list[a_location - 2].SetNext(m_list[a_location - 1].GetData());
	m_list[a_location - 1].SetPrevious(m_list[a_location - 2].GetData());

	// checking for length fixes
	CheckLength();
}

// returns the first value of the list returns -1 on fail
int LinkedList::First()
{
	if (m_list[0].GetData() == NULL)
	{
		return -1;
	}
	else
		return m_list[0].GetData();
}

// returns the last value of the list returns -1 on fail
int LinkedList::Last()
{
	if (m_list[m_usedlength - 1].GetData() == NULL)
	{
		return -1;
	}
	else
	{
		return m_list[m_usedlength - 1].GetData();
	}
}

// returns the pacement of the first value of the list returns -1 on fail
int LinkedList::Begin()
{
	return 0;
}

// returns the position of the last value in the list
int LinkedList::End()
{
	return m_usedlength - 1;
}

// returns bool testing if the list is empty or not
bool LinkedList::Empty()
{
	if (m_usedlength == 0)
	{
		return true;
	}
	else
		return false;
}

// clears all values in the list
void LinkedList::Clear()
{
	for (int i = 0; i < m_usedlength - 1; i++)
	{
		m_list[i].Delete();
		m_usedlength--;
	}

	CheckLength();
}

// checks the length of the array and resizes if too large or too small to save on memory
void LinkedList::CheckLength()
{
	if (m_allocatedlength <= m_usedlength + 5)
	{
		ChangeLength(5);
		CheckLength();
	}
	if (m_allocatedlength >= m_usedlength + 15)
	{
		ChangeLength(-5);
		CheckLength();
	}
}

// changes the length of the arrays allocated length
void LinkedList::ChangeLength(int a_length)
{
	LinkedListObject* newarr = new LinkedListObject[m_allocatedlength + a_length];
	LinkedListObject* orgarr = m_list;

	for (int i = 0; i < m_usedlength; i++)
	{
		newarr[i] = m_list[i];
	}

	m_list = newarr;
	m_allocatedlength += a_length;

	delete[] orgarr;
}

// search function returns i on matching values and returns -1 on fail
int LinkedList::Search(int a_value)
{
	for (int i = 0; i < m_usedlength; i++)
	{
		if (a_value == m_list[i].GetData())
			return i + 1;
	}
	// returns -1 on fail
	return -1;
}

void LinkedList::Sort()
{
	int n = Count();
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
		{
			if (m_list[j].GetData() > m_list[j + 1].GetData())
				Swap(j, j + 1);
		}
	}
}

void LinkedList::Swap(int _posa, int _posb)
{
	LinkedListObject temp = m_list[_posa];
	m_list[_posa] = m_list[_posb];
	m_list[_posb] = temp;

}