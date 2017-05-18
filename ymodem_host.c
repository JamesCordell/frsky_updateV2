/**

  */

/* Includes ------------------------------------------------------------------*/
#include "common.h"
#include "ymodem_host.h"
#include "crc16.h"

#define	BUFFER_SIZE (3096)
char buffer[BUFFER_SIZE];

static void ymodem_send_char(char c)
{
}

#define	DLY_1S 0x10000

static short ymodem_get_char(char *c,uint32_t timeout)
{
}

static int ymodem_download_packet(char *buffer, uint32_t len)
{
}

int ymodem_download_block(char *buffer)
{
}

/*****************END OF FILE****/
