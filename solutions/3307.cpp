// 3307. Find the K-th Character in String Game II
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        while (operations.size()>=64)
            operations.pop_back();
        if (k==1)
            return 'a';
        long long sz=1ll<<(operations.size()-1);
        int op=operations.back();
        operations.pop_back();
        if (k<=sz)
            return kthCharacter(k, operations);
        else
            return (op+kthCharacter(k-sz, operations)-'a')%26+'a';
    }
};