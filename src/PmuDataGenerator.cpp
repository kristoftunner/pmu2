#include "PmuDataGenerator.hpp"

#include <chrono>
#include <thread>

using namespace std::literals::chrono_literals;

namespace Pmu{

PmuDataGenerator::PmuDataGenerator()
{
    adData = std::make_shared<std::vector<chData>>();
    adData->reserve(4000);
    adHeader = std::make_shared<struct pmuHeader>();
}

void PmuDataGenerator::GenerateData()
{
    adHeader->ctrl = 1;
    std::time_t t1 = std::time(0);
    adHeader->unixTime = int32_t(t1);
    adHeader->reserverd0 = 0;
    adHeader->reserved1 = 0;
    adHeader->tAcc = 0;
    adHeader->lon = 19040550;
    adHeader->lat = 47498138;
    adHeader->reserved2 = 0;
    adHeader->reserved3 = 0;
    adHeader->adcId = 0;
    adHeader->adcMode = 0;
    adHeader->adcGain1 = 0;
    adHeader->adcGain2 = 0;
    adHeader->adcCfg = 0;

    struct chData data;
    for(int i = 0; i < 4000; i++)
    {
        data.ch0 = i;   
        data.ch1 = i;   
        data.ch2 = i;   
        data.ch3 = i;   
        data.ch4 = i;   
        data.ch5 = i;
        adData->push_back(data);
    }
}

void PmuDataGenerator::Tick()
{
    if(this->_dispatcher != nullptr)
    {
        while(true)
        {
            GenerateData();
            PMU_CORE_INFO("Dispatched data!");
            this->_dispatcher->post(_event);
            std::this_thread::sleep_for(500ms);
        }
    }
}
}