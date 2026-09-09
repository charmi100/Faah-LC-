class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        int currentMax = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        int bestLeft = 0;
        int bestRight = INT_MAX;

        while(pq.size() == nums.size()) {

            auto [value, listIndex, elementIndex] = pq.top();
            pq.pop();

            if(currentMax - value < bestRight - bestLeft){
                bestLeft = value;
                bestRight = currentMax;
            }

            if(elementIndex + 1 < nums[listIndex].size()){

                pq.push({
                    nums[listIndex][elementIndex + 1],
                    listIndex,
                    elementIndex + 1
                });

                currentMax = max(
                    currentMax,
                    nums[listIndex][elementIndex + 1]
                );
            }
        }

        return {bestLeft, bestRight};
    }
};