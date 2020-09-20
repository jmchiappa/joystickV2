    /*     Simple Stepper Motor Control Exaple Code
     *      
     *  by Dejan Nedelkovski, www.HowToMechatronics.com
     *  
     */
    // defines pins numbers

#ifndef JOYSTICK
#define JOYSTICK

//#define DEBUG

//#define PRINT_DBG

#ifdef PRINT_DBG
#define PRINT(A,B)  {Serial.print(A);Serial.print(B);};
#define PRINTLN(A,B)    {Serial.print(A);Serial.println(B);};
#else
#define PRINT(A,B)  {}
#define PRINTLN(A,B) {}
#endif

class JoystickV2
{
public:
    enum POLAR {
        NOT_INVERTED,
        INVERTED
    };
    // Constructor
	JoystickV2(uint8_t PinNumber_X,uint8_t PinNumber_Y,uint8_t Polar_X=NOT_INVERTED,uint8_t Polar_Y=NOT_INVERTED,uint32_t range=255);
	void begin(uint32_t Period);
    void begin(void);

    // getter
    int32_t getJoystickRelativeXValue();
    int32_t getJoystickRelativeYValue();
    
    int32_t getXaxis();
    int32_t getYaxis();
    void setJoystickReference();

private:

    // does begin has been called yet ?
    bool initialized_ =false;
    // internal getter
    void  setSpeedValue(int32_t joystick_input);
    /* Stocke la valeur du point milieu d'entrée*/
	uint32_t refX;
    uint32_t refY;
    
    /* Numéro de la broche d'entrée analogique*/
    uint8_t pinX = NC;
    uint16_t pinY = NC;
    /* Permet d'inverser le sens de calcul de direction et vitesse du joystick 
    Par exemple pousser le joystick vers le haut est négatif alors que c'est la marche avant*/
    uint8_t PolarX = NOT_INVERTED;
    uint8_t PolarY = NOT_INVERTED;
    ;
    /* range : uint8_t exprimant le nombre de bits pour le calcul de la vitesse*/
    uint32_t range;  // number of bits, for DC motor set to 8 bits

    /* période d'échantillonnage min pour calculer la vitesse en (ms) */
    uint32_t SamplingPeriod = 5;

    /* date de l'ancienne acquisition */
    uint64_t PreviousRefreshTime=0;

    /* Valeur cumulée de l'entrée pour filtrage*/
    uint64_t sumSamples=0;

    /* Nombre d'échantillons cumulées */
    uint16_t nbSamples;
};

#endif
