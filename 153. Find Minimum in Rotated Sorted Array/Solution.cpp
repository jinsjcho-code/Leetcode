class Solution {
public:
    int findMin(vector<int>& nums) {
        
        // need to find a minimum number in the arrays
        // Sort: O(nlogn)
        // Binary Search: O(logN)
        
        // Idea: compare to neighbor and find it.
        // nums[mid] < nums[mid+1] -> right = mid;
        // nums[mid] > nums[mid+1] -> left = mid+1;

        int left=0;
        int right=nums.size() -1;

        while (left < right) {
            int mid = left + (right - left) / 2; // overflow protect

            if (nums[mid] > nums[right]) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        return nums[left];
    }
};