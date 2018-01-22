#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>

#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Gridlocked");
  window.setFramerateLimit(60u);

  ImGui::SFML::Init(window);

  float size  = 100.f;
  int   edges = 6u;
  sf::CircleShape shape(size, edges);
  shape.setFillColor(sf::Color::Green);

  sf::Clock deltaClock;
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      ImGui::SFML::ProcessEvent(event);

      if (event.type == sf::Event::Closed)
        window.close();
    }

    ImGui::SFML::Update(window, deltaClock.restart());

    ImGui::Begin("Select polygon size and number of edges!");
    ImGui::SliderFloat("Size", &size, 0.f, 100.f);
    ImGui::SliderInt("Edges", &edges, 3, 10);
    ImGui::End();

    shape.setRadius(size);
    shape.setPointCount(edges);

    window.clear();
    window.draw(shape);
    ImGui::SFML::Render(window);
    window.display();
  }

  return 0;
}