class Solution {
public:
    /**
     * 
     * @param A int整型一维数组 
     * @param n int A数组长度
     * @param target int整型 
     * @return int整型
     */
    int search(int* a, int n, int target) {
        // write code here
        
         if(a == NULL)
            return -1;
        
        int start = 0, end = n - 1;
        
        while(start + 1 < end){
            int mid = start + (end - start) / 2;
            
            if(a[mid] <= a[end]){
                if(a[mid] <= target && target <= a[end]){
                    start = mid;
                }else{
                    end = mid;
                }
            }else{
                if(a[start] <= target && target <= a[mid])
                    end = mid;
                else
                    start = mid;
                
            }
        }
        
        
        if(a[start]==target)
            return start;
        if(a[end] == target)
            return end;
        
        return -1;
    }
};