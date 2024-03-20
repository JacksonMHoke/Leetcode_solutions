#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> manacher(string& s) {
    string s1="$"+s+"@";
    int r=0, c=0;
    vector<int> rt(s1.length(), 1);
    for (int i=0; i<s1.length(); ++i) {
        if (i<r)
            rt[i]=min(rt[c-(i-c)], r-i+1);
        while (s1[i+rt[i]]==s1[i-rt[i]])
            rt[i]++;
        if (i+rt[i]>r) {
            r=i+rt[i];
            c=i;
        }
    }
    return rt;
}

int main() {
    string s="CCCCCBABABABABAB";
    vector<int> pal_lengths=manacher(s);
    for (auto len : pal_lengths)
        cout << len << " ";
    cout << endl;
    return 0;
}