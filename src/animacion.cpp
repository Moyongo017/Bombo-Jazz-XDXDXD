#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include "Dibujo.hpp"
#include "GestorDibujos.hpp"

using namespace ftxui;

int main()
{
    auto screen = Screen::Create(
        Dimension::Fixed(80),
        Dimension::Fixed(24)
    );

    const std::vector<std::u32string> banda_transportadora_figura = {
        U"================================================================================",
        U"--------------------------------------------------------------------------------"
    };

    const std::vector<std::u32string> lata_figura = {
        U"  ___  ",
        U" /_ /\\ ",
        U"| | | |",
        U" \\_\\/_/"
    };

    const std::vector<std::u32string> botella_figura = {
        U"   _   ",
        U"  | |  ",
        U"  | |  ",
        U"  | |  ",
        U"  |_|  "
    };

    const std::vector<std::u32string> caja_figura = {
        U" +-----+",
        U" | ABC |",
        U" +-----+"
    };

    GestorDibujos gestor;

    gestor.Agregar(Dibujo(0, 18, banda_transportadora_figura, ftxui::Color::GrayDark));

    gestor.Agregar(Dibujo(-10, 14, botella_figura, ftxui::Color::Cyan));
    gestor.Agregar(Dibujo(-25, 15, lata_figura, ftxui::Color::Red));
    gestor.Agregar(Dibujo(-40, 15, caja_figura, ftxui::Color::Yellow));
    gestor.Agregar(Dibujo(-55, 14, botella_figura, ftxui::Color::Green));


    int frames = 800;
    int ciclo_animacion = 100;

    for (int frame = 0; frame < frames; ++frame)
    {
        screen.Clear();

        gestor.dibujos[1].x = (frame * 1 + 0) % ciclo_animacion * 80 / ciclo_animacion;
        gestor.dibujos[2].x = (frame * 1 + 25) % ciclo_animacion * 80 / ciclo_animacion;
        gestor.dibujos[3].x = (frame * 1 + 50) % ciclo_animacion * 80 / ciclo_animacion;
        gestor.dibujos[4].x = (frame * 1 + 75) % ciclo_animacion * 80 / ciclo_animacion;

        gestor.DibujarTodos(screen);

        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}