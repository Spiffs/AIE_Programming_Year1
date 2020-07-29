using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.Threading.Tasks;
using MathClasses;
using Raylib;
using static Raylib.Raylib;
using System.Runtime.CompilerServices;
using System.Runtime.ExceptionServices;
using System.Net.Http.Headers;
using System.Xml.Serialization;

namespace TankGame
{
    public class Game
    {
        Stopwatch stopwatch = new Stopwatch();

        private long currentTime = 0;
        private long lastTime = 0;
        private float timer = 0;
        private int fps = 1;
        private int frames;

        private float deltaTime = 0.005f;

        public bool projectile = false;
        public int speed = 1200;

        public int projectilecooldown;
        public int preprojectilecooldown;

        //Objects
        SceneObject earthObject = new SceneObject();

        SceneObject tankObject = new SceneObject();
        SceneObject turretObject = new SceneObject();

        //Sprites
        SpriteObject tankSprite = new SpriteObject();
        SpriteObject turretSprite = new SpriteObject();

        //Projectiles
        List<SceneObject> ProjectileSceneObjects = new List<SceneObject>();
        List<SpriteObject> ProjectileSpriteObjects = new List<SpriteObject>();

        //Acceleration
        int wacceleration;
        int sacceleration;
        bool forwardslowdown = false;
        bool backwardslowdown = false;

        public void Init()
        {
            stopwatch.Start();
            lastTime = stopwatch.ElapsedMilliseconds;

            //Initiating tank sprite
            tankSprite.Load("tankBody_blue_outline.png");
            //Face the sprite the right way
            tankSprite.SetRotate(-90 * (float)(Math.PI / 180.0f));
            //Set the centrepoint of the tank
            tankSprite.SetPosition(-tankSprite.Width / 2.0f, tankSprite.Height / 2.0f);

            //Initiating turret sprite
            turretSprite.Load("tankBlue_barrel1_outline.png");
            //Face the correct way
            turretSprite.SetRotate(-90 * (float)(Math.PI / 180.0f));
            // set the turret offset from the tank base 
            turretSprite.SetPosition(0, turretSprite.Width / 2.0f);

            //Adding Children
            turretObject.AddChild(turretSprite);
            tankObject.AddChild(tankSprite);
            tankObject.AddChild(turretObject);
            earthObject.AddChild(tankObject);
            tankObject.SetPosition(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f);
        }


        public void Shutdown() { }

        public void Update()
        {
            currentTime = stopwatch.ElapsedMilliseconds;
            deltaTime = (currentTime - lastTime) / 1000.0f;

            timer += deltaTime;

            if (timer >= 1)
            {
                fps = frames;
                frames = 0;
                timer -= 1;
            }

            frames++;

            


            #region ||MOTION||

            if (!IsKeyDown(KeyboardKey.KEY_W))
            {
                if (forwardslowdown)
                {
                    wacceleration -= 3;
                    if (wacceleration <= 0) { forwardslowdown = false; }

                    MathClasses.Vector3 facing = new MathClasses.Vector3(tankObject.LocalTransform.m1, tankObject.LocalTransform.m2, 1)
                                                 * deltaTime * wacceleration;
                    tankObject.Translate(facing.x, facing.y);
                    DrawText(wacceleration.ToString(), 10, 460, 8, Color.LIGHTGRAY);
                }
            }

            if (!IsKeyDown(KeyboardKey.KEY_S))
            {
                if (backwardslowdown)
                {
                    sacceleration -= 3;
                    if (sacceleration <= 0) { backwardslowdown = false; }

                    MathClasses.Vector3 facing = new MathClasses.Vector3(tankObject.LocalTransform.m1, tankObject.LocalTransform.m2, 1)
                                                 * deltaTime * -sacceleration;
                    tankObject.Translate(facing.x, facing.y);
                    DrawText(sacceleration.ToString(), 30, 460, 8, Color.LIGHTGRAY);
                }
            }


            #endregion


            #region ||CONTROLS||

            //Rotate Left on A
            if (IsKeyDown(KeyboardKey.KEY_A))
            {
                tankObject.Rotate(-deltaTime);
            }

            //Rotate Right on D
            if (IsKeyDown(KeyboardKey.KEY_D))
            {
                tankObject.Rotate(deltaTime);
            }

            //Forward on W
            if (IsKeyDown(KeyboardKey.KEY_W))
            {
                wacceleration += 2;
                if (wacceleration > 100) { wacceleration = 100; }
                forwardslowdown = true;

                MathClasses.Vector3 facing = new MathClasses.Vector3(tankObject.LocalTransform.m1, tankObject.LocalTransform.m2, 1)
                                        * deltaTime * wacceleration;
                tankObject.Translate(facing.x, facing.y);
                DrawText(wacceleration.ToString(), 10, 460, 8, Color.LIGHTGRAY);
            }

            //Reverse on S
            if (IsKeyDown(KeyboardKey.KEY_S))
            {
                sacceleration += 2;
                if (sacceleration > 70) { sacceleration = 70; }
                backwardslowdown = true;

                MathClasses.Vector3 facing = new MathClasses.Vector3(tankObject.LocalTransform.m1, tankObject.LocalTransform.m2, 1)
                                             * deltaTime * -sacceleration;
                tankObject.Translate(facing.x, facing.y);
                DrawText(sacceleration.ToString(), 30, 460, 8, Color.LIGHTGRAY);
            }

            //Rotate turret Lefto on Q
            if (IsKeyDown(KeyboardKey.KEY_Q))
            {
                turretObject.Rotate(-deltaTime);
            }

            //Rotate turret Right on E
            if (IsKeyDown(KeyboardKey.KEY_E))
            {
                turretObject.Rotate(deltaTime);
            }

            #endregion


            #region ||PROJECTILE||

            if (projectile)
            {
                try
                {
                    //Moves Projectiles
                    foreach (SceneObject projectileObject in ProjectileSceneObjects)
                    {
                        MathClasses.Vector3 facing = new MathClasses.Vector3(projectileObject.LocalTransform.m1, projectileObject.LocalTransform.m2, 1)
                                     * deltaTime * speed;
                        projectileObject.Translate(facing.x, facing.y);

                        //Collision
                        if ((projectileObject.GlobalTransform.m7 < 0 ||
                             projectileObject.GlobalTransform.m7 > GetScreenWidth() ||
                             projectileObject.GlobalTransform.m8 < 0 ||
                             projectileObject.GlobalTransform.m8 > GetScreenHeight()))
                        {
                            ProjectileSceneObjects.Clear();
                            Console.WriteLine("HIT");
                            ProjectileSceneObjects.Clear();
                            ProjectileSpriteObjects.Clear();
                        }
                    }
                }
                catch { }
                //Cooldown
                preprojectilecooldown++;

                if (preprojectilecooldown >= 2)
                {
                    projectilecooldown++;
                    preprojectilecooldown = 0;
                }

                //Reset
                if (projectilecooldown >= 101)
                {
                    ProjectileSceneObjects.Clear();
                    ProjectileSpriteObjects.Clear();
                    projectilecooldown = 0;
                    projectile = false;
                }
            }

            //On Space shoot projectile
            if (IsKeyDown(KeyboardKey.KEY_SPACE))
            {
                if (!projectile)
                {
                    //Creating Projectile Sprite and Objects
                    SceneObject projectileObject = new SceneObject();
                    SpriteObject projectileSprite = new SpriteObject();

                    //Show the Projectile
                    projectileSprite.Load("bulletBlue1_outline.png");
                    //Face the sprite the right way
                    projectileSprite.SetRotate(90 * (float)(Math.PI / 180.0f));
                    projectileSprite.SetPosition(0, -7);

                    projectileObject.AddChild(projectileSprite);

                    //Transform and Rotate the Projectile to the Turret
                    turretObject.AddChild(projectileObject);
                    projectileObject.UpdateTransform();
                    turretObject.RemoveChild(projectileObject);

                    ProjectileSceneObjects.Add(projectileObject);
                    ProjectileSpriteObjects.Add(projectileSprite);

                    projectileObject.UniqueTransform();

                    //"Cooldown"
                    projectilecooldown = 0;
                    preprojectilecooldown = 0;
                }
                projectile = true;

            }

            earthObject.Update(deltaTime);

            #endregion


            lastTime = currentTime;
        }

        public void Draw()
        {
            BeginDrawing();

            ClearBackground(Color.WHITE);
            DrawText(fps.ToString(), 10, 10, 12, Color.RED);

            if (projectile)
            {
                DrawText(projectilecooldown.ToString(), 600, 10, 20, Color.BLUE);
            }

            earthObject.Draw();

            foreach (SpriteObject projectileSprite in ProjectileSpriteObjects)
            {
                projectileSprite.Draw();
            }

            EndDrawing();
        }
    }
}
