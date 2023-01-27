class Solution {
public:
    vector<vector<int>>dp;
    map<string,bool>mp;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto it:words)mp[it]=1;
        int i=0;
        vector<string>ans;
        for(auto word:words)
        {
            dp=vector<vector<int>>(35,vector<int>(35,-1));
            mp.erase(mp.find(word));
            if(solve(0,"",word))
                ans.push_back(word);
            mp[word]=1;
            i++;
        }
        return ans;
    }
    bool solve(int i,string s,string &word)
    {
        if(i==word.size())return mp.find(s)!=mp.end()||s.empty();
        int&ret=dp[i][s.size()];
        if(~ret)return ret;
        bool tr=0;
        if(mp.find(s)!=mp.end())
        {
            tr|=solve(i,"",word);
            if(tr)return tr;
        }
        tr|=solve(i+1,s+word[i],word);
        return ret=tr;
    }
};