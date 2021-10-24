#include <iostream>
#include <vector>
#include <memory>

#include "Base.hpp"
#include "Dispatcher.hpp"
#include "PmuEvents.hpp"
#include "Log.hpp"
#include "PmuData.hpp"

namespace Pmu
{

class PmuDataGenerator{
public:
    PmuDataGenerator();
    ~PmuDataGenerator(){;}
    void Tick();
    void GenerateData();
    SPtr<std::vector<chData>> GetDataPtr(){return adData;}
    SPtr<struct pmuHeader> GetHeaderPtr(){return adHeader;}
    void GetDispatcher(SPtr<Dispatcher<PmuEvents>> dispatcher) {_dispatcher = dispatcher;}
private:
    void UpdateData();

    SPtr<struct pmuHeader> adHeader;
    SPtr<std::vector<chData>> adData;
    DataReadyEvent _event;
    SPtr<Dispatcher<PmuEvents>> _dispatcher;
};
}// namespace pmu