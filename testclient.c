
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include <sys/ioctl.h>
#include "test.h"
#define BUFFER_LENGTH 256               ///< The buffer length (crude but fine)
static char receive[BUFFER_LENGTH];     ///< The receive buffer from the LKM

int main(){
   int ret, fd, fp, fe;
   char stringToSend[BUFFER_LENGTH];
   printf("Starting device test code example...\n");
   fd = open("/dev/ebbchar", O_RDWR);             // Open the device with read/write access
   if (fd < 0){
      perror("Failed to open the device...");
      return errno;
   }
	char key[25];
	scanf("%[^\n]%*c", stringToSend);
	sprintf(key, "ABCD");
	query_arg_t q;
	query_arg_t t;
	q.key = key;
	ioctl(fd, CREATE, &q);
	printf("Key : %s\n", q.key);
	fp = open("/dev/encrypt0", O_RDWR);
	fe = open("/dev/decrypt0", O_RDWR);
	sprintf(key, "DCBA");
	q.key = key;
	ioctl(fd, CHANGE_KEY, &q);
	q.key = NULL;
	ioctl(fp, ENCRYPT, &t);
	printf("test: %s\n", t.key);
	ret = write(fp, stringToSend, strlen(stringToSend));
	printf("%d%d%d%d\n", stringToSend[0], stringToSend[1], stringToSend[2], stringToSend[3]);
	//getchar();
	ret = read(fe, receive, BUFFER_LENGTH);
   	printf("The received message is: [%s]\n", receive);
	ioctl(fd, DELETE, &q);
}
   
