# Comunicación Cliente-Servidor con Sockets No Bloqueantes (UDP)

Este repositorio contiene las **Prácticas 3 y 4** de la asignatura **Aplicaciones para Comunicaciones en Red (6CV2)**, impartida en la **Escuela Superior de Cómputo (ESCOM)** del **Instituto Politécnico Nacional (IPN)**.  
Ambas prácticas se enfocan en la **implementación de sockets no bloqueantes** usando el protocolo **UDP (User Datagram Protocol)**, aplicados en entornos **cliente-servidor** mediante los lenguajes **Java** y **C**.

---

## Práctica 3 — Sockets No Bloqueantes con UDP en Java

### Descripción
En esta práctica se implementa una comunicación **cliente-servidor** con **sockets no bloqueantes** en **Java**, utilizando el protocolo **UDP**.  
El objetivo es enviar y recibir archivos de manera eficiente mediante el uso de **DatagramChannel** y **Selector**, evitando que las operaciones de entrada/salida bloqueen la ejecución del programa:contentReference[oaicite:0]{index=0}.

### Objetivo
Aprender a desarrollar aplicaciones concurrentes y de alta velocidad usando **UDP no bloqueante**, optimizando el rendimiento en entornos donde la latencia es crítica (por ejemplo, mensajería o transmisión en tiempo real).

### Archivos principales
- `UDPFileServer.java` — Servidor que recibe archivos mediante `DatagramChannel` y `Selector`.
- `UDPFileClient.java` — Cliente que envía archivos en bloques hacia el servidor.

### Funcionamiento
El servidor se mantiene activo de forma continua, procesando datagramas en tiempo real y escribiendo su contenido en un archivo local (`archivorecibido.txt`).  
El cliente lee un archivo de origen y envía sus datos al servidor sin bloquearse entre cada envío:contentReference[oaicite:1]{index=1}.

### Lenguaje y herramientas
- **Lenguaje:** Java  
- **Bibliotecas:** `java.nio`, `DatagramChannel`, `Selector`, `ByteBuffer`  
- **Protocolo:** UDP  
- **Analizador de red:** Wireshark  

### Ejecución
```bash
# Compilación
javac UDPFileServer.java
javac UDPFileClient.java

# Ejecución
java UDPFileServer
java UDPFileClient archivo.txt
