class Solution {
public:
    vector<string>temp;
    vector<vector<string>>ans;
    string s;
    vector<vector<string>> partition(string ss) {
        temp.clear();
        s=ss;
        ans.clear();
        solve(0,"");
        return ans;
    }
    bool valid(string &ss)
    {
        int l=0,r=ss.size()-1;
        while(l<=r)
        {
            if(ss[l]!=ss[r])return 0;
            l++,r--;
        }
        return 1;
    }
    void solve(int i,string ss)
    {
        if(i==s.size())
        {
            if(ss.size())
            {
                if(valid(ss))
                    temp.push_back(ss);
                else 
                    return;
            }
            bool tr=1;
            if(tr)ans.push_back(temp);
            if(ss.size())
            temp.pop_back();
            return;
        }
        if(ss.size())
        {
            temp.push_back(ss);
            if(valid(ss))
                solve(i,"");
            temp.pop_back();
        }
        solve(i+1,ss+s[i]);
    }
};