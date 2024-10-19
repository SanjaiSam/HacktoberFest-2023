#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int cnt = 0;
        int element = 0; // Initialize to 0 (or any value)
        int n = nums.size();

        if (n == 0) {
            throw invalid_argument("Input array is empty.");
        }

        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                element = nums[i];
            }
            if (nums[i] == element) {
                cnt++;
            } else {
                cnt--;
            }
        }

        // Optionally, verify that the found element is indeed the majority element
        cnt = 0;
        for (int num : nums) {
            if (num == element) {
                cnt++;
            }
        }

        if (cnt > n / 2) {
            return element;
        } else {
            throw invalid_argument("No majority element found.");
        }
    }
};
