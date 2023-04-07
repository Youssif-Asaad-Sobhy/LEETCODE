class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        int vis[505][505]={};
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        auto v1=[&](int i,int j){
            return i>=0&&j>=0&&i<n&&j<m;
        };
        auto v2=[&](int i,int j){
            return i<0||j<0||i>=n||j>=m;
        };
        auto bfs=[&](int i,int j)
        {
            int ret=1;
            queue<pair<int,int>>q;
            q.push({i,j});
            vis[i][j]=1;
            while(q.size())
            {
                i=q.front().first,j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int ddx=dx[k]+i;
                    int ddy=dy[k]+j;
                    if(v1(ddx,ddy)&&grid[ddx][ddy]&&!vis[ddx][ddy])
                    {
                        ret++;
                        vis[ddx][ddy]=1;
                        q.push({ddx,ddy});
                    }
                    else if(v2(ddx,ddy))
                        ret=INT_MIN;
                }
            }
            return ret;
        };
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]&&!vis[i][j])
                {
                    int t=bfs(i,j);
                    ans+=max(t,0);
                }
            }
        }
        return ans;
    }
};