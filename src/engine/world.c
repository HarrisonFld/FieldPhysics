#include "world.h"
#include <raylib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//TODO: scale based on camera zoom and window size
void draw_axes(bool x, bool y, Camera2D* camera, float interval) {
    interval = interval * METER_TO_PIXELS;

    if (x) {
        int startPosX = GetScreenToWorld2D((Vector2){0, 0}, *camera).x;
        int endPosX = GetScreenToWorld2D((Vector2){GetScreenWidth(), 0}, *camera).x;
        int startPosY = 0;
        int endPosY = 0;
        DrawLine(startPosX, startPosY, endPosX, endPosY, RED);
        int draws = ceil(((endPosX + interval ) - (startPosX - interval)) / interval);
        int textStartPos = interval * floor(startPosX / interval);
        for (int i = 0; i < draws; i++) {
            int curPos = textStartPos + (i * interval);
            char indicator[19];
            snprintf(indicator, sizeof(indicator), "%g", curPos * PIXEL_TO_METERS);
            DrawText(indicator, curPos, 2 , 16 * RES_SCALING, RED);
        }
    }
    if (y) {
        int startPosX = 0;
        int endPosX = 0;
        int startPosY = GetScreenToWorld2D((Vector2){0, 0}, *camera).y;
        int endPosY = GetScreenToWorld2D((Vector2){0, GetScreenHeight()}, *camera).y;
        DrawLine(startPosX, startPosY, endPosX, endPosY, GREEN);
        int draws = ceil(((endPosY + interval ) - (startPosY - interval)) / interval);
        int textStartPos = interval * floor(startPosY / interval);
        for (int i = 0; i < draws; i++) {
            int curPos = textStartPos + (i * interval);
            char indicator[19];
            snprintf(indicator, sizeof(indicator), "%g", curPos * PIXEL_TO_METERS);
            DrawText(indicator, 3, curPos , 16 * RES_SCALING, GREEN);
        }
    }
}
