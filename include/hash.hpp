// Copyright by Enigma

#ifndef INCLUDE_HASH_HPP_
#define INCLUDE_HASH_HPP_

#include <boost/log/expressions.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup.hpp>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <mutex>
#include <nlohmann/json.hpp>
#include <sstream>
#include <string>

using json = nlohmann::json;

const char Ending[] = "0000";
const size_t NumZeroes = 4;
void SetUpLogging();

class JsonFiler {
 public:
  void NewElement(const std::string& randString, const std::string& hash,
                  std::time_t timestamp);

  friend std::ostream& operator<<(std::ostream& out, const JsonFiler& j);

 private:
  mutable std::mutex mut;
  json JsonArray;
};
#endif // INCLUDE_HASH_HPP_
