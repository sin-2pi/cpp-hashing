#ifndef _timer_
#define _timer_

#include <ctime>
#include <chrono>

class Timer {
   public:
      Timer();
      ~Timer();

      void Start();
      void Stop();
      double Time();
      void Reset();
      double TimeMS();
   private:
      
      std::chrono::duration<double> elapsedTime;
      bool running;
      std::chrono::high_resolution_clock::time_point startTime;
      std::chrono::high_resolution_clock::time_point stopTime;
   };

Timer::Timer():
   elapsedTime( 0.0 ), running( false ) {
   }

Timer::~Timer() {
   }

void Timer::Start() {
  if( !running ) {
    startTime = std::chrono::high_resolution_clock::now();
    running = true;
  }
}

void Timer::Stop() {
 if( running ) {
   stopTime = std::chrono::high_resolution_clock::now();
   running = false;
   elapsedTime = std::chrono::duration_cast<std::chrono::duration<double> >(stopTime - startTime); 
 }
}

double Timer::Time() {
  if( running ) {
    Stop();
    Start();
  }
  return elapsedTime.count();
}

double Timer::TimeMS() {
  typedef std::chrono::milliseconds ms;
  if( running ) {
    Stop();
    Start();
  }
  ms d = std::chrono::duration_cast<ms>(elapsedTime);
  return d.count();
}


void Timer::Reset() {
  if( running ) {
    Stop();
    elapsedTime = std::chrono::duration<double>(0.0);
    Start();
  } else 
    elapsedTime = std::chrono::duration<double>(0.0);
}
#endif
