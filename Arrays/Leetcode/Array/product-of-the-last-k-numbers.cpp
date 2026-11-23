class ProductOfNumbers {
public:
    vector<int> prod;

    ProductOfNumbers() {
        prod.push_back(1);
    }

    void add(int num) {
        if(num == 0) {
            prod.clear();
            prod.push_back(1);
        }
        else {
            prod.push_back(prod.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prod.size();

        if(k >= n)
            return 0;

        return prod.back() / prod[n-k-1];
    }
};