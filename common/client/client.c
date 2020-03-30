/*************************************************************************
	> File Name: common/client/client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月30日 星期一 08时17分00秒
 ************************************************************************/

#include "../head/head.h"
#include "./client.h"

struct sockaddr_in GetAddress(char *ip, char *port) {
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(atoi(port));
    if (inet_aton(port, &(address.sin_addr)) == -1) {
        perror("inet_aton");
        exit(1);
    }
    return address;
}

