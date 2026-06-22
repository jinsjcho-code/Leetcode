class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            
            // 1) setup the hash table
            unordered_map<int, int> counter;
            
            // 2) counter
            for (int i=0 ; i < nums.size() ; i++) {
                counter[nums[i]] = counter[nums[i]] + 1;
    
                if (counter[nums[i]] > 1) {
                    return true;
                }
            }
            // 3) check + break
            return false;
        }
    };