#include <Arduino.h>
#include <Bounce2.h>
 
#define BROCHE_DEL_TEMPO 5
#define BROCHE_BOUTON_TEMPO 6

#define BROCHE_DEL_BAS 7
#define BROCHE_BOUTON_BAS 8

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
    digitalWrite(BROCHE_DEL_BAS, etatDelTempo);
 

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
        Serial.print("bouton6 "); // Descripteur
        Serial.print(" "); // Espace
        Serial.print(1); // Valeur
        Serial.println(); // Saut de ligne


    }
    else
    {
        digitalWrite(BROCHE_DEL_TEMPO, LOW); //lumière est éteinte
    }
 
    if (BOUTON_BAS.pressed())
    {
        digitalWrite(BROCHE_DEL_BAS, HIGH);
        Serial.print("bouton8 "); // Descripteur
        Serial.print(" "); // Espace
        Serial.print(1); // Valeur
        Serial.println(); // Saut de ligne

        if ( etatDelBas == 0 ) {
            etatDelBas = 1;
        } else {
            etatDelBas = 0;    
        }

       
    }
    digitalWrite(BROCHE_DEL_BAS, etatDelBas);
    
}
 
 
 