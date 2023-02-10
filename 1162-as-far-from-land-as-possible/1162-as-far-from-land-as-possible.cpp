class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int ans=-1,n=grid.size();
        queue<pair<int,int>>q;
        vector<vector<int>>dist(n,vector<int>(n,100000));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])q.push({i,j}),dist[i][j]=0;
            }
        }
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        int i,j;
        while(q.size())
        {
            i=q.front().first;
            j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int ddx=dx[k]+i;
                int ddy=dy[k]+j;
                if(valid(ddx,ddy,n)&&dist[i][j]+1<dist[ddx][ddy])
                {
                    q.push({ddx,ddy});
                    dist[ddx][ddy]=dist[i][j]+1;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dist[i][j]!=100000)ans=max(ans,dist[i][j]);
            }
        }
        return ans==0?-1:ans;
    }
    bool valid(int i,int j,int n)
    {return i>=0&&j>=0&&i<n&&j<n;}
};