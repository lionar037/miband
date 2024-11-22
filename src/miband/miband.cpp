#include <miband/miband.hpp>

MiBand::MiBand(const std::string& address) : deviceAddress(address) {}

MiBand::~MiBand() {
    if (bluetoothConnection.isConnected()) {
        bluetoothConnection.disconnect();
    }
}

bool MiBand::connect() {
    return bluetoothConnection.connect(deviceAddress);
}

void MiBand::disconnect() {
    bluetoothConnection.disconnect();
}

bool MiBand::isConnected() const {
    return bluetoothConnection.isConnected();
}
