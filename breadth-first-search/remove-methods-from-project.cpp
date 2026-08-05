class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        vector<bool> suspicious(n, false);
        vector<int> q;
        q.push_back(k);
        suspicious[k] = true;

        int head = 0;
        while (head < q.size()) {
            int u = q[head++];
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push_back(v);
                }
            }
        }

        for (const auto& inv : invocations) {
            if (!suspicious[inv[0]] && suspicious[inv[1]]) {
                vector<int> res(n);
                for (int i = 0; i < n; ++i) {
                    res[i] = i;
                }
                return res;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!suspicious[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};