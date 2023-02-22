#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//
//int main() {
//    Trips* trips = NULL;
//    int size;
//    numberOfStructure( size);
//     createStructArr( &trips,  &size);
//    initStruct( trips);
//    printStructArray( trips, size);
//    free(trips);
//    return 0;
//}
int main() {
    int size;

    printf("Enter the number of books to add::");
    scanf("%d", &size);
    int* pn = &size;
    struct Songs* song;
    song = (struct Songs*)malloc(size * sizeof(struct Songs));
    printStructure(pn, song);
    printsong(pn, song);

    while (1)
    {
        switch (menu())
        {
            case 1:
//                sortsongsName(song, size);
                 sort(song,  size);
                printsong(pn, song);
                break;
//            case 2:
//                sortsongsAuthor(song, size);
//                printsong(pn, song);
//                break;
//            case 3:
//                sortsongsYear(song, size);
//                printsong(pn, song);
//                break;
//            case 4:
//                sortsongsGenre(song, pn);
//                printsong(pn, song);
//                break;
            case 2:
                deleteStruct(&song, pn);
                printsong(pn, song);
                break;
            case 3:
                printf("Exiting program\n");
                free(song);
                exit(0);
                break;

            default:
                printf("Invalid input\n");
                break;
        }
    }
}