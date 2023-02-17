class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,cnt=0,i=0,j=0;
        vector<int>fr(200);
        while(i<s.size())
        {
            bool tr=1;
            while(i<s.size()&&tr)
            {
                fr[s[i]]++;
                if(fr[s[i]]==2)
                    tr=0;
                else if(fr[s[i]])
                    cnt++;
                i++;
            }
            ans=max(ans,cnt);
            while(j<s.size()&&!tr)
            {
                fr[s[j]]--;
                if(fr[s[j]])tr=1;
                else cnt--;
                j++;
            }
        }
        return ans;
    }
};