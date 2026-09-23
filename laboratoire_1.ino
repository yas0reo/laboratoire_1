#include <Arduino.h>
#include <Chrono.h>
#include <Bounce2.h>

#define DEL 5
#define DEL 7

#define INTERVALLE 500

Bounce2::Button bouton = Bounce2::Button();
Chrono minuterieDel;

bool etatDel = LOW;
bool clignotementActif = false;

void setup()
{
}

void loop()
{

}