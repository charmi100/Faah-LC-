class Solution {
public:
        priority_queue<int>pq;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        for(vector<int> row : matrix){
            for(int num : row){
                pq.push(num);
                if(pq.size() > k){
                pq.pop();
            }
            }
        }
        return pq.top();
    }

};