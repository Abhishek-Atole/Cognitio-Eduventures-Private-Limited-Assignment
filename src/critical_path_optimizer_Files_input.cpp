#include <bits/stdc++.h>
using namespace std;

/**
 * Calculates the minimum completion time for a processor network with given high-speed replacements
 */
int calculateCriticalPath(const vector<vector<int>>& graph, const vector<int>& time, 
                          const vector<bool>& isHighSpeed) {
    int n = graph.size() - 1;  // Number of processors
    
    // Calculate indegree for topological sort
    vector<int> indegree(n + 1, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }
    
    // Track earliest start time for each processor
    vector<int> earliestStart(n + 1, 0);
    queue<int> q;
    
    // Push all nodes with 0 indegree
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        // Calculate processing time based on whether the processor is high-speed
        int processingTime = isHighSpeed[u] ? time[u] / 2 : time[u];
        
        for (int v : graph[u]) {
            // Update earliest start time for the dependent processor
            earliestStart[v] = max(earliestStart[v], earliestStart[u] + processingTime);
            
            // Reduce indegree and add to queue if all dependencies are processed
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // Calculate project completion time (maximum finish time)
    int result = 0;
    for (int i = 1; i <= n; i++) {
        int processingTime = isHighSpeed[i] ? time[i] / 2 : time[i];
        result = max(result, earliestStart[i] + processingTime);
    }
    
    return result;
}

/**
 * Finds the optimal critical path by iterative refinement
 */
int optimizeCriticalPath(const vector<vector<int>>& graph, const vector<int>& time, int k, int n) {
    vector<bool> isHighSpeed(n + 1, false);
    
    // Initial critical path calculation without any high-speed processors
    int bestTime = calculateCriticalPath(graph, time, isHighSpeed);
    
    // Iteratively improve by replacing the most impactful processor
    for (int iteration = 0; iteration < k; iteration++) {
        int bestProcessor = -1;
        int bestTimeReduction = 0;
        
        // Try replacing each processor that's not already high-speed
        for (int i = 1; i <= n; i++) {
            if (!isHighSpeed[i]) {
                isHighSpeed[i] = true;
                int newTime = calculateCriticalPath(graph, time, isHighSpeed);
                int timeReduction = bestTime - newTime;
                
                if (timeReduction > bestTimeReduction) {
                    bestTimeReduction = timeReduction;
                    bestProcessor = i;
                }
                
                isHighSpeed[i] = false;  // Reset for next iteration
            }
        }
        
        // If no improvement is possible, break
        if (bestTimeReduction <= 0) {
            break;
        }
        
        // Replace the processor that gives the best improvement
        isHighSpeed[bestProcessor] = true;
        bestTime -= bestTimeReduction;
    }
    
    return bestTime;
}

int main(int argc, char* argv[]) {
    // Allow input from a file if provided
    if (argc > 1) {
        freopen(argv[1], "r", stdin);  // Redirect input from the given file
    }
    
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> time(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> time[i];
    }
    
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    
    int result = optimizeCriticalPath(graph, time, k, n);
    cout << result << endl;
    
    return 0;
}