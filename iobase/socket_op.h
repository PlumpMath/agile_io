//
//  socket_op.h
//  agile_io_xc
//
//  Created by huanghaifeng on 15/9/19.
//  Copyright (c) 2015 wonghoifung. All rights reserved.
//

#ifndef __agile_io_xc__socket_op__
#define __agile_io_xc__socket_op__

#include <string>
#include <sys/socket.h>
#include <stdint.h>

int set_nonblock(int fd);
int enable_tcp_no_delay(int fd);
int disable_tcp_no_delay(int fd);
int set_keep_alive(int fd, int interval);
int set_reuse_addr(int fd);

unsigned fd_to_nl(int fd);
unsigned ip_to_nl(const char* ip);

int create_tcp_server(const char* ip, int port);

std::string get_peer_addr(int fd);
std::pair<uint32_t, uint16_t> get_peer_net_pair(int fd);

int CONNECT(int sockfd, const struct sockaddr* addr, socklen_t addrlen);
int ACCEPT(int sockfd, struct sockaddr* addr, socklen_t* addrlen);
ssize_t READ(int fd, void* buf, size_t count);
ssize_t RECV(int sockfd, void* buf, size_t len, int flags);
ssize_t WRITE(int fd, const void* buf, size_t count);
ssize_t SEND(int sockfd, const void* buf, size_t len, int flags);

uint32_t ip_str2int(const char* ip);
void ip_int2str(uint32_t ip_num, char* ip);
int sendnbytes(int sockfd, size_t N, char* buf);
int readnbytes(int fd, size_t N, char* buf);
std::pair<int, int> readuntil(int fd, char* buf, size_t buflen, char e);

#endif /* defined(__agile_io_xc__socket_op__) */
