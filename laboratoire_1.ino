#include <Arduino.h>
#include <Chrono.h>
#include <Bounce2.h>
 
#define BROCHE_DEL_TEMPO 8
#define BROCHE_BOUTON_TEMPO 7

#define BROCHE_DEL_BAS 6
#define BROCHE_BOUTON_BAS 5

Bounce2::Button BOUTON_TEMPO = Bounce2::Button();
Bounce2::Button BOUTON_BAS = Bounce2::Button();

bool etatDelTempo = LOW;
bool etatDelBas = LOW;

void setup()
{
    // Configuration de la DEL
    pinMode(BROCHE_DEL_TEMPO, OUTPUT);
    digitalWrite(BROCHE_DEL_TEMPO, etatDelTempo);

    // Configuration de la DEL
    pinMode(BROCHE_DEL_BAS, OUTPUT);
    digitalWrite(BROCHE_DEL_BAS, etatDelBas);
 

    // Configuration du bouton
    BOUTON_TEMPO.attach(BROCHE_BOUTON_TEMPO, INPUT_PULLUP);
    BOUTON_TEMPO.setPressedState(LOW);
 
    // Configuration du bouton
    BOUTON_BAS.attach(BROCHE_BOUTON_BAS, INPUT_PULLUP);
    BOUTON_BAS.setPressedState(LOW);
}

void loop()
{
    BOUTON_TEMPO.update();
    BOUTON_BAS.update();

    if (BOUTON_TEMPO.isPressed())
    {
        digitalWrite(BROCHE_DEL_TEMPO, HIGH); //lumière est allumée
        Serial.print("TEMPO"); // Descripteur
        Serial.print(" "); // Espace
        Serial.print(1); // Valeur
        Serial.println(); // Saut de ligne
    }
    else
    {
        digitalWrite(BROCHE_DEL_TEMPO, etatDelTempo); //lumière est éteinte
    }
 
    if (BOUTON_BAS.isPressed())
    {
        digitalWrite(BROCHE_DEL_BAS, HIGH); //lumière est allumée
        Serial.print("BAS"); // Descripteur
        Serial.print(" "); // Espace
        Serial.print(2); // Valeur
        Serial.println(); // Saut de ligne
        if ( etatDelBas == 0 ) {
            etatDelBas = 1;
        } else {
            etatDelBas = 0;    
        }
    }
    else
    {
        digitalWrite(BROCHE_DEL_BAS, etatDelBas); //lumière est éteinte
    }
    
}
 
 
 