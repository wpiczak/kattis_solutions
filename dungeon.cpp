#include <iostream>
#include <queue>

void solve() {
    int rows, columns, levels;
    int xStart, yStart, zStart;
    std::cin >> levels >> rows >> columns;
    std::queue<int> xQueue, yQueue, zQueue;

    char grid[levels][rows][columns];
    int distance[levels][rows][columns];
    for (auto &level: distance)
        for (auto &row: level)
            for (auto &val: row)
                val = -1;
    for (auto &level: grid)
        for (auto &row: level)
            for (auto &val: row)
                std::cin >> val;
    for (int i = 0; i < levels; i++)
        for (int j = 0; j < rows; j++)
            for (int k = 0; k < columns; k++)
                if (grid[i][j][k] == 'S')
                    zStart = i, yStart = j, xStart = k;

    int deltaX[] = {-1, 1, 0, 0, 0, 0};
    int deltaY[] = {0, 0, 1, -1, 0, 0};
    int deltaZ[] = {0, 0, 0, 0, 1, -1};

    if (xStart < 0 || yStart < 0 || zStart < 0 || xStart >= columns || yStart >= rows || zStart >= levels)
        return;
    xQueue.push(xStart);
    yQueue.push(yStart);
    zQueue.push(zStart);
    distance[zStart][yStart][xStart] = 0;

    bool finished = false;
    int xEnd, yEnd, zEnd;
    while (xQueue.size() > 0) {
        int x = xQueue.front(), y = yQueue.front(), z = zQueue.front();
        xQueue.pop();
        yQueue.pop();
        zQueue.pop();

        if (grid[z][y][x] == 'E') {
            finished = true;
            xEnd = x;
            yEnd = y;
            zEnd = z;
            break;
        }
        for (int i = 0; i < 6; i++) {
            int updatedX = x + deltaX[i], updatedY = y + deltaY[i], updatedZ = z + deltaZ[i];
            if (updatedX < 0 || updatedY < 0 || updatedZ < 0) continue;
            if (updatedX >= columns || updatedY >= rows || updatedZ >= levels) continue;
            if (distance[updatedZ][updatedY][updatedX] != -1) continue;
            if (grid[updatedZ][updatedY][updatedX] == '#') continue;
            xQueue.push(updatedX);
            yQueue.push(updatedY);
            zQueue.push(updatedZ);
            distance[updatedZ][updatedY][updatedX] = distance[z][y][x] + 1;
        }
    }

    if (finished)
        std::cout << "Escaped in " << distance[zEnd][yEnd][xEnd] << " minute(s).\n";
    else std::cout << "Trapped!\n";
    solve();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
