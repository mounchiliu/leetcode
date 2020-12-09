#include <unordered_map> 
class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        vector<int> res;
        unordered_map<int, int> map;
        // 建立hash table array's value=> array's index
        for(int i=0; i<numbers.size(); i++){
            map[numbers[i]] = i;
        }
        // 第二次遍历，查询是否存在当前数的complement在hash table中
        for(int i=0; i<numbers.size(); i++){
            int complement = target - numbers[i];
            if(map.find(complement) != map.end() && map[complement]!=i){ 
                res = {int(i)+1, map.at(complement)+1};
                return res; //或者立即break，不能少
            }
        }
        return res;
       
    }
};