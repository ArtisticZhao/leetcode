#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* next = head->next;
    struct ListNode* nextnext = head->next->next;
    next->next = head;
    if(nextnext==NULL) return next;
    return reverseList(nextnext);

}

int main(int argc, char *argv[])
{
    int nodes[] ={ 1,2,3 };
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
    struct ListNode *res = reverseList(head);
    while(res!=NULL){
        printf("%d ", res->val);
        res = res->next;
    }
    return 0;
}
