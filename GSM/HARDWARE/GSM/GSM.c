#include "GSM.h"
#include "string.h"

void gsm_command_send(char * s)
{
	gsm_send(s);
	delay_s(1);
}

void gsm_net_init(char * s, int port)
{
	char command[40];
	delay_s(5);
	gsm_command_send("\r\nAT\r\n");
	gsm_command_send("\r\nAT+CGDCONT=1,\"IP\",\"CMNET\"\r\n");//
	gsm_command_send("\r\nAT+CSQ\r\n");
	gsm_command_send("\r\nAT+CREG?\r\n");
	gsm_command_send("\r\nAT+CPSI?\r\n");//
	gsm_command_send("\r\nAT+CGREG?\r\n");
	gsm_command_send("\r\nAT+CGSOCKCONT=1,\"IP\",\"CMNET\"\r\n");
	gsm_command_send("\r\nAT+CSOCKSETPN=1\r\n");
	gsm_command_send("\r\nAT+NETCLOSE\r\n");
	gsm_command_send("\r\nAT+CIPMODE=0\r\n");//命令模式, 默认为0. 若用户想要数据模式, 请在net open前设置
	gsm_command_send("\r\nAT+NETOPEN\r\n");
	gsm_command_send("\r\nAT+IPADDR\r\n");//查询本身IP
	sprintf(command, "\r\nAT+CIPOPEN=0,\"%s\",,,%d\r\n", s, port);
	gsm_command_send(command);//here 9000 is local port
}

void gsm_upd_senddata(char * ip, int port, char * s)
{
	char x[40];
	sprintf(x, "\r\nAT+CIPSEND=0,%d,\"%s\",%d\r\n", strlen(s), ip, port);
	gsm_command_send(x);		
	delay_s(2); 
	send_uart2_str(s);
	delay_s(1);
}
