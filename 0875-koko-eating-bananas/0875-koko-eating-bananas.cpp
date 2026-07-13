class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1; 
    int right = piles[0];
    for (int i=1;i<piles.size();i++) {
        if (piles[i] > right) {
            right = piles[i];
        }
    }
    int answer = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long totalhours = 0;
        for (int i=0;i<piles.size();i++) {
            totalhours += (piles[i] + mid - 1) / mid;
        }
        if (totalhours <= h) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}
};