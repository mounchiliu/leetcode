/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        if(head == NULL)
            return true;
        
        vector<int> vals;
        
        while(head){
            vals.push_back(head->val);
            head = head->next;
        }
        
        int start = 0, end = vals.size() - 1;
        while(start < end){
            if(vals[start] != vals[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};
