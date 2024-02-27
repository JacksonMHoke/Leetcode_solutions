# Least Number of Unique Integers after K Removals

class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        least_common = Counter(arr).most_common()[::-1]
        num_reduced=0
        for num, freq in least_common:
            if k<freq:
                break
            k-=freq
            num_reduced+=1
        return len(least_common)-num_reduced