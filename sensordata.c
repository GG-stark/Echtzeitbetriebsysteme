#include "sensordata.h"
#include <stdio.h>

// Simuliert das Auslesen der Sensordaten (Testdaten)
void readSensorData(sbusdata* data) {
    sdata_init(data);
    data->sgroups.sX = 0x10;    // Beispiel: X-Sensor bei Position 5 aktiv
    
    data->sgroups.sYu = 0x02;   // Beispiel: Y-Sensor unten Position 2 aktiv
    data->sgroups.sZ = 0x01;    // Z = 1 (im Fach)
    data->sgroups.sL = 0x01;    // Lichtschranke 1 aktiv
    data->sgroups.sLt = 0;      // Lichttaster nicht aktiv
}
