/*************************************************************************
	> File Name: server.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月29日 星期日 21时45分21秒
 ************************************************************************/

#ifndef _SERVER_H
#define _SERVER_H

#define LOCK pthread_mutex_lock(&mutex)
#define UNLOCK pthread_mutex_unlock(&mutex)

char *get_value(char *path, char *key);
int check(char *line, char *key);
char *split_value(char *line);
int GetSocket();
void BindAndListen(int sockfd, int port);
void *work(void *arg);

typedef struct User {
    char name[100];
    int sockfd;
    pthread_t tid;
    struct User *next;
} User;

typedef struct UserMsg {
    char name[100];
    int type, size;
    char filename[256];
    char data[1024];
} UserMsg;

extern User *start;
#endif
