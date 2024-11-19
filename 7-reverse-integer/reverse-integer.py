class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """

        temp = str(x)
        if(x>=0):
            answer = int(temp[::-1])
            return answer if answer>=0 and answer<=2**31-1 else 0
        else:
            answer = -1*int(temp[:0:-1])
            return answer if answer<0 and answer>=-2**31 else 0