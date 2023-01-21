class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string s1,s2,s3,s4;
        vector<string>ans;
        int n=s.size();
        for(int i=1;i<=n;i++)
        {
            s1=s.substr(0,i);
            for(int j=1;j<=n-i;j++)
            {
                s2=s.substr(i,j);
                for(int k=1;k<=n-i-j;k++)
                {
                    s3=s.substr(i+j,k);                    
                    s4=s.substr(i+j+k);
                    if(valid(s1)&&valid(s2)&&valid(s3)&&valid(s4))
                    {
                        ans.push_back(s1+"."+s2+"."+s3+"."+s4);
                    }
                }
            }
        }
        return ans;
    }
    bool valid(string &s)
    {
        if(s==""||(s.size()>1&&s[0]=='0')||s.size()>3)return 0;
        int i=stoi(s);
        if(i>255)return 0;
        return 1;
    }
};







