// $Id$
// Copyright (c) 2009 Oliver Lau <ola@ctmagazin.de>, Heise Zeitschriften Verlag.
// Alle Rechte vorbehalten.

#ifdef _WIN32

#include <windows.h>
#include "compat-win32.h"


bool hasRand_s(void) 
{
    OSVERSIONINFO os;
    GetVersionEx(&os);
    return (os.dwMajorVersion > 5) && (os.dwMinorVersion >= 1);
}

#endif
