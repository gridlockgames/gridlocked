#include <debug-tools/dt.hpp>

#include "logger.hpp"

using namespace dt;

class debugTools::debugToolsImpl {
public:
  explicit debugToolsImpl()
  : m_logger("Logger", true)
  {};

  ~debugToolsImpl() = default;

  void draw() {
    m_logger.draw();
  }

private:
  logger m_logger;
};

debugTools::debugTools()
: m_pimpl(new debugToolsImpl)
{}

debugTools::~debugTools() = default;

void debugTools::draw() {
  m_pimpl->draw();
}
