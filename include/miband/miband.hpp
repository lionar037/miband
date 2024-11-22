#pragma once
#include  <radio/bluetoothConnection.hpp>

class MiBand {
public:
    MiBand(const std::string& address);
    ~MiBand();
    bool connect();
    void disconnect();
    bool isConnected() const;

private:
    BluetoothConnection bluetoothConnection;
    std::string deviceAddress;
};

// MIBAND_HPP
