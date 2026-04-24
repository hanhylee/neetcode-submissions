/**

product_stack = {1, }

num = 1
pre_product = 1 DEFAULT
curr_product = 1 * 1
post_product = ?

num = 2
pre-product = 1
curr_product = 
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix_products(len+1, 1);
        vector<int> suffix_products(len+1, 1);

        for (int i=0; i<len; i++) {
            int curr_product = nums[i] * prefix_products[i];
            prefix_products[i+1] = curr_product;
        }

        // for (int i=0; i<len+1; i++) {
        //     cout << prefix_products[i] << " ";
        // }
        // cout << endl;

        for (int i=(int)nums.size(); i>0; i--) {
            int curr_product = nums[i-1] * suffix_products[i];
            suffix_products[i-1] = curr_product;
        }

        // for (int i=0; i<len+1; i++) {
        //     cout << suffix_products[i] << " ";
        // }
        // cout << endl;

        vector<int> output(len, 1);
        for (int i=0; i<len; i++) {
            output[i] = prefix_products[i] * suffix_products[i+1];
        }

        return output;
    }
};
