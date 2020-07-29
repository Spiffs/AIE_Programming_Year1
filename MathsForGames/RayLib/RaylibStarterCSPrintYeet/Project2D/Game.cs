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

            SetTargetFPS(60);

            while (!WindowShouldClose())
            {

                BeginDrawing();

                ClearBackground(Color.RAYWHITE);

                DrawText("Yeet", 300, 200, 100, Color.RED);

                EndDrawing();

            }

            CloseWindow();

        }

    }
}
