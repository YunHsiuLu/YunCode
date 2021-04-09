class Solution:
    def twosum(self, nums, target):
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if target - nums[i] == nums[j]:
                    return i, j
        print('there is no solution!\n')
        return 0


a = Solution()
print(a.twosum([2, 7, 9, 12], 21))
