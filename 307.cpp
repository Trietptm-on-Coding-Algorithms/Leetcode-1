class NumArray {
public:
    NumArray(vector<int> &nums) {
        int size = nums.size();
        bucketNum = (int)sqrt(2*size);
        bucketSize = bucketNum / 2;
        while(bucketSize * bucketNum < size)
            ++bucketSize;

        buckets.resize(bucketNum);
        for(int i=0, k=0; i < bucketNum; ++i) {
            int temp = 0;
            buckets[i].val.resize(bucketSize);
            for(int j = 0; j < bucketSize && k<size; ++j, ++k) {
                temp += nums[k];
                buckets[i].val[j] = nums[k];
            }
            buckets[i].sum = temp;
        }
    }

    void update(int i, int val) {
        int x = i / bucketSize;
        int y = i % bucketSize;
        buckets[x].sum += (val - buckets[x].val[y]);
        buckets[x].val[y] = val;
    }

    int sumRange(int i, int j) {
        int x1 = i / bucketSize;
        int y1 = i % bucketSize;
        int x2 = j / bucketSize;
        int y2 = j % bucketSize;
        int sum = 0;

        if(x1==x2) {
            for(int a = y1; a <= y2; ++a) {
                sum += buckets[x1].val[a];
            }
            return sum;
        }

        for(int a = y1; a < bucketSize; ++a) {
            sum += buckets[x1].val[a];
        }

        for(int a=x1+1; a<x2; ++a) {
            sum += buckets[a].sum;
        }

        for(int b=0; b<=y2; ++b) {
            sum += buckets[x2].val[b];
        }
        return sum;
    }

private:
    typedef struct {
        int sum;
        vector<int> val;
    } bucket;

    int bucketNum;
    int bucketSize;
    vector<bucket> buckets;
};
