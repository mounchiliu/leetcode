#include <stack>
class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        int len = s.size();
        stack<char> myStack;
        for(int i = 0; i < len; i++){
            if(s[i] == '(') myStack.push(')');
            else if(s[i] == '[') myStack.push(']');
            else if(s[i] == '{') myStack.push('}');
            else if(myStack.empty()) return false;//only get the top//有尾没有头 []}
            else if(myStack.top() != s[i]) return false;//compare at the end//头尾不匹配
            else myStack.pop();
            
            
        }
        return myStack.empty(); //不是一对一对的情况，有头没有尾 e.g. [[{}]
    }
};