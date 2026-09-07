class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int stone : stones){
        pq.push(stone);
        }
        while( pq.size() >= 2){
            int largest = pq.top();
            pq.pop();

            int secondLargest = pq.top();
            pq.pop();

            if(largest == secondLargest){
            }
            else{
                pq.push(largest - secondLargest);
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};