#pragma once
#include  <radio/bluetoothConnection.hpp>

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
