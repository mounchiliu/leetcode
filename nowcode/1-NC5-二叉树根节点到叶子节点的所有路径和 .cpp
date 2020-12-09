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
    int sumNumbers(TreeNode* root) {
        // write code here
        if(root == NULL)
            return 0;
        
        int sum = 0;
        return preOrder(root, sum);
        
    }
private:
    int preOrder(TreeNode *root, int sum){
        if(root == NULL) return 0;
        
        sum = sum*10 + root->val;
        if(root->left == NULL && root->right == NULL) return sum; //左右子树返回的是从root到当前节点的sum
        return preOrder(root->left, sum) + preOrder(root->right, sum);
    }
};