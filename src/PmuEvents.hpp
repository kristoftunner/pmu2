#ifndef DEMO_EVENT_HH__
#define DEMO_EVENT_HH__

#include "Events.hpp"
namespace Pmu
{
enum class PmuEvents {
  READ_DATA_DONE,
  ALGO1_DONE,
  ALGO2_DONE,
  DDC_DONE,
  ZMQ_DONE,
};

class DataReadyEvent : public Event<PmuEvents>
{
public:
  DataReadyEvent() : Event<PmuEvents>(PmuEvents::READ_DATA_DONE, "Read PMU data"){};
  virtual ~DataReadyEvent() = default;
};

class DDCReadyEvent : public Event<PmuEvents>
{
public:
  DDCReadyEvent() : Event<PmuEvents>(PmuEvents::DDC_DONE, "DDC algo is done"){};
  virtual ~DDCReadyEvent() = default;
};

class  AlgoFFTEvent: public Event<PmuEvents>
{
public:
  AlgoFFTEvent() : Event<PmuEvents>(PmuEvents::ALGO1_DONE, "FFT algo is done"){};
  virtual ~AlgoFFTEvent() = default;
};
}//namespace Pmu
#endif
