// 165. Compare Version Numbers
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0, j=0;
        while (i<version1.length() || j<version2.length()) {
            int revision1=0, revision2=0;
            while (i<version1.length() && version1[i]!='.')
                revision1=revision1*10+(version1[i++]-'0');
            while (j<version2.length() && version2[j]!='.')
                revision2=revision2*10+(version2[j++]-'0');
            
            if (revision1>revision2)
                return 1;
            if (revision1<revision2)
                return -1;
            
            i++;
            j++;
        }
        return 0;
    }
};