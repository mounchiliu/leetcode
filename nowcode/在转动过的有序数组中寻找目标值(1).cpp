class Solution {
public:
    /**
     * 
     * @param A int整型一维数组 
     * @param n int A数组长度
     * @param target int整型 
     * @return int整型
     */
    int search(int* A, int n, int target) {
        // write code here
        if(A == NULL)
            return -1;
        
        int start = 0, end = n - 1;
        int mid;
        while(start + 1 < end){
            mid = start + (end - start)/2;
            if(A[mid] <= A[end]){
                if(A[mid] <= target && target <= A[end]){
                    start = mid;
                }else{
                    end = mid;
                }
            }
            if(A[mid] > A[end]){
                if(A[start] <= target && target <= A[mid]){
                    end = mid;
                }else{
                    start = mid;
                }
            }
        }
        
        if(A[start] == target)
            return start;
        if(A[end] == target)
            return end;
        return -1;
    }
};