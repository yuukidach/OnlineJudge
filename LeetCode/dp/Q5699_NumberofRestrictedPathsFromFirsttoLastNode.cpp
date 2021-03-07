class Solution {
public:
    using ll = long long;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        constexpr int mod = 1e9 + 7;
        vector<vector<pair<int,int>>> g(n);
        for(auto e : edges){
            int u = e[0], v = e[1], w = e[2];
            -- u, -- v;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u ,w);
        }
        priority_queue<pair<int,int>> pq;
        vector<ll> d(n, 5e9);
        d[n - 1] = 0;
        pq.emplace(0, n - 1);
        vector<ll> cnt(n, 0);
        cnt[n - 1] = 1;
        while(!pq.empty()){
            auto [w, u] = pq.top();
            pq.pop();
            w = -w;
            if(w > d[u]) continue;
            for(auto& [v, ww] : g[u]){
                if(ww + w < d[v]){
                    d[v] = ww + w;
                    pq.emplace(-d[v], v);
                }
                if(d[u] < d[v]) cnt[v] = (cnt[v] + cnt[u]) % mod;
            }
        }
        return cnt[0];
    }
};
