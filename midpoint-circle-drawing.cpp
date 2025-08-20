#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

struct Point {
    int x, y;
};

// Function to check if a point is inside the clipping boundary
bool inside(Point p, int edge, int xmin, int ymin, int xmax, int ymax) {
    switch (edge) {
        case 0: return (p.x >= xmin); // Left
        case 1: return (p.x <= xmax); // Right
        case 2: return (p.y >= ymin); // Bottom
        case 3: return (p.y <= ymax); // Top
    }
    return false;
}

// Intersection of polygon edge with clipping boundary
Point intersection(Point p1, Point p2, int edge, int xmin, int ymin, int xmax, int ymax) {
    Point i;
    float m = (p2.x != p1.x) ? (float)(p2.y - p1.y) / (p2.x - p1.x) : 1e9;

    switch (edge) {
        case 0: // Left
            i.x = xmin;
            i.y = p1.y + (xmin - p1.x) * m;
            break;
        case 1: // Right
            i.x = xmax;
            i.y = p1.y + (xmax - p1.x) * m;
            break;
        case 2: // Bottom
            i.y = ymin;
            i.x = (p2.x != p1.x) ? p1.x + (ymin - p1.y) / m : p1.x;
            break;
        case 3: // Top
            i.y = ymax;
            i.x = (p2.x != p1.x) ? p1.x + (ymax - p1.y) / m : p1.x;
            break;
    }
    return i;
}

// Sutherland-Hodgman Polygon Clipping
vector<Point> clipPolygon(vector<Point> poly, int xmin, int ymin, int xmax, int ymax) {
    vector<Point> output = poly;

    for (int edge = 0; edge < 4; edge++) {
        vector<Point> input = output;
        output.clear();

        for (int i = 0; i < input.size(); i++) {
            Point curr = input[i];
            Point prev = input[(i - 1 + input.size()) % input.size()];

            bool currInside = inside(curr, edge, xmin, ymin, xmax, ymax);
            bool prevInside = inside(prev, edge, xmin, ymin, xmax, ymax);

            if (prevInside && currInside) {
                output.push_back(curr);
            } else if (prevInside && !currInside) {
                output.push_back(intersection(prev, curr, edge, xmin, ymin, xmax, ymax));
            } else if (!prevInside && currInside) {
                output.push_back(intersection(prev, curr, edge, xmin, ymin, xmax, ymax));
                output.push_back(curr);
            }
        }
    }

    return output;
}

// Draw polygon using graphics.h
void drawPolygon(vector<Point> poly, int color) {
    setcolor(color);
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        line(poly[i].x, poly[i].y, poly[(i + 1) % n].x, poly[(i + 1) % n].y);
    }
}

int main() {
    int gd = DETECT, gm;
    initwindow(800, 600, "Sutherland-Hodgman Clipping");

    // Clipping window
    int xmin = 200, ymin = 150, xmax = 500, ymax = 400;
    rectangle(xmin, ymin, xmax, ymax);

    // Input polygon
    vector<Point> poly = {{100,200},{300,100},{450,300},{250,450},{150,350}};

    // Draw original polygon in RED
    drawPolygon(poly, RED);

    getch();

    // Perform clipping
    vector<Point> clipped = clipPolygon(poly, xmin, ymin, xmax, ymax);

    // Draw clipped polygon in GREEN
    drawPolygon(clipped, GREEN);

    getch();
    closegraph();
    return 0;
}
