// utility/src/version.cc
#include "version.h"

namespace dpm::version
{

const char* tag()
{
    return DPM_GIT_TAG;
}

const char* hash()
{
    return DPM_GIT_HASH;
}

}
