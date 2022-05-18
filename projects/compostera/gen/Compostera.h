
#ifndef COMPOSTERA_H_
#define COMPOSTERA_H_

#include "..\inc\sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'compostera'.
*/

/*! Define dimension of the state configuration vector for orthogonal states. */
#define COMPOSTERA_MAX_ORTHOGONAL_STATES 5

/*! Define maximum number of time events that can be active at once */
#define COMPOSTERA_MAX_PARALLEL_TIME_EVENTS 5

/*! Define indices of states in the StateConfVector */
#define SCVI_COMPOSTERA_TEC1_DEBOUNCE_O 0
#define SCVI_COMPOSTERA_TEC1_INICIO 0
#define SCVI_COMPOSTERA_TEC1_OPRIMIDO 0
#define SCVI_COMPOSTERA_TEC1_VALIDACION_O 0
#define SCVI_COMPOSTERA_TEC1_NO_OPRIMIDO 0
#define SCVI_COMPOSTERA_TEC1_DEBOUNCE_N_O 0
#define SCVI_COMPOSTERA_TEC1_VALIDACION_N_O 0
#define SCVI_COMPOSTERA_TEC2_DEBOUNCE_O 1
#define SCVI_COMPOSTERA_TEC2_INICIO 1
#define SCVI_COMPOSTERA_TEC2_OPRIMIDO 1
#define SCVI_COMPOSTERA_TEC2_VALIDACION_O 1
#define SCVI_COMPOSTERA_TEC2_NO_OPRIMIDO 1
#define SCVI_COMPOSTERA_TEC2_DEBOUNCE_N_O 1
#define SCVI_COMPOSTERA_TEC2_VALIDACION_N_O 1
#define SCVI_COMPOSTERA_TEC3_DEBOUNCE_O 2
#define SCVI_COMPOSTERA_TEC3_INICIO 2
#define SCVI_COMPOSTERA_TEC3_OPRIMIDO 2
#define SCVI_COMPOSTERA_TEC3_VALIDACION_O 2
#define SCVI_COMPOSTERA_TEC3_NO_OPRIMIDO 2
#define SCVI_COMPOSTERA_TEC3_DEBOUNCE_N_O 2
#define SCVI_COMPOSTERA_TEC3_VALIDACION_N_O 2
#define SCVI_COMPOSTERA_TEC4_DEBOUNCE_O 3
#define SCVI_COMPOSTERA_TEC4_INICIO 3
#define SCVI_COMPOSTERA_TEC4_OPRIMIDO 3
#define SCVI_COMPOSTERA_TEC4_VALIDACION_O 3
#define SCVI_COMPOSTERA_TEC4_NO_OPRIMIDO 3
#define SCVI_COMPOSTERA_TEC4_DEBOUNCE_N_O 3
#define SCVI_COMPOSTERA_TEC4_VALIDACION_N_O 3
#define SCVI_COMPOSTERA_ACTIVITY_ESPERANDO 4
#define SCVI_COMPOSTERA_ACTIVITY_ENFRIANDO 4
#define SCVI_COMPOSTERA_ACTIVITY_HUMEDECIENDO 4
#define SCVI_COMPOSTERA_ACTIVITY_DESHUMEDECIENDO 4
#define SCVI_COMPOSTERA_ACTIVITY_COMPOSTANDO 4
#define SCVI_COMPOSTERA_ACTIVITY_COMPOSTANDO_R1_RELLENANDO 4
#define SCVI_COMPOSTERA_ACTIVITY_COMPOSTANDO_R1_SONANDO 4
#define SCVI_COMPOSTERA_ACTIVITY_COMPOSTANDO_R1_MEZCLANDO 4

/*! Enumeration of all states */ 
typedef enum
{
	Compostera_last_state,
	Compostera_TEC1_DEBOUNCE_O,
	Compostera_TEC1_INICIO,
	Compostera_TEC1_OPRIMIDO,
	Compostera_TEC1_VALIDACION_O,
	Compostera_TEC1_NO_OPRIMIDO,
	Compostera_TEC1_DEBOUNCE_N_O,
	Compostera_TEC1_VALIDACION_N_O,
	Compostera_TEC2_DEBOUNCE_O,
	Compostera_TEC2_INICIO,
	Compostera_TEC2_OPRIMIDO,
	Compostera_TEC2_VALIDACION_O,
	Compostera_TEC2_NO_OPRIMIDO,
	Compostera_TEC2_DEBOUNCE_N_O,
	Compostera_TEC2_VALIDACION_N_O,
	Compostera_TEC3_DEBOUNCE_O,
	Compostera_TEC3_INICIO,
	Compostera_TEC3_OPRIMIDO,
	Compostera_TEC3_VALIDACION_O,
	Compostera_TEC3_NO_OPRIMIDO,
	Compostera_TEC3_DEBOUNCE_N_O,
	Compostera_TEC3_VALIDACION_N_O,
	Compostera_TEC4_DEBOUNCE_O,
	Compostera_TEC4_INICIO,
	Compostera_TEC4_OPRIMIDO,
	Compostera_TEC4_VALIDACION_O,
	Compostera_TEC4_NO_OPRIMIDO,
	Compostera_TEC4_DEBOUNCE_N_O,
	Compostera_TEC4_VALIDACION_N_O,
	Compostera_activity_ESPERANDO,
	Compostera_activity_ENFRIANDO,
	Compostera_activity_HUMEDECIENDO,
	Compostera_activity_DESHUMEDECIENDO,
	Compostera_activity_COMPOSTANDO,
	Compostera_activity_COMPOSTANDO_r1_RELLENANDO,
	Compostera_activity_COMPOSTANDO_r1_SONANDO,
	Compostera_activity_COMPOSTANDO_r1_MEZCLANDO
} ComposteraStates;

/*! Type definition of the data structure for the ComposteraIface interface scope. */
typedef struct
{
	sc_boolean evTEC1NoOprimido_raised;
	sc_boolean evTEC1Oprimido_raised;
	sc_boolean evTEC2NoOprimido_raised;
	sc_boolean evTEC2Oprimido_raised;
	sc_boolean evTEC3NoOprimido_raised;
	sc_boolean evTEC3Oprimido_raised;
	sc_boolean evTEC4NoOprimido_raised;
	sc_boolean evTEC4Oprimido_raised;
} ComposteraIface;


/* Declaration of constants for scope ComposteraIface. */
extern const sc_integer COMPOSTERA_COMPOSTERAIFACE_LEDR;
extern const sc_integer COMPOSTERA_COMPOSTERAIFACE_LEDG;
extern const sc_integer COMPOSTERA_COMPOSTERAIFACE_LEDB;
extern const sc_integer COMPOSTERA_COMPOSTERAIFACE_LED1;
extern const sc_integer COMPOSTERA_COMPOSTERAIFACE_LED2;
extern const sc_integer COMPOSTERA_COMPOSTERAIFACE_LED3;
extern const sc_boolean COMPOSTERA_COMPOSTERAIFACE_LED_ON;
extern const sc_boolean COMPOSTERA_COMPOSTERAIFACE_LED_OFF;
extern const sc_integer COMPOSTERA_COMPOSTERAIFACE_TEC1;
extern const sc_integer COMPOSTERA_COMPOSTERAIFACE_TEC2;
extern const sc_integer COMPOSTERA_COMPOSTERAIFACE_TEC3;
extern const sc_integer COMPOSTERA_COMPOSTERAIFACE_TEC4;


/*! Type definition of the data structure for the ComposteraInternal interface scope. */
typedef struct
{
	sc_boolean siTemperaturaMayor60_raised;
	sc_boolean siTemperaturaEstable_raised;
	sc_boolean siHumedadMenor40_raised;
	sc_boolean siHumedadEstable_raised;
	sc_boolean siHumedadMayor60_raised;
	sc_boolean siAberturaTapa_raised;
	sc_boolean siCerradoTapa_raised;
} ComposteraInternal;



/*! Type definition of the data structure for the ComposteraTimeEvents interface scope. */
typedef struct
{
	sc_boolean compostera_TEC1_DEBOUNCE_O_tev0_raised;
	sc_boolean compostera_TEC1_DEBOUNCE_N_O_tev0_raised;
	sc_boolean compostera_TEC2_DEBOUNCE_O_tev0_raised;
	sc_boolean compostera_TEC2_DEBOUNCE_N_O_tev0_raised;
	sc_boolean compostera_TEC3_DEBOUNCE_O_tev0_raised;
	sc_boolean compostera_TEC3_DEBOUNCE_N_O_tev0_raised;
	sc_boolean compostera_TEC4_DEBOUNCE_O_tev0_raised;
	sc_boolean compostera_TEC4_DEBOUNCE_N_O_tev0_raised;
	sc_boolean compostera_activity_COMPOSTANDO_r1_RELLENANDO_tev0_raised;
	sc_boolean compostera_activity_COMPOSTANDO_r1_MEZCLANDO_tev0_raised;
} ComposteraTimeEvents;




/*! 
 * Type definition of the data structure for the Compostera state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	ComposteraStates stateConfVector[COMPOSTERA_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	ComposteraIface iface;
	ComposteraInternal internal;
	ComposteraTimeEvents timeEvents;
} Compostera;



/*! Initializes the Compostera state machine data structures. Must be called before first usage.*/
extern void compostera_init(Compostera* handle);

/*! Activates the state machine */
extern void compostera_enter(Compostera* handle);

/*! Deactivates the state machine */
extern void compostera_exit(Compostera* handle);

/*! Performs a 'run to completion' step. */
extern void compostera_runCycle(Compostera* handle);

/*! Raises a time event. */
extern void compostera_raiseTimeEvent(Compostera* handle, sc_eventid evid);

/*! Raises the in event 'evTEC1NoOprimido' that is defined in the default interface scope. */ 
extern void composteraIface_raise_evTEC1NoOprimido(Compostera* handle);

/*! Raises the in event 'evTEC1Oprimido' that is defined in the default interface scope. */ 
extern void composteraIface_raise_evTEC1Oprimido(Compostera* handle);

/*! Raises the in event 'evTEC2NoOprimido' that is defined in the default interface scope. */ 
extern void composteraIface_raise_evTEC2NoOprimido(Compostera* handle);

/*! Raises the in event 'evTEC2Oprimido' that is defined in the default interface scope. */ 
extern void composteraIface_raise_evTEC2Oprimido(Compostera* handle);

/*! Raises the in event 'evTEC3NoOprimido' that is defined in the default interface scope. */ 
extern void composteraIface_raise_evTEC3NoOprimido(Compostera* handle);

/*! Raises the in event 'evTEC3Oprimido' that is defined in the default interface scope. */ 
extern void composteraIface_raise_evTEC3Oprimido(Compostera* handle);

/*! Raises the in event 'evTEC4NoOprimido' that is defined in the default interface scope. */ 
extern void composteraIface_raise_evTEC4NoOprimido(Compostera* handle);

/*! Raises the in event 'evTEC4Oprimido' that is defined in the default interface scope. */ 
extern void composteraIface_raise_evTEC4Oprimido(Compostera* handle);

/*! Gets the value of the variable 'LEDR' that is defined in the default interface scope. */ 
extern const sc_integer composteraIface_get_lEDR(const Compostera* handle);
/*! Gets the value of the variable 'LEDG' that is defined in the default interface scope. */ 
extern const sc_integer composteraIface_get_lEDG(const Compostera* handle);
/*! Gets the value of the variable 'LEDB' that is defined in the default interface scope. */ 
extern const sc_integer composteraIface_get_lEDB(const Compostera* handle);
/*! Gets the value of the variable 'LED1' that is defined in the default interface scope. */ 
extern const sc_integer composteraIface_get_lED1(const Compostera* handle);
/*! Gets the value of the variable 'LED2' that is defined in the default interface scope. */ 
extern const sc_integer composteraIface_get_lED2(const Compostera* handle);
/*! Gets the value of the variable 'LED3' that is defined in the default interface scope. */ 
extern const sc_integer composteraIface_get_lED3(const Compostera* handle);
/*! Gets the value of the variable 'LED_ON' that is defined in the default interface scope. */ 
extern const sc_boolean composteraIface_get_lED_ON(const Compostera* handle);
/*! Gets the value of the variable 'LED_OFF' that is defined in the default interface scope. */ 
extern const sc_boolean composteraIface_get_lED_OFF(const Compostera* handle);
/*! Gets the value of the variable 'TEC1' that is defined in the default interface scope. */ 
extern const sc_integer composteraIface_get_tEC1(const Compostera* handle);
/*! Gets the value of the variable 'TEC2' that is defined in the default interface scope. */ 
extern const sc_integer composteraIface_get_tEC2(const Compostera* handle);
/*! Gets the value of the variable 'TEC3' that is defined in the default interface scope. */ 
extern const sc_integer composteraIface_get_tEC3(const Compostera* handle);
/*! Gets the value of the variable 'TEC4' that is defined in the default interface scope. */ 
extern const sc_integer composteraIface_get_tEC4(const Compostera* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean compostera_isActive(const Compostera* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean compostera_isFinal(const Compostera* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean compostera_isStateActive(const Compostera* handle, ComposteraStates state);


#ifdef __cplusplus
}
#endif 

#endif /* COMPOSTERA_H_ */
