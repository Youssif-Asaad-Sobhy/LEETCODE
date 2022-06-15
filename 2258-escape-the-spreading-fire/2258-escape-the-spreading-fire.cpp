class Solution {
public:
    vector<vector<int>>good;
    int dx[8]= {1,-1,0,0,1,-1,1,-1}; //{1,-1,0,0,1,-1,1,-1}
    int dy[8]= {0,0,-1,1,1,-1,-1,1}; //{0,0,-1,1,1,-1,-1,1}
    bool valid(int x,int y,vector<vector<int>>& grid)
    {
        return x>=0&&y>=0&&x<grid.size()&&y<grid[x].size()&&grid[x][y]==0;
    }
    void fire(vector<vector<int>>& grid)
    {
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({{i,j},0});
                    good[i][j]=0;
                }
            }
        }
        pair<int,int>in;
        int cnt;
        while(q.size())
        {
            in=q.front().first;
            cnt=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int ddx=in.first+dx[i];
                int ddy=in.second+dy[i];
                if(valid(ddx,ddy,grid)&&cnt+1<good[ddx][ddy])
                {
                    good[ddx][ddy]=cnt+1;
                    q.push({{ddx,ddy},cnt+1});
                }
            }
        }
    }
    bool bfs(int t,vector<vector<int>>& grid)
    {
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},t});
        vector<vector<bool>>arr(300,vector<bool>(300,0));
        pair<int,int>in,ed={grid.size()-1,grid[0].size()-1};
        int cnt;
        while(q.size())
        {
            in=q.front().first;
            cnt=q.front().second;
            if(in==ed)
                return 1;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int ddx=in.first+dx[i];
                int ddy=in.second+dy[i];
                if(valid(ddx,ddy,grid)&&(cnt+1<good[ddx][ddy])&&!arr[ddx][ddy])
                {
                    arr[ddx][ddy]=1;
                    q.push({{ddx,ddy},cnt+1});
                }
                else if(ed.first==ddx&&ed.second==ddy&&cnt+1==good[ddx][ddy])
                return 1;
            }
        }
        return 0;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        good=vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        fire(grid);
        int l=0,r=grid.size()*grid[0].size(),md,ans=-1;
        while(l<=r)
        {
            md=l+(r-l)/2;
            if(bfs(md,grid))
            {
                l=md+1;
                ans=md;
            }
            else r=md-1;
        }
        if(ans==grid.size()*grid[0].size())return 1e9;
        else return ans;
    }
};