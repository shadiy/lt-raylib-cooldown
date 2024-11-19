#pragma once
#include <raylib.h>

// Expects value in seconds
void LTGuiCircleCooldown(Vector2 center, float innerRadus, float outerRadius, Color color, float minValue, float maxValue, float value) {
    if (value <= minValue) return;
    if (value >= maxValue) return;

    float diff = maxValue - minValue;

    float percent = (value - minValue) / diff;

    float angle = -360 * percent;

    int segments = 26;
    if (angle > 90)  segments = 8;
    if (angle > 180) segments = 14;
    if (angle > 270) segments = 20;

    DrawRing(center, innerRadus, outerRadius, -90, angle - 90, segments, color);
}

// Expects value in seconds
void LTGuiSquareCooldown(Vector2 center, int width, Color color, float minValue, float maxValue, float value) {
    BeginScissorMode(center.x - width / 2, center.y - width / 2, width, width);

    LTGuiCircleCooldown((Vector2){center.x, center.y}, 0, width * 2, color, minValue, maxValue, value);

    EndScissorMode();
}

void LTGuiCooldownText(Vector2 center, int fontSize, Color color, float value) {
    if (value <= 0) return;

    char* text = (char*)TextFormat("%.0f", value);
    float mins = value / 60;

    if (mins > 1) {
        text = (char*)TextFormat("%.0f", floorf(mins));
        int pos = strlen(text);
        TextAppend(text, "m", &pos);
    } 

    Vector2 textMeasurment =  MeasureTextEx(GuiGetFont(), text, fontSize, GuiGetStyle(DEFAULT, TEXT_SPACING));

    Vector2 finalPos = {center.x - textMeasurment.x / 2, center.y - textMeasurment.y / 2};

    DrawTextEx(GuiGetFont(), text, finalPos, fontSize, GuiGetStyle(DEFAULT, TEXT_SPACING), color);
}

