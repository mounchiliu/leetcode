class Solution {
public:
    /**
     * 进制转换
     * @param M int整型 给定整数
     * @param N int整型 转换到的进制
     * @return string字符串
     */
    string solve(int M, int N) {
        // write code here
        string s = "0123456789ABCDEF";
        string res;
        bool neg = false;
        
        if(M == 0)
            return 0;
        if(M < 0){
            neg = true;
            M = -M;
        }
        
        while(M){
            res += s[M%N];
            M = M/N;
        }
        if(neg){
            res += "-";
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};