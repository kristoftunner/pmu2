#include "PmuDataGenerator.hpp"
#include "ZmqStreamer.hpp"
#include "Dispatcher.hpp"
#include "PmuEvents.hpp"

int main()
{
    Pmu::PmuDataGenerator p;
    Pmu::ZmqStreamer streamer;
    Pmu::Log logger;
    logger.Init();
    
    std::shared_ptr<Pmu::Dispatcher<Pmu::PmuEvents>> dispatcher1 = std::make_shared<Pmu::Dispatcher<Pmu::PmuEvents>>();
    streamer.Connect();
    p.GetDispatcher(dispatcher1);
    p.Tick();    
}