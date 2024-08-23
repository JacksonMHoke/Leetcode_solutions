# 592. Fraction Addition and Subtraction
class Solution:
    def fractionAddition(self, expression: str) -> str:
        def gcd(a, b):
            if a<b:
                a, b = b, a
            while b:
                a, b = b, a%b
            return a
        # turn expression into list of fractions in list format
        expression=expression.replace('+', ' +').replace('-', ' -').split(' ')
        if expression[0]=='':
            expression=expression[1:]
        expression=[frac.split('/') for frac in expression]

        # find common denominator
        denom=1
        for frac in expression:
            denom*=int(frac[1])
        
        # sum numerators scaled with denom
        numerator=0
        for frac in expression:
            numerator+=int(frac[0])*denom//int(frac[1])

        # simplify
        gcd=gcd(numerator, denom)
        return str(numerator//abs(gcd))+'/'+str(denom//abs(gcd))