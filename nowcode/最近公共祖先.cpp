/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
class ResultType{
public:
    bool o1_exist, o2_exist;
    TreeNode *node;
    
    ResultType(bool a, bool b, TreeNode *n){
        o1_exist = a;
        o2_exist = b;
        node = n;
    }
};

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        if(root == NULL)
            return -1;
        
        ResultType result = helper(root, o1, o2);
        if(result.o1_exist && result.o2_exist)
            return result.node->val;
        return -1;
    }
    
    ResultType helper(TreeNode *root, int o1, int o2){
        if(root == NULL)
            return ResultType(false, false, NULL);
        
        ResultType left_rt = helper(root->left, o1, o2);
        ResultType right_rt = helper(root->right, o1, o2);
        
        bool o1_exist = left_rt.o1_exist || right_rt.o1_exist || root->val == o1;
        bool o2_exist = left_rt.o2_exist || right_rt.o2_exist || root->val == o2;
        
        if(root->val == o1 || root->val == o2)
            return ResultType(o1_exist, o2_exist, root);
        
        if(left_rt.node != NULL && right_rt.node != NULL)
            return ResultType(o1_exist, o2_exist, root);
        
        
        if(left_rt.node != NULL)
            return ResultType(o1_exist, o2_exist, left_rt.node);
        
        if(right_rt.node != NULL)
            return ResultType(o1_exist, o2_exist, right_rt.node);
        
        return ResultType(o1_exist, o2_exist, NULL);
    }
};