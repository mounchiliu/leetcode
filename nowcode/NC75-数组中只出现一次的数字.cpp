#include <unordered_map>
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() == 0 || num1 == NULL || num2 ==NULL)
            return;
        
        //version 1 Hashmap 时间复杂度O（n）、空间复杂度O（n）
        /*
        unordered_map<int, int> map;
        for(int &k: data) map[k]++;
        vector<int> result;
        for(int &i: data){
            if(map[i] == 1)
                result.push_back(i);
        }
        
        *num1 = result[0];
        *num2 = result[1];
        */
        
        //Version 2 位运算 时间复杂度O（n）空间复杂度O（1）
        //相同的数异或运算为0，不同为1 //n^n = 0
        //且任何数转换成二进制，每位和0异或，最后得到的数应该和原数相同 所以n^0 = n
        //且满足交换律 n^n^m = n^(n^m)
        //Step 1 让数组中每个数字异或一下，得到的结果等于两个出现一次的数的异或结果
        //Step 2 找这样一个结果中为1的那几位
        //因为其他位一定都相同这几位一定一个数为1一个为0
        //这里使用二进制补码
        //负数补码为正数的反码+1，举个例子
        //假如ret = 1110 ， -ret = 0010 ,and后得所以 i = 0010
        //所以，再异或一遍即可得到答案
        int ret = 0;
        for(int k: data) ret = ret^k;//异或运算
        ret &= (-ret);
        
        *num1 = 0, *num2 = 0;
        for(int k: data){
            if(k & ret) *num1 ^= k; //find it
            else *num2 ^= k; //n^n^m = 0^m = m
        }
    }
};