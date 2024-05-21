#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define TABLE_SIZE 11

// Function to perform the folding hash function
int foldingHash(char *key, int tableSize) {
    int sum = 0;
    int length = strlen(key);
    
    // Process each part of the key
    for (int i = 0; i < length; i++) {
        sum += key[i];
    }
    
    // Return the sum modulo table size
    return sum % tableSize;
}

int main() {
    char keys[TABLE_SIZE][MAX_KEY_LENGTH];
    int hashTable[TABLE_SIZE];
    
    // Initialize the hash table with -1 to indicate empty slots
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
        keys[i][0] = '\0';
    }

    // Input keys from the user
    int numKeys;
    printf("Enter the number of keys: ");
    scanf("%d", &numKeys);

    if (numKeys > TABLE_SIZE) {
        printf("Number of keys exceeds the table size. Please use a smaller number of keys.\n");
        return 1;
    }

    printf("Enter the keys:\n");
    for (int i = 0; i < numKeys; i++) {
        printf("Key %d: ", i + 1);
        scanf("%s", keys[i]);
        
        int index = foldingHash(keys[i], TABLE_SIZE);

        // Handle collisions using linear probing
        while (hashTable[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
        }

        // Store the key index in the hash table
        hashTable[index] = i;
    }

    // Print the hash table
    printf("\nHash Table (Index => Key):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d => Key %s\n", i, keys[hashTable[i]]);
        } else {
            printf("Index %d => Empty\n", i);
        }
    }

    return 0;
}
