#include <stdio.h>
#include "listdin.h"

int main() {
    // Test CreateListDin
    ListDin myList;
    CreateListDin(&myList, 10);
    
    // Test other functions...
    // For example:
    insertLast(&myList, 5);
    insertLast(&myList, 10);
    insertLast(&myList, 15);
    
    printf("List contents: ");
    printList(myList);
    printf("\n");
    
    // Add more tests for other functions
    
    // Don't forget to deallocate at the end
    dealocateList(&myList);
    
    return 0;