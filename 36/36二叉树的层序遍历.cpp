#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

const int MAXN = 2001;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* queue[MAXN];
int l, r;

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root != nullptr) {
			l = r = 0;
			::queue[r++] = root;
			while (l < r) {
				int size = r - l;
				vector<int> list;
				for (int i = 0; i < size; i++) {
					TreeNode* cur = ::queue[l++];
					list.push_back(cur->val);
					if (cur->left != nullptr) {
						::queue[r++] = cur->left;
					}
					if (cur->right != nullptr) {
						::queue[r++] = cur->right;
					}

				}
				ans.push_back(list);
			}
		}
		return ans;
	}
};
int main() {
	return 0;
}