// 这个是高赞答案，让我学到了partial_sum，以及冒号后跟的初始化变量列表才是真正意义上的初始化。构造函数里面的操作，实际上是已经先创建好了，然后再赋值。所以如果冒号后面没有显式初始化的话，就相当于调用了默认的缺省构造函数。
class NumArray {
public:
    vector<int> partialSum;
    NumArray(vector<int>& nums): partialSum(nums.size()+1, 0) {
        partial_sum(nums.begin(), nums.end(), partialSum.begin()+1);	// 默认尾插法
    }
    
    int sumRange(int i, int j) {
        return partialSum[j+1]-partialSum[i];
    }
};

// 在不知道具体初始化之前，我去了解了partial_sum之后写的方法。弊端就是有可能引起扩容效率降低。
class NumArray {
public:
    vector<int> partialSum;
    NumArray(vector<int>& nums) {
        partialSum.push_back(0);
        partial_sum(nums.begin(), nums.end(), back_inserter(partialSum));
    }
    
    int sumRange(int i, int j) {
        return partialSum[j+1]-partialSum[i];
    }
};


// 在更加没想清楚可以用这种方法求解的时候，我第一反应是记忆化搜索，也就是创建一个map来当备忘录，每次都从里面查，没有的话往里面加，巨慢巨蠢。
class NumArray {
public:
    map<string, int> memo;
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr = nums;
    }
    
    int sumRange(int i, int j) {
        string key = to_string(i)+"_"+to_string(j);
        map<string, int>::iterator iter = memo.begin();
        iter = memo.find(key);
        if (iter != memo.end())
            return iter->second;
        
        int sum = 0;
        for (int index = i; index <= j; ++index) {
            sum += arr[index];
        }
        memo.insert(make_pair(key, sum));
        return sum;
    }
};