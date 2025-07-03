// 3304. Find the K-th Character in String Game I
class Solution {
public:
    char kthCharacter(int k) {
        if (k==1)
            return 'a';
        return (1+kthCharacter(k-(1<<(int)log2(k-1)))-'a')%26+'a';
    }
};