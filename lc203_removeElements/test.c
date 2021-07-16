#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* new_head;
    new_head = head;
    struct ListNode* temp=head;
    bool is_head = true;
    while(head != NULL){
        if(head->val == val){
            if(is_head){
                head = head->next;
                // free(temp);
                new_head = head;
                temp = head;
            }else{
                temp->next = head->next;
                head = head->next;
            }
            
            // free(temp);
        }else{
            temp = head;
            head = head->next;
            
            is_head = false;
        }
    }
    return new_head;
}

int main(int argc, char *argv[])
{
    int nodes[] ={ 6,6,6 };
    struct ListNode* head;
    struct ListNode* p;
    p = head;
    for (int i = 0; i < sizeof(nodes)/sizeof(int); ++i) {
        if(i==0){
            head = (struct ListNode*)malloc(sizeof(struct ListNode));
            head->val = nodes[i];
            head->next = NULL;
            p = head;
        }else{
            p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            p = p->next;
            p->val = nodes[i];
            p->next = NULL;
        }
    }
    struct ListNode* res = removeElements(head, 6);
    while(res!=NULL){
        printf("%d ", res->val);
        res = res->next;
    }
    return 0;
}
