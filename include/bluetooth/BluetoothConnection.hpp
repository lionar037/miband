#ifndef BLUETOOTH_CONNECTION_HPP
#define BLUETOOTH_CONNECTION_HPP

#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <iostream>
#include <unistd.h>

class BluetoothConnection {
public:
    BluetoothConnection();
    ~BluetoothConnection();
    bool connect(const std::string& deviceAddress, uint8_t channel = 1);
    void disconnect();
    bool isConnected() const;

private:
    int sock;
    struct sockaddr_rc addr;
    bool connected;
};

#endif // BLUETOOTH_CONNECTION_HPP
