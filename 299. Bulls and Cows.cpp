class Solution {
public:
    string getHint(string secret, string guess) {

        int bulls = 0, cows = 0;

        vector<int> nums(10, 0);

        for(int i=0; i<secret.size(); i++) {

            int s = secret[i] - '0';
            int g = guess[i] - '0';

            if(s == g) {
                bulls++;
            }
            
            else {
                if(nums[s] < 0) cows++;
                if(nums[g] > 0) cows++;

                nums[s]++;
                nums[g]--;
            }
        }  

        // return bulls+"A" + cows+"B";
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
