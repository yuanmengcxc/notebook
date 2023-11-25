#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int first, last;
int randomizedSelect(vector<int>& nums, int l, int r, int k);
void partition(vector<int>& nums, int l, int r, int x);
int findKthLargest(vector<int>& nums, int k) {

    return randomizedSelect(nums, 0, nums.size() - 1, nums.size() - k);
}

void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
int randomizedSelect(vector<int>& nums, int l, int r, int k) {

    int ans = 0;
    while (l <= r) {
        int i = rand() % (r - l + 1) + l;
        partition(nums, l, r, nums[i]);
        if (k < first) {
            r = first - 1;
        }
        else if (k > last) {
            l = last + 1;
        }
        else {
            ans = nums[first];
            break;
        }
    }
    return ans;
}
void partition(vector<int>& nums, int l, int r, int x) {
    first = l;
    last = r;
    int i = l;
    while (i <= last) {
        if (nums[i] == x) {
            i++;
        }
        else if (nums[i] < x) {
            swap(nums, i++, first++);
        }
        else {
            swap(nums, i, last--);
        }
    }
}

int main() {
    vector<int> nums = { 1,2,3,4,5,6 };
    cout << findKthLargest(nums, 2) << endl;
    return 0;
}