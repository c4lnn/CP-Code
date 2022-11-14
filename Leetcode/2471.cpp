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
    int minimumOperations(TreeNode* rt) {
        int ret = 0;
        std::vector<std::vector<int>> a(100050);

        std::function<void(TreeNode*, int)> build = [&](TreeNode* u, int dep) -> void {
            a[dep].push_back(u->val);
            if (u->left) {
                build(u->left, dep + 1);
            }
            if (u->right) {
                build(u->right, dep + 1);
            }
        };

        build(rt, 0);

        for (int i = 0; a[i].size(); i++) {
            std::vector<std::pair<int,int>> b;

            for (int j = 0; j < a[i].size(); j++) {
                b.emplace_back(a[i][j], j);
            }

            std::sort(b.begin(), b.end());

            for (int j = 0; j < b.size(); j++) {
                a[i][b[j].second] = j;
            }

            std::vector<std::vector<int>> g(b.size());

            for (int j = 0; j < b.size(); j++) {
                g[j].push_back(a[i][j]);
            }

            std::vector<bool> in(b.size());
            int loop = 0;
            std::function<void(int)> dfs = [&](int u) -> void {
                if (in[u]) {
                    ++loop;
                    return;
                }

                in[u] = true;

                for (auto v : g[u]) {
                    dfs(v);
                }

            };

            for (int j = 0; j < b.size(); j++) {
                if (!in[j]) {
                    dfs(j);
                }
            }

            ret += b.size() - loop;
        }
        return ret;
    }
};