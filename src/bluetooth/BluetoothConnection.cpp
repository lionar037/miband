#include <bluetooth/BluetoothConnection.hpp>


BluetoothConnection::BluetoothConnection() : sock(-1), connected(false) {
    // Inicializar la dirección
    addr = { 0 };
    addr.rc_family = AF_BLUETOOTH;
}

BluetoothConnection::~BluetoothConnection() {
    if (connected) {
        disconnect();
    }
}

bool BluetoothConnection::connect(const std::string& deviceAddress, uint8_t channel) {
    bdaddr_t bdaddr;
    
    // Convertir la dirección MAC de string a bdaddr_t
    str2ba(deviceAddress.c_str(), &bdaddr);

    // Crear el socket RFCOMM
    sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    if (sock == -1) {
        std::cerr << "Error creando socket Bluetooth" << std::endl;
        return false;
    }

    addr.rc_channel = channel;
    addr.rc_bdaddr = bdaddr;

    // Intentar conectar al dispositivo
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        std::cerr << "Error conectando al dispositivo" << std::endl;
        close(sock);
        sock = -1;
        return false;
    }

    connected = true;
    std::cout << "Conectado a la Mi Band" << std::endl;
    return true;
}

void BluetoothConnection::disconnect() {
    if (sock != -1) {
        close(sock);
        sock = -1;
        connected = false;
        std::cout << "Desconectado de la Mi Band" << std::endl;
    }
}

bool BluetoothConnection::isConnected() const {
    return connected;
}
