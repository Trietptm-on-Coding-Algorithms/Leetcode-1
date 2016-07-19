/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (nullptr == head)
            return nullptr;

        ListNode* odd = nullptr, * evenRoot = nullptr, * evenCur = nullptr;
        ListNode* cur = head;

        for (int i = 1; nullptr != cur; ++i, cur = cur->next) {
            if (i & 1 == 1) {
                if (nullptr == odd) {
                    odd = cur;
                } else {
                    odd->next = cur;
                    odd = odd->next;
                }
            } else {
                if (nullptr == evenRoot) {
                    evenRoot = cur;
                    evenCur = evenRoot;
                } else {
                    evenCur->next = cur;
                    evenCur = evenCur->next;
                }
            }
        }

        if (nullptr != evenCur)
            evenCur->next = nullptr;

        odd->next = evenRoot;

        return head;
    }
};
