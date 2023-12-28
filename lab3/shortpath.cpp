#include <iostream>
#include <vector>

using namespace std;

int shortDis(int sx, int sy, int ex, int ey, vector<vector<int>> &grid, int dis)
{
    if (grid[sx][sy] == 0)
        return -1;
    if (sx == ex && sy == ey)
        return dis;

    dis++;
    int rowDir = (ex - sx) > 0 ? 1 : ((ex - sx) < 0 ? -1 : 0);
    int colDir = (ey - sy) > 0 ? 1 : ((ey - sy) < 0 ? -1 : 0);

    int dis1 = -1;
    int dis2 = -1;

    if (rowDir != 0)
        dis1 = shortDis(sx + rowDir, sy, ex, ey, grid, dis);
    if (colDir != 0)
        dis2 = shortDis(sx, sy + colDir, ex, ey, grid, dis);

    if (dis1 == -1 && dis2 == -1)
        return -1;
    if (dis1 == -1)
        return dis2;
    if (dis2 == -1)
        return dis1;
    return min(dis1, dis2);
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

    int dis = shortDis(sx, sy, ex, ey, grid, 0);

    if (dis > 0)
        cout << "The minimum distance is " << dis << endl;
    else
        cout << "There is no possible path" << endl;

    return 0;
}