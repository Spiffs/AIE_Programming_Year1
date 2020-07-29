#pragma once

#include "Player.h"

#ifndef _DYNAMIC_ARRAY_
#define _DYNAMIC_ARRAY_

class DynamicArray
{
public:
	DynamicArray();

	DynamicArray(int a_length);

	~DynamicArray();

	void RemoveEnd();

	void AddEnd(int a_score, char a_name[4]);

	void UpdatePos(int position, int a_score);

	void RemoveMiddle();

	void AddMiddle(int a_score, char a_name[4]);

	void ChangeLength(int a_length);

	void CheckLength();

	int Length();

	void CheckOnlyPositiveLength();

	Player PrintAt(int i);

	void Clear();

	void ReadFile();

	void WriteFile();

	void Highscores();

	void NameSort();

	int BinarySort(char a_name[4]);

	int GetScore(int position);

	char* GetName(int position);

private:
	int m_usedlength = 0;
	int m_allocatedlength = 5;
	Player* m_DA;

};

#endif