#include "../include/client_utils.h"

// Function to perform Caesar cipher encryption
void encryption(char *text) {
     for (int i = 0; text[i] != '\0'; i++) {
       // Handle uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + 3) % 26) + 'A';
        }
       // Handle lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + 3) % 26) + 'a';
        }
       // Handle non-alpha characters by rotating them
       else {
            text[i] = ((text[i] + 3) % 256);
       }
     }
}
// Function to perform Caesar cipher decryption
void decryption(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        // Handle uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' - 3 + 26) % 26) + 'A';
        }
        // Handle lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' - 3 + 26) % 26) + 'a';
        }
         // Handle non-alpha characters by rotating them
         else {
             text[i] = ((text[i] - 3 + 256) % 256);
         }
    }
}




