class NumMatrix {
public:
    vector<vector<int>>arr;
    NumMatrix(vector<vector<int>>& matrix) {
        arr=matrix;
        int n=matrix.size();
        int m=matrix[0].size();
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                arr[i][j] =arr[i][j]+arr[i-1][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                arr[i][j] += arr[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int t1,t2,t3,t4;
        t1=arr[row2][col2];
        if(row1!=0)t2=arr[row1-1][col2];
        else t2=0;
        if(col1!=0)t3=arr[row2][col1-1];
        else t3=0;
        if(row1!=0&&col1!=0)t4=arr[row1-1][col1-1];
        else t4=0;
        cout<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;
        return t1-t2-t3+t4;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */