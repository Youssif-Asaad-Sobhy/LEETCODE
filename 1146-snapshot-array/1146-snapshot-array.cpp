class SnapshotArray {
    vector<vector<pair<int,int>>>v;
    int snapId=0;
public:
    SnapshotArray(int length) {
        v=vector<vector<pair<int,int>>>(length,(vector<pair<int,int>>(1,{0,0})));
    }
    
    void set(int index, int val) {
        v[index].push_back({snapId,val});
        
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        int l=0,r=v[index].size()-1,md;
        while(l<=r)
        {
            md=(l+r)/2;
            if(v[index][md].first>snap_id)
            {
                r=md-1;
            }
            else l=md+1;
        }
        
        return v[index][l-1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */