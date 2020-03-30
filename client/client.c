/*************************************************************************
	> File Name: client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月30日 星期一 07时49分11秒
 ************************************************************************/

#include "../common/head/head.h"
#include "../common/color.h"
#include "../common/client/client.h"

char *path = "./client.conf";

int main() {
    int sockfd = GetSocket();
    struct sockaddr_in address = GetAddress(get_value(path, "SERVER_IP"), get_value(path, "PORT"));
    char *name = strdup(get_value(path, "USERNAME"));
    send(sockfd, (void *) name, strlen(name), 0);
    char *status = (char *) calloc(sizeof(char), 100);
    recv(sockfd, (void *) status, 100, 0);
    printf("%s\n", status);
    close(sockfd);
    return 0;
}
