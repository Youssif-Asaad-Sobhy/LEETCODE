class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int re=0;
        string ans;
        for(int i=0;i<a.size()||i<b.size();i++)
        {
            if(i<a.size())
                re+=a[i]-'0';
            if(i<b.size())
                re+=b[i]-'0';
            if(re==1)ans+='1',re=0;
            else if(re==2)ans+='0',re=1;
            else if(re==3) ans+='1',re=1;
            else if(re==0)ans+='0';
        }
        if(re==1)ans+='1',re=0;
        else if(re==2)ans+='0',re=1;
        else if(re==3) ans+='1',re=1;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};