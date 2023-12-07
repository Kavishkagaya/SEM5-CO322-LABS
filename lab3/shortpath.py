import ast

# Read the first line
h = int(input().strip())

# Read the second line
w = int(input().strip())

# Read the third and fourth lines
sx, sy = map(int, input().strip().split())
ex, ey = map(int, input().strip().split())

# Using a list comprehension to create a dynamic 2D list
grid = [list(map(int, ast.literal_eval(input().strip()))) for _ in range(h)]

dis = [[-1 for _ in range(w)] for _ in range(h)]
i = 0
j = 0

def shortdis(currX, currY, endX, endY, distance):
    if(currX < 0 or currY < 0):
        return
    if(currX >= h or currY >= w):
        return
    if(grid[currX][currY] == 0):
        return
    if(currX == endX and currY == endY):
        return
    
    if(dis[currX][currY] < 0 or distance < dis[currX][currY]):
        dis[currX][currY] = distance

    shortdis(currX+1,currY,endX, endY, distance+1)
    shortdis(currX,currY+1,endX, endY, distance+1)
    shortdis(currX-1,currY,endX, endY, distance+1)
    shortdis(currX,currY-1,endX, endY, distance+1)

shortdis(sx,sy,ex,ey,0)

for row in dis:
    print(*row)