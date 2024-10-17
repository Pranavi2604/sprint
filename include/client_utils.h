#ifndef CLIENT_UTILS_H
#define CLIENT_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>

#define LINE_NUMBER (__LINE__)
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 11112
#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20
#define MAX_MSG_LEN 256

FILE *log_file;
time_t t;

void logger_init();
void logger(char *level, char *filename, int line_number, char *message, char *activity, char *event);
void signalHandler(int sig_num);
void encryption(char *text);
void decryption(char *text);
void *receive_messages(void *arg);

#endif // CLIENT_UTILS_H

