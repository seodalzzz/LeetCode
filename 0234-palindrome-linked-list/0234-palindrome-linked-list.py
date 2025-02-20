# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def is_palind(self, s):
        return s==s[::-1]
    def isPalindrome(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: bool
        """
        curr=head
        lst=""
        while(curr!=None):
            lst=lst+str(curr.val)
            curr=curr.next
        return self.is_palind(lst)