#include "logger.hpp"

using namespace dt;

logger::logger(const char * title, bool isOpen)
  : m_buffer(),
    m_filter(),
    m_title(title),
    m_isOpen(isOpen),
    m_autoscroll(true)
{}

void logger::add(const char * const& log) {
  // TODO
}

void logger::clear() {
  // TODO
}

void logger::open() {
  m_isOpen = true;
}

void logger::close() {
  m_isOpen = false;
}

void logger::saveToFile() {
  // TODO
}

void logger::draw() {
  if (m_isOpen) {
    ImGui::SetNextWindowSize({0, 0}, ImGuiCond_FirstUseEver);
    ImGui::Begin(m_title, &m_isOpen);

    if (ImGui::Button("Clear")) clear();

    ImGui::SameLine();
    bool copy = ImGui::Button("Copy");

    ImGui::SameLine();
    bool save = ImGui::Button("Save");

    ImGui::SameLine();
    ImGui::Checkbox("Autoscrolling", &m_autoscroll);

    ImGui::SameLine();
    m_filter.Draw("Filter", -100.0f);

    ImGui::Separator();
    ImGui::BeginChild("scrolling", {0, 0}, false, ImGuiWindowFlags_HorizontalScrollbar);

    if (copy) {
      ImGui::LogToClipboard();
    }

    if (save) {
      saveToFile();
    }

    if (m_filter.IsActive()) {
      const char *buf_begin = m_buffer.begin();
      const char *line = buf_begin;
      for (int line_no = 0; line != NULL; line_no++) {
        const char *line_end = (line_no < m_lineOffsets.Size) ? buf_begin + m_lineOffsets[line_no] : NULL;
        if (m_filter.PassFilter(line, line_end))
          ImGui::TextUnformatted(line, line_end);
        line = line_end && line_end[1] ? line_end + 1 : NULL;
      }
    } else {
      ImGui::TextUnformatted(m_buffer.begin());
    }

    if (m_autoscroll) {
      ImGui::SetScrollHere(1.0f);
    }

    ImGui::EndChild();
    ImGui::End();
  }
}
