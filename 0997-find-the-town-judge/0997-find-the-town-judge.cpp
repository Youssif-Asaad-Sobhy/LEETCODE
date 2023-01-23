class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //          in  out
        vector<pair<int,int>>trustCounter(n+5);
        for(auto it:trust)
        {
            trustCounter[it[1]].first++;
            trustCounter[it[0]].second++;
        }
        int townJudge=-1;
        for(int i=1;i<=n;i++)
        {
            if(trustCounter[i].first==n-1&&trustCounter[i].second==0)
            {
                townJudge=i;
                break;
            }
        }
        return townJudge;
    }
};