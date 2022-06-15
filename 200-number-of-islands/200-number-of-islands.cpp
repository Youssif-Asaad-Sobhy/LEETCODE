class Solution {
public:
    int dx[8]= {1,-1,0,0,1,-1,1,-1}; //{1,-1,0,0,1,-1,1,-1}
    int dy[8]= {0,0,-1,1,1,-1,-1,1}; //{0,0,-1,1,1,-1,-1,1}
    bool valid(int x,int y,vector<vector<char>>& grid)
    {
        return x>=0&&y>=0&&x<grid.size()&&y<grid[x].size()&&grid[x][y]=='1';
    }
    void bfs(int i,int j,vector<vector<char>>& grid)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=0;
        pair<int,int>in;
        while(q.size())
        {
            in=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int ddx=in.first+dx[i];
                int ddy=in.second+dy[i];
                if(valid(ddx,ddy,grid))
                {
                    grid[ddx][ddy]=0;
                    q.push({ddx,ddy});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0,i,j,x;
        for(i=0;i<grid.size();i++)
        {
            for(j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    bfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};