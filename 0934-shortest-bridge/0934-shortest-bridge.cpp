class Solution {
public:
    const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool notvalid(int i,int j,int n)
    {
        return i < 0 || i >= n || j < 0 || j >= n;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int islandId) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1) {
            return;
        }

        grid[i][j] = islandId;

        for (const auto& dir : directions) {
            int newRow = i + dir.first;
            int newCol = j + dir.second;
            dfs(grid, newRow, newCol, islandId);
        }
    }

    void findIslands(vector<vector<int>>& grid, int& islandCount) {
        int n = grid.size();
        int m = grid[0].size();
        int islandId = 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, islandId);
                    ++islandId;
                    ++islandCount;
                    if (islandCount == 2) {
                        return;
                    }
                }
            }
        }
    }
    int countFlips(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int cnt=INT_MAX;
        vector<vector<int>>mn(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {  
                    q.push({i,j});
                    mn[i][j]=0;
                }
            }
        }
        while(q.size())
        {
            int ci=q.front().first;
            int cj=q.front().second;
            q.pop();
            if(grid[ci][cj]==3)
            {
                cnt=min(cnt,mn[ci][cj]-1);
                continue;
            }
            for (const auto& dir : directions) {
                int newRow = ci + dir.first;
                int newCol = cj + dir.second;
                if(!notvalid(newRow,newCol,n)&&grid[newRow][newCol]!=2&&mn[ci][cj]+1<mn[newRow][newCol])
                {
                    mn[newRow][newCol]=mn[ci][cj]+1;
                    q.push({newRow,newCol});
                }
            }
        }
        return cnt;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int islandCount = 0;
        findIslands(grid, islandCount);
        return countFlips(grid);
    }
};