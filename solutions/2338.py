# 2338. Count the Number of Ideal Arrays
class Solution:
    def idealArrays(self, n: int, maxValue: int) -> int:
        MAX_K = 14
        C = [[1] + [0]*MAX_K for i in range(n+MAX_K+1)]

        for i in range(1, n+MAX_K+1):
            for j in range(1, MAX_K+1):
                C[i][j] = C[i-1][j-1] + C[i-1][j];

        primes=set(range(2, maxValue+1))
        for i in range(int(sqrt(maxValue))+1):
            if i in primes:
                for curr in range(i*2, maxValue+1, i):
                    if curr in primes:
                        primes.remove(curr)

        def getPrimeFactorization(n):
            f=defaultdict(int)
            for p in primes:
                if n==1:
                    break
                while n%p==0:
                    n/=p
                    f[p]+=1
            return f
        curr=0
        MOD=int(1e9+7)
        for i in range(1, maxValue+1):
            freqs=getPrimeFactorization(i)
            v=1
            for p, freq in freqs.items():
                v*=C[n+freq-1][freq]
            curr=(curr+v)%MOD
        return curr