class Solution {
public:
    int lower_bound (vector<int>& nums, int target) {
        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) /2;
            if (nums[mid] < target) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }

        return left;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // define the lower bound and upper bound
        // I will use the Binary Search metric.
        // Time: O(logn), Space: O(1)

        // if I don't have any target in array them return -1, -1
        // lower bound function.

        if (!nums.size())
            return {-1, -1};

        int ans1 = lower_bound(nums, target);
        
        cout << "ans1: " << ans1 << endl;

        if (ans1 >= nums.size() ||  nums[ans1]!=target) {
            return {-1, -1};
        }

        int ans2 = lower_bound(nums, target+1)-1;

        cout << "ans2: " << ans2 << endl;
        
        return {ans1, ans2};
    }
};