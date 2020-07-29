#pragma once
#include "../AIE_RayLib_Template/raylib/src/raylib.h"

const int COLUMNS = 7;
const int ROWS = 6;
const int BORDER = 50;

class ConnectFourApp {
public:

	ConnectFourApp();
	virtual ~ConnectFourApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	bool checkForWin();

protected:
	Font*	m_font;

	int					m_board[COLUMNS][ROWS];
	int					m_currentPlayer;
	bool				m_isGameOver;	// be careful, base class defines m_gameOver (which will close the app)

	Texture2D* m_croissant;
	Texture2D* m_cupcake;
};