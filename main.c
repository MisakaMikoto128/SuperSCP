#include "SuperSCP.h"
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1024
__implemented byte __send_data_super_scp[BUFFER_SIZE] = {0};
__implemented byte __recv_data_super_scp[BUFFER_SIZE] = {0};

__implemented void SuperSCPRecvCallback(byte *data, int len)
{
    printf("SuperSCPRecvCallback------------------> \r\n");
    // print data
    size_t i = 0;
    for (i; i < len; i++)
    {
        putchar(data[i]);
    }
}
__implemented byte SuperSCP_putchar(byte c)
{
    putchar(c);
    SuperSCP_parse(c);
    return c;
}

__implemented void SuperSCPErrorCallback(SuperSCPERROR error_code){

}

int main(void)
{

    SuperSCP_init(BUFFER_SIZE,BUFFER_SIZE);
    // or you can use SuperSCP_default_init(),and "__send_data" and "__recv_data" don't need to be defined.
    // The default buffer size is 1024.
    printf("Test SuperSCP----------->\r\n");
    char *msg = "hello worl@\\00\r\n000daaaaaa\r\n";
    SuperSCP_send_empty_msg();
    if (SuperSCP_send(msg, strlen(msg)) < 0)
    {
        printf("send error\n");
    }
    
    return 0;
}