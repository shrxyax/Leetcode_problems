class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // minHeap: {cost, node, stops}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        // dist[node][stops] = minimum cost to reach `node` with `stops` flights
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int cost = cur[0], node = cur[1], stops = cur[2];

            if (node == dst) return cost; // Found cheapest

            if (stops > k) continue; // Already exceeded max stops

            for (auto &edge : adj[node]) {
                int next = edge.first, price = edge.second;
                int newCost = cost + price;

                // Only push if strictly better than any previous cost with same stops
                if (newCost < dist[next][stops+1]) {
                    dist[next][stops+1] = newCost;
                    pq.push({newCost, next, stops+1});
                }
            }
        }
        return -1;
    }
};

