class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // need to find peak
        // pattern: it has some portion of direction. it's not sorted array.
        // Idea: Binarty Search + find a direciton
        // O(logN), O(1):

        int left=0;
        int right=nums.size()-1;

        while (left < right) {
            int mid = left + (right - left) /2 ;

            if (nums[mid] < nums[mid+1]) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};