#include <iostream>
#include <headers.h>
#include "sock_logging.h"

int main() {

    WSADATA wsa_data;
    
    // MAKEWORD(2, 2) => 0x 02 02 = 514
    int result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if(result != 0) {
        std::cerr << "WSAStartup failed: " << result << std::endl; 
        return 1;
    }

    PrintWSAData(wsa_data);

    SOCKET server_socket = INVALID_SOCKET;
    server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket == INVALID_SOCKET) {
        std::cerr << "Error creating socket: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return ~0;
    } else {
        std::cout << "socket() is OK!" << std::endl;
    }

    

    // create service (socket address)
    u_short port = 55555;

    sockaddr_in service{};
    service.sin_family = AF_INET;
    service.sin_port = htons(port);

#ifdef LOOPBACK_LISTEN  
    InetPtonA(AF_INET, "127.0.0.1", &service.sin_addr); // Loopback 127.0.0.1
#else
    service.sin_addr.s_addr = htonl(INADDR_ANY); // Any interface
#endif

    int bind_result = bind(server_socket, (SOCKADDR*)&service, sizeof(service));
    if(bind_result == SOCKET_ERROR) {
        std::cout << "bind() failed: " << WSAGetLastError() << std::endl;
        closesocket(server_socket);
        WSACleanup();
        return -1;
    } else {
        std::cout << "bind() is OK!" << std::endl;
    }
    
    int listen_result = listen(server_socket, 1);
    if(listen_result == SOCKET_ERROR) {
        std::cout << "listen(): Error listening on socket " << WSAGetLastError() << std::endl; 
    } else {
        std::cout << "listen() is OK! Waiting for connections..." << std::endl;
    }

    WSACleanup();
    return 0;
}