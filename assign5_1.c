#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define NAME_SIZE 30

typedef struct {
    int id;
    char name[NAME_SIZE];
} Faculty;

typedef struct {
    Faculty faculty;
    int isOccupied;
} HashTableEntry;

void initializeTable(HashTableEntry table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].isOccupied = 0;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insertFaculty(HashTableEntry table[], int id, char name[]) {
    int index = hashFunction(id);
    int originalIndex = index;
    int found = 0;
    
    do {
        if (!table[index].isOccupied) {
            table[index].faculty.id = id;
            strcpy(table[index].faculty.name, name);
            table[index].isOccupied = 1;
            found = 1;
            break;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != originalIndex);

    if (!found) {
        printf("Hash table is full, unable to insert new record.\n");
    }
}

Faculty* searchFaculty(HashTableEntry table[], int id) {
    int index = hashFunction(id);
    int originalIndex = index;

    do {
        if (table[index].isOccupied && table[index].faculty.id == id) {
            return &table[index].faculty;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != originalIndex && table[index].isOccupied);

    return NULL;
}

void displayTable(HashTableEntry table[]) {
    printf("Index\tID\tName\n");
    printf("----------------------\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].isOccupied) {
            printf("%d\t%d\t%s\n", i, table[i].faculty.id, table[i].faculty.name);
        } else {
            printf("%d\t-\t-\n", i);
        }
    }
}

int main() {
    HashTableEntry table[TABLE_SIZE];
    initializeTable(table);

    insertFaculty(table, 1, "Dr. Smith");
    insertFaculty(table, 12, "Dr. Jones");
    insertFaculty(table, 23, "Dr. Brown");
    insertFaculty(table, 34, "Dr. White");
    insertFaculty(table, 45, "Dr. Black");

    displayTable(table);

    int searchId;
    printf("Enter the faculty ID to search: ");
    scanf("%d", &searchId);
    
    Faculty* faculty = searchFaculty(table, searchId);
    if (faculty != NULL) {
        printf("Faculty found: ID = %d, Name = %s\n", faculty->id, faculty->name);
    } else {
        printf("Faculty not found.\n");
    }

    return 0;
}
