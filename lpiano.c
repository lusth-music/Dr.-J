#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
#define base "piano/bright_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "rpiano";
char *PROGRAM_VERSION = "0.01";

void intro(void);
void verse(void);
void refrain(void);
void bridge(void);

int octave = 3;
int instrument;
double stride;

int
main()
    {
    songInit();

    instrument = readScale(dir,base);

    setStride(0.10);
    setSustain(0.99996);
    setAmplitude(0.2);

    openOutput("lpiano.rra",0,0);

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
    b(1,Qd,instrument,octave,"x-x","-x-",SX);
    b(5,Qd,instrument,octave-1,"x-x","-x-",SX);
    b(6,Qd,instrument,octave-1,"x-x","-x-",SX);
    b(4,Qd,instrument,octave-1,"xx-","--x",SX);
    c(4,Qd,instrument,octave-1);
    c(5,Qd,instrument,octave-1);

    rest(H);

    b(1,Qd,instrument,octave,"-x-","x-x",SX);
    b(5,Qd,instrument,octave-1,"-x-","x-x",SX);
    b(6,Qd,instrument,octave-1,"--x","xx-",SX);
    b(4,Qd,instrument,octave-1,"x--","-xx",SX);
    c(5,Qd,instrument,octave-1);
    c(5,Qd,instrument,octave-1);

    rest(H);

    b(1,Qd,instrument,octave,"x-x","-x-",SX);
    b(5,Qd,instrument,octave-1,"x-x","-x-",SX);
    b(6,Qd,instrument,octave-1,"x-x","-x-",SX);
    b(4,Qd,instrument,octave-1,"x-x","-x-",SX);
    c(5,Qd,instrument,octave-1);
    c(5,Qd,instrument,octave-1);

    rest(H);

    softer(2);
    ci3(1,W,instrument,octave);
    louder(2);
    backwards(W);

    n(1,Q,instrument,octave,1);
    n(1,Q,instrument,octave,2);
    n(1,Q,instrument,octave,1);
    n(1,Q,instrument,octave,0);
    ci4(1,Hd,instrument,octave);


    checkMeasure();
    }

void
intro(void)
    {
    rest(Q);
    n(1,H,instrument,octave-1,7);
    n(4,Hd,instrument,octave-1,0);
    n(4,Hd,instrument,octave-1,4);

    rest(Q);
    n(6,H,instrument,octave-1,-2);
    n(5,Hd,instrument,octave-1,0);
    n(5,W,instrument,octave-1,4);

    rest(Q);
    n(6,H,instrument,octave-1,3);
    n(6,Hd,instrument,octave-1,0);
    n(4,Hd,instrument,octave-1,0);

    rest(Q);
    n(6,H,instrument,octave-1,2);
    n(5,Hd,instrument,octave-1,0);
    n(1,W,instrument,octave-1,7);

    rest(H);

    checkMeasure();
    }

void
verse(void)
    {
    b(1,W,instrument,octave,"-x-","-x-","-x-","-n-",SX);
    b(4,W,instrument,octave-1,"--x","-x-","--x","--n",SX);
    b(6,W,instrument,octave-1,"--x","-x-","x--","q--",SX);
    b(5,W,instrument,octave-1,"x--","x--","--x","--n",SX);

    b(1,W,instrument,octave,"--x","-x-","--x","x--",SX);
    b(6,W,instrument,octave-1,"x--","-x-","x--","-n-",SX);
    b(4,W,instrument,octave-1,"x--","-x-","-x-","--x",SX);
    b(2,W,instrument,octave-1,"x--","x--","x--","-x-",SX);

    b(1,W,instrument,octave,"-x-","x--","-x-","--x",SX);
    b(4,W,instrument,octave-1,"x--","--x","-x-","--x",SX);
    b(6,W,instrument,octave-1,"x--","-p-","x--","--x",SX);
    b(5,W,instrument,octave-1,"x--","x--","--x","x--",SX);

    b(6,W,instrument,octave-1,"x--","-p-","x--","--x",SX);
    b(4,W,instrument,octave-1,"x--","-p-","-x-","--n",SX);
    b(1,W,instrument,octave,"-x-","-m-","-x-","--x",SX);
    ci4(5,W,instrument,octave-1);

    checkMeasure();
    }
