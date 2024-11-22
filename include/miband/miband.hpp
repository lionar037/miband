#ifndef MIBAND_HPP
#define MIBAND_HPP

#include  <bluetooth/bluetoothConnection.hpp>

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

#endif // MIBAND_HPP
