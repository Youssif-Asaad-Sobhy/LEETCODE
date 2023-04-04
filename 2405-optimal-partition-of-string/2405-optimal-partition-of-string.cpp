class Solution {
public:
    int partitionString(string s) {
        int ans=1;
        vector<bool>taken(200),clean(200);
        for(int i=0;i<s.size();i++)
        {
            if(taken[s[i]])
            {
                ans++;
                taken=clean;
            }
            taken[s[i]]=1;
        }
        return ans;
    }
};