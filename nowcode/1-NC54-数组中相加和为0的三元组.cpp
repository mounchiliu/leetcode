class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
        if(num.size() < 3)
            return result;
        
        sort(num.begin(), num.end());//【】不能少

        //i确定第一个数
        for(int i = 0; i < num.size() - 2; i++){
            int left = i + 1;//确定第二个数，方向往后移动
            int right = num.size() - 1;//确定第三个数，方向向前移动
            
            while(left < right){
                //结果太大，尾部收缩
                if(num[left] + num[right] + num[i] > 0) right--;
                //结果太小，头部收缩
                else if(num[left] + num[right] + num[i] < 0) left++;
                else{
                    //相等//找到
                    result.push_back({num[i],num[left],num[right]});
                    //以下操作，处理重复元素
                    while(left + 1 < right && num[left+1] == num[left])
                        left++;
                    while(right - 1 > left && num[right-1] == num[right])
                        right--;
                    left++;
                    right--;
                }
            }
            while(i+1 < num.size()-2 && num[i+1] == num[i]) i++;
        }
        return result;
    }
};