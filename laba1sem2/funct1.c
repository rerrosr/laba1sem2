#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

int enterWithValidation() {
    int a;

    while (scanf_s("%d", &a) != 1 || a < 1 || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
    }

    return a;
}

int enterWithValidationForIndex(int index) {
    int a;

    while (scanf_s("%d", &a) != 1 || a < 1 || a > index || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
    }

    return a;
}

void deleteStruct(struct Songs** song, int* size)
{
    int num;
    printf("Enter the number of the struct to delete:");
    scanf("%d", &num);
    if (num < 1 || num > *size) {
        printf("Invalid input\n");
        return;
    }
    for (int i = num - 1; i < *size - 1; i++)
    {
        (*song)[i] = (*song)[i + 1];
    }
    *size = *size - 1;
    struct Songs* temp = (struct Songs*)realloc(*song, *size * sizeof(struct Songs));
    if (temp != NULL) {
        *song = temp;
    } else {
        printf("Error: memory allocation failed.\n");
        return;
    }
}
char* getString(){
    int size = 0;
    int realSize = 16;
    char* string = malloc(realSize * sizeof(char));
   int i = getchar();
    char check;
    while (i != '\n'){
        check = (char)i;
        string[size] = check;
        size++;
        if (size >= realSize) {
          realSize += 2;
                string = realloc(string, realSize * sizeof(char ));
            }
          i = getchar();
        }
        string[size] = '\0';
    return string;

    }

void printStructure(const int* size, struct Songs* song) {

    for (int i = 0; i < *size; i++) {
        printf("\nEnter name of %d's song: ", i + 1);
        rewind(stdin);
        song[i].name = getString();

        printf("\nenter year of %d's song: ", i + 1);
        song[i].year = enterWithValidation();

        printf("\nenter author of %d's song: ", i + 1);
        song[i].author = getString();

        printf("\nenter genre of %d's song: ", i + 1);
        song[i].genre = enterWithValidation();
    }

}
//
void printsong(const int* size, struct Songs* song){
    for (int i = 0; i < *size; i++)
    {
        if (song[i].genre >= 0 && song[i].genre < 6) {
            printf("\tName:%s\t Author:%s\t Year:%d\t Language:%s\n", song[i].name, song[i].author, song[i].year, NameOfGenre[song[i].genre]);
        } else {
            printf("\tName:%s\t Author:%s\t Year:%d\t Language: Unknown\n", song[i].name, song[i].author, song[i].year);
        }
    }
}
int compareByName(struct Songs song1, struct Songs song2)
{
    int cmp = strcmp(song1.name, song2.name);
    if (cmp == 0)
    {
        return strcmp(song1.author, song2.author);
    }
    return cmp;
}

int compareByAuthor(struct Songs songs1, struct Songs songs2)
{
    int cmp = strcmp(songs1.author, songs2.author);
    if (cmp == 0)
    {
        return songs1.year - songs2.year;
    }
    return cmp;
}

int compareByYear(struct Songs songs1, struct Songs songs2)
{
    int cmp = songs1.year - songs2.year;
    if (cmp == 0)
    {
        return strcmp(songs1.name, songs2.name);
    }
    return cmp;
}

int compareByLanguage(struct Songs songs1, struct Songs songs2)
{
    int cmp = songs1.genre - songs2.genre;
    if (cmp == 0)
    {
        return strcmp(songs1.name, songs2.name);
    }
    return cmp;
}

void sort(struct Songs *song, int size) {
    printf("1. Name\n2. Author\n3. Year \n4. Genre\n0. Exit\n");
    int inp;
    while (!scanf("%d", &inp) || inp > 4 || inp < 0 || getchar() != '\n') {
        printf("Wrong input! Enter again:");
        rewind(stdin);
    }
    if (inp == 0) return;
    if (inp == 1) qsort(song, size, sizeof(struct Songs), (int (*)(const void *, const void *)) compareByName);
    if (inp == 2) qsort(song, size, sizeof(struct Songs), (int (*)(const void *, const void *)) compareByAuthor);
    if (inp == 3) qsort(song, size, sizeof(struct Songs), (int (*)(const void *, const void *)) compareByYear);
    if (inp == 4) qsort(song, size, sizeof(struct Songs), (int (*)(const void *, const void *)) compareByLanguage);
}


void sortsongsName(struct Songs* song, int size) {
    struct Songs tmp;

    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (strcmp(song[j].name, song[j + 1].name) > 0) {
                tmp = song[j];
                song[j] = song[j + 1];
                song[j + 1] = tmp;
            }
        }
    }
}

void sortsongsAuthor(struct Songs* song, int size) {
    struct Songs tmp;

    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if ((song[j].author) > (song[j + 1].author)) {
                tmp = song[j];
                song[j] = song[j + 1];
                song[j + 1] = tmp;
            }
        }
    }
}

void sortsongsYear(struct Songs* song, int size) {
    struct Songs tmp;

    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if ((song[j].year) > (song[j + 1].year)) {
                tmp = song[j];
                song[j] = song[j + 1];
                song[j + 1] = tmp;
            }
        }
    }
}
void sortsongsGenre(struct Songs* song, int size) {
    struct Songs tmp;

    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if ((song[j].genre) > (song[j + 1].genre)) {
                tmp = song[j];
                song[j] = song[j + 1];
                song[j + 1] = tmp;
            }
        }
    }
}
int menu()
{
    int arg;
    printf("Enter:\n");
    printf("1 - To sort the structure \n");
//    printf("1 - To sort the structure by song name\n");
//    printf("2 - To sort the structure by author name\n");
//    printf("3 - To sort the structure by year \n");
//    printf("4 - To sort the structure by genre\n");
    printf("5 - To delete a structure by song number\n");
    printf("6 - To exit the program\n");

    scanf("%d", &arg);
    return arg;
}


// Menu to test functionality

//int numberOfStructure(int size){
//    printf("Enter the number of trips:");
//    while (scanf_s("%d", &size) != 1 || getchar() != '\n' || size < 1) {
//        printf("input error try again\n");
//        rewind(stdin);
//    }
//    return size;
//}
//void charMemoryAllocate(char** string) {
//    *string = (char*)malloc(255 * sizeof(char));
//}
//
//void charMemoryRelocate(char** string) {
//    int len = strlen(*string);
//    *string = (char*)realloc(*string, len);
//    (*string)[len - 1] = '\0';
//}
//
//void printStructArray(Trips* trips, int count) {
//    for (int i = 0; i < count; i++) {
//        printf("%s\n", trips[i].arrival);
//    }
//}
//
//void initStruct(Trips* trips) {
//	int userInput;
//	printf("Arrival: ");
//	charMemoryAllocate(&trips->arrival);
//	fgets(trips->arrival, 255, stdin);
//	charMemoryRelocate(&trips->arrival);
//	printf("data: ");
//	scanf_s(" %f", &trips->data);
//	printf("passanger ");
//	scanf_s(" %d", &userInput);
//	printf("price ");
//	scanf_s(" %d", &trips->price);
//	rewind(stdin);
//	printf("departure");
//	charMemoryAllocate(&trips->departure);
//	fflush(stdin);
//	fgets(trips->departure, 255, stdin);
//	charMemoryRelocate(&trips->departure);
//
//}
//void createStructArr(Trips** trips, int* count) {
//    printf("Enter the number of trips: ");
//    while ((scanf_s(" %d", count)) != 1 || getchar() != '\n' || *count <= 0) {
//        printf("try again ");
//        rewind(stdin);
//    }
//    *trips = (Trips*)malloc((*count) * sizeof(Trips));
//    for (int i = 0; i < *count; i++) {
//        printf("initialisation %d structure in array\n\n", i + 1);
//        initStruct(*trips + i);
//        printf("\nnext!");
//        Sleep(3000);
//        system("cls");
//        rewind(stdin);
//    }
//}
