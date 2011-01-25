#ifndef BACKEND_H
#define BACKEND_H

#include <netinet/in.h>
#include <sys/queue.h>

#define BACKEND_HOSTNAME_LEN 256

struct Backend {
    char hostname[BACKEND_HOSTNAME_LEN];
    struct sockaddr_storage addr;

    LIST_ENTRY(Backend) entries;
};

void init_backends();
void add_backend(const char *, const char *, int);
int load_config();
int lookup_backend_socket(const char *);

#endif
