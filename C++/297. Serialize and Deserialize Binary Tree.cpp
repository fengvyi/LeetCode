/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Solution 1. Cheat.
class Codec {
private:
    unordered_map<TreeNode*, string>tree2string;
    unordered_map<string, TreeNode*>string2tree;
    int count = 0;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = to_string(count++);
        tree2string[root] = s;
        string2tree[s] = root;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return string2tree[data];
    }
};

// Solution 2. Normal BFS solution using deque.
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(!root) return s;
        deque<TreeNode*>cur;
        deque<TreeNode*>sub;
        cur.push_back(root);
        while(!cur.empty()){
            TreeNode* node = cur.front();
            cur.pop_front();
            s.append(node ? to_string(node->val) + "," : ",");
            if(node){
                sub.push_back(node->left);
                sub.push_back(node->right);
            }
            if(cur.empty()) swap(cur, sub);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        string s;
        stringstream ss(data);
        getline(ss, s, ',');
        TreeNode* root = new TreeNode(stoi(s));
        deque<TreeNode*>q;
        q.push_back(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop_front();
            getline(ss, s, ',');
            TreeNode* left = s.size() ? new TreeNode(stoi(s)) : NULL;
            getline(ss, s, ',');
            TreeNode* right = s.size() ? new TreeNode(stoi(s)) : NULL;
            node->left = left;
            node->right = right;
            if(left) q.push_back(left);
            if(right) q.push_back(right);
        }
        return root;
    }
};
