class Solution {
public:
    priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
    > pq;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        if(nums1.empty() || nums2.empty() || k == 0)
            return {};

        for(int i = 0; i < nums1.size(); i++){
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        vector<vector<int>> ans;

        while(ans.size() < k && !pq.empty()) {

            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            if(j + 1 < nums2.size()){
                pq.push({
                    nums1[i] + nums2[j+1],
                    i,
                    j+1
                });
            }
        }

        return ans;
    }
};