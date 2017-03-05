# 算法描述
# 在一个点进行分割时，他是三种分割点，即：第一个，第二个，第三个，那么，如果已知其是第几个分割点时，可以由他求出下一个割点i之前的和，即:sum(0...< i)，这样累加到最后一个数时，就可以知道他是不是可分为四块的了
# 比如求[2, 5, 1, 1, 1, 1, 4, 3, 7, 5, 7]，在位置2时，如果我们计算其为第一个分割点，那么下一个分割点之前的和应该是：2 + 5 + 1 + 7，那么在位置7时，我们就以知道其为第二个分割点，计算下一个点为：7 * 3 + 1 + 3 = 25，也就是位置9，在位置9时，可以同样算，7 * 4 + 1 + 3 + 5 = 37，那么就知道最好是分割点了。。
class Solution(object):
    def segment(self, nums):
        if len(nums) < 7:
            return None
        # 记录相关值: record为一个字典，记录了以其为分割点相关的信息，每个
        # 点记录三个值，分别对应其这第一分割点、第二分割点、第三分割点的相关信
        # 息，分别是：[是否为分割点，每段的值，前面的分割点的和值]
        record = dict()
        cum = 0
        for k in range(len(nums)):
            if k != 0:
                # 做为第一分割点，计算下一个分割点
                part1 = cum * 2 + nums[k]
                if part1 not in record:
                    record[part1] = [[0 for j in range(3)] for i in range(3)]
                record[part1][0] = [1, cum, nums[k]]
                
                if cum in record:
                    # 做为第二分割点，计算第三分割点
                    if record[cum][0][0] != 0:
                        part2 = record[cum][0][1] * 3 + nums[k] + record[cum][0][2]
                        if part2 not in record:
                            record[part2] = [[0 for j in range(3)] for i in range(3)]
                        record[part2][1] = [1, record[cum][0][1], record[cum][0][2] + nums[k]]
                    # 做为第三分割点，计算最后的和值，也可以当作第四分割点
                    if record[cum][1][0] != 0:
                        part3 = record[cum][1][1] * 4 + nums[k] + record[cum][1][2]
                        if part3 not in record:
                            record[part3] = [[0 for j in range(2)] for i in range(3)]
                        record[part3][2] = [1, record[cum][1][1], record[cum][1][2] + nums[k]]
            cum += nums[k]

        # 最后的和值是不是第四分割点，如果是，则可分，否则不可分
        if cum not in record or record[cum][2][0] == 0:
            return None
        rst = []
        sub = []
        acc = 0
        i = 0
        # 计算每个子串
        while i < len(nums):
            if i == 0 or acc != record[cum][2][1]:
                acc += nums[i]
                sub.append(nums[i])
            elif acc == record[cum][2][1]:
                rst.append(sub[:])
                sub = []
                acc = 0
            i += 1
        return rst
                        
if __name__ == '__main__':
    so = Solution()
    nums = [2, 5, 1, 1, 1, 1, 4, 3, 7, 5, 7]
    re = so.segment(nums)
    print(re)

