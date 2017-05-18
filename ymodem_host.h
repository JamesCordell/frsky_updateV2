/**
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _YMODEM_H_
#define _YMODEM_H_

#include "stdint.h"

/* Exported constants --------------------------------------------------------*/
#define PACKET_SEQNO_INDEX      (1)
#define PACKET_SEQNO_COMP_INDEX (2)

#define PACKET_HEADER           (3)
#define PACKET_TRAILER          (2)
#define PACKET_OVERHEAD         (PACKET_HEADER + PACKET_TRAILER)
#define PACKET_SIZE             (128)
#define PACKET_1K_SIZE          (1024)

#define FILE_NAME_LENGTH        (256)
#define FILE_SIZE_LENGTH        (16)

#define SOH                     (0x01)  /* start of 128-byte data packet */
#define STX                     (0x02)  /* start of 1024-byte data packet */
#define SER                     (0x03)
#define EOT                     (0x04)  /* end of transmission */
#define	EOB			(0x05)  /* end of block */
#define ACK                     (0x06)  /* acknowledge */
#define NAK                     (0x15)  /* negative acknowledge */
#define CAN                     (0x18)  /* two of these in succession aborts transfer */
#define CRC16                   (0x43)  /* 'C' == 0x43, request 16-bit CRC */

#define ABORT1                  (0x41)  /* 'A' == 0x41, abort by user */
#define ABORT2                  (0x61)  /* 'a' == 0x61, abort by user */

#define NAK_TIMEOUT             (0x100000)
#define MAX_ERRORS              (5)
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
int ymodem_download_block(char *);
extern char buffer[3096];

#endif  /* _YMODEM_H_ */

/*******************(C)COPYRIGHT YYYY STMicroelectronics *****END OF FILE****/
