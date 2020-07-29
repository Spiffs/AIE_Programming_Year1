#include "DynamicArray.h"
#include <iostream>

// empty constructor
DynamicArray::DynamicArray()
{
	m_DA = new int[5];

	for (int i = 0; i < 3; i++)
	{
		m_usedlength++;
		m_DA[i] = i + 1;
	}
}

// int constructor using array length 
DynamicArray::DynamicArray(int a_length)
{
	m_DA = new int[5 + a_length];
	
	m_allocatedlength = 5 + a_length;
}

// destructor
DynamicArray::~DynamicArray()
{
	delete[] m_DA;
}

// removes the last value of the array
void DynamicArray::RemoveEnd()
{
	m_usedlength--;
	m_DA[m_usedlength] = NULL;

	if (m_allocatedlength <= m_usedlength + 5)
	{
		ChangeLength(5);
	}
}

// adds a value to the end of the array
void DynamicArray::AddEnd(int a_additionalvalue)
{
	m_DA[m_usedlength] = a_additionalvalue;
	m_usedlength++;
	CheckLength();
}

// removes the middle value of the array
// (if the array length is an odd number it will round down)
void DynamicArray::RemoveMiddle()
{
	if (m_usedlength >= 2)
	{
		m_DA[m_usedlength / 2] = NULL;
	}

	// moves all values after the removed value to fill in empty space
	for (int i = (m_usedlength / 2) + 1; i < m_usedlength; i++)
	{
		m_DA[i - 1] = m_DA[i];
	}
}

// adds a value into the middle of the array
void DynamicArray::AddMiddle(int a_additionalvalue)
{
	for (int i = (m_usedlength - 1); i > m_usedlength / 2; i--)
	{
		m_DA[i] = m_DA[i + 1];
	}

	m_DA[m_usedlength / 2] = a_additionalvalue;
	CheckLength;
}

// changes the length of the arrays allocated length
void DynamicArray::ChangeLength(int a_length)
{
	int* newarr = new int[m_allocatedlength + a_length];
	int* orgarr = m_DA;

	for (int i = 0; i < m_usedlength; i++)
	{
		newarr[i] = m_DA[i];
	}

	m_DA = newarr;
	m_allocatedlength += a_length;

	delete[] orgarr;
}

// checks only if there is not enough space in the array to hold length while inputting values
void DynamicArray::CheckOnlyPositiveLength()
{
	if (m_allocatedlength <= m_usedlength + 5)
	{
		ChangeLength(5);
	}
}

// checks the length of the array and resizes if too large or too small to save on memory
void DynamicArray::CheckLength()
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

int DynamicArray::PrintAt(int i)
{
	return m_DA[i];
}

void DynamicArray::Clear()
{
	for (int i = 0; i < m_usedlength; i++)
	{
		m_DA[i] = NULL;
		CheckLength();
	}

	m_usedlength = 0;
}

