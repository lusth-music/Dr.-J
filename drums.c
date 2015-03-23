#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/drums-hihat/"
#define base "osd-open_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "drums";
char *PROGRAM_VERSION = "0.01";

void intro(void);
void verse(void);
void refrain(void);
void bridge(void);

int instrument;
double stride;

int
main()
    {
    songInit();

    instrument = readScale(dir,base);


    setStride(0.10);
    setSustain(0.99996);
    setAmplitude(0.1);

    openOutput("drums.rra",0,0);

    #include "song"

    closeOutput();

    return 0;
    }

void
bridge()
    {
    rest(measuresToBeats(14));
    }
void
refrain()
    {
    rest(measuresToBeats(10));
    }

void
intro(void)
    {
    rest(measuresToBeats(10));

    checkMeasure();
    }

void
verse(void)
    {
    int spot;

    rest(measuresToBeats(2));

    spot = getLocation();
    drumkitCrash   (2,1,"----",SX); setLocation(spot);
    drumkitHHClosed(2,0.5,"xXxx",SX); setLocation(spot);
    drumkitSnare   (2,1,"-x-v",SX); setLocation(spot);
    drumkitKick    (2,3,"X-X-",SX);
    spot = getLocation();
    drumkitCrash   (3,1,"----","--g-","----","x---",SX); setLocation(spot);
    drumkitHHClosed(3,0.5,"xxXx","xxxX","Xxxx","xXxx",SX); setLocation(spot);
    drumkitSnare   (3,1,"-x-v","v-x-","v-x-","^x^v",SX); setLocation(spot);
    drumkitKick    (3,3,"X-X-","X-X-","X-XX","X-X-XxX-",SX);
    backwards(measuresToBeats(1));

    checkMeasure();
    }
