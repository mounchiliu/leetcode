class Solution {
public:
    int jumpFloor(int number) {
        int A[number + 1];
        A[0] = 0, A[1] = 1, A[2] = 2;
        
        if(number <= 2){
            return A[number];
        }
        
        for(int i = 3; i <= number; i++){
            A[i] = A[i-1] + A[i-2];
        }
        
        return A[number];
        
    }
};