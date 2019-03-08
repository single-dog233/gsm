#ifndef _GSM_H_
#define _GSM_H_

#include "usart.h"
#include "delay.h"

//REG
#define ATE0_CMD "ATE0\r\n"           		/// 禁止回显
#define CREG_CMD "AT+CREG?\x00D\x00A"       /// 查询网络注册情况
#define SIMCARD_CMD "AT+CPIN?\x00D\x00A"
#define CEREG_CMD "AT+CREG?\x00D\x00A"

//LTE APN AT+CGDCONT=1,\042IP\042,\042CMNET\042
#define GPRS_DEF_PDP "AT+CGDCONT=1,\042IP\042,\042CMNET\042\x00D\x00A"  /// 接入点APN
#define GPRS_ACT_PDP "AT+CGATT=1\x00D\x00A"                                 /// GPRS激活PDP
#define GPRS_CLOSE "AT+CIPCLOSE=0\x00D\x00A"                                 /// 关闭链接 怕万一已经有链接了
#define GPRS_DEACT_PDP "AT+CGACT\x00D\x00A"                             /// 去激活
#define GPRS_NET_OPEN "AT+NETOPEN\x00D\x00A"                             /// 去激活
#define GPRS_NET_CLOSE "AT+NETCLOSE\x00D\x00A"                             /// 去激活

//CONNECT...
#define GPRS_BJ_ADDR "AT+CGPADDR=1\x00D\x00A"   /// 获取本地IP
#define GPRS_TCP1 "AT+CIPOPEN=0,"            /// 建立一个IP连接
#define GPRS_TCP2 PROTOTOCOL
#define GPRS_TCP3 IPADDR
#define GPRS_TCP4 PORTNUM

#define PM "^SIM800A^"
//SEND  GPRS
#define GPRS_SEND_DATA "AT+CIPSEND=0,\x00D\x00A"
#define GPRS_CELL_SOC "AT+CSOCKSETPN=1\x00D\x00A"
#define GPRS_CELL_STA "AT+CNETSTART\x00D\x00A"
#define GPRS_CELL_LOC "AT+CLBS=1\x00D\x00A"

//SEND SMS
#define GSM_MSG_MODE "AT+CMGF=1\x00D\x00A"
//#define GSM_CENTER_NUM "AT+CSCA=\"+8613800512500\"\x00D\x00A"
#define GSM_CHAR_MODE "AT+CSCS=\"GSM\"\x00D\x00A"
#define GSM_SEND_TEXT "AT+CMGS=\"+8613512963352\"\x00D\x00A"
//READ SMS
#define SMSCAT "CMTI: \"SM\","
#define SMSCATRHOS "+CMT:"
//ds18b20
#define NO_SENSOR "no sensor"



#define gsm_send send_uart2_str
#define delay_1s(num) delay_ms(1000*num), delay_ms(1000*0num), delay_ms(num)
void gsm_net_init(char * s, int port);
void gsm_upd_senddata(char * ip, int port, char * s);
#endif


