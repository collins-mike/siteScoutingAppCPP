#include "specan.h"
#include "bb_api.h"


Specan::Specan()
{

}

bool Specan::findSpecan()
{
    bbStatus openStatus = bbOpenDevice(&handle);
    if(openStatus != bbNoError) {
        return false;
    }
    return true;
}

