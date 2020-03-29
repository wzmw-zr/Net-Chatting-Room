/*************************************************************************
	> File Name: server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月29日 星期日 21时48分02秒
 ************************************************************************/

#include "../common/head.h"
#include "../common/color.h"
#include "../common/server/server.h"

char *path = "./server.conf";

int main() {
    start = (User *) calloc(sizeof(User), 1);
    int sockfd = GetSocket();
    BindAndListen(sockfd, atoi(get_value(path, "PORT")));
    while (1) {
        int fd;
        pthread_t tid;
        if ((fd = accept(sockfd, NULL, NULL)) == -1) {
            perror("accept");
            continue;
        }
        User *user = (User *) calloc(sizeof(User), 1);
        user->sockfd = fd;
        pthread_create(&(user->tid), NULL, work, (void *) user);
    }
    return 0;
}
