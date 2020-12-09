//【Reverseve VS Non-Recursive】
//Version 1 Reversive
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

//Version 2 Non-recursive
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        
        vector<int> pre;
        vector<int> in;
        vector<int> post;
        preOrder(root, pre);
        inOrder(root, in);
        postOrder(root, post);
        
        return {pre, in, post};
    }
    
private:
    void preOrder(TreeNode *root, vector<int> &result){
        if(root == NULL)
            return;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode *head = s.top(); s.pop();
            result.push_back(head->val);
            
            if(head->right){
                s.push(head->right);
            }
            
            if(head->left){
                s.push(head->left);
            }
        }
    }
    
    
    void inOrder(TreeNode *root, vector<int> &result){
       if(root == NULL)
           return;
        
        stack<TreeNode *> s;
        TreeNode *node = root;
        while(!s.empty() || node){
            while(node){
                s.push(node);
                node = node->left;
            }
            
            node = s.top();s.pop();
            result.push_back(node->val);
            
            node = node->right;
        }
    }
    
    void postOrder(TreeNode *root, vector<int> &result){
        if(root == NULL)
            return;
        
        stack<TreeNode *> s;
        TreeNode *node = root;
        TreeNode *lastVisited = NULL;
        
        while(!s.empty() || node != NULL){
            while(node != NULL){
                s.push(node);
                node = node->left;
            }
            
            node = s.top();
            if(node->right == NULL || node->right == lastVisited){
                s.pop();
                result.push_back(node->val);
                lastVisited = node;
                node = NULL;
            }else{
                node = node->right;
            }
        }
           
    }
    
};
