/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    typedef vector<int>::iterator Itr;
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return buildTreeRecur(pre.begin(), pre.end(), 
                             vin.begin(), vin.end());
    }
private:
    TreeNode *buildTreeRecur(Itr pstart, Itr pend, Itr istart, Itr iend){
        if(istart == iend) return NULL;
        
        int rootVal = *pstart;
        Itr itr_root = find(istart, iend, rootVal);
        TreeNode *res = new TreeNode(rootVal);
        int leftsize = itr_root - istart;
        res->left = buildTreeRecur(pstart+1, pstart+leftsize+1, istart, itr_root);
        res->right = buildTreeRecur(pstart+leftsize+1, pend, itr_root+1, iend);
        
        return res;
    }
};