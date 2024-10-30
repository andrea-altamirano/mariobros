#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;
    auto can = Canvas(200, 200);
    //can.DrawPointLine(0, 0, 10, 10);
    ////can.DrawPointCircle(10, 10, 10);
    can.DrawBlockCircle(100, 100, 50);
    can.DrawBlockEllipse(80, 90, 5, 10);
    can.DrawBlockEllipse(110, 90, 5, 10);
    can.DrawPointLine(200, 100, 200, 200);
    auto ColorSupport = vbox({});
    while (true)
    {
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        // Element personaje = spinner(20, frame);
        Element lienzo = bgcolor(Color::DarkRed, border(vbox(ColorSupport, canvas(&can))));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        frame++;
    }

    return 0;
}