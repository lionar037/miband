#include <config/config.hpp>
#include <bluetooth/bluetoothConnection>
#include <miband/miband.hpp>
#include <iostream>


int main() {
    // Dirección MAC de la Mi Band (reemplazar con la dirección correcta)
    std::string deviceAddress = ADDRESS_MIBAND ; // Dirección de la Mi Band

    MiBand miBand(deviceAddress);

    if (miBand.connect()) {
        // Aquí puedes añadir código para interactuar con la Mi Band
        std::cout << "Mi Band conectada con éxito." << std::endl;

        // Luego de interactuar, desconectamos
        miBand.disconnect();
    } else {
        std::cerr << "No se pudo conectar a la Mi Band." << std::endl;
    }

    return 0;
}
