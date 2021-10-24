#ifndef DEMO_EVENT_HH__
#define DEMO_EVENT_HH__

#include "Event.hh"

enum class EventType1 {
  READ_DONE,
  ALGO1_DONE,
  ALGO2_DONE,
  DDC_DONE,
};

class DataReadyEvent : public Event<EventType1>
{
public:
  DataReadyEvent() : Event<EventType1>(EventType1::READ_DONE, "Read PMU data"){};
  virtual ~DataReadyEvent() = default;
};

class DDCReadyEvent : public Event<EventType1>
{
public:
  DDCReadyEvent() : Event<EventType1>(EventType1::DDC_DONE, "DDC algo is done"){};
  virtual ~DDCReadyEvent() = default;
};

class  AlgoFFTEvent: public Event<EventType1>
{
public:
  AlgoFFTEvent() : Event<EventType1>(EventType1::ALGO1_DONE, "FFT algo is done"){};
  virtual ~AlgoFFTEvent() = default;
};

#endif
