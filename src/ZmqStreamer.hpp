#include "zmq.hpp"
#include "zmq_addon.hpp"
#include "Log.hpp"
#include "Base.hpp"

namespace Pmu{

class ZmqStreamer
{
public:
    ZmqStreamer();
    ~ZmqStreamer();
    void Tick();
    void Connect();

private:
    zmq::context_t _context;
    zmq::socket_t _socket;
    
};
}