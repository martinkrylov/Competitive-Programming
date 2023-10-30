class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pt = (minutesToTest/minutesToDie) + 1;
        int result = 0;
        while(pow(pt,result)<buckets) result++;
        return result;
    }
};