class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size()>str2.size())swap(str1,str2);
        vector<int>sizes;
        int n=str1.size(),m=str2.size();
        for(int i=1;i<=m;i++)
        {
            if(n%i==0&&m%i==0)
                sizes.push_back(i);
        }
        string ans="";
        for(auto sz:sizes)
        {
            bool valid1=1;
            string mains=str1.substr(0,sz);
            int i=0;
            while(i<n)
            {
                if(mains!=str1.substr(i,sz))
                {
                    valid1=0;
                    break;
                }
                i+=sz;
            }
            if(!valid1)continue;
            bool valid2=1;
            i=0;
            while(i<m)
            {
                if(mains!=str2.substr(i,sz))
                {
                    valid2=0;
                    break;
                }
                i+=sz;
            }
            if(!valid2)continue;
            ans=max(ans,mains);
        }
        return ans;
    }
};