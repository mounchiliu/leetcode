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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast != NULL && fast->next != NULL){ //保证不会出现对NULL查找next的情况
            fast = fast->next->next;
            slow = slow->next;
            
            //找相遇点
            if(fast == slow){
                ListNode *slow2 = head;//设置以相同速度的新指针从起始位置出发
                while(slow2 != slow){////未相遇循环
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow;
            }
        }
        return NULL;
            
    }
};