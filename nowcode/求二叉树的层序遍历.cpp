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
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        if(root == NULL){
            return {};
        }
        
        vector<vector<int>> result;
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()){
            int size = Q.size();
            vector<int> level;
            
            for(int i = 0; i < size; i++){
                TreeNode *node = Q.front(); Q.pop();
                level.push_back(node->val);
                
                if(node->left != NULL)
                    Q.push(node->left);
                if(node->right != NULL)
                    Q.push(node->right);
            }
            result.push_back(level);
        }
        return result;
        
    }
};