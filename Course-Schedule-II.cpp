class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> result;

        // Build the graph and indegree array
        for (auto& pre : prerequisites) {
            int x = pre[0]; // course
            int y = pre[1]; // prerequisite
            adj[y].push_back(x); // y → x
            indegree[x]++;       // x has one more prereq
        }

        // Enqueue nodes with 0 indegree
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Kahn's Algorithm (BFS Topological Sort)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If result size == numCourses, return it; otherwise, cycle exists
        if (result.size() == numCourses) return result;
        return {};
    }
};
