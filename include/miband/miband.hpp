#pragma once

#include <string>

namespace BLUETOOTH{
    class BluetoothConnection;
}

namespace XIAOMI{
    class MiBand {
    public:
        MiBand(const std::string& address);
        ~MiBand();
        bool connect();
        void disconnect();
        bool isConnected() const;

    private:
        BLUETOOOTH::BluetoothConnection bluetoothConnection;
        std::string deviceAddress;
    };
}
// MIBAND_HPP
