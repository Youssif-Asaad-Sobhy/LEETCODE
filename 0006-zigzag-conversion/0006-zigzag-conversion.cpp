class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<string>v(numRows);
        int j=0;
        bool state=0;
        for(int i=0;i<s.size();i++)
        {
            v[j].push_back(s[i]);
            if(j==numRows-1)state^=1,j--;
            else if(j==0&&state)j=(1%numRows),state^=1;
            else if(state)j--;
            else j++;
        }
        string ans;
        for(auto it:v)ans+=it;
        return ans;
    }
};