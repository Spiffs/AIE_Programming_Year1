using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Raylib;
using static Raylib.Raylib;

namespace Project2D
{
    class Game
    {
        public static void Start()
        {
            const int screenWidth = 800;
            const int screenHeight = 450;

            InitWindow(screenWidth, screenHeight, "Yes");

            Vector2 ballPosition = float screenWidth / 2,  float screenHeight / 2;

            SetTargetFPS(60);

            while (!WindowShouldClose())
            {
                if (IsKeyDown(KeyboardKey.KEY_RIGHT)) ballPosition.x += 2.0f;
                if (IsKeyDown(KeyboardKey.KEY_LEFT)) ballPosition.x -= 2.0f;
                if (IsKeyDown(KeyboardKey.KEY_UP)) ballPosition.y -= 2.0f;
                if (IsKeyDown(KeyboardKey.KEY_DOWN)) ballPosition.y += 2.0f;

                BeginDrawing();

                

            }

            CloseWindow();

        }

    }
}
