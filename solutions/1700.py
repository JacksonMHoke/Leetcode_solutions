# 1700. Number of Students Unable to Eat Lunch
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        counts=Counter(students)
        n=len(students)
        k=0
        while n>k and counts[sandwiches[k]]>0:
            counts[sandwiches[k]]-=1
            k+=1
        return n-k