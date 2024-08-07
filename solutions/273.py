# 273. Integer to English Words
class Solution:
    def numberToWords(self, num: int) -> str:
        if num==0:
            return "Zero"
        ones = { 0: "", 1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five", 6: "Six", 7: "Seven", 8: "Eight", 9: "Nine", 10: "Ten", 11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen", 15: "Fifteen", 16: "Sixteen", 17: "Seventeen", 18: "Eighteen", 19: "Nineteen" }
        tens = { 20: "Twenty", 30: "Thirty", 40: "Forty", 50: "Fifty", 60: "Sixty", 70: "Seventy", 80: "Eighty", 90: "Ninety"}
        def helper(num):
            if num>=1000000000:
                return helper(num//1000000000)+" Billion "+helper(num%1000000000)
            if num>=1000000:
                return helper(num//1000000)+" Million "+helper(num%1000000)
            if num>=1000:
                return helper(num//1000)+" Thousand "+helper(num%1000)
            if num>=100:
                return helper(num//100)+" Hundred "+helper(num%100)
            if num>=20:
                return tens[(num//10)*10]+" "+helper(num%10)
            return ones[num]
        return helper(num).replace("  ", " ").strip()