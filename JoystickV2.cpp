    /*     Simple Stepper Motor Control Exaple Code
     *      
     *  by Dejan Nedelkovski, www.HowToMechatronics.com
     *  
     */
    // defines pins numbers

#include "Arduino.h"
#include "JoystickV2.h"


JoystickV2::JoystickV2(uint8_t PinNumber_X,uint8_t PinNumber_Y,uint8_t Polar_X,uint8_t Polar_Y,uint32_t range):
	pinX(PinNumber_X),
	pinY(PinNumber_Y),
	PolarX(Polar_X),
	PolarY(Polar_Y),
	range(range)
{
	// cleanup
	this->refX  = 0;	
	this->refY  = 0;	
	// this->sumSamples =0;
	// this->MaxOutputSpeedCoef=100;
	// this->MaxValue=0;
	// this->output_speed=0;
	// this->output_direction = FORWARD;
	// // évite le débordement du calcul par 2^n -1 si n=32
	// for(uint8_t i=0;i<range;i++)
	// 	this->MaxValue |= (1<<i);	// allume les bits jusqu'à range-1
}

void JoystickV2::begin() {
	initialized_ = true;
	this->refX = analogRead(this->pinX);
	this->refY = analogRead(this->pinY);
}

void JoystickV2::setJoystickReference()
{
	begin();
}

int32_t JoystickV2::getJoystickRelativeXValue()
{
	if(!initialized_) begin();
	return analogRead(this->pinX) - this->refX;
}

int32_t JoystickV2::getJoystickRelativeYValue()
{
	if(!initialized_) begin();
	return analogRead(this->pinY) - this->refY;
}

int32_t JoystickV2::getXaxis()
{
	int32_t out;
	if(!initialized_) begin();
	uint16_t val = analogRead(this->pinX);
	if(val>this->refX) {
		out = map(val,this->refX, 1023,0,range);
	}else {
		out = map(val,0, this->refX,-range,0);
	}
	if(PolarX==INVERTED) {
		out = -out;
	}
	return out;
}

int32_t JoystickV2::getYaxis()
{
	int32_t out;
	if(!initialized_) begin();
	uint16_t val = analogRead(this->pinY);
	if(val>this->refY) {
		out = map(val,this->refY,1023,0,range);
	}else {
		out = map(val,0, this->refY,-range,0);
	}
	if(PolarY==INVERTED) {
		out = -out;
	}
	return out;
}
