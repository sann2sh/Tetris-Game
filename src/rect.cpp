#include "rect.h"
#include "colors.h"
void DrawLineBresenham(int x1, int y1, int x2, int y2, Color color) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        DrawPixel(x1, y1, color);

        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

// Function to draw a rectangle using Bresenham's line algorithm
void DrawRectangleBresenham(int x, int y, int width, int height, Color color) {
    DrawLineBresenham(x, y, x + width, y, color);          // Top
    DrawLineBresenham(x, y, x, y + height, color);         // Left
    DrawLineBresenham(x + width, y, x + width, y + height, color);  // Right
    DrawLineBresenham(x, y + height, x + width, y + height, color); // Bottom
}

// Function to fill a rectangle using the scanline method
void FillRectangleScanline(int x, int y, int width, int height, Color fillColor) {
    for (int row = y; row <= y + height; row++) {
        DrawLineBresenham(x, row, x + width, row, fillColor);
    }
}

// Custom function to draw and fill a rectangle
void drawrect(int x, int y, int width, int height, Color fillColor) {
    Color borderColor = darkBlue;
    FillRectangleScanline(x, y, width, height, fillColor);   // Fill the rectangle first
    DrawRectangleBresenham(x, y, width, height, borderColor); // Draw the border
}
