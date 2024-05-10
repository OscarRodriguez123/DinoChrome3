#include<iostream>
#include<string>
#include<ftxui/dom/elements.hpp>
#include<ftxui/screen/screen.hpp>
#include<thread>
#include<list>
#include<Dibujo.hpp>
#include<Archivo.hpp>
#include<experimental/random>
using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    Archivo cactus("./assets/images/cactus.txt");

    list<Dibujo> dibujos;
    for (size_t i = 0; i <20; i++)
    {
        Dibujo d=cactus.CrearDibujo();
        d.EstablecerPosicion(experimental::randint(0,20),experimental::randint(0,20));
       dibujos.push_back(d);
    }
    
    


    for (int i = 0; i < 20; i++)
    {
        list<string>c;
        c.push_back("Personaje"+to_string(i));
        c.push_back("  O");
        c.push_back("--|--");
        c.push_back(" / \\");

        Dibujo contenido(c,experimental::randint(0,50),experimental::randint(0,50));
        dibujos.push_back(contenido);
    }
    

    auto Pantalla=Screen::Create(Dimension::Full(),Dimension::Full());

    while(true){
        Pantalla.Clear();
        this_thread::sleep_for(0.1s);
        for (auto &&i : dibujos)
        {
            i.DesplazarX(experimental::randint(-1,1));
            i.DesplazarY(experimental::randint(-1,1));
        }

        for (auto &&i : dibujos)
        {
            i.Dibujar(Pantalla);
        }


        Pantalla.Print();
        
        cout<<Pantalla.ResetPosition();
    }
    return 0;
}
