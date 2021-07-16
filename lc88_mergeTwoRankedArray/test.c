#include <stdlib.h>
#include <stdio.h>

struct double_link{
    int val;
    struct double_link* pre;
    struct double_link* aft;
};

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    struct double_link* header;
    struct double_link* tail;
    struct double_link* temp;
    struct double_link* temp_add;
    if(m>0){
        // add first to double_link
        header = (struct double_link*)malloc(sizeof(struct double_link));
        header->pre = NULL;
        header->val = nums1[0];
        tail = header;
        for(int i=1; i<m; ++i){
            temp = (struct double_link*)malloc(sizeof(struct double_link));
            temp->pre = tail;
            temp->val = nums1[i];
            tail->aft = temp;
            tail = temp;
        }
        tail->aft = NULL;

        for(int i=0; i<n; ++i){
            if(nums2[i] >= tail->val){
                temp = (struct double_link*)malloc(sizeof(struct double_link));
                temp->val = nums2[i];
                temp->pre = tail;
                temp->aft = NULL;
                tail->aft = temp;
                tail = temp;
                continue;
            }
            if(nums2[i] <= header->val){
                temp = (struct double_link*)malloc(sizeof(struct double_link));
                temp->val = nums2[i];
                temp->pre = NULL;
                temp->aft = header;
                header->pre = temp;
                header = temp;
                continue;
            }
            // add in the link
            temp = header;
            while(temp != NULL){
                if(temp->val <= nums2[i] && nums2[i] <= temp->aft->val){
                    // add here
                    temp_add = (struct double_link*)malloc(sizeof(struct double_link));
                    temp_add->val = nums2[i];
                    temp_add->pre = temp;
                    temp_add->aft = temp->aft;
                    temp->aft->pre = temp_add;
                    temp->aft = temp_add;
                    temp = temp_add;
                    break;
                }
                temp = temp->aft;
            }
        }
     
        temp = header;
        for(int i=0; i<m+n; ++i){
            nums1[i] = temp->val;
            temp = temp->aft;
        }

    }else{
        memcpy(nums1, nums2, sizeof(int)*nums2Size);
    }
}

int main(int argc, char *argv[])
{
    int nums1[] = {4,5,6,0,0,0};
    int nums2[] = {1,2,3};
    merge(nums1, 6, 3, nums2, 3, 3);
    for(int i=0; i<6; ++i)
        printf("%d ", nums1[i]);
    return 0;
}
