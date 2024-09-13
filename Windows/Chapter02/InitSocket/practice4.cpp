#include "..\..\Common.h"

int f(int x) {
	if (x >= 0) {
		WSASetLastError(0);  
		return 0; 
	}
	else {
		WSASetLastError(WSAEINVAL); 
		return SOCKET_ERROR; 
	}
}


int main(int argc, char* argv[])
{
	// ���� �ʱ�ȭ
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;
	printf("[�˸�] ���� �ʱ�ȭ ����\n");

	int retval = f(100);
	if (retval == SOCKET_ERROR) err_quit("f()");

	// ���� ����
	WSACleanup();
	return 0;
}
