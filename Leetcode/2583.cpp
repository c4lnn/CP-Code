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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        map<int, long long> mp;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* u, int dep) -> void {
            mp[dep] += u->val;
            if (u->left) {
                dfs(u->left, dep + 1);
            }
            if (u->right) {
                dfs(u->right, dep + 1);
            }
        };
        dfs(root, 0);
        if (mp.size() < k) {
            return -1;
        }
        vector<long long> vec;
        for (auto x : mp) {
            vec.push_back(x.second);
        }
        sort(vec.begin(), vec.end(), greater<long long>());
        return vec[k - 1];
    }
};