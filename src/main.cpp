/*********************************************************************************************************
*                                               <Module name>
*						<Module description>
*
*						<Copyright>
*
*						<Copyright or distribution terms>
*
*
*********************************************************************************************************/

/*********************************************************************************************************
*                                               <File description>
*
* Filename	: Filename
* Version	: Module version					
* Programmer(s) : Programmer initial(s)
**********************************************************************************************************
*  Note(s):
*
*
*
*********************************************************************************************************/

/*********************************************************************************************************
 *
 * \file		${file_name}
 * \brief		Descripcion del modulo
 * \date		${date}
 * \author		Nicolas Ferragamo nferragamo@frba.utn.edu.ar
 * \version 
*********************************************************************************************************/

/*********************************************************************************************************
 *** INCLUDES
*********************************************************************************************************/

#include <Arduino.h>
#include <util/delay.h>

/*********************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
*********************************************************************************************************/

/*********************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
*********************************************************************************************************/
#define SET_PIN(PORT,PIN) (PORT|= 1<<PIN)
#define CLEAR_PIN(PORT,PIN) (PORT&=~(1<<PIN))

#define bot1 ((PIND>>4)&0X01)
#define bot2 ((PIND>>5)&0x01)
#define bot3 ((PIND>>6)&0X01)
#define bot4 ((PIND>>7)&0X01)
/*********************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODULO/
*********************************************************************************************************/

/*********************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
*********************************************************************************************************/



/*********************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 *   se escriben en CamelCase y están precedidas por la identificación del 
 *   módulo seguida de un _ 
 *   ej: MEM_POOL  Mem_PoolHeap; 
*********************************************************************************************************/
char cont=1;
char FLAG_BT1=0;


/*********************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
 *   se declaran con static y se escriben en CamelCase y están precedidas por la 
 *   identificación del módulo seguida de un _ y usan _ para separar las palabras
 *   cuando tienen nombres compuestos
 *   ej: static MEM_POOL  Mem_Pool_Heap; 
*********************************************************************************************************/



/*********************************************************************************************************
 *** PROTOTIPO DE FUNCIONES PRIVADAS AL MODULO
 * se declaran como estaticas y se escriben en CamelCase, están precedidas por la
 * identificación del módulo seguida de un _. No se decaran en el .h
 * ej static void Clk_DateTimer(parametros)
*********************************************************************************************************/



/*********************************************************************************************************
 *** FUNCIONES PRIVADAS AL MODULO
*********************************************************************************************************/

void mostrar_led(char num);

/*********************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
*********************************************************************************************************/

/**
	\fn  		Nombre de la Funcion
	\brief 		Descripcion
 	\author 	Nombre
 	\date 		${date}
 	\param [in] 	parametros de entrada
 	\param [out] 	parametros de salida
	\return tipo 	y descripcion de retorno
*/





/*

Respetar este pin out.

PD4 -> BOTON 1 
PD5 -> BOTON 2 
PD6 -> BOTON 3 
PD7 -> BOTON 4

PD2 -> LED 1   
PD3 -> LED 2 
PB0 -> LED 3
PB1 -> LED 4 
PB2 -> LED 5 
PB3 -> LED 6
PB4 -> LED 7

*/

/*
** The main function. Application starts here.
*/
int main (void)
{

 
  //! aca se escriben las inicializaciones
 DDRD &=~(1<<PD4);
 DDRD &=~(1<<PD5);
 DDRD &=~(1<<PD6);
 DDRD &=~(1<<PD7);

 DDRD |=(1<<PD2);
 DDRD |=(1<<PD3);
 DDRB |=(1<<PB0);
 DDRB |=(1<<PB1);
 DDRB |=(1<<PB2);
 DDRB |=(1<<PB3);
 DDRB |=(1<<PB4);

 PORTD |=(1<<PD4);
 PORTD |=(1<<PD5);
 PORTD |=(1<<PD6);
 PORTD |=(1<<PD7);
   
   //! aca se escribe el programa principal
   
   while(1)
  {
   if(bot1==0)
   {
     FLAG_BT1=1;
   }
  if (FLAG_BT1==1)
  {
      cont++;
    
     if (cont==7)
     {
       cont=1;
     }
     
     mostrar_led(cont);
     _delay_ms(100); 
  }
 
  if (bot2 == 0)
  {
    FLAG_BT1=0;
  }
  if (bot3 == 0 || bot4 == 0)
  {
    CLEAR_PIN(PORTD,PD2);
    CLEAR_PIN(PORTD,PD3);
    CLEAR_PIN(PORTB,PB0);
    CLEAR_PIN(PORTB,PB1);
    CLEAR_PIN(PORTB,PB2);
    CLEAR_PIN(PORTB,PB3);
    CLEAR_PIN(PORTB,PB4);
  }
  

  }

  return 0;
}

void mostrar_led(char num)
{
  CLEAR_PIN(PORTD,2);
  CLEAR_PIN(PORTD,3);
  CLEAR_PIN(PORTB,0);
  CLEAR_PIN(PORTB,1);
  CLEAR_PIN(PORTB,2);
  CLEAR_PIN(PORTB,3);
  CLEAR_PIN(PORTB,4);

  switch (num)
  {
   case 1: 
          SET_PIN(PORTB,PB4);
          break;
   case 2:
          SET_PIN(PORTB,PB0);
          SET_PIN(PORTB,PB1);
          break;
   case 3:
         SET_PIN(PORTB,PB4);
         SET_PIN(PORTB,PB0);
         SET_PIN(PORTB,PB1); 
         break;
   case 4:
         SET_PIN(PORTD,PD2);
         SET_PIN(PORTB,PB0);
         SET_PIN(PORTB,PB1);
         SET_PIN(PORTB,PB3);
         break;
   case 5:
         SET_PIN(PORTD,PD2);
         SET_PIN(PORTB,PB0);
         SET_PIN(PORTB,PB1);
         SET_PIN(PORTB,PB3);
         SET_PIN(PORTB,PB4);
         break;
   case 6:
         SET_PIN(PORTD,PD2);
         SET_PIN(PORTD,PD3);
         SET_PIN(PORTB,PB0);
         SET_PIN(PORTB,PB1);
         SET_PIN(PORTB,PB2);
         SET_PIN(PORTB,PB3);
         break;

  }
}
/*********************************************************************************************************
** end of file
*********************************************************************************************************/
