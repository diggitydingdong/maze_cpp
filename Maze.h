#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdlib.h>

#include "Point.cpp"

using namespace std;

#pragma once

class Maze {
public:
    int size;
    
    vector<vector<int>> maze;
    
    Maze(int size): size(size) {
        maze.resize(size*2+1);
        
        for(int y = 0; y < size*2+1; y++)
        {
            maze[y].resize(size*2+1);
            for(int x = 0; x < size*2+1; x++)
            {
                if(y % 2 == 1 && x % 2 == 1) maze[y][x] = -1;
                else maze[y][x] = 1;
            }
        }
        
        maze[0][1] = 0;
        maze[size*2][size*2-1] = 0;
    };
    
    vector<Point> getUnvisNeighbours(int x, int y, int unvis, int d);
    void rdfs(int x, int y);
    void bfs(int x, int y);
    void bfs(int x, int y, vector<Point> path);
    void displayMaze();
};