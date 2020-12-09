class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() < k){
            return {};
        }
       quickSort(input, 0, input.size()-1);
        vector<int> result;
        int size = input.size();
        if(k > size) return result;
        if(k == size) return input;
        for(int i = 0; i<k; i++){
            result.push_back(input[i]);
        }
        return result;
        
    }
    
private:
    void quickSort(vector<int> &input, int start, int end){
        if(start >= end){
            return;
        }
        
        int left = start;
        int right = end;
        int mid = input[start + (end - start) / 2];
        
        while(left <= right){
            while(left <= right && input[left] < mid){
                left++;
            }
            while(left <= right && input[right] > mid){
                right--;
            }
            
            if(left <= right){
                int temp = input[left];
                input[left] = input[right];
                input[right] = temp;
                
                left++;
                right--;
            }
            
        }
        //此时，左边都比baseline小，右边都比baseline大
        //递归，对左右分层进行相同操作
        quickSort(input, start, right);
        quickSort(input, left, end);
        
    }
};