#include <iostream> 
#include <vector>

using namespace std;

int trap(vector<int>& height){
	int ans = 0;
	int l = height.size();
	vector<int> pre_max(l);
	pre_max[0] = height[0];
	for (int i = 1; i < l; i++) {
		pre_max[i] = max(pre_max[i -1], height[i]);
	}
	vector<int> suf_max(l);
	suf_max[l - 1] = height[l - 1];
	for (int i = l - 2; i >= 0; i--) {
		suf_max[i] = max(suf_max[i + 1], height[i]);
	}
	for (int i = 0; i < l; i++) {
		ans += min(pre_max[i], suf_max[i]) - height[i];
	}
	return ans;
}

int main() {
	vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = trap(nums);
	cout << ans << endl;
	return 0;
}

