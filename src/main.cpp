#include <iostream>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <unistd.h>

int main() {
    struct sockaddr_rc addr = { 0 };
    int sock, status;
    bdaddr_t bdaddr;
    
    // Dirección MAC de la Mi Band (reemplazar con la MAC correcta)
    str2ba("08:16:d5:98:61:12", &bdaddr);
    
    // Crear socket Bluetooth
    sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    if (sock == -1) {
        std::cerr << "Error creando socket Bluetooth" << std::endl;
        return -1;
    }
    
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;  // El canal RFCOMM, puede variar según la configuración del dispositivo
    addr.rc_bdaddr = bdaddr;
    
    // Conectar al dispositivo
    status = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (status == -1) {
        std::cerr << "Error conectando con la Mi Band" << std::endl;
        close(sock);
        return -1;
    }
    
    std::cout << "Conectado a la Mi Band" << std::endl;
    
    // Aquí puedes añadir código para leer datos o enviar comandos a la Mi Band
    
    // Cerrar la conexión
    close(sock);
    
    return 0;
}
