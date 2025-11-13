class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> adj; // adjacency list
        unordered_map<char, int> indegree;     // indegree count

        // Step 1: Initialize all characters in indegree map
        for (auto &word : words)
            for (auto &ch : word)
                indegree[ch] = 0;

        // Step 2: Build graph from word pairs
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool foundDiff = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    foundDiff = true;
                    break;
                }
            }

            // Invalid case: prefix conflict (e.g., "abcd" before "ab")
            if (!foundDiff && w1.size() > w2.size())
                return "";
        }

        // Step 3: Topological Sort (Kahn’s Algorithm)
        queue<char> q;
        for (auto &p : indegree)
            if (p.second == 0)
                q.push(p.first);

        string order;
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            order += c;

            for (auto &next : adj[c]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        // Step 4: Check for cycles (invalid ordering)
        if (order.size() != indegree.size())
            return "";

        return order;
    }
};
