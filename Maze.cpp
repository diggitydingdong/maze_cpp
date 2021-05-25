#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdlib.h>

#include "Point.cpp"
#include "Maze.h"

using namespace std;

#pragma once

bool a = false;
vector<Point> sol;

vector<Point> Maze::getUnvisNeighbours(int x, int y, int unvis, int d)
{
    vector<Point> neighbours;
    if(x != d-1 && maze[y][x-d] == unvis) neighbours.emplace_back(x-d, y);
    if(y != d-1 && maze[y-d][x] == unvis) neighbours.emplace_back(x, y-d);
    if(x != size*2-(d-1) && maze[y][x+d] == unvis) neighbours.emplace_back(x+d, y);
    if(y != size*2-(d-1) && maze[y+d][x] == unvis) neighbours.emplace_back(x, y+d);
    return neighbours;
}

void Maze::rdfs(int x, int y)
{
    maze[y][x] = 0;
    vector<Point> n = getUnvisNeighbours(x, y, -1, 2);
    while(n.size() != 0)
    {
        Point p = n[rand() % n.size()];
        
        Point w = p.getWall(Point(x, y));
        maze[w.y][w.x] = 0;
        rdfs(p.x, p.y);
        
        n = getUnvisNeighbours(x, y, -1, 2);
    }
    
}

void Maze::bfs(int x, int y)
{
    vector<Point> p;
    bfs(x, y, p);
}

void Maze::bfs(int x, int y, vector<Point> path)
{
    path.emplace_back(x, y);
    cout << x << " " << y << endl;
    maze[y][x] = 2;
    vector<Point> n = getUnvisNeighbours(x, y, 2, 1);
    for(int i = 0; i < n.size(); i++)
    {
        if(n[i].x == size*2-1 && n[i].y == size*2 && !a)
        {
            a = true;
            sol = path;
        }
        
        bfs(n[i].x, n[i].y, path); 
    }
}

void Maze::displayMaze()
{
    for(int i = 0; i < sol.size(); i++) maze[sol[i].y][sol[i].x] = 3;
    
    for(int y = 0; y < size*2+1; y++)
    {
        for(int x = 0; x < size*2+1; x++)
        {
            if(maze[y][x] % 2 == 0) cout << "  ";
            else if(maze[y][x] == 1) cout << "\%\%";
            else if(maze[y][x] == 3) cout << "..";
        }
        cout << endl;
    }
    
    cout << sol.size();
}