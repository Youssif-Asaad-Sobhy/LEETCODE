class Solution {
public:
    vector<vector<int>>dp;
    const int mod=1e9+7;
    vector<vector<int>>pos;
    int get(char c)
    {return c-'a';}
    long long solve(int i,int j,vector<string>&w,string&t)
    {
        if(j==t.size())return 1;
        if(i==w[0].size())return 0;
        int&ret=dp[i][j];
        if(~ret)return ret;
        int need=get(t[j]);
        long long cnt=0;
        cnt+=pos[i][need]*(solve(i+1,j+1,w,t)%mod);
        cnt%=mod;
        cnt+=solve(i+1,j,w,t);
        cnt%=mod;
        return ret=cnt;
    }
    int numWays(vector<string>& words, string target) {
        dp=vector<vector<int>>(words[0].size()+5,vector<int>(target.size()+5,-1));
        pos=vector<vector<int>>(words[0].size(),vector<int>(27));
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                pos[j][get(words[i][j])]++;
            }
        }
        return solve(0,0,words,target);
    }
};