// Copyright (c) Athena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef _IF_MAP_H_
#define _IF_MAP_H_

#include "../common/mmo.h"

#define MAX_MAP_SERVERS 30

struct mmo_map_server
{
	int fd;
	uint32 ip;
	uint16 port;
	int users;
	unsigned short map[MAX_MAP_PER_SERVER];
};

extern struct mmo_map_server server[MAX_MAP_SERVERS];

bool mapif_auth_data_send(int id, int account_id, int char_id, int login_id1, uint8 sex);
int parse_frommap(int fd);
int mapif_send(int fd, const void* buf, unsigned int len);
int mapif_sendallwos(int fd, const void* buf, unsigned int len);
int mapif_sendall(const void* buf, unsigned int len);

void mapif_server_init(int id);
void mapif_server_destroy(int id);
void mapif_server_reset(int id);
bool mapif_server_isconnected(int id);

void do_init_mapif(void);
void do_final_mapif(void);


#endif // _IF_MAP_H_
