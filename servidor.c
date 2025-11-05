#include <stdio.h>     
#include <stdlib.h>   
#include <string.h>    // Necesario para memset y strlen
#include <winsock2.h>  // Necesario para sockets en Windows
#include <ws2tcpip.h>  // Necesario para funciones de red

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsaData;
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in servaddr, cliaddr;
    int len;
    int n;

    // Inicializar Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("Error al inicializar Winsock");
        return EXIT_FAILURE;
    }

    // Crear el socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Error al crear el socket");
        WSACleanup();
        return EXIT_FAILURE;
    }

    // Inicializar la dirección del servidor
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;            // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;    // Aceptar conexiones de cualquier IP
    servaddr.sin_port = htons(PORT);          // Convertir el puerto al formato de red

    // Enlazar el socket con la dirección del servidor
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error en el bind");
        closesocket(sockfd);
        WSACleanup();
        return EXIT_FAILURE;
    }

    len = sizeof(cliaddr);

    while (1) {
        // Recibir datos del cliente (bloqueante)
        n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&cliaddr, &len);
        if (n < 0) {
            perror("Error al recibir datos");
            break;
        }

        buffer[n] = '\0'; // Añadir un terminador de cadena al final del mensaje recibido
        printf("Cliente : %s\n", buffer);

        // Enviar una respuesta al cliente (bloqueante)
        if (sendto(sockfd, buffer, n, 0, (struct sockaddr *)&cliaddr, len) < 0) {
            perror("Error al enviar respuesta");
            break;
        }
    }

    closesocket(sockfd);
    WSACleanup(); // Limpiar Winsock
    return 0;
}
