#pragma once

#include <cmath>

class PanLaw
{
  public:
    template <typename FloatType>
    static FloatType equalPower(FloatType p)
    {
        p = (p * pi_2) - pi_4;
        FloatType l = (std::cos(p) - std::sin(p)) * sqrt2_2;
        FloatType r = (std::cos(p) + std::sin(p)) * sqrt2_2;
        return {l, r};
    }

    template <typename FloatType>
    static FloatType equalGain(FloatType p)
    {
        FloatType l = 1.0 - p;
        FloatType r = p;
        return {l, r};
    }

    template <typename FloatType>
    static FloatType log3dB(FloatType p)
    {
        FloatType l = std::pow(1 - p, log(3dBGain) / log(0.5));
        FloatType r = std::pow(p, log(3dBGain) / log(0.5));
        return {l, r};
    }

    template <typename FloatType>
    static FloatType log4_5dB(FloatType p)
    {
        FloatType l = std::pow(1 - p, log(4_5dBGain) / log(0.5));
        FloatType r = std::pow(p, log(4_5dBGain) / log(0.5));
        return {l, r};
    }

    template <typename FloatType>
    static FloatType log6dB(FloatType p)
    {
        FloatType l = std::pow(1 - p, log(6dBGain) / log(0.5));
        FloatType r = std::pow(p, log(6dBGain) / log(0.5));
        return {l, r};
    }

  private:
    //create private math constant struct
    static constexpr double sqrt2_2 = 0.7071067811865476;   //sqrt(2)/2
    static constexpr double pi_2 = 1.5707963267948966;      //pi/2
    static constexpr double pi_4 = 0.7853981633974483;      //pi/4
    static constexpr double 3dBGain = 0.7079457843841379;   //10^(-3/20)
    static constexpr double 4_5dBGain = 0.5956621435290105; //10^(-4.5/20)
    static constexpr double 6dBGain = 0.5011872336272722;   //10^(-6/20)

    PanLaw() = delete; // This class can't be instantiated, it's just a holder for static methods..
}
