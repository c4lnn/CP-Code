class Solution {
public:
    int closestMeetingNode(vector<int>& e, int n1, int n2) {
        vector<int> dist1(e.size(), -1), dist2(e.size(), -1);
        int u = n1;
        dist1[u] = 0;
        while (true) {
            if (e[u] == -1 || dist1[e[u]] >= 0) {
                break;
            }
            dist1[e[u]] = dist1[u] + 1;
            u = e[u];
        }
        u = n2;
        dist2[u] = 0;
        while (true) {
            if (e[u] == -1 || dist2[e[u]] >= 0) {
                break;
            }
            dist2[e[u]] = dist2[u] + 1;
            u = e[u];
        }
        int len = INT_MAX, ret = -1;
        for (int i = 0; i < e.size(); i++) {
            if (dist1[i] >= 0 && dist2[i] >= 0) {
                if (max(dist1[i], dist2[i]) < len) {
                    ret = i;
                    len = max(dist1[i], dist2[i]);
                }
            }
        }
        return ret;
    }
};