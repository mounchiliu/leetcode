class Finder {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        quickSort(a,0,n-1);
        return a[a.size()-K];
    }
private:
    void quickSort(vector<int> &a, int start, int end){
        if(start >= end) //рв╢М
            return;
        
        int mid = a[start + (end - start)/2];
        int left = start;
        int right = end;
        
        while(left <= right){
            while(left <= right && a[left] < mid){
                left++;
            }
            while(left <= right && a[right] > mid){
                right--;
            }
            
            if(left <= right){
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                
                left++;
                right--;
            }
            quickSort(a, start, right);
            quickSort(a, left, end);
            
        }    
    }
};