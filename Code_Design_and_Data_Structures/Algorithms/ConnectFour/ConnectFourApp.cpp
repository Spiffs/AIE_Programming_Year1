#include "ConnectFourApp.h"
#include "main.cpp"
#include "../AIE_RayLib_Template/raylib/src/raylib.h"

ConnectFourApp::ConnectFourApp() : m_isGameOver(false), m_currentPlayer(1) {

}

ConnectFourApp::~ConnectFourApp() {

}

bool ConnectFourApp::startup() {
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	*m_font = LoadFontEx("../bin/font/consolas.ttf", 32, 0, 250);
	*m_croissant = LoadTexture("../bin/textures/croissant.png");
	*m_cupcake = LoadTexture("../bin/textures/cake.png");

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			m_board[i][j] = 0;
		}
	}

	return true;
}

void ConnectFourApp::shutdown() {

	delete m_font;
	delete m_croissant;
	delete m_cupcake;
}

bool ConnectFourApp::checkForWin()
{
	// TODO: Complete this function
	return false;
}

void ConnectFourApp::update(float deltaTime) {
	static int height = GetScreenHeight();
	static int width = GetScreenWidth();
	static bool wasMouseDown = false;

	if (!m_isGameOver) {
		if (IsMouseButtonDown(0) && wasMouseDown == false)
		{
			Vector2 mouseposition = GetMousePosition();
			int x = mouseposition.x, y = mouseposition.y;

			float xInc = (width - (BORDER << 1)) / COLUMNS;
			int col = (x - BORDER) / xInc;

			if (col >= 0 && col < COLUMNS) {
				// find the lowest row and place a tile there
				for (int row = 0; row < ROWS; row++)
				{
					if (m_board[col][row] == 0) {
						m_board[col][row] = m_currentPlayer;

						m_currentPlayer = (m_currentPlayer == 1) ? 2 : 1;

						break;
					}
				}
			}
		}
		wasMouseDown = IsMouseButtonDown(0);

		m_isGameOver = checkForWin();
	}

	// exit the application
	WindowShouldClose();
}

void ConnectFourApp::draw() {
	static int height = GetScreenHeight();
	static int width = GetScreenWidth();

	// wipe the screen to the background colour
	ClearBackground(WHITE);

	// begin drawing sprites
	BeginDrawing();

	// draw game board
	float xInc = (width - (BORDER << 1)) / COLUMNS;
	float yInc = (height - (BORDER << 1)) / ROWS;
	for (int x = 0; x <= COLUMNS; x++) {
		DrawLine(BORDER + x*xInc, BORDER + yInc*ROWS, BORDER + x*xInc, BORDER, BLACK);
	}
	for (int y = 0; y <= ROWS; y++) {
		DrawLine(BORDER, BORDER + y*yInc, BORDER + xInc*COLUMNS, BORDER + y*yInc, BLACK);
	}

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			if (m_board[i][j] == 1) {
				DrawTexture(*m_croissant, 50 + i*xInc, 50 + j*yInc, WHITE);
			}
			else if (m_board[i][j] == 2) {
				DrawTexture(*m_cupcake, 50 + i*xInc, 50 + j*yInc, WHITE);
			}
		}
	}

	if (m_isGameOver) {
		DrawTextEx(*m_font, "GAME OVER", Vector2{ (float)(width >> 1) - 50, (float)height - 30 }, 32, 2, BLACK);
	}
	else {
		if (m_currentPlayer == 1) {
			DrawTextEx(*m_font, "Player 1 go", Vector2{ 10, (float)height - 30 }, 12, 2, GREEN);
		}
		else {
			DrawTextEx(*m_font, "Player 2 go", Vector2{ 10, (float)height - 30 }, 12, 2, RED);
		}
	}

	// output some text, uses the last used colour
	DrawTextEx(*m_font, "Press ESC to quit", Vector2{ 0, 0 }, 12, 2, BLACK);

	// done drawing sprites
	EndDrawing();
}