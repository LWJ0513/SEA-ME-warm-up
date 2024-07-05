#include <string>
#include <iostream>

typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 } ListNode;

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



// for test ----------------------------


ListNode* makeNodeList(std::string num){

    ListNode* start = nullptr;
    ListNode* last;

    for (int i=0; i < num.length() ; i++){

        ListNode* newNode = new ListNode(num[i] - '0');

        if (start == nullptr )
            start = newNode;
        else
            last->next = newNode;
        last = newNode;
    }
    return start;
}

void printList(ListNode * list){

    ListNode* tmp;
    tmp = list;

    while (tmp != nullptr){
        std::cout << tmp->val << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

void deleteList(ListNode *list) {

    ListNode* current;
    ListNode* next;

    current = list;
    while (current != nullptr) {

        next = current->next;
        delete current;
        current = next;
    }
}


int main(int argc, char *argv[])
{

    Solution s;

    ListNode *l1 = makeNodeList("9999999");
    ListNode *l2 = makeNodeList("9999");

    // print input
    std::cout << "[Input]" << std::endl;
    std::cout << "l1 = " ;
    printList(l1);
    std::cout << "l2 = " ;
    printList(l2);
    std::cout << std::endl;


    ListNode* result = s.addTwoNumbers(l1, l2);

    printList(result);


    // delete List
    deleteList(l1);
    deleteList(l2);
    deleteList(result);

}
