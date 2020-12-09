/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int maxDepth(TreeNode* root) {
        // write code here
        if(root == NULL)
            return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        int depth = max(left, right) + 1;
        return depth;
    }
};