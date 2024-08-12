class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.klargest = sorted(nums)[-k:]
        heapify(self.klargest)
        self.k = k

    def add(self, val: int) -> int:
        if self.klargest and len(self.klargest)==self.k:
            if self.klargest[0]>=val:
                return self.klargest[0]
            heappop(self.klargest)
        heappush(self.klargest, val)
        return self.klargest[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)