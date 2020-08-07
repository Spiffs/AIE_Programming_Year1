#pragma once
#include <vector>
#include "raylib.h"
#include "WinInc.h"
#include <windows.h>
#include <iostream>

struct Entity {
	float x = 0, y = 0;
	float rotation = 0;
	float speed = 0;
	unsigned char r = 0, g = 0, b = 0;
	float size = 1;
};

class EntityDisplayApp  {
public:
	EntityDisplayApp(int screenWidth = 800, int screenHeight = 450);
	~EntityDisplayApp();

	bool Startup();
	void Shutdown();

	void Update(float deltaTime);
	void Draw();

	void ReadEntries()
	{
		//DWORD* numentries;
		mappedEntitiySizeFileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"bd5784ac-c657-4bf1-abe3-02fd44fdf5f1");
		mappedEntitiyFileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"bd5784ac-c657-4bf1-abe3-02fd44fdf5f0");

		int* pNumEntities = (int *)MapViewOfFile(mappedEntitiySizeFileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(int));

		if (pNumEntities == nullptr)
			return;

		// TODO: make sure m_entities has the right number of items in the collectiuon.

		if ((int)m_entities.size() < *pNumEntities)
		{
			int pEntitySize = m_entities.size();
			for (int i = pEntitySize; i < *pNumEntities; i++)
			{
				m_entities.push_back(Entity());
			}
		}

		int size = sizeof(Entity) * *pNumEntities;
		Entity* data = (Entity*)MapViewOfFile(mappedEntitiyFileHandle, FILE_MAP_ALL_ACCESS, 0, 0, size);
		for (int i = 0; i < *pNumEntities; i++)
		{
			m_entities[i] = data[i]; // write to our mapped memory
		}

		

		// UnmapViewOfFile(data);
	}

protected:
	int m_screenWidth;
	int m_screenHeight;

	//DWORD* data;

	HANDLE mappedEntitiySizeFileHandle;
	HANDLE mappedEntitiyFileHandle;

	// an array of an unknown number of entities

	std::vector<Entity> m_entities;
};