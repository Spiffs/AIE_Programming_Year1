#pragma once

#ifndef _DYNAMIC_ARRAY_
#define _DYNAMIC_ARRAY_

class DynamicArray
{
public:
	DynamicArray();

	DynamicArray(int a_length);

	~DynamicArray();

	void RemoveEnd();

	void AddEnd(int a_additionalvalue);

	void RemoveMiddle();

	void AddMiddle(int a_additionalvalue);

	void ChangeLength(int a_length);

	void CheckLength();

	void CheckOnlyPositiveLength();

	int PrintAt(int i);

	void Clear();

private:
	int m_usedlength = 0;
	int m_allocatedlength = 5;
	int* m_DA;

};

#endif