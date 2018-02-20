#pragma once

#include <imgui/imgui.h>

#include <debug-tools/dt.hpp>

namespace dt {

class logger {
public:
  explicit logger(const char *, bool isOpen);

  ~logger() = default;

  void add(const char *const&);

  void clear();

  void open();

  void close();

  void saveToFile();

  void draw();

private:
  ImGuiTextBuffer m_buffer;
  ImGuiTextFilter m_filter;
  ImVector<int> m_lineOffsets;

  const char *m_title;
  bool m_isOpen;
  bool m_autoscroll;
};

}
