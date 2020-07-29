﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Raylib;
using static Raylib.Raylib;

namespace TankGame
{
    class Program
    {
        static void Main(string[] args)
        {
            Game game = new Game();

            SetTargetFPS(60);
            InitWindow(640, 480, "2D TANK");

            game.Init();
            
            while(!WindowShouldClose())
            {
                game.Update();
                game.Draw();
            }

            game.Shutdown();
            CloseWindow();
        }
    }
}
