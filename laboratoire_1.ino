#include <Arduino.h>
#include <Bounce2.h>

#define BROCHE_BOUTON_TEMPO 6
#define BROCHE_DEL_TEMPO 5

#define BROCHE_BOUTON_BASCULE 8
#define BROCHE_DEL_BASCULE 7

Bounce2::Button boutonBascule = Bounce2::Button();
bool etatDelBascule = LOW;

void setup()
{
    // la DEL reste allumée tant que le bouton est maintenu
    pinMode(BROCHE_BOUTON_TEMPO, INPUT_PULLUP);
    pinMode(BROCHE_DEL_TEMPO, OUTPUT);
    digitalWrite(BROCHE_DEL_TEMPO, LOW);

    // un appui allume, un second appui éteint
    pinMode(BROCHE_DEL_BASCULE, OUTPUT);
    digitalWrite(BROCHE_DEL_BASCULE, etatDelBascule);

    boutonBascule.attach(BROCHE_BOUTON_BASCULE, INPUT_PULLUP);
    boutonBascule.setPressedState(LOW);
}

void loop()
{
    // Gestion du bouton momentané
    bool boutonEnfonce = (digitalRead(BROCHE_BOUTON_TEMPO) == LOW);
    digitalWrite(BROCHE_DEL_TEMPO, boutonEnfonce ? HIGH : LOW);

     //Gestion du bouton bascule
    boutonBascule.update();
    if (boutonBascule.pressed())
    {
        etatDelBascule = !etatDelBascule;
        digitalWrite(BROCHE_DEL_BASCULE, etatDelBascule);
    }
}