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
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        if(head == NULL){
            return NULL;
        }
        //快指针先走n步，然后再和慢指针一起走，
        //此时当快指针走完的时候，慢指针则刚好走到倒数的第n个结点。
        ListNode *dummy = new ListNode(-1); //index 和第几个之间相差1，多加一个头
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return dummy->next;

    }
};