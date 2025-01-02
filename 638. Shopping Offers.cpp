class Solution {
public:
    map<vector<int>, int> mp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        if(mp.count(needs) != 0) {
            return mp[needs];   
        }

        int ans = 0;
        for(int i=0; i<needs.size(); i++) {
            ans += needs[i] * price[i];
        }

        for(int i=0; i<special.size(); i++) {
            bool isValid = true;
            for(int j=0; j<needs.size(); j++) {
                if(needs[j] < special[i][j]) {
                    isValid = false;
                    break;
                }
            }

            if(isValid) {
                for(int j=0; j<needs.size(); j++) {
                    needs[j] -=special[i][j];
                }

                int ans2 = special[i].back() + shoppingOffers(price, special, needs);
                ans = min(ans, ans2);

                for(int j=0; j<needs.size(); j++) {
                    needs[j] += special[i][j];
                }
            }
        }

        return mp[needs] = ans;

    }
};
