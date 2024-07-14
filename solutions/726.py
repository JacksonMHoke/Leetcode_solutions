# 726. Number of Atoms
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        split=re.findall('([A-Z][a-z]*|[0-9]+|[(]|[)])', formula)
        stack=[]
        counter=Counter()
        n=len(split)
        tot_mult=1
        for i in range(n-1, -1, -1):
            if 'A'<=split[i][0]<='Z':
                counter[split[i]]+=(int(split[i+1]) if i+1<n and split[i+1].isdigit() else 1)*tot_mult
            elif split[i][0]==')':
                mult=int(split[i+1]) if i+1<n and split[i+1].isdigit() else 1
                stack.append(mult)
                tot_mult*=mult
            elif split[i][0]=='(':
                tot_mult//=stack[-1]
                stack.pop()
                
        return ''.join([key+(str(counter[key] if counter[key]>1 else '')) for key in sorted(counter.keys())])