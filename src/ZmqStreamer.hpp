#include <vector>

#include "zmq.hpp"
#include "zmq_addon.hpp"
#include "Log.hpp"
#include "Base.hpp"
#include "PmuData.hpp"

namespace Pmu{

class ZmqStreamer
{
public:
    ZmqStreamer();
    ~ZmqStreamer();
    void Tick();
    void Connect();
    void SetupPtrs(SPtr<std::vector<chData>> dataptr, SPtr<pmuHeader> headerptr);
private:
    zmq::context_t _context;
    zmq::socket_t _socket;
    SPtr<struct pmuHeader> adHeader;
    SPtr<std::vector<chData>> adData; 
};
}