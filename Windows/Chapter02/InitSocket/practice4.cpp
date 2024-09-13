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
	// 윈속 초기화
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;
	printf("[알림] 윈속 초기화 성공\n");

	int retval = f(100);
	if (retval == SOCKET_ERROR) err_quit("f()");

	// 윈속 종료
	WSACleanup();
	return 0;
}
