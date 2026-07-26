class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int& fresh,int m,int n) {
      int size = q.size();

        while(size--) {

            auto f = q.front();
            q.pop();

            int x = f.first;
            int y = f.second;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n &&
                   grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 2)
                    q.push({i,j});

                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int t = 0;

        while(!q.empty() && fresh > 0) {

            bfs(grid, q, fresh,m,n);
            t++;
        }

        if(fresh > 0)
            return -1;

        return t;
    }
};