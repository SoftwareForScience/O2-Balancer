// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.
#include "O2/FLP/Utils.h"
#include <cmath>
#include <random>

using namespace O2;

int FLP::generateSineSize(int average, O2::Balancer::heartbeatID heartbeat) {
    const auto res = std::sin(heartbeat) * 2;

    return (res > 0)? res * average : - res * average ;
}

std::default_random_engine generator;

int FLP::generateRandomSize(int average) {
    std::uniform_real_distribution<float> distribution(average * 0.5f, average * 1.5f);
    return (int) distribution(generator);
}
