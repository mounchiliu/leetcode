class Solution {
public:
    /**
     * 二分查找
     * @param n int整型 数组长度
     * @param v int整型 查找值
     * @param a int整型vector 有序数组
     * @return int整型
     */
    int upper_bound_(int n, int target, vector<int>& a) {
        // write code here
        if(n = 0)
            return -1;
        int start = 0, end = n - 1;
        int mid;
        while(start + 1 < end){
            mid = start + (end - start)/2;
            
            if(a[mid] >= target){
                end = mid;
            }else{
                start = mid + 1;
            }
        
        }
        
        if(a[start] >= target) return (start + 1);
        if(a[end] >= target) return (end + 1);
        
        return (n + 1);
    }
};