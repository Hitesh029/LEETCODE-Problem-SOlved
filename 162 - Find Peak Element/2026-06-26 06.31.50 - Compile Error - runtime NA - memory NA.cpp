class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        int n = costs.size();

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        int left = 0;
        int right = n - 1;

        for(int i = 0; i < candidates && left <= right; i++)
        {
            pq.push({costs[left], left});
            left++;
        }

        for(int i = 0; i < candidates && left <= right; i++)
        {
            pq.push({costs[right], right});
            right--;
        }

        long long ans = 0;

        while(k--)
        {
            auto curr = pq.top();
            pq.pop();

            ans += curr.first;

            int idx = curr.second;

            if(left <= right)
            {
                if(idx < left)
                {
                    pq.push({costs[left], left});
                    left++;
                }
                else
                {
                    pq.push({costs[right], right});
                    right--;
                }
            }
        }

        return ans;
    }
};