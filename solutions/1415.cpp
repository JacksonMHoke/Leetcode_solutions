// 1415. The k-th Lexicographical String of All Happy Strings of Length n
class Solution {
    public:
        // finds non-repeating character that is nth from 'a'
        void append(string& curr, int nth) {
            char last=(!curr.empty())? curr.back(): 'd';
            for (int i='a'; i<='c'; ++i) {
                if (last==i)
                    continue;
                if (nth==0)
                    curr+=i;
                nth--;
            }
        }
    
        void recursion(vector<int>& numStrings, string& curr, int i, int k) {
            if (k>numStrings[i]) {
                curr="";
                return;
            }
            if (i>=numStrings.size()-1 && k<3)
                return;
            if (k<=numStrings[i+1]) {
                append(curr, 0);
                recursion(numStrings, curr, i+1, k);
            } else if (k<=numStrings[i+1]*2) {
                append(curr, 1);
                recursion(numStrings, curr, i+1, k-numStrings[i+1]);
            } else {
                append(curr, 2);
                recursion(numStrings, curr, i+1, k-2*numStrings[i+1]);
            }
        }
    
        string getHappyString(int n, int k) {
            vector<int> numStrings(n+1, 1);
            for (int i=n-1; i>=0; --i)
                numStrings[i]=numStrings[i+1]*2;
            numStrings[0]=numStrings[1]*3;
            string curr="";
            recursion(numStrings, curr, 0, k);
            return curr;
        }
    };