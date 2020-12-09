class Solution {
public:
    /**
     * max sum of the subarray
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxsumofSubarray(vector<int>& arr) {
        if(arr.empty()) return 0;
        int id = 0, sum = 0, num = 0;
        while(id < arr.size()){
            num = max(arr[id], arr[id]+num);//从前往后推，要保证每个位置的值都起码>=原本的
            //max（当前值，当前值+前一时刻的累加和）
            sum = max(sum, num);//保存当前时刻的最大累积和
            id++;
        }
        return sum;//返回容器末尾元素的引用
    }
};