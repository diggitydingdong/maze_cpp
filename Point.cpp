#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#pragma once

struct Point {
    int x;
    int y;
    
    Point(int x, int y): x(x), y(y) {}
        
    Point getWall(Point a) {
        return Point((a.x + x)/2, (a.y + y)/2);
    }
};