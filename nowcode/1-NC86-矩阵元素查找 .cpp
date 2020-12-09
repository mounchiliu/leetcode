class Finder {
public:
    vector<int> findElement(vector<vector<int> > matrix, int n, int m, int target) {
        // write code here
        if(m == 0 || n == 0)
            return {};
        int cols = m;
        int rows = n;
        int row = 0, col = m - 1;
        
        //【从左下角开始往右上角逼近、或者右上角出发往左下角逼近】
        while(row<rows && col>=0){
            if(matrix[row][col] == target){
                return {row, col};//已经搜到，因为每一列排序也没有重复的数，跳过  
            }

            else if(matrix[row][col] > target){ //这一列的第一个元素是最小的，如果targe比这个还小，这一列不要
                col--; //这一列不搜索，跳过
            }

            else if(mat[row][col] < x){
                row++;//往下搜
            }
            
        }
        return {};//没找到
    }
};