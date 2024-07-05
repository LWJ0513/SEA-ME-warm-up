# SEA-ME

## [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/)


You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
<br>
<br>

### Example 1:
![ex01](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)
```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```
<br>

### Example 2:
```
Input: l1 = [0], l2 = [0]
Output: [0]
```
<br>

### Example 3:
```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

<br>

## Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

<br>

---

# Solution Code
```

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        bool ten = false;
        ListNode* result = nullptr, *current;


        while (l1 != nullptr || l2 != nullptr) {

            int n1 = (l1 == nullptr) ? 0 : l1->val;
            int n2 = (l2 == nullptr) ? 0 : l2->val;

            int sum = n1 + n2;
            if (ten && (l1 != nullptr || l2 != nullptr)){
                ++sum;
                ten = false;
            }
            int num = sum >= 10 ? sum - 10 : sum;
            ten = sum >= 10;

            if (result == nullptr) {
                result = new ListNode(num);
                current = result;
            } else {
                current->next = new ListNode(num);
                current = current->next;
            }

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        if (ten)
            current->next = new ListNode(1);

        return result;
    }
};

```