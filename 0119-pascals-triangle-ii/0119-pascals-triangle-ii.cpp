class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>v(rowIndex+1);
        for(int i=0;i<=rowIndex;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0||j==i)v[i].push_back(1);
                else v[i].push_back(v[i-1][j-1]+v[i-1][j]);
            }
        }
        return v[rowIndex];
    }
};