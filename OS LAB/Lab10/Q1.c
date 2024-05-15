#include <stdio.h>
#include <stdlib.h>

void fifo(int nframes, int npages, int pages[]) {
    int i, j, k, flag = 0, count = 0;
    int *frames = (int*)malloc(nframes * sizeof(int));

    for(i = 0; i < nframes; ++i){
        frames[i] = -1;
    }

    for(i = 0; i < npages; ++i){
        flag = 0;
        for(j = 0; j < nframes; ++j){
            if(frames[j] == pages[i]){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            frames[count++ % nframes] = pages[i];
        }
    }

    printf("Number of page faults: %d\n", count);
    free(frames);
}

void optimal(int nframes, int npages, int pages[]) {
    int i, j, k, l, flag1 = 0, flag2 = 0, count = 0, temp, max, pos;
    int *frames = (int*)malloc(nframes * sizeof(int));

    for(i = 0; i < nframes; ++i){
        frames[i] = -1;
    }

    for(i = 0; i < npages; ++i){
        flag1 = flag2 = 0;

        for(j = 0; j < nframes; ++j){
            if(frames[j] == pages[i]){
                flag1 = flag2 = 1;
                break;
            }
        }

        if(flag1 == 0){
            for(j = 0; j < nframes; ++j){
                if(frames[j] == -1){
                    count++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
            max = -1;
            for(j = 0; j < nframes; ++j){
                for(k = i + 1; k < npages; ++k){
                    if(frames[j] == pages[k]){
                        if(k > max){
                            max = k;
                            pos = j;
                        }
                        break;
                    }
                }
            }
            if(max == -1){
                count++;
                frames[j] = pages[i];
            }
            else{
                count++;
                frames[pos] = pages[i];
            }
        }
    }

    printf("Number of page faults: %d\n", count);
    free(frames);
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

    printf("\nFIFO:\n");
    fifo(nframes, npages, pages);

    printf("\nOptimal:\n");
    optimal(nframes, npages, pages);

    free(pages);
    return 0;
}
