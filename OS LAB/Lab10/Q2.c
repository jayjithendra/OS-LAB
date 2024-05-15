#include <stdio.h>
#include <stdlib.h>

void lru(int nframes, int npages, int pages[]) {
    int i, j, k, flag1 = 0, flag2 = 0, count = 0, min, pos;
    int *frames = (int*)malloc(nframes * sizeof(int));
    int *used = (int*)malloc(nframes * sizeof(int));

    for(i = 0; i < nframes; ++i){
        frames[i] = -1;
    }

    for(i = 0; i < npages; ++i){
        flag1 = flag2 = 0;

        for(j = 0; j < nframes; ++j){
            if(frames[j] == pages[i]){
                count++;
                used[j] = count;
                flag1 = flag2 = 1;
                break;
            }
        }

        if(flag1 == 0){
            for(j = 0; j < nframes; ++j){
                if(frames[j] == -1){
                    count++;
                    frames[j] = pages[i];
                    used[j] = count;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
            min = used[0];
            pos = 0;

            for(j = 1; j < nframes; ++j){
                if(used[j] < min){
                    min = used[j];
                    pos = j;
                }
            }

            count++;
            frames[pos] = pages[i];
            used[pos] = count;
        }
    }

    printf("Number of page faults: %d\n", npages - count);
    free(frames);
    free(used);
}

int main() {
    int nframes, npages, i;
    printf("Enter the number of frames: ");
    scanf("%d", &nframes);
    printf("Enter the number of pages: ");
    scanf("%d", &npages);

    int *pages = (int*)malloc(npages * sizeof(int));
    printf("Enter the page numbers: ");
    for(i = 0; i < npages; i++){
        scanf("%d", &pages[i]);
    }

    printf("\nLRU:\n");
    lru(nframes, npages, pages);

    free(pages);
    return 0;
}
