class Solution {
public:
    // 속도 k로 모든 더미를 먹는 데 걸리는 총 시간
    long long hoursNeeded(vector<int>& piles, int k) {
        long long total = 0;
        for (int p : piles) {
            total += (p + k - 1) / k;   // ceil(p / k)
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // 답(속도 k)의 범위를 이진탐색: "h시간 이하로 먹을 수 있는 가장 작은 k"
        // Time: O(n log(maxPile)), Space: O(1)

        int lo = 1;
        int hi = 1;
        for (int p : piles) hi = max(hi, p);   // 최대 더미 = 가장 빠른 속도

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (hoursNeeded(piles, mid) <= h) {
                hi = mid;          // 충분히 빠름 → mid도 후보, 안 버림
            }
            else {
                lo = mid + 1;      // 너무 느림 → 더 빠르게
            }
        }

        return lo;   // lo == hi == 정답
    }
};
