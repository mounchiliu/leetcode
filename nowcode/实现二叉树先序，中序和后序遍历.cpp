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
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        if(root == NULL)
            return {{},{},{}};
        vector<int> preorder;
        vector<int> inorder;
        vector<int> postorder;
        
        preTraverse(root, preorder);
        inTraverse(root, inorder);
        postTraverse(root, postorder);
        
        
        vector<vector<int>> result = {preorder, inorder, postorder};
        return result;
    }
    
private:
    void preTraverse(TreeNode * root, vector<int> &preOrder){
        if(root == NULL) return;
        
        preOrder.push_back(root->val);
        preTraverse(root->left, preOrder);
        preTraverse(root->right, preOrder);
    }
    
    void inTraverse(TreeNode * root, vector<int> &inOrder){
        if(root == NULL) return;
        
        inTraverse(root->left, inOrder);
        inOrder.push_back(root->val);
        inTraverse(root->right, inOrder);
    }
    
    void postTraverse(TreeNode * root, vector<int> &postOrder){
        if(root == NULL) return;
        
        postTraverse(root->left, postOrder);
        postTraverse(root->right, postOrder);
        postOrder.push_back(root->val);
    }
    
        
    
};