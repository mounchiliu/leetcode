class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int m = str1.size();
        int n = str2.size();
        if(m == 0 || n == 0)
            return "-1";

        int dp[m+1][n+1];//dp[i][j] 表示str1前(i-1)个字符与str2前(j-1)个字符的最长公共子串
        int maxLen = 0, end = 0;
        
        //initialize the zero step
        for(int i = 0; i <= m; i++) dp[i][0] = 0;
        for(int j = 0; j <= n; j++) dp[0][j] = 0;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = 0;
                if(dp[i][j] > maxLen){
                    maxLen = dp[i][j];
                    end = i - 1; //i对应下方str1， 若使用j对应下方str2
                }
            }
        }
        
        if(maxLen == 0) return "-1";
        return str1.substr(end - maxLen + 1, maxLen);
    }
};