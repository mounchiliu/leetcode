//【思路】：分治、归并
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0)
            return NULL;
        if(lists.size() == 1)
            return lists[0];
        vector<ListNode *> mergeTemp;
        for(int i = 0; i < lists.size()/2; i++){
            mergeTemp.push_back(
                mergeTwoLists(lists[i*2], lists[i*2+1]));
        }
        //for odd numbers of lists
        if(lists.size() % 2 == 1){
            mergeTemp.push_back(lists.back());
        }
        
        return mergeKLists(mergeTemp);
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        //version 1 non-reversive
        /*if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                ptr->next = l1;
                l1 = l1->next;
            }else{
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        
        while(l1){
            ptr->next = l1;
            l1 = l1->next;
            ptr = ptr->next;
        }
        while(l2){
            ptr->next = l2;
            l2 = l2->next;
            ptr = ptr->next;
        }
        return dummy->next;*/
        
        //version 2 recursive
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        
    }
};