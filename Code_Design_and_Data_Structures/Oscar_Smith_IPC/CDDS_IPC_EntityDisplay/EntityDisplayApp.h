#pragma once
#include <vector>
#include "raylib.h"
#include "WinInc.h"

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
		HANDLE fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MySharedMemory");

		DWORD *data = (DWORD*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, 0);

		numentries = *data;
		
		Entity* tmpEntries = (Entity*)(data + 1);

		for (int i = 0; i < *data; i++) 
		{
			m_entities.push_back(tmpEntries[i]);
		}

		UnmapViewOfFile(data);
		CloseHandle(fileHandle);
	}

protected:
	int m_screenWidth;
	int m_screenHeight;

	// an array of an unknown number of entities
	DWORD numentries;
	std::vector<Entity> m_entities;
};