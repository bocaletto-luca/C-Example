#include <arpa/inet.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10
#define BUF_SIZE 4096

void *handle_client(void *arg) {
    int client = *(int *)arg;
    free(arg);

    char buffer[BUF_SIZE];
    read(client, buffer, BUF_SIZE - 1);

    FILE *f = fopen("public/index.html", "rb");
    if (!f) {
        close(client);
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    rewind(f);
    char *content = malloc(len);
    fread(content, 1, len, f);
    fclose(f);

    char header[BUF_SIZE];
    int hlen = snprintf(header, sizeof(header),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html; charset=UTF-8\r\n"
        "Content-Length: %ld\r\n"
        "Connection: close\r\n\r\n", len);

    write(client, header, hlen);
    write(client, content, len);

    free(content);
    close(client);
    return NULL;
}

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = { .sin_family = AF_INET,
                                .sin_port = htons(PORT),
                                .sin_addr.s_addr = INADDR_ANY };

    bind(sock, (struct sockaddr *)&addr, sizeof(addr));
    listen(sock, BACKLOG);

    printf("Server in ascolto su http://localhost:%d\n", PORT);

    while (1) {
        int *client = malloc(sizeof(int));
        *client = accept(sock, NULL, NULL);
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, client);
        pthread_detach(tid);
    }

    close(sock);
    return 0;
}
