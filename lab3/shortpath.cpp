#include <iostream>
#include <vector>

using namespace std;

void shortdis(int currX, int currY, int endX, int endY, int distance, vector<vector<int>> &grid, vector<vector<int>> &dis)
{
    if (currX < 0 || currY < 0 || currX >= grid.size() || currY >= grid[0].size())
    {
        return;
    }
    if (grid[currX][currY] == 0)
    {
        return;
    }
    if (dis[currX][currY] > 0)
    {
        if (dis[currX][currY] > distance)
            dis[currX][currY] = distance;
        return;
    }

    if (dis[currX][currY] < 0 || distance < dis[currX][currY])
    {
        dis[currX][currY] = distance;
    }

    if (currX == endX && currY == endY)
    {
        return;
    }

    shortdis(currX + 1, currY, endX, endY, distance + 1, grid, dis);
    shortdis(currX, currY + 1, endX, endY, distance + 1, grid, dis);
    shortdis(currX - 1, currY, endX, endY, distance + 1, grid, dis);
    shortdis(currX, currY - 1, endX, endY, distance + 1, grid, dis);
}

int main()
{
    int h, w, sx, sy, ex, ey;
    cin >> h >> w >> sx >> sy >> ex >> ey;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++)
    {
        char ch;
        cin >> ch; // Read the opening bracket
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
            cin >> ch; // Read the comma or closing bracket
        }
    }

    vector<vector<int>> dis(h, vector<int>(w, -1));

    shortdis(sx, sy, ex, ey, 0, grid, dis);
    
    cout << sx << " " << sy << endl;
    cout << ex << " " << ey << endl;
    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "\n";
    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << "\n";
    }

    if (dis[ex][ey] > 0)
        cout << "The minimum distance is " << dis[ex][ey] << endl;
    else
        cout << "There is no possible path" << endl;

    return 0;
}