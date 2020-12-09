/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *a = pHead1, *b = pHead2;
        while(a != b){//不相等的时候移动指针
            a = a != NULL ? a->next : pHead2; //解决a、b不等长的问题
            b = b != NULL ? b->next : pHead1;
        }
        
        return a;
    }
};