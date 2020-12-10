class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if(matrix.empty())
            return {};
        
        if(matrix[0].size()==0)
            return {};
        
        //注意边界的判断
        vector<int> res;
        int left = 0, top = 0;
        int right = matrix[0].size() - 1, bottom = matrix.size() - 1;
        
        while (top < (matrix.size()+1) / 2 
               && left < (matrix[0].size()+1) / 2){
            //move to the right
            for(int i = left; i <= right; i++){
                res.push_back(matrix[top][i]);
            }
            //move to the bottom
            for(int i = top + 1; i <= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            //move to the left
            for(int i = right - 1; i >= left && top != bottom; i--){
                res.push_back(matrix[bottom][i]);
            }
            //move to the top
            for(int i = bottom - 1; i >= top + 1 && left != right; i--){
                res.push_back(matrix[i][left]);
            }
        
            //update four boundaries
            left++;right--;
            top++;bottom--;
        }
        return res;
        
    }
};