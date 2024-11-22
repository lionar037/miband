#include <miband/miband.hpp>

namespace XIAOMI{

    MiBand::MiBand(const std::string& address) : deviceAddress(address) {}

    MiBand::~MiBand() {
        if (bluetoothConnection.isConnected()) {
            bluetoothConnection.disconnect();
        }
    }

    bool MiBand::connect() {
        //return bluetoothConnection.connect(deviceAddress);
        return bluetoothConnection.connectToDevice(deviceAddress);

    }

    void MiBand::disconnect() {
        bluetoothConnection.disconnect();
    }

    bool MiBand::isConnected() const {
        return bluetoothConnection.isConnected();
    }
}