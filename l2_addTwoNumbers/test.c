#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool is_finsh(struct ListNode** c_l1, struct ListNode** c_l2){
    if((*c_l1)->next == NULL && (*c_l2)->next == NULL){
        return true;
    }else if((*c_l1)->next != NULL && (*c_l2)->next == NULL){
        (*c_l1) = (*c_l1)->next;
        (*c_l2)->val = 0;
        (*c_l2)->next = NULL;
        return false;
    }else if((*c_l1)->next == NULL && (*c_l2)->next != NULL){
        (*c_l2) = (*c_l2)->next;
        (*c_l1)->val = 0;
        (*c_l1)->next = NULL;
         return false;
    }else{
        (*c_l1) = (*c_l1)->next;
        (*c_l2) = (*c_l2)->next;
         return false;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int cin=0;
    struct ListNode* c_l1 = l1;
    struct ListNode* c_l2 = l2;
    struct ListNode* header = NULL;
    struct ListNode* temp;

    // calc first
    header = (struct ListNode*)malloc(sizeof(struct ListNode));
    header->val = (c_l1->val + c_l2->val);
    if (header->val > 9){
        header->val -= 10;
        cin=1;
    }
    if(is_finsh(&c_l1, &c_l2)){
        if(cin==0){
            header->next = NULL;
        }else{
            header->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            header->next->val = 1;
            header->next->next = NULL;
        }
        return header;
    }

    temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    header->next = temp;

    while(1){

        temp->val = cin + c_l1->val + c_l2->val;
        if(temp->val > 9){
            temp->val -=10;
            cin=1;
        }else{
            cin=0;
        }
        if (is_finsh(&c_l1, &c_l2)){
            if(cin==0){
                temp->next = NULL;
            }else{
                temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                temp->next->val = 1;
                temp->next->next = NULL;
            }
            return header;
        }
        temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next->next = NULL;
        temp = temp->next;

    }
    return header;
}

int main(int argc, char *argv[])
{
    struct ListNode l1, l2, l3;
    l1.val = 5;
    l1.next = &l3;
    l2.val = 6;
    l2.next = NULL;
    l3.val = 1;
    l3.next = NULL;
    addTwoNumbers(&l1, &l2);
    return 0;
}
