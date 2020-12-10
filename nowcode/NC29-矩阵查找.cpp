class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> 
     * @param target int整型 
     * @return bool布尔型
     */
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        // write code here
        //trun the sorted matrix to a array using the row_index and col_index.
        if(matrix.size() == 0)
            return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int start = 0, end = rows * cols - 1;
        int mid;
        while(start + 1 < end){
            mid = start + (end - start) / 2;
            
            if(matrix[mid/cols][mid%cols] == target)
                return true;
            if(matrix[mid/cols][mid%cols] > target)
                end = mid;
            if(matrix[mid/cols][mid%cols] < target)
                start = mid;
        }
        
        //check the last two point
        if(matrix[start/cols][start%cols] == target)
            return true;
        if(matrix[end/cols][end%cols] == target)
            return true;
        return false;
    }
};