# 2491. Divide Players Into Teams of Equal Skill
class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        teamSkill=sum(skill)//(len(skill)//2)
        c=Counter(skill)
        
        rt=0
        for sk, freq in c.items():
            if c[sk]!=c[teamSkill-sk]:
                return -1
            rt+=c[sk]*sk*(teamSkill-sk)
        return rt//2