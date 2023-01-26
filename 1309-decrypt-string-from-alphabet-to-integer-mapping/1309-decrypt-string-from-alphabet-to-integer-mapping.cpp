class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        for(int i=0;i<s.size();)
        {
            string ss=s.substr(i,3);
            if(ss.back()=='#')
            {
                int a=ss[0]-'0';
                a*=10;
                a+=ss[1]-'0';
                a--;
                ans+='a'+a;
                i+=3;
            }
            else ans+='a'+(s[i++]-'1');
        }
        return ans;
    }
};