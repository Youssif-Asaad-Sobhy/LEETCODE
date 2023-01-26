class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>weight(27);
        for(int i=0;i<order.size();i++)weight[order[i]-'a']=i;
        return is_sorted(words.begin(),words.end(),[&](string &a,string &b)
            {
                if(a==b)return 0;
            for(int i=0;i<min(a.size(),b.size());i++)
            {
                if(weight[a[i]-'a']<weight[b[i]-'a'])return 1;
                else if(weight[a[i]-'a']>weight[b[i]-'a'])return 0;
            }
            return (int)(a.size()<b.size());
            });
    }
};