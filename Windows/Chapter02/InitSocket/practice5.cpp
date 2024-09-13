#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")



int main() {
    WSADATA wsa;
    SOCKET tcpSock, udpSock;

    // ���� �ʱ�ȭ
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        return 1;
    }
    printf("[�˸�] ���� �ʱ�ȭ ����\n");

    // TCP ���� ���� (SOCK_STREAM ���)
    tcpSock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
    if (tcpSock == INVALID_SOCKET) {
        WSACleanup();
        return 1;
    }
    printf("[�˸�] TCP ���� ���� ����\n");

    // UDP ���� ���� (SOCK_DGRAM ���)
    udpSock = WSASocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP, NULL, 0, 0);
    if (udpSock == INVALID_SOCKET) {
        closesocket(tcpSock);
        WSACleanup();
        return 1;
    }
    printf("[�˸�] UDP ���� ���� ����\n");

    // ���� �ݱ�
    closesocket(tcpSock);
    closesocket(udpSock);

    // ���� ����
    WSACleanup();
    printf("[�˸�] ���� ���� �Ϸ�\n");

    return 0;
}
