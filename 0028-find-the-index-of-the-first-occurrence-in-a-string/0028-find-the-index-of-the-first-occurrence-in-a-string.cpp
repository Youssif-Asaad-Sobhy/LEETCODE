class Solution {
public:
    int strStr(string s, string t) {
        if(s.size()<t.size())return -1;
        for(int i=0;i<=s.size()-t.size();i++)
        {
            if(s[i]==t[0])
            {
                int ans=i;
                bool tr=1;
                for(int j=0;j<t.size();j++,i++)
                {
                    if(s[i]!=t[j])
                    {
                        tr=0;
                        break;
                    }
                }
                if(tr)return ans;
                else i=ans;
            }
        }
        return -1;
    }
};