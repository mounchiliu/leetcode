class Solution {
public:
    /**
     * retrun the longest increasing subsequence
     * @param arr int整型vector the array
     * @return int整型vector
     */
    vector<int> LIS(vector<int>& arr) {
        // write code here
        if(arr.size() == 0)
            return {};
        
        // dp[i]表示长度为i的最长上升子序列的末尾元素的最小值//即字典序最小
        vector<int> result;
        vector<int> dp(arr.size(), 0);
        vector<int> pos(arr.size(), 0); //pos[i]=j用来记录nums[i]在dp中的第j个位置
        
        int len = 0;
        dp[len] = arr[0];
        
        for(int i = 1; i < arr.size(); i++){
            // nums[i]比最长的末尾元素的都大，直接更新
            if(arr[i] > dp[len]){
                len++;
                dp[len] = arr[i];
                pos[i] = len;//index
            }
            else{ // 二分查找
                //找arr[i]在[0，len]应该插入的地方
                //即二分找最后一个比他小的， 或第一个比arr[i]大的
                //这里找第一个比他大的，这个index就是我们插入的index
                int left = 0, right = len;
                while(left + 1 < right){
                    int mid = left + (right - left) / 2;
                    if(arr[i] >= dp[mid]){
                        left = mid + 1;
                    }else{
                        right = mid;
                    }
                }
                
                if(dp[left] > arr[i]){
                    dp[left] = arr[i];
                    pos[i] = left;
                }
                else if(dp[right] > arr[i]){
                    dp[right] = arr[i];
                    pos[i] = right;
                }
                else{ //没找到
                    dp[0] = arr[i];//update the first element
                    pos[i] = 0;
                }
            }
        }
        //update path;
        vector<int> res(len + 1, INT_MAX);
        //dp[i]存放的是 长度为(i+1)的最后一个元素的最小值
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (pos[i] == len) { //如果arr[i]的位置和dp的位置一致
                res[len] = min(res[len], arr[i]);  //res[len] = arr[i];
                len--;
            }
        }
        return res;
            
        
    }
};