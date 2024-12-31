class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bool isValid = true;
                int prev = 0;

                for (int k = 0; k < i; k++) {
                    if (k > 0 && nums[k] <= nums[k - 1]) {
                        isValid = false;
                        break;
                    }
                    prev = nums[k];
                }

                if (isValid && i > 0 && j < n - 1 && nums[j +1] <= prev) {
                    isValid = false;
                }

                if (isValid) {
                    for (int k = j + 1; k < n; k++) {
                        if (k > j + 1 && nums[k] <= nums[k - 1]) {
                            isValid = false;
                            break;
                        }
                    }
                }
                if (isValid)
                    count += 1;
            }
        }
        return count;
        
    }
};
