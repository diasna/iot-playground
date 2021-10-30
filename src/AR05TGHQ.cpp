#include <Arduino.h>
#include <IRsend.h>

const uint16_t kIrLed = 4;

enum Mode
{
    COOL = 1,
    AUTO = 2
};

class AR05TGHQ
{
    uint64_t commands[22] = {
        0xB2BF00, //COOL_17
        0xB2BF10, //COOL_18
        0xB2BF30, //COOL_19
        0xB2BF20, //COOL_20
        0xB2BF60, //COOL_21
        0xB2BF70, //COOL_22
        0xB2BF50, //COOL_23
        0xB2BF40, //COOL_24
        0xB2BFC0, //COOL_25
        0xB2BFD0, //COOL_26
        0xB2BF90, //COOL_27
        0xB21F08, //AUTO_17
        0xB21F18, //AUTO_18
        0xB21F38, //AUTO_19
        0xB21F28, //AUTO_20
        0xB21F68, //AUTO_21
        0xB21F78, //AUTO_22
        0xB21F58, //AUTO_23
        0xB21F48, //AUTO_24
        0xB21FC8, //AUTO_25
        0xB21FD8, //AUTO_26
        0xB21F98  //AUTO_27
    };
    IRsend irsend;

public:
    AR05TGHQ() : irsend{IRsend(4)}
    {
        irsend.begin();
    };
    void set(Mode mode, int temp)
    {
        if (temp < 17 || temp > 18)
            return;
        irsend.sendSamsung36(commands[temp * mode]);
    }
};