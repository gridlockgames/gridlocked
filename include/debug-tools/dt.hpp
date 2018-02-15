#pragma once

#include <memory>

namespace dt
{

class debugTools
{
public:
  explicit debugTools();
  ~debugTools();

  void draw();

private:
  class debugToolsImpl;
  std::unique_ptr<debugToolsImpl> m_pimpl;
};

}
