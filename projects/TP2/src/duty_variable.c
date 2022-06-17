/*=============================================================================
 * Copyright (c) 2019, Eric Pernia <ericpernia@gmail.com>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE file)
 * Date: 2019/05/03
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "mygpio.h"
#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/

// EDU-CIAA-NXP V1.1 primer tirada (abajo dice ASSISI)
#define edu_ciaa_nxp_v_1_1_0

// EDU-CIAA-NXP V1.1 segunda tirada (abajo dice ASEMBLI)
//#define edu_ciaa_nxp_v_1_1_1

#if defined(edu_ciaa_nxp_v_1_1_0)
   #define LUZ_ROJA     LED2
   #define LUZ_AMARILLA LED1
   #define LUZ_VERDE    LEDG
#elif defined(edu_ciaa_nxp_v_1_1_1)
   #define LUZ_ROJA     LED1
   #define LUZ_AMARILLA LED2
   #define LUZ_VERDE    LED3
#endif


/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   bool_t LED_ON;
   /* Variable de Retardo no bloqueante */
   delay_t delay_NB;
   int32_t duty = 500;

   // ----- Setup -----------------------------------
   boardInit();

   /* Inicializar Retardo no bloqueante con tiempo en milisegundos
      (500ms = 0,5s) */
   delayConfig( &delay_NB, duty );
   mygpioWrite( LED2, ON );
   LED_ON = true;


   while( true ) {
	 delay(100);
	      /* delayRead retorna TRUE cuando se cumple el tiempo de retardo */
	 if ( delayRead( &delay_NB ) ){
		 mygpioToggle( LUZ_ROJA );
		 if(LED_ON == true){
			 LED_ON = false;
			 delayWrite( &delay_NB, 1000 - duty );
		 }else{
			 LED_ON = true;
			 delayWrite( &delay_NB, duty );
		 }
	  }else{
			if(!mygpioRead( TEC1 )){
		       if(duty < 1000) {
		    	   duty += 10;
		       }
		   }

			if(!mygpioRead( TEC2 )){
			      if(duty > 0) {
			    	  duty -= 10;
			      }
			}
	  }

   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the
   // case of a PC program.
   return 0;
}
