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
void ExistHandle(User *user);
void HandleMessage(UserMsg msg);
void Communicate(User *user);

extern User *start;
#endif
