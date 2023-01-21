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
                    if(valid(s1,s2,s3,s4))
                    {
                        ans.push_back(s1+"."+s2+"."+s3+"."+s4);
                    }
                }
            }
        }
        return ans;
    }
    bool valid(string &s1,string &s2,string &s3,string &s4)
    {
        if(s1==""||s2==""||s3==""||s4=="")return 0;
        if(s1.size()>3||s2.size()>3||s3.size()>3||s4.size()>3)return 0;
        int i=stoi(s1),j=stoi(s2),k=stoi(s3),l=stoi(s4);
        if(i>255||j>255||k>255||l>255)return 0;
        if((s1.size()>1&&s1[0]=='0')||(s2.size()>1&&s2[0]=='0')||(s3.size()>1&&s3[0]=='0')||(s4.size()>1&&s4[0]=='0'))return 0;
        return 1;
    }
};







