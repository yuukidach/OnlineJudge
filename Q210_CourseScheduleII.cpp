class Solution {
public:
    vector<vector<int>> e;
    vector<int> v;
    vector<int> res;
    bool has_loop = false;

    void dfs(int u) {
        v[u] = 1;

        for (int su : e[u]) {
            if (v[su] == 0) dfs(su); 
            else if (v[su] == 1){
                has_loop = true;
                return;
            }
        }

        res.push_back(u);
        v[u] = 2;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        e.resize(numCourses);
        v.resize(numCourses);

        for (const auto &info : prerequisites) {
            e[info[0]].push_back(info[1]);
        }

        for (int i = 0; i < numCourses && !has_loop; ++i) {
            if (!v[i]) dfs(i);
        }

        if (has_loop) return {};
        return res;
    }
};
