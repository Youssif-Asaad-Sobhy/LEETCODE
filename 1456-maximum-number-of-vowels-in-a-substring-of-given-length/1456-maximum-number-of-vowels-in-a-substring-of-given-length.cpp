class Solution {
public:
    bool isvowel(char c)
    {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    int maxVowels(string s, int k) {
        int ans=0,cnt=0;
        int l=0,r=0;
        while(r<s.size())
        {
            cnt+=isvowel(s[r]);
            if(r-l>=k)cnt-=isvowel(s[l++]);
            ans=max(ans,cnt);
            r++;
        }
        return ans;
    }
};