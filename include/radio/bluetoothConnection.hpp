#pragma once
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <iostream>
#include <unistd.h>

namespace BLUETOOOTH{

    class BluetoothConnection {
    public:
        BluetoothConnection();
        ~BluetoothConnection();
        bool connectToDevice(const std::string& deviceAddress, uint8_t channel = 1);  // Renombrado
        void disconnect();
        bool isConnected() const;

    private:
        int sock;
        struct sockaddr_rc addr;
        bool connected;
    };

}