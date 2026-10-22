#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y, dir, steps;
};

int main() {
    int M, N;
    cin >> M >> N;
    vector<string> grid(M);
    for (int i = 0; i < M; i++) cin >> grid[i];

    vector<pair<int, int>> src, dst;

    // Find ladder source and destination
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'l') src.push_back({i, j});
            if (grid[i][j] == 'L') dst.push_back({i, j});
        }
    }

    int len = src.size();
    sort(src.begin(), src.end());
    sort(dst.begin(), dst.end());

    // Determine orientations
    bool src_vert = (len > 1 && src[1].first != src[0].first);
    bool dst_vert = (len > 1 && dst[1].first != dst[0].first);

    // Calculate center points
    auto get_center = [&](vector<pair<int, int>> v) {
        int mid = len / 2;
        return v[mid];
    };

    auto [sx, sy] = get_center(src);
    auto [dx, dy] = get_center(dst);

    // Directions for movement
    int dxs[4] = {-1, 1, 0, 0};
    int dys[4] = {0, 0, -1, 1};

    auto valid = [&](int x, int y, bool vert) {
        for (int i = 0; i < len; i++) {
            int nx = x + (vert ? i - len / 2 : 0);
            int ny = y + (vert ? 0 : i - len / 2);
            if (nx < 0 || ny < 0 || nx >= M || ny >= N || grid[nx][ny] == 'B')
                return false;
        }
        return true;
    };

    auto can_rotate = [&](int x, int y) {
        int startx = x - len / 2;
        int starty = y - len / 2;
        for (int i = startx; i < startx + len; i++) {
            for (int j = starty; j < starty + len; j++) {
                if (i < 0 || j < 0 || i >= M || j >= N || grid[i][j] == 'B')
                    return false;
            }
        }
        return true;
    };

    queue<State> q;
    vector<vector<vector<bool>>> vis(M, vector<vector<bool>>(N, vector<bool>(2, false)));

    q.push({sx, sy, src_vert, 0});
    vis[sx][sy][src_vert] = true;

    while (!q.empty()) {
        auto [x, y, dir, steps] = q.front();
        q.pop();

        if (x == dx && y == dy && dir == dst_vert) {
            cout << steps << endl;
            return 0;
        }

        // Try moving
        for (int i = 0; i < 4; i++) {
            int nx = x + dxs[i];
            int ny = y + dys[i];
            if (valid(nx, ny, dir) && !vis[nx][ny][dir]) {
                vis[nx][ny][dir] = true;
                q.push({nx, ny, dir, steps + 1});
            }
        }

        // Try rotating
        if (can_rotate(x, y)) {
            int ndir = !dir;
            if (!vis[x][y][ndir] && valid(x, y, ndir)) {
                vis[x][y][ndir] = true;
                q.push({x, y, ndir, steps + 1});
            }
        }
    }

    cout << "Impossible" << endl;
    return 0;
}
