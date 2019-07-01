// version 1:
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int round = 0;
        int temp = 0;
        while (true) {
            for (int i = 0; i < num_people; ++i) {
                temp = round + i + 1;
                if (temp >= candies) {
                    res[i] += candies;
                    return res;
                } else {
                    res[i] += temp;
                    candies -= temp;
                }
            }
            round += num_people;
        }
    }
};


// version 2:
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int rounds = 0;
        int i = 0;
        while ( candies >= (rounds*num_people*num_people + num_people*(num_people+1)/2) ) {
            for (i = 0; i < num_people; ++i) {
                res[i] += (rounds*num_people + i+1);
            }
            candies -= (rounds*num_people*num_people + num_people*(num_people+1)/2);
            ++rounds;
        }
        i = 0;
        while (candies > 0) {
            res[i] += (rounds*num_people + i + 1) > candies ? candies : (rounds*num_people + i + 1);
            candies -= (rounds*num_people + i + 1);
            ++i;
        }
        return res;
    }
};