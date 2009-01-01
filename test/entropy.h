// $Id$
// Copyright (c) 2008 Oliver Lau <ola@ctmagazin.de>, Heise Zeitschriften Verlag.
// Alle Rechte vorbehalten.

#ifndef __ENTROPY_H_
#define __ENTROPY_H_

#ifdef _DEBUG
#include <iostream>
#include <iomanip>
#endif

#include <cstdlib>
#include <vector>
#include <cmath>
#include <cassert>

#include "math_functions.h"

namespace ctrandom {

    /// Ermitteln der Entropie einer Zufallszahlenfolge.
    /// @param ran Zufallszahlenfolge
    /// @param _min kleinstm�glicher Wert in der Zufallszahlenfolge
    /// @param _max gr��tm�glicher Wert in der Zufallszahlenfolge
    /// @return Entropie in Bits pro Bit.
    template <typename VariateType>
    double entropy_test(const std::vector<VariateType>& ran, const VariateType _min, const VariateType _max)
    {
        assert(_max > _min);
        assert(ran.size() > 100);
        size_t range = (size_t) (_max - _min);
        std::vector<size_t> histo(range, 0);
        for (size_t i = 0; i < ran.size(); ++i)
            ++histo[ran[i]];
        double ent = 0.0;
        for (size_t i = 0; i < range; ++i)
        {
            double p = (double) histo[i] / ran.size();
            if (p > 0.0)
                ent += p * M_LOG2E * log(1.0 / p);
        }
        double bitsPerVariate = log((double) range) * M_LOG2E;
#ifdef _DEBUG
        std::cout << "bitsPerVariate = " << std::setprecision(20) << bitsPerVariate << std::endl;
#endif
        return ent / bitsPerVariate;
    }

};

#endif // __ENTROPY_H_