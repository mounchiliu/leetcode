class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return -1;
        
        int start = 0, end = rotateArray.size() - 1;
        int mid;
        while(start + 1 < end){
            mid = start + (end - start)/2;
            if(rotateArray[mid] <= rotateArray[end]){
                end = mid;
            }
            if(rotateArray[mid] > rotateArray[end]){
                start = mid;
            }
        }
        
        return min(rotateArray[start],rotateArray[end]);
    }
};