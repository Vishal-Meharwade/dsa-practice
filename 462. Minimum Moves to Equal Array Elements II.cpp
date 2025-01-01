class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        // O(n) time complexity, O(1) space 
        // sort(nums.begin(), nums.end());

        // int mid = 0 + (nums.size() - 0) / 2;
        // int operations = 0;
        // int midEle = nums[mid];
        
        // for(int i=0; i<nums.size(); i++) {
        //     int diff = abs(midEle - nums[i]);
        //     operations += diff;
        // }
        // return operations;

        //Optimal Approach using 2 pointers :
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = nums.size()-1;

        int count = 0;

        while(s <= e) {
            int diff = abs(nums[s] - nums[e]);
            count += diff;
            s++;
            e--;
        }

        return count;
    }
};
