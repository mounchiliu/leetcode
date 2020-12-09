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
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if(head == NULL)
               return NULL;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *start = head, 
        *end = head, *next = head;
        
        while(next != NULL){
            //find kth
            for(int i = 1; i < k && end != NULL; i++){
                end = end->next;
            }
            
            if(end == NULL){
                break; //cant reverse, not enough nodes
            }
            next = end->next;
            
            //break for reverse
            end->next = NULL;
            end = start;//back up
            //reverse
            start = reverse(start);
            
            end->next = next;
            pre->next = start;
            //reverse done, define the position of the node for new start
            pre = end;
            start = next;
            end = start;
        }
        return dummy->next;
    }
    
private:
    ListNode* reverse(ListNode *head){
        ListNode *cur = head;
        ListNode *pre = NULL;
        ListNode *next = NULL;
        
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};