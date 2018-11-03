
#ifndef TEST_H
#define TEST_H
#include <linux/ioctl.h>
 
typedef struct
{
	int dev;
	char* key;
} query_arg_t;
 
#define CREATE _IOW('q', 1, query_arg_t *)
#define DELETE _IOR('q', 2, query_arg_t *)
#define CHANGE_KEY _IOW ('q', 3, query_arg_t *)
#define ENCRYPT _IOW ('q', 4, query_arg_t *)
#define DECRYPT _IOW ('q', 5, query_arg_t *)
 
#endif
