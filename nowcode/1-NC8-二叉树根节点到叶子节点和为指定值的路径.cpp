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
     * @param sum int整型 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        // write code here
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        vector<int> path;
        Traverse(root, sum, path, result);
        return result;
    }
    
private:
    void Traverse(TreeNode *root, int sum, 
                  vector<int> &path, vector<vector<int>> &result){
        if(root == NULL)
            return;
        
        sum = sum - root->val;
        path.push_back(root->val);
        if(sum == 0 && root->left == NULL && root->right == NULL){
            result.push_back(path);
        }else{
            Traverse(root->left, sum, path, result);
            Traverse(root->right, sum, path, result);
        }
        path.pop_back();
    }
};