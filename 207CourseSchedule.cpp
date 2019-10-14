class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> graph;	// adjacency list
        vector<int> indegree(numCourses, 0);
        for (auto course : prerequisites) {
            graph[course[1]].push_back(course[0]);
            ++indegree[course[0]];
        }
        
        // topological sort
        int count = 0;
        queue<int> que;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }
        
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            ++count;
            auto item = graph.find(cur);
            if (item != graph.end()) {
                for (int i : item->second) {
                    if (--indegree[i] == 0) {
                        que.push(i);
                    }
                }
            }
        }
        
        return count == numCourses;
    }
};