class Solution {
public:
    int compress(vector<char>& chars) {
        char c;
        string ans,tmp;
        for(int i=0;i<chars.size();)
        {
            c=chars[i];
            int cnt=0;
            while(i<chars.size()&&c==chars[i])
            {
                cnt++,i++;
            }
            ans+=c;
            if(cnt>1)
            {
                tmp="";
                while(cnt)
                {
                    tmp+='0'+(cnt%10);
                    cnt/=10;
                }
                reverse(tmp.begin(),tmp.end());
                ans+=tmp;
            }
        }
        for(int i=0;i<ans.size();i++)chars[i]=ans[i];
        return ans.size();
    }
};