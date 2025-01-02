class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        // int n = nums.size();
        
        // for(int i = 1; i < n; i++) {
        //     if((i % 2 == 1 && nums[i] < nums[i-1]) || (i % 2 == 0 && nums[i] > nums[i-1])) {
        //         swap(nums[i], nums[i-1]);
        //     }
        // }
        // return nums;
        // above not breaking for edge testcase 


        // using priority queue(heap)

        priority_queue<int> maxHeap;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            maxHeap.push(nums[i]);
        }

        for(int i=1; i<n; i+=2) {
            nums[i] = maxHeap.top();
            maxHeap.pop();
        }

        for(int i=0; i<n; i+=2) {
            nums[i] = maxHeap.top();
            maxHeap.pop();
        }
    }
};
