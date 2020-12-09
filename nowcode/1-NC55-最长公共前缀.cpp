class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        // write code here
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
        
        sort(strs.begin(), strs.end());
        string result;
        int i = 0, j = 0;
        while(i < strs[0].size() && j < strs[strs.size()-1].size()){
            if(strs[0][i] != strs[strs.size()-1][j]){
                break;
            }
            result += strs[0][i];
            i++; j++;
        }
        
        return result;
        
    }
};