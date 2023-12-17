#include<vector>
#include<queue>
using namespace std;

struct TreeNode1 {
	int val;
	TreeNode1* left;
	TreeNode1* right;
	TreeNode1() : val(0), left(nullptr), right(nullptr) {}
	TreeNode1(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode1(int x, TreeNode1* left, TreeNode1* right) : val(x), left(left), right(right) {}
};

const int MAXN = 2001;
TreeNode1* queue[MAXN];
int l1, r1;

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode1* root) {
		vector<vector<int>> ans;
		if (root != nullptr) {
			l1 = r1 = 0;
			::queue[r1++] = root;
			bool reverse = false;//´ú±í´Ó×óÍùÓÒ
			while (l1 < r1) {
				int size = r1 - l1;
				vector<int> list;
				for (int i = reverse ? r1 - 1 : l1, j = reverse ? -1 : 1, k = 0; k < size; k++, i += j) {
					TreeNode1* cur = ::queue[i];
					list.push_back(cur->val);
				}
				for (int i = 0; i < size; i++) {
					TreeNode1* cur = ::queue[l1++];
					if (cur->left != nullptr) {
						::queue[r1++] = cur->left;
					}
					if (cur->right != nullptr) {
						::queue[r1++] = cur->right;
					}
				}
				ans.push_back(list);
				reverse = !reverse;
			}
		}
		return ans;
	}
};
