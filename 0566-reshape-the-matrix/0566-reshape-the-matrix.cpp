class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c!=mat.size()*mat[0].size())return mat;
        vector<vector<int>>v(r);
        int ii=0,jj=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++,jj++)
            {
                if(jj==c)ii++,jj=0;
                v[ii].push_back(mat[i][j]);
            }
        }
        return v;
    }
};