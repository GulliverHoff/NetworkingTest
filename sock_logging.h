#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

void PrintWSAData(const WSADATA& data)
{
    std::cout << "=== WSADATA ===" << std::endl;

    // Print version info
    std::cout << "wVersion: "
              << (data.wVersion & 0xFF) << "."
              << ((data.wVersion >> 8) & 0xFF)
              << std::endl;

    std::cout << "wHighVersion: "
              << (data.wHighVersion & 0xFF) << "."
              << ((data.wHighVersion >> 8) & 0xFF)
              << std::endl;

#ifdef _WIN64
    // On 64-bit Windows, these fields may not be populated (depends on SDK).
    std::cout << "iMaxSockets: " << data.iMaxSockets << std::endl;
    std::cout << "iMaxUdpDg: " << data.iMaxUdpDg << std::endl;
#else
    // On 32-bit Windows you usually get full fields
    std::cout << "szDescription: " << data.szDescription << std::endl;
    std::cout << "szSystemStatus: " << data.szSystemStatus << std::endl;
    std::cout << "iMaxSockets: " << data.iMaxSockets << std::endl;
    std::cout << "iMaxUdpDg: " << data.iMaxUdpDg << std::endl;
#endif

    std::cout << "================" << std::endl;
}
