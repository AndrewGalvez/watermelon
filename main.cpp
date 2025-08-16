#include "raylib.h"
#include <string>

bool isMouseOn(Rectangle dest) {
  Vector2 mpos = GetMousePosition();

  return mpos.x > dest.x && mpos.x < dest.x + dest.width && mpos.y > dest.y &&
         mpos.y < dest.y + dest.height;
}

int main() {
  InitWindow(600, 600, "Watermelon Clicker");

  SetTargetFPS(60);

  Texture2D watermelon_tex = LoadTexture("watermelon_normal_big.png");
  int watermelons = 0;
  int timebonuswatermelons = 30;

  int tseconds = 60;
  int tsit = 60;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    std::string wstr = std::to_string(watermelons);

    DrawText(wstr.c_str(), 300 - (MeasureText(wstr.c_str(), 70) / 2), 2, 70,
             WHITE);
    DrawText("watermelons", 300 - (MeasureText("watermelons", 32) / 2),
             2 + 72 + 42, 32, WHITE);

    std::string wbstr = std::to_string(timebonuswatermelons);

    DrawText(wbstr.c_str(), 300 - (MeasureText(wbstr.c_str(), 40) / 2), 75, 40,
             GREEN);

    DrawTexturePro(watermelon_tex, {0, 0, 25, 25}, {250, 300, 100, 100}, {0, 0},
                   0.0f, WHITE);

    std::string tstr = std::to_string((tseconds - tseconds % 60) / 60) + ':' +
                       std::to_string(tseconds % 60);

    DrawText(tstr.c_str(), 300 - (MeasureText(tstr.c_str(), 48) / 2), 600 - 50,
             48, tseconds > 30 ? GREEN : RED);

    EndDrawing();

    if ((isMouseOn({250, 300, 100, 100}) &&
         IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) ||
        IsKeyPressed(KEY_SPACE)) {
      watermelons++;
      if (watermelons == timebonuswatermelons) {
        tseconds += 10;
        timebonuswatermelons *= 2;
      }
    }

    tsit--;
    if (tsit == 0) {
      tsit = 60;
      tseconds--;
      if (tseconds == 0) {
        break;
      }
    }
  }

  CloseWindow();
  return 0;
};
