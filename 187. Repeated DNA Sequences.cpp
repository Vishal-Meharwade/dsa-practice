class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string, int> mpp;
        vector<string> res;

        for(int i=0; i+10 <= s.size(); i++) {
            mpp[s.substr(i, 10)]+=1;
        }

        for(auto& [key, value] : mpp) {
            if(value > 1) res.push_back(key);
        }

        return res;
    }
};
