// 1352. Product of the Last K Numbers
class ProductOfNumbers {
    public:
        vector<int> pre;
        vector<int> zeros;
        ProductOfNumbers() {
            pre.push_back(1);
            zeros.push_back(0);
        }
        
        void add(int num) {
            if (pre.back()==0)
                pre.push_back(num);
            else
                pre.push_back(pre.back()*num);
            zeros.push_back(zeros.back()+(num==0));
        }
        
        int getProduct(int k) {
            if (zeros.back()>zeros[zeros.size()-k-1])
                return 0;
            return pre.back()/((pre[pre.size()-k-1]!=0)? pre[pre.size()-k-1]: 1);
        }
    };