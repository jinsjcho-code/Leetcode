class Solution {
public:
    int search(vector<int>& nums, int target) {

    // Understand: need to return the index of target. otherwise, return -1
    // Pattern: It has been rotated.
    // Idea: need to use Binary Search. Because if we use the sort then it would be O(nlogN)
    // first of all, i need to find sort section. after that find a target.
    // Time: O(logN), Space: O(1)

    /*
    Main algorithm
    if (nums[mid] > nums[left]) : Left side of mid is sorted array. can skip this area.
        left = mid+1;
    else if (nums[mid] < nums[right]) : right side of mid is sorted array. can skip this area.
        right = mid-1;
    else if (nums[mid] < nums[left]) {
        right = mid-1;
    }
    else if (nums[mid] > nums[right]) {
        left = mid+1;
    }
        
    }
    
    
     { right side of mid is not sorted array. we need to find this array.
        
    } 
    */

        int left =0;
        int right = nums.size()-1;

        // array size: 1

        if (nums.size()==1) {
            if (nums[left] == target) return left;
            else return -1;
        }

        while (left <= right ) { // if size of array is more than 2...
            int mid = left + (right - left) /2;
            
            // 1) if find a target
            if (nums[mid] == target) return mid;

            // 2) Check the sorted array
            if (nums[mid] >= nums[left]) { //Left side of mid is sorted array.
                if (target >= nums[left] && target <=nums[mid]) {
                    right = mid-1;
                }
                else {
                    left = mid+1;
                }
            }
            else
                if (target >= nums[mid] && target <=nums[right]) {
                    left = mid+1;
                }   
                else
                    right = mid-1;
        }
       
        return -1;
    }
};