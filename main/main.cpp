#include <atomic>
#include <fstream>
#include <functional>
#include <future>
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

#include "log_level.h"
#include "logger_factory.h"

static std::atomic<bool> run_thread_flag(false);

void work() {
  std::ostringstream s;
  s << "thread id: " << std::this_thread::get_id();
  while (run_thread_flag) {
    if (!logging::ERROR(s.str()).has_error())
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    if (!logging::WARN(s.str()).has_error())
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    if (!logging::INFO(s.str()).has_error())
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    if (!logging::DEBUG(s.str()).has_error())
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    if (!logging::TRACE(s.str()).has_error())
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

int main(void) {
  unsigned concurent_threads_supported = std::thread::hardware_concurrency();
  bool ret = 0;

  run_thread_flag = true;
  std::vector<std::future<void>> threads;
  for (size_t i = 0; i < concurent_threads_supported + 1; ++i) {
    threads.emplace_back(std::async(std::launch::async, work));
  }

  std::cin.ignore();
  //std::this_thread::sleep_for(std::chrono::seconds(7));

  run_thread_flag = false;
  return ret;
}
