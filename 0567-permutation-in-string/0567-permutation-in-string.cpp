class Solution {
public:
    vector<int>fr1,fr2;
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return 0;
        fr1=fr2=vector<int>(27);
        for(int i=0;i<s1.size();i++)fr1[s1[i]-'a']++,fr2[s2[i]-'a']++;
        if(valid())return 1;
        for(int i=s1.size(),j=0;i<s2.size();i++,j++)
        {
            fr2[s2[i]-'a']++;
            fr2[s2[j]-'a']--;
            if(valid())return 1;
        }
        return 0;
    }
    bool valid()
    {
        for(int i=0;i<27;i++)
            if(fr1[i]!=fr2[i])return 0;
        return 1;
    }
};