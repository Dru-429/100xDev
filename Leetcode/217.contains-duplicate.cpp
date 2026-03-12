#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();

        if(len <= 1){
            return false;
        }
        for(int i =0; i < len; i++){
            int count = 1;
            for (int j = i+1; j < len; j++){
                if (nums[i] == nums[j]){
                    count ++;
                }
                if (count >=2){
                    return true;
                    break;
                }
            }
        }

        return false;
    }
};
// @lc code=end

