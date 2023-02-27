
#ifndef LABA1SEM2_FUNCTIONS_H
#define LABA1SEM2_FUNCTIONS_H
enum genre {
    jazz,
    rock,
    electronic,
    pop,
    hipHop,
    other
} ;

static char* NameOfGenre[]=
        {
                "jazz",
                "rock",
                "electronic",
                "pop",
                "hipHop",
                "other"
        };
struct Songs {
    char* name;
    char* author;
    int year;
    enum genre genre ;
} ;

int menu();
void sortsongsGenre(struct Songs* song, int size);
void sortsongsYear(struct Songs* song, int size);
void sortsongsAuthor(struct Songs* song, int size);
void sortsongsName(struct Songs* song, int size);
void printsong(const int* size, struct Songs* song);
void printStructure(const int* size, struct Songs* song);
char* getString();
void deleteStruct(struct Songs** song, int* size);
void sort(struct Songs *song, int size);
int enterWithValidationForIndex(int index);
int enterWithValidation();
#endif //LABA1SEM2_FUNCTIONS_H
