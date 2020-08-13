//
//  main.cpp
//  1.两数之和
//
//  Created by Pinna on 2020/8/14.
//  Copyright © 2020 Pinna. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 1.排序双指针 nLog(n)
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> tmp;
        vector<int> res;
        tmp = nums;
        sort(tmp.begin(), tmp.end());
        int n = tmp.size() - 1;
        int i = 0;
        while(i < n){
            while(tmp[i] + tmp[n] < target) {
                i++;
            }
            while(tmp[i] + tmp[n] > target) {
                n--;
            }
            if(tmp[i] + tmp[n] == target){
                break;
            }
        }
        for (int k = 0; k < tmp.size(); ++k) {
            if (i < n && tmp[i] == nums[k]) {
                res.push_back(k);
                i = n;
            } else if (tmp[n] == nums[k]) {
                res.push_back(k);
            }
        }
        return res;
    }
    
    // 2.hash 表 O(n)
    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (map[target - nums[i]] && map[target - nums[i]] != i) {
                ret.push_back(i);
                ret.push_back(map[target - nums[i]]);
                break;
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> num1 = {3, 3};
    vector<int> num2 = {1, 5, 2, 6, 7};
    vector<int> tmp1 = s.twoSum1(num1, 6);
    vector<int> tmp2 = s.twoSum1(num2, 9);
    for (int i = 0; i < tmp2.size(); ++i) {
        cout << tmp2[i] << endl;
    }
    return 0;
}

