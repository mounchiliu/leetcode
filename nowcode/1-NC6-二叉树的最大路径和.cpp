/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
class ResultType{
public:
    // singlePath: 从root往下走到任意点的最大路径，这条路径可以不包含任何点
    // maxPath: 从树中任意到任意点的最大路径，这条路径至少包含一个点
    int singleSum, maxSum;
    
    ResultType(int single, int max){
        singleSum = single;
        maxSum = max;
    }
    
};
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int maxPathSum(TreeNode* root) {
        // write code here
        if(root == NULL)
            return 0;
        
        //分治法。 需要考虑的是，子树中最大的路不一定必过根节点。
        //所以要记录single Path的值
        ResultType rt = helper(root);
        return rt.maxSum;
    }

private:
    ResultType helper(TreeNode * root){
        if(root == NULL){
            return ResultType(0, INT_MIN);
        }
        
        ResultType left = helper(root->left);
        ResultType right = helper(root->right);
        
        int single = max(left.singleSum, right.singleSum) + root->val;
        single = max(single, 0);
        
        int maxSum = max(left.maxSum, right.maxSum);
        maxSum = max(maxSum, left.singleSum + right.singleSum + root->val);
        
        return ResultType(single, maxSum);
    }
};