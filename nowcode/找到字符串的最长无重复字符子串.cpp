#include <unordered_map>
class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        unordered_map<int,int> lastIndex;
        for(int i = 0; i < arr.size(); i++){
            lastIndex[arr[i]] = -1;
        }
        int curID = 0;//string的起点
        int length = 0;
        for(int i = 0; i < arr.size(); i++){
            if(lastIndex[arr[i]] != -1)
                curID = max(curID, lastIndex[arr[i]]+1);//如果a出现过，那么指针的位置要大于a上次出现的位置，即now=max(now,last[a]);
            length = max(length, i - curID + 1);
            lastIndex[arr[i]] = i;
            
        }
        return length;
        
        
    }
};