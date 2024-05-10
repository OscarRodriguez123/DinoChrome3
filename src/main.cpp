#include<iostream>
#include<string>
#include<thread>
#include<ftxui/dom/elements.hpp>
#include<ftxui/screen/screen.hpp>
#include<ftxui/screen/string.hpp>
#include<ftxui/screen/terminal.hpp>
#include<fstream>
#include<Dibujo.hpp>

using namespace std;
using namespace ftxui;


 int main(int argc, char const *argv[])
 {
    Archivo dReptil("./assets/images/dinosaurio.txt");
    Archivo dCactus("./assets/images/cactus.txt");
  



    int fotograma=0;
    while(true){

        fotograma++;
        Element personaje = spinner(21,fotograma) | bold | color(Color::Blue1) | bgcolor(Color::Green1);
        Element reptil = dReptil.GetElement() | bold | color(Color::Green1) | bgcolor(Color::Blue1) ;
        Element lienzo = hbox({personaje , reptil, dCactus.GetElement()});

        Screen pantalla = Screen::Create(
            Dimension::Full(),
            Dimension::Fit(lienzo)
             );



        Render(pantalla,lienzo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();

        this_thread::sleep_for(0.1s);
     }
    return 0;
 }
 