#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

void drawRectangle(int left, int top, int right, int bottom, int color) {
    setcolor(color);
    rectangle(left, top, right, bottom);
    setfillstyle(SOLID_FILL, color);
    floodfill(left + 1, top + 1, color); // inside point
}

int main(){
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");
    drawRectangle(100, 100, 200, 200, RED);
    drawRectangle(130, 130, 230, 230, BLUE);
    drawRectangle(160, 160, 260, 260, GREEN);
    getch();
    closegraph();
    return 0;
}
