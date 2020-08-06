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

class EntityEditorApp {
public:
	EntityEditorApp(int screenWidth = 800, int screenHeight = 450);
	~EntityEditorApp();

	bool Startup();
	void Shutdown();

	void Update(float deltaTime);
	void Draw();

	void SendEntries()
	{
		int size = sizeof(m_entities) / sizeof(m_entities[0]);

		HANDLE fileHandle = CreateFileMapping(
			INVALID_HANDLE_VALUE,
			NULL,
			PAGE_READWRITE,
			0, size,
			L"MySharedMemory"
		);

		void * data = MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, size);

		CopyMemory(data, m_entities, size);
		CloseHandle(fileHandle);

		UnmapViewOfFile(data);
	}

protected:
	int m_screenWidth;
	int m_screenHeight;

	// define a block of entities that should be shared
	enum { ENTITY_COUNT = 10 };
	Entity m_entities[ENTITY_COUNT];

	HANDLE h;
};