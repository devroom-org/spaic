#pragma once

#define defineUnitUDLRaw(underscore, unitType)                                                    \
    CssUnit<CssUnitType::unitType> operator"" underscore##unitType(long double v) noexcept        \
    {                                                                                             \
        return CssUnit<CssUnitType::unitType>(v);                                                 \
    }                                                                                             \
    CssUnit<CssUnitType::unitType> operator"" underscore##unitType(unsigned long long v) noexcept \
    {                                                                                             \
        return CssUnit<CssUnitType::unitType>(v);                                                 \
    }
#define defineUnitUDL(unitType) defineUnitUDLRaw(_, unitType)

#include <string>

namespace spaic::css::unit
{
enum class CssUnitType
{
    em,
    ex,
    cap,
    ch,
    ic,
    rem,
    lh,
    rlh,
    vw,
    vh,
    vi,
    vb,
    vmin,
    vmax,
    cm,
    mm,
    q,
    in,
    pc,
    pt,
    px,
    deg,
    grad,
    rad,
    turn,
    s,
    ms,
    hz,
    khz,
    dpi,
    dpcm,
    dppx,
    percent
};
template <CssUnitType T>
class CssUnit
{
private:
    long double value;

public:
    CssUnit(long double value) noexcept;

    std::string toCssValue();
};

defineUnitUDL(em);
defineUnitUDL(ex);
defineUnitUDL(cap);
defineUnitUDL(ch);
defineUnitUDL(ic);
defineUnitUDL(rem);
defineUnitUDL(lh);
defineUnitUDL(rlh);
defineUnitUDL(vw);
defineUnitUDL(vh);
defineUnitUDL(vi);
defineUnitUDL(vb);
defineUnitUDL(vmin);
defineUnitUDL(vmax);
defineUnitUDL(cm);
defineUnitUDL(mm);
defineUnitUDL(q);
defineUnitUDL(in);
defineUnitUDL(pc);
defineUnitUDL(pt);
defineUnitUDL(px);
defineUnitUDL(deg);
defineUnitUDL(grad);
defineUnitUDL(rad);
defineUnitUDL(turn);
defineUnitUDL(s);
defineUnitUDL(ms);
defineUnitUDL(hz);
defineUnitUDL(khz);
defineUnitUDL(dpi);
defineUnitUDL(dpcm);
defineUnitUDL(dppx);
defineUnitUDL(percent);
} // namespace spaic::css::unit

#undef defineUnitUDLRaw
#undef defineUnitUDL

#include <spaic-css/detail/Unit.hpp>