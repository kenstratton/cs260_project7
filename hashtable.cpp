#include <iostream>
#include <string.h>

#define SIZE_TABLE 3
#define SIZE_KEY 3

using namespace std;


// Structure of a HASH
struct HASH {
    char key[SIZE_KEY]; // Hash Data 1: Keyword
    int value;          // Hash Data 2: Integer value
    struct HASH *next;  // Hash Data 3: Pointer links to another hash address
};

struct HASH * hashtable[SIZE_TABLE]; // A hash table
struct HASH * hsh;                   // A hash used for searching or deleting a target
struct HASH * new_hsh;               // A new hash


// Print all registered values in the hash table
void printfHashTable(){
    int i;
    for(i = 0; i < SIZE_TABLE; i++){
        if(hashtable[i] != NULL){
            hsh = hashtable[i];
            while(hsh != NULL){
                printf("hashVal:%d key:%s value:%d\n", i, hsh->key, hsh->value);
                hsh = hsh->next;
            }
        }
    }
    printf("\n");
}


/*******************************************
 Contains fuction :
 * 1. Check whether a hashtable contains a given key (check one -> go to a next hash)
 * 2. Return a hash OR NULL(not found)
********************************************/
struct HASH* contains(int hashVal, const char* targetKey) {
    // * 1
    hsh = hashtable[hashVal];
    while(hsh != NULL){
        if (strcmp(hsh->key, targetKey) == 0) return hsh;
        hsh = hsh->next;
    }

    return NULL; // * 2
}


/*******************************************
 Add fuction :
 * 1. Check whether a hash value and a key are in the defined range
 * 2. If a given key already exists, just override the existing key's value
 * 3. Allocate memory for a new hash with a key and a value
 * 4. Insert a new hash in different ways depending on whether values exists or not
 * 4. Return bool (success->true OR failure->false)
********************************************/
bool add(int hashVal, const char* key, int value) {
    // * 1
    if (hashVal >= SIZE_TABLE or strlen(key) > SIZE_KEY) return false; // * 5

    // * 2
    hsh = contains(hashVal, key);
    if (hsh != NULL) {
        hsh->value = value;
        cout << "Registered!" << endl;
        printfHashTable();
        return true; // * 5
    }

    // * 3
    new_hsh = (struct HASH*)malloc(sizeof(struct HASH));
    if (new_hsh == NULL) return false; // * 5
    strcpy(new_hsh->key, key);
    new_hsh->value = value;
    new_hsh->next = NULL;

    // * 4
    hsh = hashtable[hashVal];
    if (hsh == NULL) {
        hashtable[hashVal] = new_hsh;
    } else {
        while(hsh->next != NULL) hsh = hsh->next;
        hsh->next = new_hsh;
    }

    printf("Registered!\n");
    printfHashTable();

    return true; // * 5
}


/*******************************************
Test fuction :
 * 1. Test adding values using all hash values
 * 2. Test overriding a value of an existing key
 * 3. Test chaining hashes in the identical hash value
 * 4. Test validation for addition not to insert an inappropriate hash
********************************************/
void testHashTable() {
    printf("Tests start!\n\n");

    // * 1
    assert(add(0, "a", 1) == true);
    assert(add(1, "b", 2) == true);
    assert(add(2, "c", 3) == true);

    hsh = contains(0, "a");
    assert(hsh->value == 1);
    hsh = contains(1, "b");
    assert(hsh->value == 2);
    hsh = contains(2, "c");
    assert(hsh->value == 3);

   // * 2
    assert(add(2, "c", 6) == true);
    hsh = contains(2, "c");
    assert(hsh->value == 6);

    // * 3
    assert(add(0, "d", 100) == true);
    hsh = contains(0, "d");
    assert(hsh->value == 100);

    // * 4
    assert(add(3, "d", 100) == false);
    assert(add(0, "abcd", 100) == false);

    printf("Tests Done!\n");
}

// User Operation
int main() {
    testHashTable();
}
