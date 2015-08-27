/*
 * c_config.h
 *
 *  Created on: 2015年8月11日
 *      Author: Stur
 */

#ifndef SRC_ADDON_DEPS_C_CONFIG_H_
#define SRC_ADDON_DEPS_C_CONFIG_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#define DEFAULT_DOMAIN "nodejs"
#define SPLIT "-"
#define THREAD_GROUP_NAME "NodeThreadGroup"
#define THREAD_NAME "null"
#define STR_NULL "null"
#define STR_SIZE 1024

typedef struct g_config{
	char* domain;
	char* server;
	int port;
} g_config;

typedef struct g_context{
	unsigned int initialized;
	char* local_ip;
	char local_ip_hex[8];
	unsigned int msg_index;
} g_context;

typedef struct default_message_tree{
	char Domain[STR_SIZE];
	char HostName[STR_SIZE];
	char IpAddress[16];
	struct cat_message *message;
	char MessageId[STR_SIZE];
	char ParentMessageId[STR_SIZE];
	char RootMessageId[STR_SIZE];
	char SessionToken[STR_SIZE];
	char ThreadGroupName[STR_SIZE];
	unsigned int ThreadId;
	char ThreadName[STR_SIZE];
} default_message_tree;

void add_message(struct cat_message* message);
void setup();
void set_domain(char* domain);
char* next_message_id();

extern char * number_to_array(unsigned int number);
extern long get_tv_usec();
extern void init_ip();
extern void str_copy(char* dest,char* source);

#endif /* SRC_ADDON_DEPS_C_CONFIG_H_ */

