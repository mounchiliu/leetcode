class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    int sqrt(int x) {
        // write code here
        if(x <= 1) return x;
        
        int left = 1, right = x;
        while(left < right){ //must exist, so stop when equal,at the last return one of the value
            long mid = left + (right - left)/2;
            if(mid * mid <= x && (mid + 1) * (mid + 1) > x) //两数相乘 会溢出
                return mid;
            if(mid * mid > x) right = mid;
            else left = mid;
        }
        
        return left;
    }
};


class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    int sqrt(int x) {
        // write code here
        if(x < 0)
            return -1;
        if(x <= 1)
            return x;
        
        int start = 1, end = x;
        int mid;
        while(start + 1 < end){
            mid = start + (end - start) / 2;
            
            if(mid <= x/mid && (mid + 1) > x/(mid+1)){
                return mid;
            }
            if(mid > x/mid){
                end = mid;
            }else{
                start = mid;
            }
        }
        if(start <= x/start && (start+1) > x/(start+1))
            return start;
        return end;
    }
};

OR 防止溢出
class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    int sqrt(int x) {
        // write code here
        if(x < 0)
            return -1;
        if(x <= 1)
            return x;
        
        int start = 1, end = x;
        int mid;
        while(start < end){
            mid = start + (end - start) / 2;
            
            if(mid <= x/mid && (mid + 1) > x/(mid + 1)){
                return mid;
            }
            if(mid < x/mid){
                start = mid;
            }else{
                end = mid;
            }
        }
        return start;
        
    }
};