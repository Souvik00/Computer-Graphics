#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");
    int n;
    int w[] = {120, 40, 320, 40, 320, 240, 120, 240, 120, 40};
    setcolor(RED);
    drawpoly(5, w);
    cout << "Enter the no. of vertices of polygon: ";
    cin >> n;
    vector<int> poly(2 * n + 2);
    cout << "Enter the coordinates of points:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "(x" << i << ", y" << i << "): ";
        cin >> poly[2 * i] >> poly[2 * i + 1];
    }
    poly[2 * n] = poly[0];
    poly[2 * n + 1] = poly[1];
    setcolor(WHITE);
    drawpoly(n + 1, poly.data());
    cout << "\nPress a button to clip a polygon..";
    getch();
    setcolor(RED);
    drawpoly(5, w);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(2, 2, RED);
    getch();
    cleardevice();
    closegraph();
    return 0;
}
