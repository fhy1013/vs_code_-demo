#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tmp_map;
        for(auto i = 0; i < nums.size(); ++i){
            auto tmp = target - nums[i];
            if(tmp_map.end() != tmp_map.find(tmp)){
                return vector<int>{tmp_map[tmp], i};
            }
            if(tmp_map.end() == tmp_map.find(nums[i]))
                tmp_map[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* res = new ListNode(0);
        ListNode* cur = new ListNode(0);
        ListNode* temp_node = new ListNode(0);
        res->next = cur;
        char tem_r = 0;
        while(1)
        {
            
            char temp = (l1->val + l2->val + tem_r);
            cur->next =  new ListNode(temp%10);
            cur = cur->next;
            tem_r = temp/10;
            l1 = l1->next;
            l2 = l2->next;
            if(l1==NULL && l2==NULL && tem_r==0 ) break;
            if(l1 == NULL) l1= temp_node;
            if(l2 == NULL) l2= temp_node;
        }
        return res->next->next;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res;
        ListNode* curr;
        ListNode* null_node = new ListNode(0);
        int carry = 0;
        bool flag = true;

        while(l1 || l2 || carry > 0){
            if(l1 == NULL) l1 = null_node;
            if(l2 == NULL) l2 = null_node;
            int sum = l1->val + l2->val + carry;
            curr = new ListNode(sum%10);
            if(flag){
                res = curr;
                flag = false;
            }
            carry = sum/10;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        return res;
    }
};

int main(){
    std::cout<< "hello..." << std::endl;
    Solution s;
    vector<int> vec{1, 1, 3, 5, 7, 10, 11};
    int target = 6;
    auto ret = s.twoSum(vec, target);
    if(!ret.empty()){
        cout<<ret[0] << ", "<<ret[1]<<endl;
    }

    return 0;
}