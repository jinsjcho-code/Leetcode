class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;   // overflow 방지

            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;  // 오른쪽 절반 탐색
            else right = mid - 1;                          // 왼쪽 절반 탐색
        }

        return -1;  // 못 찾음
    }
};
