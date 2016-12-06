class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        self.nums1 = nums1
        self.nums2 = nums2
        len1 = len(nums1)
        len2 = len(nums2)

        if (len1 + len2) % 2 == 0:
            # there is even number of numbers
            rst1 = self.getMid(0, len1, 0, len2, (len1 + len2) // 2)
            rst2 = self.getMid(0, len1, 0, len2, (len1 + len2) // 2 + 1)
            return (rst1 + rst2) / 2.0
        else:
            # there is odd number of numbers
            return self.getMid(0, len1, 0, len2, (len1 + len2) // 2 + 1)

    def getMid(self, start1, end1, start2, end2, aim):
        """
        :type start1: int
        :type end1: int
        :type start2: int
        :type end2: int
        :type aim: int
        :rtype: int
        """
        # either of the list is encounter the end
        if start1 >= end1:
            return self.nums2[aim - start1 - 1]
        if start2 >= end2:
            return self.nums1[aim - start2 - 1]

        mid1 = (start1 + end1) // 2
        mid2 = (start2 + end2) // 2
        # reduce either of the list and expand the other list
        if mid1 + mid2 + 2 < aim:
            if self.nums1[mid1] < self.nums2[mid2]:
                tmp = max(start2, mid2 - mid1 - 1)
                return self.getMid(mid1 + 1, end1, tmp, end2, aim)
            else:
                tmp = max(start1, mid1 - mid2 - 1)
                return self.getMid(tmp, end1, mid2 + 1, end2, aim)
        elif mid1 + mid2 + 2 > aim:
            if self.nums1[mid1] < self.nums2[mid2]:
                tmp = min(mid1 + 1 + end2 - mid2, end1)
                return self.getMid(start1, tmp, start2, mid2, aim)
            else:
                tmp = min(mid2 + 1 + end1 - mid1, end2)
                return self.getMid(start1, mid1, start2, tmp, aim)
        else:
            if self.nums1[mid1] > self.nums2[mid2]:
                return self.getMid(start1, mid1 + 1, mid2 + 1, end2, aim)
            elif self.nums1[mid1] < self.nums2[mid2]:
                return self.getMid(mid1 + 1, end1, start2, mid2 + 1, aim)
            else:
                return self.nums1[mid1]

if __name__ == '__main__':
    so = Solution()
    test1 = [1, 3]
    test2 = [2, 4]
    rst = so.findMedianSortedArrays(test1, test2)
    print("rst: " + str(rst))
