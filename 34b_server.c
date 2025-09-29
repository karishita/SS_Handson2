/*
Name : 34b_server.c
Author : Ishita Kar
Description:Write a program to create a concurrent server using pthread_create(client)
Date: 20th Sep, 2025.
_______________________________________________________________________________
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 5056
#define BUF_SIZE 1024


void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    free(arg);
    char buffer[BUF_SIZE];
    int bytes_read;

    while ((bytes_read = read(client_socket, buffer, BUF_SIZE - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Client: %s", buffer);

        // Echo back to client
        write(client_socket, buffer, strlen(buffer));
    }

    printf("Client disconnected.\n");
    close(client_socket);
    pthread_exit(NULL);
}

int main() {
    int server_fd, *new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t tid;

   
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Bind failed.\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 5) == -1) {
        printf("Listen failed.\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        int client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            printf("Accept failed.\n");
            continue;
        }

        printf("New client connected.\n");

        // Allocate memory for client socket
        new_sock = malloc(sizeof(int));
        *new_sock = client_socket;

        // Create a new thread for each client
        if (pthread_create(&tid, NULL, handle_client, (void *)new_sock) != 0) {
            printf("Thread creation failed.\n");
            free(new_sock);
        }

        pthread_detach(tid);
    }

    close(server_fd);
    return 0;
}

/*_____________________________________________________________________________
 OUTPUT

 Server listening on port 5056...
New client connected.
Client: Hello from Client
Client disconnected.
New client connected.
Client: Hello from Client
Client disconnected.
______________________________________________________________________________
*/
