#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")



int main() {
    WSADATA wsa;
    SOCKET tcpSock, udpSock;

    // 윈속 초기화
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        return 1;
    }
    printf("[알림] 윈속 초기화 성공\n");

    // TCP 소켓 생성 (SOCK_STREAM 사용)
    tcpSock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
    if (tcpSock == INVALID_SOCKET) {
        WSACleanup();
        return 1;
    }
    printf("[알림] TCP 소켓 생성 성공\n");

    // UDP 소켓 생성 (SOCK_DGRAM 사용)
    udpSock = WSASocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP, NULL, 0, 0);
    if (udpSock == INVALID_SOCKET) {
        closesocket(tcpSock);
        WSACleanup();
        return 1;
    }
    printf("[알림] UDP 소켓 생성 성공\n");

    // 소켓 닫기
    closesocket(tcpSock);
    closesocket(udpSock);

    // 윈속 종료
    WSACleanup();
    printf("[알림] 윈속 종료 완료\n");

    return 0;
}
