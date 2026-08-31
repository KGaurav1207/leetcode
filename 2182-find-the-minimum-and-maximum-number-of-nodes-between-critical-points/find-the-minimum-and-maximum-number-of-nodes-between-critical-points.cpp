/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans = {-1,-1};
        int prev = head->val, f = -1;
        head = head->next;
        int cnt = 1, p = 0, mx = INT_MIN, mn = INT_MAX;

        while(head->next){
            cnt++;
            int next = head->next->val;
            int curr = head->val;
            if(prev<curr && next<curr || prev>curr && next>curr){
                if(f == -1){
                    f = cnt;
                    p = cnt;
                }
                else{
                    mx = cnt - f;
                    mn = min(mn,cnt-p);
                    p = cnt;
                }
            }
            prev = head->val;
            head = head->next;
        }

        if(mx != INT_MIN){
            ans[0] = mn;
            ans[1] = mx;
        }

        return ans;
    }
};