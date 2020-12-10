/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return;
        //先拆半、后半逆序、最后并序
        ListNode *fast = head->next;
        ListNode *slow = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        //break into two pieces
        ListNode *rightList = slow->next;
        slow->next = NULL;
        
        //reverse the rightList
        rightList = reverse(rightList);
        
        //sort
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr = dummy; 
        bool reverse = false;
        while(head && rightList){
            if(reverse){
                ptr->next = rightList;
                rightList = rightList->next;
            }else{
                ptr->next = head;
                head = head->next;
            }
            ptr = ptr->next;
            reverse = !reverse;
        }
        ptr->next = rightList == NULL ? head : rightList;
        head = dummy->next;
        
    }
    
private:
    ListNode* reverse(ListNode *head){
        if(head == NULL)
            return NULL;
        
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