#include "positionsbest.h"
#include <stdio.h>

// Berechnet die Position anhand der neuen Logik für Y (yo/yu)
void positionBestimmen(const sbusdata* sdata, Position* pos) {
    pos->x = 0;
    pos->y = 0;
    pos->z = sdata->sgroups.sZ;

    // X-Position ermitteln (wie gehabt)
    for (int i = 0; i < 10; ++i) {
        if ((sdata->sgroups.sX >> i) & 1) {
            pos->x = i + 1;
            break;
        }
    }

    int yo_found = 0;
    int yu_found = 0;

    // Yo-Schleife (y oben)
    for (int i = 0; i < 5; ++i) {
        if ((sdata->sgroups.sYo >> i) & 1) {
            pos->y = (i + 1) * 2;     // y = yo*2
            yo_found = 1;
            break; // falls mehrere, nur das erste
        }
    }

    // Yu-Schleife (y unten), nur wenn kein yo aktiv
    if (!yo_found) {
        for (int i = 0; i < 5; ++i) {
            if ((sdata->sgroups.sYu >> i) & 1) {
                pos->y = (i + 1) * 2 - 1; // y = yu*2-1
                yu_found = 1;
                break;
            }
        }
    }

    // Wenn weder yo noch yu gefunden (beide = 0)
    if (!yo_found && !yu_found) {
        pos->y = 0; // oder ein besonderer Wert, z.B. "nicht erkannt"
    }

    printf("[Positionsbestimmung] X=%d, Y=%d, Z=%d\n", pos->x, pos->y, pos->z);
}
