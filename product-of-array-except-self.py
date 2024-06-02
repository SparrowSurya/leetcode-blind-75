from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        products: List[int] = []
        product = 1

        # prefix product
        for num in nums:
            products.append(product)
            product *= num

        # suffix product
        product = 1
        for i in range(len(nums) - 1, -1, -1):
            products[i] = products[i] * product
            product *= nums[i]

        return products
