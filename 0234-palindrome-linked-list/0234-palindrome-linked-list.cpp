
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;

        while (head != NULL) {
            arr.push_back(head->val);
            head = head->next;
        }

        int i = 0;
        int j = arr.size() - 1;

        while (i < j) {
            if (arr[i] != arr[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
