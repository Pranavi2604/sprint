#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>

#define LINE_NUMBER (__LINE__)
#define MAX_CLIENTS 10
#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20
#define REGISTRATION_FILE "/home2/user19/mpcc/data/registration.txt"
#define MAX_MSG_LEN 256
#define ENCRYPTION_KEY 0x0F // Encryption key

struct Client {
    int socket;
    char username[MAX_USERNAME_LEN];
};

// Declare global variables as extern
extern int server_socket;
extern struct Client clients[MAX_CLIENTS];
extern int num_clients;
extern pthread_mutex_t mutex;
extern FILE *log_file;
extern time_t t;

// Function declarations
void logger_init();
void logger(char *level, char *filename, int line_number, char *message, char *activity, char *event);
void signalHandler(int sig_num);
void encryption(char *text);
void decryption(char *text);
void register_client(char *username, char *password);
int authenticate(char *username, char *password);
void *handle_client(void *arg);

#endif

