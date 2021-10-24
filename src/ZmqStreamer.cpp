#include "ZmqStreamer.hpp"

namespace Pmu{

ZmqStreamer::ZmqStreamer()
    :   _context(1), 
        _socket(_context,zmq::socket_type::pub)
{}

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

void ZmqStreamer::Tick()
{
    
}

}//namespace Pmu