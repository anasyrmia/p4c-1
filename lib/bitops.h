/*
Copyright 2013-present Barefoot Networks, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef P4C_LIB_BITOPS_H_
#define P4C_LIB_BITOPS_H_

#include "gmputil.h"
#include "bitvec.h"

static inline unsigned bitmask2bytemask(const bitvec &a) {
    int max = a.max().index();
    if (max < 0) return 0;
    unsigned rv = 0;
    for (unsigned i = 0; i <= max/8U; i++)
        if (a.getrange(i*8, 8))
            rv |= 1 << i;
    return rv;
}

#endif /* P4C_LIB_BITOPS_H_ */
