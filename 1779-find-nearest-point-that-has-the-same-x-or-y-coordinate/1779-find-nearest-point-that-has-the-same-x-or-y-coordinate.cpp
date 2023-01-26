class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans=-1,mn=INT_MAX,i=0;
        for(auto it:points)
        {
            if(it[0]==x||it[1]==y)
            {
                if(abs(x-it[0])+abs(it[1]-y)<mn)
                    ans=i,mn=abs(x-it[0])+abs(it[1]-y);
            }
            i++;
        }
        return ans;
    }
};