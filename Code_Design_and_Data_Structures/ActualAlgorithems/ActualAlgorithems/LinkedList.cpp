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
	int a_previous; 
	int a_data = a_value;
	int a_next;
	
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
		a_next = m_list[1].GetData;
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
	int a_previous = m_list[m_usedlength - 1].GetData;
		// gets value of the functions input 
	int a_data = a_value;
	int a_next = NULL;

	// sets the pervious last variables next value to the new value
	m_list[m_usedlength].SetNext(a_value);

	
	LinkedListObject newobj(a_previous, a_data, a_next);
	m_list[m_usedlength - 1] = newobj;
	m_usedlength++;
}

// inserts a value to a certain point in the list
void LinkedList::Insert(int a_location, int a_value)
{
	for (int i = m_usedlength; i > a_location - 1; i++)
	{
		m_list[i] = m_list[i + 1];
	}

	int a_previous = m_list[a_location - 1].GetData;
	int a_data = a_value;
	int a_next = m_list[a_location + 1].GetData;
	
	LinkedListObject newobj(a_previous, a_data, a_next);
	m_list[a_location] = newobj;
	m_usedlength++;

	CheckLength();
}

int LinkedList::Count()
{
	return m_usedlength;
}

void LinkedList::PopFront()
{
	for (int i = m_usedlength; i > 0; i++)
	{
		m_list[i] = m_list[i - 1];
	}


}



// checks the length of the array and resizes if too large or too small to save on memory
void LinkedList::CheckLength()
{
	if (m_allocatedlength <= m_usedlength + 5)
	{
		ChangeLength(5);
	}
	if (m_allocatedlength >= m_usedlength + 15)
	{
		ChangeLength(-5);
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