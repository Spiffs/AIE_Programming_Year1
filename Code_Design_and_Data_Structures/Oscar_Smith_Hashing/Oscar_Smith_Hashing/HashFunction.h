#pragma once
#include <string>
#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;

template<typename TData, typename TValue>
class HashFunction
{
public:
	struct Entry
	{
		TData m_data;
		TValue m_value;
	};

public:

	HashFunction()
	{
		tablelength = 10;
		m_table = new Entry[tablelength];
	}

	HashFunction(int size)
	{
		tablelength = size;
		m_table = new Entry[tablelength];

	}

	~HashFunction()
	{
		delete[] m_table;
	}

	int IntHashFunction(TData& a_data)
	{
		int hashresult = 0;
		int length = a_data.length();
		for (int i = 0; i < length; i++)
		{
			hashresult += a_data.at(i);
		}
		hashresult %= tablelength;
		return hashresult;
	}

	int UpdateValue(TData& a_data, TValue& a_value)
	{
		for (int i = IntHashFunction(a_data); i < tablelength; i++)
		{
			if (m_table[i].m_data == a_data)
			{
				m_table[i].m_value = a_value;
				return -1;
			}
			else if (m_table[i].m_value == a_value)
			{
				m_table[i].m_data = a_data;
				return -1;
			}
			else if (m_table[i].m_data == "")
			{
				return i;
			}
		}
		return 0;
	}

	void AddEntry(TData a_data, TValue a_value)
	{
		int placement = UpdateValue(a_data, a_value);
		if (placement > 0)
		{
			m_table[placement].m_data = a_data;
			m_table[placement].m_value = a_value;
		}
		else if (placement == 0)
		{
			cout << "no space" << endl;
		}
	}

	TValue& GetValue(TData a_data)
	{
		for (int i = IntHashFunction(a_data); i < tablelength; i++)
		{
			if (m_table[i].m_data == a_data)
			{
				return m_table[i].m_value;
			}
		}
	}

	void Print()
	{
		for (int i = 0; i < tablelength; i++)
		{
			cout << i + 1 << ". ";
			if (m_table[i].m_data != "") {
				cout << m_table[i].m_data << " :  ";
				cout << m_table[i].m_value << endl;
			}
			else
			{
				cout << endl;
			}
		}
	}

	bool Exists(TData a_data)
	{
		for (int i = IntHashFunction(a_data); i < tablelength; i++)
		{
			if (m_table[i].m_data == a_data)
			{
				return true;
			}
		}
		return false;
	}

protected:
	int tablelength;
	Entry* m_table = nullptr;

};