/*
Problem: Trapping Rain Water

My Approach:
- Initially thought for each index check left & right max → O(n^2).
- Then optimized using precomputed arrays / two pointers.

Optimized Idea:
- Water depends on min(leftMax, rightMax).
- Use two pointers to avoid extra space.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {

        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while(l < r) {

            if(height[l] < height[r]) {

                if(height[l] >= leftMax)
                    leftMax = height[l];
                else
                    water += leftMax - height[l];

                l++;
            }
            else {

                if(height[r] >= rightMax)
                    rightMax = height[r];
                else
                    water += rightMax - height[r];

                r--;
            }
        }

        return water;
    }
};