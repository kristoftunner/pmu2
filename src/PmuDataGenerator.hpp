#include <iostream>
#include <vector>

#include "Base.hpp"

namespace Pmu{
struct pmuHeader{
    uint8_t ctrl;
    uint8_t reserverd0;
    uint16_t reserved1;
    int32_t unixTime;
    uint32_t tAcc;
    int32_t lon;
    int32_t lat;
    uint64_t reserved2;
    uint16_t reserved3;
    uint16_t adcId;
    uint16_t adcMode;
    uint16_t adcGain1;
    uint16_t adcGain2;
    uint16_t adcCfg;
};

struct chData{
    int32_t ch0,ch1,ch2,ch3,ch4,ch5;
};

class PmuDataGenerator{
public:
    void Tick();

private:
    void UpdateData();

    Sptr<std::vector<pmuHeader>> adHeader;
    Sptr<std::vector<chData>> adData;
};
}// namespace pmu