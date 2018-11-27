#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
#define IP_PROTOCOL 0 
#define PORT_NO 8080 
#define NET_BUF_SIZE 5024 
#define Key 'O' 
#define sendrecvflag 0 
  

char encrypt(char ch) 
{ 
    return ch ^ Key; 
} 

int recvFile(char* buf, int s) 
{ 
    int i; 
    char ch; 
    for (i = 0; i < s; i++) { 
        ch = buf[i]; 
        ch = encrypt(ch); 
        if (ch == EOF) 
            return 1; 
        else
            printf("%c", ch); 
    } 
    return 0; 
} 

int main(int argc, char**argv)  
{ 
	int sockfd, nBytes; 
   	struct sockaddr_in addr_con; 
	int addrlen = sizeof(addr_con);
	char *serverAdd
	if (argc < 2) 
	{  
	      printf("please enter as ./client < IP address >\n");  
	      exit(1);    
     	}  
      
     serverAdd = argv[1];  
    
    addr_con.sin_family = AF_INET; 
    addr_con.sin_port = htons(PORT_NO); 
    addr_con.sin_addr.s_addr = inet_addr(serverAdd); 
    char net_buf[NET_BUF_SIZE]; 
    FILE* fp; 

    sockfd = socket(AF_INET, SOCK_DGRAM, 
                    IP_PROTOCOL); 
  
    if (sockfd < 0)
    {
        printf("\nSocket Not Created\n");
    }
    else
        printf("\nSocket Id is %d\n", sockfd); 
  
    while (1) { 
        printf("\nPlease enter file name to receive:\n"); 
        scanf("%s", net_buf); 
        sendto(sockfd, net_buf, NET_BUF_SIZE, 
               sendrecvflag, (struct sockaddr*)&addr_con, 
               addrlen); 
  
        printf("\n---------Data Received---------\n"); 
  
        while (1) { 

            bzero(net_buf,sizeof(net_buf)); 
            nBytes = recvfrom(sockfd, net_buf, NET_BUF_SIZE, 
                              sendrecvflag, (struct sockaddr*)&addr_con, 
                              &addrlen); 
  
           
            if (recvFile(net_buf, NET_BUF_SIZE)) { 
                break; 
            } 
        } 
        printf("\n-------------------------------\n"); 
    }
} 
