#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

double x_left = 120, x_right = 500, y_bottom = 100, y_top = 350;
int Left = 1, Right = 2, Bottom = 4, Top = 8;

int regionCode(double x, double y) {
    int code = 0;
    if (x > x_right) code |= Right;
    else if (x < x_left) code |= Left;
    if (y > y_top) code |= Top;
    else if (y < y_bottom) code |= Bottom;
    return code;
}

bool cohenSutherland(double &x1, double &y1, double &x2, double &y2) {
    int code1 = regionCode(x1, y1);
    int code2 = regionCode(x2, y2);

    while (true) {
        if (!(code1 | code2)) {
            return true; // Completely inside
        }
        else if (code1 & code2) {
            return false; // Completely outside
        }
        else {
            double x, y;
            int code = code1 ? code1 : code2;
            if (code & Top) {
                y = y_top;
                x = x1 + (x2 - x1) * (y - y1) / (y2 - y1);
            }
            else if (code & Bottom) {
                y = y_bottom;
                x = x1 + (x2 - x1) * (y - y1) / (y2 - y1);
            }
            else if (code & Left) {
                x = x_left;
                y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
            }
            else if (code & Right) {
                x = x_right;
                y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
            }

            if (code == code1) {
                x1 = x;
                y1 = y;
                code1 = regionCode(x1, y1);
            }
            else {
                x2 = x;
                y2 = y;
                code2 = regionCode(x2, y2);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setcolor(YELLOW);
    rectangle(x_left, y_bottom, x_right, y_top);
    double x1 = 50, y1 = 200, x2 = 500, y2 = 400;
    setcolor(RED);
    line(x1, y1, x2, y2);
    outtextxy(50, 20, "Press any key to clip...");
    getch();
    cleardevice();
    setcolor(YELLOW);
    rectangle(x_left, y_bottom, x_right, y_top);
    if (cohenSutherland(x1, y1, x2, y2)) {
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    }
    else outtextxy(50, 50, "Line lies completely outside!");
    getch();
    closegraph();
    return 0;
}
