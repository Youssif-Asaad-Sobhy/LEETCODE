class Solution {
public:
    string interpret(string s) {
        string ans;
        for(int i=0;i<s.size();)
        {
            if(s[i]=='G')ans+=s[i++];
            else if(s[i]=='('&&s[i+1]==')')ans+='o',i+=2;
            else ans+="al",i+=4;
        }
        return ans;
    }
};