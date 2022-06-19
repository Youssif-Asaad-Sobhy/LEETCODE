class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& v, string s) {
        int i,j,x=v.size(),cnt=0;
        sort(v.begin(),v.end());
        
        vector<vector<string>>vvv;
        for(i=1;i<=s.size();i++)
        {
            cnt=0;
            string s1=s.substr(0,i);
            vector<string>vv;
            for(j=0;j<x;j++)
            {
                string ss;
                ss=v[j].substr(0,i);
                if(ss==s1)
                {
                    cnt++;
                    vv.push_back(v[j]);
                }
                if(cnt==3)break;
            }
            vvv.push_back(vv);
        }
        return vvv;
    }
};