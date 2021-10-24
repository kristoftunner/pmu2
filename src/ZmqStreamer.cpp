#include "ZmqStreamer.hpp"

namespace Pmu{

ZmqStreamer::ZmqStreamer()
    :   _context(1), 
        _socket(_context,zmq::socket_type::pub)
{
    adHeader = std::make_shared<pmuHeader>();
    adData = std::make_shared<std::vector<chData>>();
    adData.reserve(4000);
}

ZmqStreamer::~ZmqStreamer()
{
    _socket.close();
    _context.close();
}

void ZmqStreamer::Connect()
{
    try{
        _socket.bind("tcp://127.0.0.1:5555");
        PMU_CORE_INFO("ZMQ: connected");
    }
    catch(const zmq::error_t& e)
    {
        PMU_CORE_ERROR("ZMQ: failed to connect");
        
    }
}

bool ZmqStreamer::SetupPtrsSPtr<std::vector<chData>> dataptr, SPtr<pmuHeader> headerptr);
{
    if(dataptr != nullptr && headerptr != nullptr)
    {
        adHeader = headerptr;
        adData = dataptr;
        return true;
    }
    else
    {
        return false;
    }
}

void ZmqStreamer::Tick()
{
    _socket.send()
}

}//namespace Pmu