#pragma once
#include <raylib.h>
#include<math.h>
#include "grid.h"


void DrawLineBresenham(int x1, int y1, int x2, int y2, Color color);
void DrawRectangleBresenham(int x, int y, int width, int height, Color color);
void FillRectangleScanline(int x, int y, int width, int height, Color fillColor);
void drawrect(int x, int y, int width, int height, Color fillColor);




