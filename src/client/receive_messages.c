#include "../include/client_utils.h"
  

void *receive_messages(void *arg) {
    int client_socket = *((int *)arg);
    free(arg);

    logger_init();
    logger("INFO", "receive_messages.c", LINE_NUMBER, "Receive messages", "receive_messages", "start");
    
    char buffer[MAX_MSG_LEN + MAX_USERNAME_LEN + 1];
    char *message;
    char *username;

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        
        if (bytes_received <= 0) {
            logger("FATAL", "receive_messages.c", LINE_NUMBER, "Error while receiving messages", "receive_messages", "end");
            perror("Error receiving message from server");
            close(client_socket);
            fclose(log_file);
            exit(EXIT_FAILURE);
        }

        buffer[bytes_received] = '\0';
        decryption(buffer);
        username = strtok(buffer, "|");
        message = strtok(NULL, "|");
        printf("[%s]: %s\n", username, message);
        logger("INFO", "receive_messages.c", LINE_NUMBER, "Message received", "receive_messages", "end");
    }

    return NULL;
}

