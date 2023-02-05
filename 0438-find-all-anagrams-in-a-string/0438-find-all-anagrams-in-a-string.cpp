class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>fr1(27),fr2(27);
        if(p.size()>s.size())return {};
        for(int i=0;i<p.size()&&i<s.size();i++)fr1[s[i]-'a']++,fr2[p[i]-'a']++;
        vector<int>ans;
        if(valid(fr1,fr2))ans.push_back(0);
        for(int i=p.size(),j=0;i<s.size();i++,j++)
        {
            fr1[s[i]-'a']++;
            fr1[s[j]-'a']--;
            if(valid(fr1,fr2))ans.push_back(j+1);
        }
        return ans;
    }
    bool valid(vector<int>&fr1,vector<int>&fr2)
    {
        for(int i=0;i<27;i++)
            if(fr1[i]!=fr2[i])return 0;
        return 1;
    }
};