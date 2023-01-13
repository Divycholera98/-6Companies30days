/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(vector <int> &v,TreeNode* root)
    {
        if(root==nullptr)return;
        v.push_back(root->val);
        dfs(v,root->left);
        dfs(v,root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector <int> v;
        dfs(v,root1);
        dfs(v,root2);
        sort(v.begin(),v.end());
        return v;
    }
};
