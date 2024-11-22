//codigo main.cpp

#include <config/config.hpp>
#include <radio/bluetoothConnection.hpp>
#include <miband/miband.hpp>
#include <iostream>
#include <memory>

int main() {
    // Dirección MAC de la Mi Band (reemplazar con la dirección correcta)
    const std::string deviceAddress = ADDRESS_MIBAND ; // Dirección de la Mi Band

     auto miBand{std::make_unique<XIAOMI::MiBand>(deviceAddress)};

    if (miBand->connect()) {
        // Aquí puedes añadir código para interactuar con la Mi Band
        std::cout << "Mi Band conectada con éxito." << std::endl;

        // Luego de interactuar, desconectamos
        miBand->disconnect();
    } else {
        std::cerr << "No se pudo conectar a la Mi Band." << std::endl;
    }

    return 0;
}
