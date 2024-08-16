class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dictt={}
        for i in range(len(nums)):
            if((nums[i]) in dictt.keys()):
                return [i,dictt[nums[i]]]
            dictt[target-nums[i]]=i
            
    


        