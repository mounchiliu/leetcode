class Solution {
public:
    /**
     * 反转字符串
     * @param str string字符串 
     * @return string字符串
     */
    string solve(string str) {
        // write code here
        if(str.empty())
            return "";
        
        for(int i = 0; i < str.size()/2; i++){
            char temp = str[i];
            str[i] = str[str.size()-1-i];
            str[str.size()-1-i] = temp;
        }
        return str;
    }
};