class ResultType{
public:
    int depth;
    bool valid;
    
    ResultType(int d, bool v){
        depth = d;
        valid = v;
    }
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL)
            return true;
        
        ResultType rt = helper(pRoot);
        return rt.valid;

    }
    
private:
    ResultType helper(TreeNode *root){
        if(root == NULL){
            return ResultType(0,true);
        }
        
        ResultType left = helper(root->left);
        ResultType right = helper(root->right);
        int depth = max(left.depth, right.depth) + 1;
        
        if(!left.valid || !right.valid){
            return ResultType(depth, false);
        }
        
        if(abs(left.depth - right.depth)>1){
            return ResultType(depth, false);
        }
        
        return ResultType(depth, true);
    }
};