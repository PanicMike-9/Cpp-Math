#pragma once

#include <cmath>
#include <cassert>

#include "vector2.hpp"

namespace geom
{

class Mat2
{
    public:
        static constexpr int COL {2};
        static constexpr int ROW {2};

        float data[COL][ROW];

        // default
        constexpr Mat2() noexcept
            : data
            {
                {1.0f, 0.0f}, // column 0
                {0.0f, 1.0f} // column 1
            }
        {}

        constexpr Mat2(float c0_r0, float c1_r0, float c0_r1, float c1_r1) noexcept
            : data
            {
                {c0_r0, c0_r1}, // column 0
                {c1_r0, c1_r1} // column 1
            }
        {}
};

} // namespace geom
