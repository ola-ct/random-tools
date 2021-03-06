// $Id$
// Copyright (c) 2008 Oliver Lau <oliver@von-und-fuer-lau.de>
// Alle Rechte vorbehalten.

#include "rng-assessor.h"
#include "test/run-above-below.h"
#include "test/run-up-down.h"


////////////////////////////////////////////////////////////
/////
///// RUN TEST
/////
////////////////////////////////////////////////////////////
void test_runs(void)
{
    double p;

    if (!quiet)
        std::cout << "RUN TEST" << std::endl
                  << " ... Serien oberhalb des Median : " << std::flush;
    p = randomtools::run_above_test<variate_t>(r, r_min, r_max);
    if (!quiet)
        std::cout << "p = " << std::setprecision(5) << std::setw(9) << std::left << p << " "
                  << " " << (((alpha < p) && (p < (1-alpha)))? "OK" : "NICHT BESTANDEN")
                  << '.' << std::endl;

    if (!quiet)
        std::cout << " ... Serien unterhalb des Median: " << std::flush;
    p = randomtools::run_below_test<variate_t>(r, r_min, r_max);
    if (!quiet)
        std::cout << "p = " << std::setprecision(5) << std::setw(9) << std::left << p << " "
                  << " " << (((alpha < p) && (p < (1-alpha)))? "OK" : "NICHT BESTANDEN") << '.'
                  << std::endl << std::endl;
}
