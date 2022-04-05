/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Player.h"
#include "SpawnVolume.h"
#include "vector"
#include "stdio.h"

#define MAXBULLETS 30

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1280;
    int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    
    Player Player(screenWidth/2, screenHeight/2);
    SpawnVolume spawner(screenWidth,screenHeight);

    std::vector<Enemy> enemyList;
    std::vector<Bullet> bulletList;
    std::vector<Bullet>::iterator it;

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update - Always Update First
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        
        // Check to Move Player if Alive.
        if (Player.checkAlive()) {
            
            // Update Player Position
            Player.movePlayer();

            // Create a Bullet.
            Player.shoot(bulletList);

            // Update each Bullet
            for (Bullet& bullet : bulletList) {
                bullet.calcBullet();
            }

            // Update each Enemy
            for (Enemy &enemy : enemyList) {
                if (enemy.getAlive()) {

                    for (it = bulletList.begin(); it != bulletList.end(); it++) {

                        // Check each Bullet Collision with an each Enemy
                        enemy.checkPlayerAttack(*it);

                    }

                    // Remove Bullets that are 'dead'
                    bulletList.erase(
                        std::remove_if(bulletList.begin(), bulletList.end(), [&](Bullet x) {return (x.reachDest) ; })
                        , bulletList.end());

                    // Update Enemy Position
                    enemy.moveEnemy(Player);

                    // Check and Update on Enemy collision with Player.
                    enemy.checkCollidePlayer(Player);
                    
                }
            }

            // Update Enemy Spawner
            spawner.spawnEnemy(enemyList);
        }
        if (IsKeyDown(KEY_P)) {
            Player.setAlive(false);
        }

        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        DrawText("Survive", screenWidth/2-40, screenHeight/2 + 10, 20, LIGHTGRAY);

        // Draw Player
        if (Player.checkAlive()) {
            Player.drawPlayer();
            Player.drawSwordPointer();

            for (Enemy enemy : enemyList) {
                for (Bullet& bullet : bulletList) {
                    bullet.drawBullet();
                    enemy.checkPlayerAttack(bullet);
                }
                if (enemy.getAlive()) {
                    enemy.drawEnemy();
                }
            }

        }
        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
