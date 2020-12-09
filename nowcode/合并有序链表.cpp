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
     * @param l1 ListNode类 
     * @param l2 ListNode类 
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // write code here
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        ListNode *head = new ListNode(0), *tail = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            }
            
        }
        tail->next = (l1 == NULL) ? l2 : l1;
        /* while(l1){
            ptr->next = l1;
            l1 = l1->next;
            ptr = ptr->next;
        }
        while(l2){
            ptr->next = l2;
            l2 = l2->next;
            ptr = ptr->next;
        }*/
        return head->next;
    }
};