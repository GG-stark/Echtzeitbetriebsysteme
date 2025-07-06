#include <vxWorks.h>
#include <pipeDrv.h>
#include <ioLib.h>
#include <stdio.h>
#include <strLib.h>
#include <taskLib.h>

void start_empfaenger(void) {
    int fd = open("/pipe/test", O_RDONLY, 0);
    if (fd == ERROR) {
        printf("Empfaenger: Fehler beim Öffnen der Pipe.\n");
        return;
    }
    
    for (int i = 0; i < 30; i++) {
    	taskDelay(100);
    	
    	int bytes = 0;
    	if (ioctl(fd, FIONREAD, &bytes) == ERROR) {
    		printf("ERROR: ioctl failed!\n");
    		continue;
    	}
    	
    	if (bytes <= 0) {
    		printf("Empfaenger: keine Nachricht vorhanden\n");
    		continue;
    	}
    	
    	char buffer[100];
    	read(fd, buffer, sizeof(buffer));
    	printf("Empfaenger: Nachricht erhalten: %s\n", buffer);
    }

    close(fd);
}
