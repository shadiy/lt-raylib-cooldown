#include <stdio.h>

#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include "lt-cooldown.h"

int main(int argc, char *argv[]) {
    InitWindow(1280, 720, "lt-cooldown");

    SetTargetFPS(60);

    float cooldown = 65;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        cooldown -=  GetFrameTime();

        DrawRectangle(100 - 25, 100 - 25, 50, 50, ORANGE);
        LTGuiCircleCooldown((Vector2){100, 100}, 20, 25, (Color){61, 61, 61, 128}, 0, 65, cooldown);

        DrawRectangle(200 - 25, 100 - 25, 50, 50, ORANGE);
        LTGuiSquareCooldown((Vector2){200, 100}, 50, (Color){61, 61, 61, 128}, 0, 65, cooldown);
        LTGuiCooldownText((Vector2){200, 100}, 32, WHITE, cooldown);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}