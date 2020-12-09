class Palindrome {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        if(n == 0 || n == 1){
            return n;
        }
        int longlen = 0;
        for(int i = 0; i < A.size(); i++){
            const int len1 = expandAroundCenter(A, i, i);
            const int len2 = expandAroundCenter(A, i, i+1);
            
            int len = max(len1, len2);
            if(len > longlen){
                longlen = len;
            }
        }
        
        return longlen;
    }
    
private:
    int expandAroundCenter(string &A, int left, int right){
        while(A[left]==A[right] && left>=0 && right<A.size()){
            left--;
            right++;
        }
        return (right - left - 1);
    }
};