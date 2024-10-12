// Leetcode 33 search in rotated sorted array

#include<iostream>
#include<bits/stdc++.h>



class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0;
        int n = nums.size();

        int end = n-1;

        

        while(start <= end){

            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[start] <= nums[mid]){

                if(target < nums[mid] && target >= nums[start]){

                    end  = mid -1;
                }
                else{

                    start = mid + 1;
                }
            }
            else if(nums[mid] <= nums[end]){

                if(target > nums[mid] && target <= nums[end]){

                    start = mid + 1;
                }
                else end = mid -1;


            }
            
        }

        return -1;

    }
};