class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> variables;
        int n = 0;
        for (auto eq : equations) {
            if (variables.count(eq[0]) < 1) variables.emplace(eq[0], n++);
            if (variables.count(eq[1]) < 1) variables.emplace(eq[1], n++);
        }

        vector<vector<double>> graph(n, vector<double>(n, -1.0));
        int idx = 0;
        for (auto eq : equations) {
            graph[variables[eq[0]]][variables[eq[1]]] = values[idx];
            graph[variables[eq[1]]][variables[eq[0]]] = 1 / values[idx++];
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if(graph[i][k] > 0 && graph[k][j] > 0) {
                        graph[i][j] = graph[i][k] * graph[k][j];
                    }
                }
            }
        }

        vector<double> res;
        for (auto q : queries) {
            if (variables.count(q[0]) && variables.count(q[1])) {
                int va =variables[q[0]], vb = variables[q[1]];
                res.emplace_back(graph[va][vb]);
            } else {
                res.emplace_back(-1.0);
            }
            
        }

        return res;
    }
};