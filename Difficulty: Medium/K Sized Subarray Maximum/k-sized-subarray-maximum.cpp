class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            pq.push({arr[i], i}); // push value and index

            // window starts at i >= k-1
            if (i >= k - 1) {

                // remove elements not in the window
                while (!pq.empty() && pq.top().second <= i - k)
                    pq.pop();

                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};