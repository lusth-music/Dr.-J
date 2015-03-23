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

int octave = 4;
int instrument;
double stride;

int
main()
    {
    songInit();

    instrument = readScale(dir,base);

    setStride(0.10);
    setSustain(0.99996);
    setAmplitude(0.4);

    openOutput("rpiano.rra",0,0);

    #include "song"

    closeOutput();

    return 0;
    }

void
refrain()
    {
    ci3(1,Qd,instrument,octave-1);
    ci1(5,Qd,instrument,octave-1);
    ci1(6,Qd,instrument,octave-1);
    ci2(4,Qd,instrument,octave-1);
    ci2(4,Qd,instrument,octave-1);
    ci1(5,Qd,instrument,octave-1);

    rest(H);

    ci3(1,Qd,instrument,octave-1);
    ci2(5,Qd,instrument,octave-1);
    ci2(6,Qd,instrument,octave-1);
    ci2(4,Qd,instrument,octave-1);
    ci1(5,Qd,instrument,octave-1);
    ci2(5,Qd,instrument,octave-1);

    rest(H);

    ci2(1,Qd,instrument,octave);
    ci2(5,Qd,instrument,octave-1);
    ci3(6,Qd,instrument,octave-1);
    ci3(4,Qd,instrument,octave-1);
    ci2(5,Qd,instrument,octave-1);
    ci1(5,Qd,instrument,octave-1);

    rest(H);

    softer(2);
    c(1,W,instrument,octave);
    louder(2);
    backwards(W);

    n(1,Q,instrument,octave,1);
    n(1,Q,instrument,octave,2);
    n(1,Q,instrument,octave,1);
    n(1,Q,instrument,octave,0);
    c(1,Hd,instrument,octave);


    checkMeasure();
    }

void
intro(void)
    {
    setBrokenAmplitudes(1.0,0.8,1.0,DX);
    b(1,Hd,instrument,octave,"-x-","--x","x--",SX);
    ci2(4,Hd,instrument,octave-1);
    softer(2);
    stride = setStride(0);
    ci2(4,Hd,instrument,octave-1);
    setStride(stride);
    louder(2);

    b(6,Hd,instrument,octave-1,"-x-","x--","--x",SX);
    ci2(5,Hd,instrument,octave-1);
    softer(2);
    stride = setStride(0);
    ci2(5,W,instrument,octave-1);
    setStride(stride);
    louder(2);

    b(6,Hd,instrument,octave-1,"--x","-n-","-x-",SX);
    ci6(6,Hd,instrument,octave-1);
    softer(2);
    stride = setStride(0);
    ci6(4,Hd,instrument,octave-1);
    setStride(stride);
    louder(2);

    b(6,Hd,instrument,octave-1,"x--","--x","-x-",SX);
    c(5,Hd,instrument,octave-1);
    softer(2);
    stride = setStride(0);
    c(1,W,instrument,octave-1);
    setStride(stride);
    louder(2);


    rest(H);

    checkMeasure();
    }

void
verse(void)
    {
    setBrokenAmplitudes(1.0,1.0,0.75,0.8,DX);
    b(1,W,instrument,octave,"xxx","-x-","xxx","-n-",SX);
    b(4,W,instrument,octave-1,"xxx","--x","xxx","--n",SX);
    b(6,W,instrument,octave-1,"xxx","-x-","xxx","--x",SX);
    b(5,W,instrument,octave-1,"xxx","--n","xxx","-n-",SX);

    /* second line */

    b(1,W,instrument,octave,"xxx","-x-","xxx","--p",SX);
    b(6,W,instrument,octave-1,"xxx","--n","xxx","--p",SX);
    b(4,W,instrument,octave-1,"xxx","-x-","xxx","--x",SX);
    b(2,W,instrument,octave-1,"xxx","-n-","xxx","--m",SX);

    /* third line */

    b(1,W,instrument,octave,"xxx","-n-","xxx","n--",SX);
    b(4,W,instrument,octave-1,"xxx","-p-","xxx","--p",SX);
    b(6,W,instrument,octave-1,"xxx","-n-","xxx","-p-",SX);
    b(5,W,instrument,octave-1,"xxx","--n","xxx","-n-",SX);

    /* fourth line */

    b(6,W,instrument,octave-1,"xxx","-n-","xxx","-p-",SX);
    b(4,W,instrument,octave-1,"xxx","-p-","xxx","--p",SX);
    b(1,W,instrument,octave,"xxx","-n-","xxx","n--",SX);
    c(5,W,instrument,octave-1);

    checkMeasure();
;
    }

void
bridge(void)
    {
    setBrokenAmplitudes(1.0,0.8,1.0,DX);
    b(1,W,instrument,octave,"-x-","--x","---x",SX);
    softer(2);
    ci2(4,W,instrument,octave-1);
    louder(2);
    b(6,W,instrument,octave-1,"---x","--x-","-x",SX);
    softer(2);
    ci2(5,W,instrument,octave-1);
    louder(2);
    b(6,W,instrument,octave-1,"---x","--n-","-n-",SX);
    softer(2);
    ci6(6,W,instrument,octave-1);
    louder(2);
    b(6,W,instrument,octave-1,"-x-","---x","--x",SX);
    softer(2);
    c(5,W,instrument,octave-1);
    softer(2);
    stride = setStride(0);
    c(6,W,instrument,octave-1);
    setStride(stride);
    louder(2);
    louder(2);

    b(6,W,instrument,octave-1,"---x","--n-","-n-",SX);
    softer(2);
    ci6(6,W,instrument,octave-1);
    louder(2);
    b(6,W,instrument,octave-1,"-x-","---x","--x",SX);
    softer(2);
    c(4,W,instrument,octave-1);
    louder(2);
    b(6,W,instrument,octave-1,"-x-","---x","--x",SX);
    softer(2);
    c(5,W,instrument,octave-1);
    softer(2);
    stride = setStride(0);
    ci4(1,W,instrument,octave-1);
    setStride(stride);
    louder(2);
    louder(2);

    checkMeasure();
    }
