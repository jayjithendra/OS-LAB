#include<stdio.h>
#include<stdlib.h>

void SSTF(int arr[], int head, int size) {
    // Implement SSTF algorithm
    int seek_count = 0;
    int distance, cur_track;
    int shortest = INT_MAX, shortest_index;
    int seek_sequence[size];
    
    for (int count = 0; count < size; count++) {
        shortest = INT_MAX;
        
        for (int i = 0; i < size; i++) {
            distance = abs(arr[i] - head);
            if (distance < shortest) {
                shortest = distance;
                shortest_index = i;
            }
        }
        
        seek_count += shortest;
        head = arr[shortest_index];
        seek_sequence[count] = head;
        arr[shortest_index] = INT_MAX; // mark as visited
    }
    
    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence is: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\n");
}

void SCAN(int arr[], int head, int size) {
    // Implement SCAN algorithm
    int seek_count = 0;
    int distance, cur_track;
    int seek_sequence[size], seek_count = 0;
    
    // sort the array
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // find the location of head in the sorted array
    int loc;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= head) {
            loc = i;
            break;
        }
    }
    
    // move towards the end
    for (int i = loc; i < size; i++) {
        seek_count += abs(head - arr[i]);
        head = arr[i];
        seek_sequence[seek_count++] = head;
    }
    
    // move towards the start
    for (int i = loc - 1; i >= 0; i--) {
        seek_count += abs(head - arr[i]);
        head = arr[i];
        seek_sequence[seek_count++] = head;
    }
    
    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence is: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\n");
}

void CSCAN(int arr[], int head, int size) {
    // Implement C-SCAN algorithm
    int seek_count = 0;
    int distance, cur_track;
    int seek_sequence[size], seek_count = 0;
    
    // sort the array
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // find the location of head in the sorted array
    int loc;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= head) {
            loc = i;
            break;
        }
    }
    
    // move towards the end
    for (int i = loc; i < size; i++) {
        seek_count += abs(head - arr[i]);
        head = arr[i];
        seek_sequence[seek_count++] = head;
    }
    
    // jump to the start
    seek_count += abs(head - arr[0]);
    head = arr[0];
    
    // move towards the initial head position
    for (int i = 0; i < loc; i++) {
        seek_count += abs(head - arr[i]);
        head = arr[i];
        seek_sequence[seek_count++] = head;
    }
    
    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence is: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\n");
}

void CLOOK(int arr[], int head, int size) {
    // Implement C-LOOK algorithm
    int seek_count = 0;
    int distance, cur_track;
    int seek_sequence[size], seek_count = 0;
    
    // sort the array
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // find the location of head in the sorted array
    int loc;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= head) {
            loc = i;
            break;
        }
    }
    
    // move towards the end
    for (int i = loc; i < size; i++) {
        seek_count += abs(head - arr[i]);
        head = arr[i];
        seek_sequence[seek_count++] = head;
    }
    
    // jump to the initial head position
    seek_count += abs(head - arr[0]);
    head = arr[0];
    
    // move towards the initial head position
    for (int i = 0; i < loc; i++) {
        seek_count += abs(head - arr[i]);
        head = arr[i];
        seek_sequence[seek_count++] = head;
    }
    
    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence is: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\n");
}


int main() {
    int choice;
    int arr[20], head, size, i;
    printf("Enter the number of disk locations: ");
    scanf("%d", &size);
    printf("Enter the disk locations: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    do {
        printf("\n*** Disk Scheduling Algorithms ***\n");
        printf("1. SSTF\n");
        printf("2. SCAN\n");
        printf("3. C-SCAN\n");
        printf("4. C-LOOK\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                SSTF(arr, head, size);
                break;
            case 2:
                SCAN(arr, head, size);
                break;
            case 3:
                CSCAN(arr, head, size);
                break;
            case 4:
                CLOOK(arr, head, size);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while(choice != 5);
    return 0;
}
