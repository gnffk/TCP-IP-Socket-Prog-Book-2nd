#include "..\..\Common.h"

int main(int argc, char* argv[])
{
	// ���� �ʱ�ȭ
	WSADATA wsa;

	WORD version = 0x0202;
	if (WSAStartup(version, &wsa) != 0)
		return 1;
	printf("[�˸�] ���� �ʱ�ȭ ����\n");

	printf("wVersion : %d.%d\n", LOBYTE(wsa.wVersion),HIBYTE(wsa.wVersion));
	printf("wHighVersion : %d.%d\n", LOBYTE(wsa.wHighVersion),HIBYTE(wsa.wHighVersion));
	printf("szDescription : %s\n", (wsa.szDescription));	
	printf("szSystemStatus : %s\n", (wsa.szSystemStatus));
	
	
	// ���� ����
	WSACleanup();
	return 0;
}
