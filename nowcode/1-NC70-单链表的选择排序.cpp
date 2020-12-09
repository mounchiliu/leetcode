//【思路】 二分 归并
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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        // write code here
        if(head == NULL || head->next == NULL)
            return head;
        
        //使用快慢指针找中点
        ListNode *slow = head, *fast = head->next;//fast用next是为了保证 
                                                  //[3,2] 这种情况下 fast和slow指针不会指向一个
        while(fast->next && fast){
            slow = slow->next;
            fast = fast->next->next;
        }
        //分成两个链表
        ListNode *rightList = slow->next;
        slow->next = NULL;
        
        //分治，左右各返回他们排好的
        ListNode *left = sortInList(head);
        ListNode *right = sortInList(rightList);
        
        ListNode *head_ = new ListNode(-1);
        ListNode *ptr = head_;
        
        //归并排序
        while(left && right){
            if(left->val < right->val){
                ptr->next = left;
                left = left->next;
            }else{
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }
        ptr->next = left != NULL ? left:right; //解决一个链表比另一个长一个的问题，因为二分了所以最多只能相差一个
        return head_->next;
        
    }
};
