# 2161. Partition Array According to Given Pivot

def pivotArray(nums, pivot):
        lessers, equals, greaters = [], [], []
        for x in nums:
            if x < pivot:
                lessers.append(x)
            elif x == pivot:
                equals.append(x)
            else:
                greaters.append(x)
        return print(lessers + equals + greaters)

pivotArray([9,12,5,10,14,3,10], 10) # Expected output: [9, 5, 3, 10, 10, 12, 14]
pivotArray([-3,4,3,2], 2) # Expected output: [-3, 2, 4, 3]