class FoodRatings {
public:
    struct rec {
        string s;
        int val;
        rec () = default;
        rec(string s, int val) : s(s), val(val) {}
        bool operator<(const rec& other) const {
            return val < other.val || val == other.val && s > other.s;
        }
    };
    unordered_map<string, int> mp, val, col;
    int cnt = 0;
    priority_queue<rec> q[20005];
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        mp.clear();
        for (int i = 0; i < f.size(); i++) {
            while (q[i].size()) {
                q[i].pop();
            }
        }
        for (int i = 0; i < f.size(); i++) {
            if (!mp.count(c[i])) {
                mp[c[i]] = cnt++;
            }
            val[f[i]] = r[i];
            q[col[f[i]] = mp[c[i]]].emplace(f[i], r[i]);
        }
    }

    void changeRating(string f, int nr) {
        val[f] = nr;
        q[col[f]].emplace(f, nr);
    }

    string highestRated(string c) {
        while(q[mp[c]].top().val != val[q[mp[c]].top().s]) {
            q[mp[c]].pop();
        }
        return q[mp[c]].top().s;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */