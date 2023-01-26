class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int& a,int& b){
            int aa=a,bb=b;
            int cnta=0,cntb=0;
            while(aa)
            {
                cnta+=(aa&1);
                aa>>=1;
            }
            while(bb)
            {
                cntb+=(bb&1);
                bb>>=1;
            }
            if(cnta<cntb)return 1;
            else if(cnta>cntb)return 0;
            else return (int)(a<b);
        });
        return arr;
    }
};