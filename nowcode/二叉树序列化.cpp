/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    char* Serialize(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        
        //使用容器方便存储、读取信息。//这里使用vector是因为一个根可能有多个子元素一次性压进去了，使用vector可以方便访问直接q[i]
                                   //且vector尾巴可以出 即pop_back
                                   //这里使用vector最主要是一件给了你树结构，只需要根据BFS一层一层左右往下走就行，走到一个压进vector即可。
        vector<TreeNode *> q;
        q.push_back(root);
        for(int  i = 0; i < q.size(); i++) { //【这里的size是动态，因为不断更新vectorsize获取node】
            TreeNode * node = q[i];
            if (node == NULL) { //该节点NULL 不往下搜索了
                continue;
            }
            q.push_back(node->left);
            q.push_back(node->right);
        }
        while (q[q.size() - 1] == NULL) { //最后一个元素因为没有左右点一定有NULL， 所以删除最后连续的NULL
                q.pop_back();//删除最后一个元素//销毁并抛弃vector的最后一个元素,vector的size改变
        }//用来删除多于NULL
        
        //to string
        //处理开头
        string sb="";
        sb += "{";
        sb += to_string(q[0]->val);
        
        //处理中间部分
        for (int i = 1; i < q.size(); i++) {
            if (q[i] == NULL) {
                sb += (",#");
            } 
            else {
                sb += ",";
                sb += to_string(q[i]->val);
            }
        }
        
        //处理结尾
        sb += "}";
        
        char *result = new char[sb.size()];
        for(int i = 0; i < sb.size(); i++){
            result[i] = (char) sb[i];
        }
        return result;
        
    }
    TreeNode* Deserialize(char *str) {
        if(str == NULL) return NULL;
        string data(str);
        
        vector<string> vals = split(data.substr(1, data.size()-2), ",");
        
        queue<TreeNode *> Q;
        TreeNode *root = new TreeNode(atoi(vals[0].c_str()));
        Q.push(root);
        bool isleft = true;
        
        for(int i = 1; i < vals.size(); i++){
            if(vals[i] != "#"){
                TreeNode *node = new TreeNode(atoi(vals[i].c_str()));
                
                if(isleft) Q.front()->left = node;
                else Q.front()->right = node;
                Q.push(node);
            }
            if(!isleft){
                Q.pop();
            }
            isleft = !isleft;
            
            
        }
        return root;
    }
    
    vector<string> split(const string &str, string delim) {
        vector<string> results;
        int lastIndex = 0, index;
        while ((index = str.find(delim, lastIndex)) != string::npos) { //这里表示若找到了 find delimma's position //string::npos说明查找没有匹配
            results.push_back(str.substr(lastIndex, index - lastIndex));
            lastIndex = index + delim.length();//更新到下一个不是delim的头位置
        }
        if (lastIndex != str.length()) { //全部找完之后，之后 由于，后面可能还有元素 lastIndex不是str的结尾，把剩下的push进去
            results.push_back(str.substr(lastIndex, str.length() - lastIndex));
        }
        return results;
    }
    
    
};