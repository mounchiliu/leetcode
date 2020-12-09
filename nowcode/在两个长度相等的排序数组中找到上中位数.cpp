class Solution {
public:
    /**
     * find median in two sorted array
     * @param arr1 int整型vector the array1
     * @param arr2 int整型vector the array2
     * @return int整型
     */
    int findMedianinTwoSortedAray(vector<int>& A, vector<int>& B) {
        // write code here
       int m = A.size(), n = B.size();
       if(m == 0 && n == 0)
            return -1;

        
        if((m + n % 2) == 1){
            return getKth(A, 0, B, 0, (m + n)/2 + 1);
        }

        int left = getKth(A, 0, B, 0, (m + n)/2);
        //int right = getKth(A, 0, B, 0, (m + n)/2 + 1);
        //return (left + right)/2.0;
        return left;
    }
    
  
    int getKth(vector<int>& A, int startA, vector<int>& B, int startB, int k) {
        
        //循环停止的三个情况
        if(startA >= int(A.size())) //A遍历完, 则在B中找第k个元素 //【注意等号】
            return B[startB + k - 1];
        if(startB >= int(B.size()))
            return A[startA + k - 1];
        
        // 已经找到第k小的数---循环结束
        if (k == 1) {
            return min(A[startA], B[startB]);
        }
        
        
        //不用担心k是奇数k/2去尾，因为如果这里少看了，之后k-k/2还会把没看的元素补回来
        //比较两个数组中第k/2的元素，用来舍弃一部分元素
        int halfKthA = startA + k / 2 - 1 < int(A.size()) //【注意】-1，因为第几个和index差1
                        ? A[startA + k / 2 - 1] : INT_MAX;
        //如果这个index算出来不在A的index范围内，赋值无穷大 
        //因为比如一个特殊情况，A数组size很小，B很大，A没有第k/2个元素，则应该从B中删除k/2元素，因为A中数组个数+k/2 < k，也就是B中前k/2个一定不是两个数组合起来的k个元素
        int halfKthB = startB + k /2 - 1 < int(B.size())
                       ? B[startB + k / 2 - 1] :INT_MAX;
        
        
        if(halfKthA < halfKthB){//A的第K/2个元素小，删除A的
            return getKth(A, startA + k / 2, B, startB, k - k / 2);
        }
        if(halfKthA > halfKthB) 
            return getKth(A, startA, B, startB + k/2, k - k/2);
        if(halfKthA == halfKthB) //相等，k/2+k/2 = k 不用找了
            return halfKthA;
        
        return -1;
        
    }
};