class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>degree(n+5);
        for(auto it:trust)
        {
            degree[it[1]]++;
            degree[it[0]]--;
        }
        for(int i=1;i<=n;i++)
        {
            if(degree[i]==n-1)return i;
        }
        return -1;
    }
};