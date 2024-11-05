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
    int frame_direction = 1;
    const int frame_max = 5;
    const int frame_min = 0;

    auto ColorSupport = vbox({});
    
    while (true)
    {
        auto can = Canvas(200, 200);
        can.DrawBlockCircle(100, 100, 50);
        can.DrawBlockEllipse(80, 90, 5, 10);
        can.DrawBlockEllipse(110, 90, 5, 10);
        can.DrawBlockCircle(100, 125, frame);

        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::DarkRed, border(vbox(ColorSupport, canvas(&can))));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        if (frame >= frame_max)
            frame_direction = -1;
        if (frame <= frame_min)
            frame_direction = 1;
        frame += frame_direction;
        
    }

    return 0;
}