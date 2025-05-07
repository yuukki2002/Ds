/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

假设数组非空，并且一定存在满足条件的数字。

思考题：

假设要求只能使用 O(n)
 的时间和额外 O(1)
 的空间，该怎么做呢？
数据范围
数组长度 [1,1000]
。

样例
输入：[1,2,1,1,3]

输出：1
*/
#include <vector>
#include <iostream>
using namespace std;
/*
 * 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 思路：使用摩尔投票法，时间复杂度O(n)，空间复杂度O(1)
 */

class Solution {
    public:
        int moreThanHalfNum_Solution(vector<int>& nums) {
            int res=nums[0], count=1;
            for(int i=1;i<nums.size();i++){
                if(nums[i]!=res)
                    count--;
                else count++;
                if(count==0){
                    res=nums[i];
                    count++;
                }
            }
            return res;
        }
    };