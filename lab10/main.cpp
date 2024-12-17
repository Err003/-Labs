#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
constexpr auto BUFLEN = 1024;
constexpr auto PORT = 8888;
static int WSAInit()
{
    static unsigned int count = 0;
    if (count++)
        return 0;
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) 
    {
        printf("WSAStartup failed. Error code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Winsock Initialized.\n");
    return 0;
}

int SendDatagram(SOCKET s, char* msg, unsigned int msglen, struct sockaddr* si_dest, unsigned int slen) 
{
    if (sendto(s, msg, msglen, 0, si_dest, slen) == SOCKET_ERROR) 
    {
        printf("sendto() failed with error code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    return 0;
}

int RecvDatagram(SOCKET s, char* buf, unsigned int buflen, struct sockaddr* si_dest, int* slen) 
{
    if (recvfrom(s, buf, buflen, 0, si_dest, slen) == SOCKET_ERROR) 
    {
        printf("recvfrom() failed with error code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    return 0;
}

void StartServer() 
{
    struct sockaddr_in si_other;
    SOCKET s;
    int slen = sizeof(si_other);
    char buf[BUFLEN];
    char msg[BUFLEN];

    s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (s == SOCKET_ERROR) 
    {
        printf("Socket creation failed. Error code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    memset((char*)&si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);
    si_other.sin_addr.s_addr = INADDR_ANY;

    if (bind(s, (struct sockaddr*)&si_other, sizeof(si_other)) == SOCKET_ERROR) 
    {
        printf("Bind failed with error code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (true) 
    {
        memset(buf, '\0', BUFLEN);
        RecvDatagram(s, buf, BUFLEN, (struct sockaddr*)&si_other, &slen);
        printf("Received message: %s\n", buf);
        printf("Enter response: ");
        fgets(msg, BUFLEN, stdin); 
        SendDatagram(s, msg, (unsigned int)strlen(msg), (struct sockaddr*)&si_other, slen);
    }
    closesocket(s);
    WSACleanup();
}

void StartClient() 
{
    struct sockaddr_in si_other;
    SOCKET s;
    int slen = sizeof(si_other);
    char buf[BUFLEN];
    char message[BUFLEN];

    s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (s == SOCKET_ERROR) 
    {
        printf("Socket creation failed. Error code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    memset((char*)&si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;

    char server_ip[40];
    printf("Enter server IP address: ");
    scanf_s("%s", server_ip);
    if (inet_pton(AF_INET, server_ip, &si_other.sin_addr) <= 0) 
    {
        printf("Invalid IP address or format not supported.\n");
        exit(EXIT_FAILURE);
    }
    si_other.sin_port = htons(PORT);

    printf("Enter message to send: ");
    getchar();
    fgets(message, BUFLEN, stdin);
    SendDatagram(s, message, (unsigned int)strlen(message), (struct sockaddr*)&si_other, slen);

    memset(buf, '\0', BUFLEN);
    RecvDatagram(s, buf, BUFLEN, (struct sockaddr*)&si_other, &slen);
    printf("Received response: %s\n", buf);

    closesocket(s);
    WSACleanup();
}

int main(int argc, char* argv[])
{
    WSAInit();
    if (argc < 2) 
    {
        printf("Please specify 'server' or 'client' as an argument.\n");
        return 1;
    }

    if (strcmp(argv[1], "server") == 0) {
        StartServer();
    }
    else if (strcmp(argv[1], "client") == 0) 
        StartClient();
    else 
        printf("Invalid argument. Please specify 'server' or 'client'.\n");
    return 0;
}
