class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                int ii=0,jj=0;
                while(ii<n&&grid[ii][j]==grid[i][jj])
                {
                    ii++,jj++;
                }
                if(ii==n)ans++;
            }
        }
        return ans;
    }
};