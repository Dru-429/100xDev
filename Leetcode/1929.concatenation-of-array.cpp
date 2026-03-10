#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int arr[n*2];

        for (int i =0; i<n; i++){
            arr[i] = nums[i];
            arr[i+n] = nums[i];
        }

        return vector<int>(arr, arr + 2*n);
    }
};
// @lc code=end
