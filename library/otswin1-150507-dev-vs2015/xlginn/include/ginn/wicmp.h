#if !defined(GINN_WICMP_H)
#define GINN_WICMP_H

//#include <sys/time.h>
#define         MAXPACKET       4096
#define		GINN_ICMP_INTERVAL	500000

#define         SIZE_ICMP_HDR   8
//#define         SIZE_TIME_DATA  8
#define         SIZE_TIME_DATA  sizeof(struct timeval)
#define         DEF_DATALEN     56

#if defined(EC_WIN32) || defined(_GINN_WIN32_)
#define         ICMP_MINLEN     8
#define         ICMP_ECHOREPLY  0
#define         ICMP_ECHO       8

struct  icmp    {
        unsigned        char    icmp_type;
        unsigned        char    icmp_code;
        unsigned        short   icmp_cksum;
        unsigned        short   icmp_id;
        unsigned        short   icmp_seq;
        unsigned        char    icmp_data[1];
};
#endif

#if defined(EC_WIN32)
#include	<winsock2.h>
struct  ip      {
        unsigned        int     ip_hl:4;
        unsigned        int     ip_v:4;
        unsigned        char    ip_tos;
        unsigned        short   ip_len;
        unsigned        short   ip_id;
        unsigned        short   ip_off;
        unsigned        char    ip_ttl;
        unsigned        char    ip_p;
        unsigned        short   ip_sum;
        struct  in_addr         ip_src;
        struct  in_addr         ip_dst;
};

#else
#include        <netinet/in.h>
#endif

#include        "ginn/cdefs.h"

__BEGIN_DECLS

#ifdef  _GINN_SCO_
extern  int     h_errno;
#endif

GINNIMPORT      void    icmp_logfp(FILE *fp);
GINNIMPORT      void    icmp_timeout(int microsec);
GINNIMPORT      void    icmp_interval(int microsec);
GINNIMPORT      in_addr_t     icmp_send(const char *host);
GINNIMPORT      int     icmp_receive(void);
GINNIMPORT      char    *icmp_check(in_addr_t);
GINNIMPORT      int     icmp_checksequence(void);
GINNIMPORT      int     icmp_checkhost(const char *host, int times);

__END_DECLS
#endif
