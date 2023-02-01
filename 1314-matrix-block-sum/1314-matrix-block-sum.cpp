class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size()));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                for(int r=max(0,i-k);r<=min((int)mat.size()-1,i+k);r++)
                {
                    for(int c=max(0,j-k);c<=min((int)mat[0].size()-1,j+k);c++)
                    {
                        ans[i][j]+=mat[r][c];
                    }
                }
            }
        }
        return ans;
    }
};