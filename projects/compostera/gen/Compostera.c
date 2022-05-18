
#include "Compostera.h"
#include "..\inc\sc_types.h"
#include "ComposteraRequired.h"

#include <stdlib.h>
#include <string.h>
/*! \file Implementation of the state machine 'compostera'
*/

/* prototypes of all internal functions */
static sc_boolean check_TEC1_DEBOUNCE_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC1_INICIO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC1_OPRIMIDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC1_OPRIMIDO_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC1_VALIDACION_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC1_VALIDACION_O_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC1_NO_OPRIMIDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC1_NO_OPRIMIDO_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC1_DEBOUNCE_N_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC1_VALIDACION_N_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC1_VALIDACION_N_O_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC2_DEBOUNCE_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC2_INICIO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC2_OPRIMIDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC2_OPRIMIDO_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC2_VALIDACION_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC2_VALIDACION_O_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC2_NO_OPRIMIDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC2_NO_OPRIMIDO_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC2_DEBOUNCE_N_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC2_VALIDACION_N_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC2_VALIDACION_N_O_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC3_DEBOUNCE_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC3_INICIO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC3_OPRIMIDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC3_OPRIMIDO_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC3_VALIDACION_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC3_VALIDACION_O_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC3_NO_OPRIMIDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC3_NO_OPRIMIDO_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC3_DEBOUNCE_N_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC3_VALIDACION_N_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC3_VALIDACION_N_O_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC4_DEBOUNCE_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC4_INICIO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC4_OPRIMIDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC4_OPRIMIDO_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC4_VALIDACION_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC4_VALIDACION_O_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC4_NO_OPRIMIDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC4_NO_OPRIMIDO_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC4_DEBOUNCE_N_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC4_VALIDACION_N_O_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC4_VALIDACION_N_O_tr1_tr1(const Compostera* handle);
static sc_boolean check_activity_ESPERANDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_activity_ESPERANDO_tr1_tr1(const Compostera* handle);
static sc_boolean check_activity_ESPERANDO_tr2_tr2(const Compostera* handle);
static sc_boolean check_activity_ESPERANDO_tr3_tr3(const Compostera* handle);
static sc_boolean check_activity_ENFRIANDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_activity_ENFRIANDO_tr1_tr1(const Compostera* handle);
static sc_boolean check_activity_HUMEDECIENDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_activity_HUMEDECIENDO_tr1_tr1(const Compostera* handle);
static sc_boolean check_activity_DESHUMEDECIENDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_activity_DESHUMEDECIENDO_tr1_tr1(const Compostera* handle);
static sc_boolean check_activity_COMPOSTANDO_r1_RELLENANDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_activity_COMPOSTANDO_r1_RELLENANDO_tr1_tr1(const Compostera* handle);
static sc_boolean check_activity_COMPOSTANDO_r1_SONANDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_activity_COMPOSTANDO_r1_MEZCLANDO_tr0_tr0(const Compostera* handle);
static void effect_TEC1_DEBOUNCE_O_tr0(Compostera* handle);
static void effect_TEC1_INICIO_tr0(Compostera* handle);
static void effect_TEC1_OPRIMIDO_tr0(Compostera* handle);
static void effect_TEC1_OPRIMIDO_tr1(Compostera* handle);
static void effect_TEC1_VALIDACION_O_tr0(Compostera* handle);
static void effect_TEC1_VALIDACION_O_tr1(Compostera* handle);
static void effect_TEC1_NO_OPRIMIDO_tr0(Compostera* handle);
static void effect_TEC1_NO_OPRIMIDO_tr1(Compostera* handle);
static void effect_TEC1_DEBOUNCE_N_O_tr0(Compostera* handle);
static void effect_TEC1_VALIDACION_N_O_tr0(Compostera* handle);
static void effect_TEC1_VALIDACION_N_O_tr1(Compostera* handle);
static void effect_TEC2_DEBOUNCE_O_tr0(Compostera* handle);
static void effect_TEC2_INICIO_tr0(Compostera* handle);
static void effect_TEC2_OPRIMIDO_tr0(Compostera* handle);
static void effect_TEC2_OPRIMIDO_tr1(Compostera* handle);
static void effect_TEC2_VALIDACION_O_tr0(Compostera* handle);
static void effect_TEC2_VALIDACION_O_tr1(Compostera* handle);
static void effect_TEC2_NO_OPRIMIDO_tr0(Compostera* handle);
static void effect_TEC2_NO_OPRIMIDO_tr1(Compostera* handle);
static void effect_TEC2_DEBOUNCE_N_O_tr0(Compostera* handle);
static void effect_TEC2_VALIDACION_N_O_tr0(Compostera* handle);
static void effect_TEC2_VALIDACION_N_O_tr1(Compostera* handle);
static void effect_TEC3_DEBOUNCE_O_tr0(Compostera* handle);
static void effect_TEC3_INICIO_tr0(Compostera* handle);
static void effect_TEC3_OPRIMIDO_tr0(Compostera* handle);
static void effect_TEC3_OPRIMIDO_tr1(Compostera* handle);
static void effect_TEC3_VALIDACION_O_tr0(Compostera* handle);
static void effect_TEC3_VALIDACION_O_tr1(Compostera* handle);
static void effect_TEC3_NO_OPRIMIDO_tr0(Compostera* handle);
static void effect_TEC3_NO_OPRIMIDO_tr1(Compostera* handle);
static void effect_TEC3_DEBOUNCE_N_O_tr0(Compostera* handle);
static void effect_TEC3_VALIDACION_N_O_tr0(Compostera* handle);
static void effect_TEC3_VALIDACION_N_O_tr1(Compostera* handle);
static void effect_TEC4_DEBOUNCE_O_tr0(Compostera* handle);
static void effect_TEC4_INICIO_tr0(Compostera* handle);
static void effect_TEC4_OPRIMIDO_tr0(Compostera* handle);
static void effect_TEC4_OPRIMIDO_tr1(Compostera* handle);
static void effect_TEC4_VALIDACION_O_tr0(Compostera* handle);
static void effect_TEC4_VALIDACION_O_tr1(Compostera* handle);
static void effect_TEC4_NO_OPRIMIDO_tr0(Compostera* handle);
static void effect_TEC4_NO_OPRIMIDO_tr1(Compostera* handle);
static void effect_TEC4_DEBOUNCE_N_O_tr0(Compostera* handle);
static void effect_TEC4_VALIDACION_N_O_tr0(Compostera* handle);
static void effect_TEC4_VALIDACION_N_O_tr1(Compostera* handle);
static void effect_activity_ESPERANDO_tr0(Compostera* handle);
static void effect_activity_ESPERANDO_tr1(Compostera* handle);
static void effect_activity_ESPERANDO_tr2(Compostera* handle);
static void effect_activity_ESPERANDO_tr3(Compostera* handle);
static void effect_activity_ENFRIANDO_tr0(Compostera* handle);
static void effect_activity_ENFRIANDO_tr1(Compostera* handle);
static void effect_activity_HUMEDECIENDO_tr0(Compostera* handle);
static void effect_activity_HUMEDECIENDO_tr1(Compostera* handle);
static void effect_activity_DESHUMEDECIENDO_tr0(Compostera* handle);
static void effect_activity_DESHUMEDECIENDO_tr1(Compostera* handle);
static void effect_activity_COMPOSTANDO_tr0(Compostera* handle);
static void effect_activity_COMPOSTANDO_r1_RELLENANDO_tr0(Compostera* handle);
static void effect_activity_COMPOSTANDO_r1_RELLENANDO_tr1(Compostera* handle);
static void effect_activity_COMPOSTANDO_r1_SONANDO_tr0(Compostera* handle);
static void effect_activity_COMPOSTANDO_r1_MEZCLANDO_tr0(Compostera* handle);
static void enact_TEC1_DEBOUNCE_O(Compostera* handle);
static void enact_TEC1_OPRIMIDO(Compostera* handle);
static void enact_TEC1_NO_OPRIMIDO(Compostera* handle);
static void enact_TEC1_DEBOUNCE_N_O(Compostera* handle);
static void enact_TEC2_DEBOUNCE_O(Compostera* handle);
static void enact_TEC2_OPRIMIDO(Compostera* handle);
static void enact_TEC2_NO_OPRIMIDO(Compostera* handle);
static void enact_TEC2_DEBOUNCE_N_O(Compostera* handle);
static void enact_TEC3_DEBOUNCE_O(Compostera* handle);
static void enact_TEC3_OPRIMIDO(Compostera* handle);
static void enact_TEC3_NO_OPRIMIDO(Compostera* handle);
static void enact_TEC3_DEBOUNCE_N_O(Compostera* handle);
static void enact_TEC4_DEBOUNCE_O(Compostera* handle);
static void enact_TEC4_OPRIMIDO(Compostera* handle);
static void enact_TEC4_NO_OPRIMIDO(Compostera* handle);
static void enact_TEC4_DEBOUNCE_N_O(Compostera* handle);
static void enact_activity_ESPERANDO(Compostera* handle);
static void enact_activity_ENFRIANDO(Compostera* handle);
static void enact_activity_HUMEDECIENDO(Compostera* handle);
static void enact_activity_DESHUMEDECIENDO(Compostera* handle);
static void enact_activity_COMPOSTANDO_r1_RELLENANDO(Compostera* handle);
static void enact_activity_COMPOSTANDO_r1_SONANDO(Compostera* handle);
static void enact_activity_COMPOSTANDO_r1_MEZCLANDO(Compostera* handle);
static void exact_TEC1_DEBOUNCE_O(Compostera* handle);
static void exact_TEC1_DEBOUNCE_N_O(Compostera* handle);
static void exact_TEC2_DEBOUNCE_O(Compostera* handle);
static void exact_TEC2_DEBOUNCE_N_O(Compostera* handle);
static void exact_TEC3_DEBOUNCE_O(Compostera* handle);
static void exact_TEC3_DEBOUNCE_N_O(Compostera* handle);
static void exact_TEC4_DEBOUNCE_O(Compostera* handle);
static void exact_TEC4_DEBOUNCE_N_O(Compostera* handle);
static void exact_activity_COMPOSTANDO_r1_RELLENANDO(Compostera* handle);
static void exact_activity_COMPOSTANDO_r1_MEZCLANDO(Compostera* handle);
static void enseq_TEC1_DEBOUNCE_O_default(Compostera* handle);
static void enseq_TEC1_INICIO_default(Compostera* handle);
static void enseq_TEC1_OPRIMIDO_default(Compostera* handle);
static void enseq_TEC1_VALIDACION_O_default(Compostera* handle);
static void enseq_TEC1_NO_OPRIMIDO_default(Compostera* handle);
static void enseq_TEC1_DEBOUNCE_N_O_default(Compostera* handle);
static void enseq_TEC1_VALIDACION_N_O_default(Compostera* handle);
static void enseq_TEC2_DEBOUNCE_O_default(Compostera* handle);
static void enseq_TEC2_INICIO_default(Compostera* handle);
static void enseq_TEC2_OPRIMIDO_default(Compostera* handle);
static void enseq_TEC2_VALIDACION_O_default(Compostera* handle);
static void enseq_TEC2_NO_OPRIMIDO_default(Compostera* handle);
static void enseq_TEC2_DEBOUNCE_N_O_default(Compostera* handle);
static void enseq_TEC2_VALIDACION_N_O_default(Compostera* handle);
static void enseq_TEC3_DEBOUNCE_O_default(Compostera* handle);
static void enseq_TEC3_INICIO_default(Compostera* handle);
static void enseq_TEC3_OPRIMIDO_default(Compostera* handle);
static void enseq_TEC3_VALIDACION_O_default(Compostera* handle);
static void enseq_TEC3_NO_OPRIMIDO_default(Compostera* handle);
static void enseq_TEC3_DEBOUNCE_N_O_default(Compostera* handle);
static void enseq_TEC3_VALIDACION_N_O_default(Compostera* handle);
static void enseq_TEC4_DEBOUNCE_O_default(Compostera* handle);
static void enseq_TEC4_INICIO_default(Compostera* handle);
static void enseq_TEC4_OPRIMIDO_default(Compostera* handle);
static void enseq_TEC4_VALIDACION_O_default(Compostera* handle);
static void enseq_TEC4_NO_OPRIMIDO_default(Compostera* handle);
static void enseq_TEC4_DEBOUNCE_N_O_default(Compostera* handle);
static void enseq_TEC4_VALIDACION_N_O_default(Compostera* handle);
static void enseq_activity_ESPERANDO_default(Compostera* handle);
static void enseq_activity_ENFRIANDO_default(Compostera* handle);
static void enseq_activity_HUMEDECIENDO_default(Compostera* handle);
static void enseq_activity_DESHUMEDECIENDO_default(Compostera* handle);
static void enseq_activity_COMPOSTANDO_default(Compostera* handle);
static void enseq_activity_COMPOSTANDO_r1_RELLENANDO_default(Compostera* handle);
static void enseq_activity_COMPOSTANDO_r1_SONANDO_default(Compostera* handle);
static void enseq_activity_COMPOSTANDO_r1_MEZCLANDO_default(Compostera* handle);
static void enseq_TEC1_default(Compostera* handle);
static void enseq_TEC2_default(Compostera* handle);
static void enseq_TEC3_default(Compostera* handle);
static void enseq_TEC4_default(Compostera* handle);
static void enseq_activity_default(Compostera* handle);
static void enseq_activity_COMPOSTANDO_r1_default(Compostera* handle);
static void exseq_TEC1_DEBOUNCE_O(Compostera* handle);
static void exseq_TEC1_INICIO(Compostera* handle);
static void exseq_TEC1_OPRIMIDO(Compostera* handle);
static void exseq_TEC1_VALIDACION_O(Compostera* handle);
static void exseq_TEC1_NO_OPRIMIDO(Compostera* handle);
static void exseq_TEC1_DEBOUNCE_N_O(Compostera* handle);
static void exseq_TEC1_VALIDACION_N_O(Compostera* handle);
static void exseq_TEC2_DEBOUNCE_O(Compostera* handle);
static void exseq_TEC2_INICIO(Compostera* handle);
static void exseq_TEC2_OPRIMIDO(Compostera* handle);
static void exseq_TEC2_VALIDACION_O(Compostera* handle);
static void exseq_TEC2_NO_OPRIMIDO(Compostera* handle);
static void exseq_TEC2_DEBOUNCE_N_O(Compostera* handle);
static void exseq_TEC2_VALIDACION_N_O(Compostera* handle);
static void exseq_TEC3_DEBOUNCE_O(Compostera* handle);
static void exseq_TEC3_INICIO(Compostera* handle);
static void exseq_TEC3_OPRIMIDO(Compostera* handle);
static void exseq_TEC3_VALIDACION_O(Compostera* handle);
static void exseq_TEC3_NO_OPRIMIDO(Compostera* handle);
static void exseq_TEC3_DEBOUNCE_N_O(Compostera* handle);
static void exseq_TEC3_VALIDACION_N_O(Compostera* handle);
static void exseq_TEC4_DEBOUNCE_O(Compostera* handle);
static void exseq_TEC4_INICIO(Compostera* handle);
static void exseq_TEC4_OPRIMIDO(Compostera* handle);
static void exseq_TEC4_VALIDACION_O(Compostera* handle);
static void exseq_TEC4_NO_OPRIMIDO(Compostera* handle);
static void exseq_TEC4_DEBOUNCE_N_O(Compostera* handle);
static void exseq_TEC4_VALIDACION_N_O(Compostera* handle);
static void exseq_activity_ESPERANDO(Compostera* handle);
static void exseq_activity_ENFRIANDO(Compostera* handle);
static void exseq_activity_HUMEDECIENDO(Compostera* handle);
static void exseq_activity_DESHUMEDECIENDO(Compostera* handle);
static void exseq_activity_COMPOSTANDO(Compostera* handle);
static void exseq_activity_COMPOSTANDO_r1_RELLENANDO(Compostera* handle);
static void exseq_activity_COMPOSTANDO_r1_SONANDO(Compostera* handle);
static void exseq_activity_COMPOSTANDO_r1_MEZCLANDO(Compostera* handle);
static void exseq_TEC1(Compostera* handle);
static void exseq_TEC2(Compostera* handle);
static void exseq_TEC3(Compostera* handle);
static void exseq_TEC4(Compostera* handle);
static void exseq_activity(Compostera* handle);
static void exseq_activity_COMPOSTANDO_r1(Compostera* handle);
static void react_TEC1_DEBOUNCE_O(Compostera* handle);
static void react_TEC1_INICIO(Compostera* handle);
static void react_TEC1_OPRIMIDO(Compostera* handle);
static void react_TEC1_VALIDACION_O(Compostera* handle);
static void react_TEC1_NO_OPRIMIDO(Compostera* handle);
static void react_TEC1_DEBOUNCE_N_O(Compostera* handle);
static void react_TEC1_VALIDACION_N_O(Compostera* handle);
static void react_TEC2_DEBOUNCE_O(Compostera* handle);
static void react_TEC2_INICIO(Compostera* handle);
static void react_TEC2_OPRIMIDO(Compostera* handle);
static void react_TEC2_VALIDACION_O(Compostera* handle);
static void react_TEC2_NO_OPRIMIDO(Compostera* handle);
static void react_TEC2_DEBOUNCE_N_O(Compostera* handle);
static void react_TEC2_VALIDACION_N_O(Compostera* handle);
static void react_TEC3_DEBOUNCE_O(Compostera* handle);
static void react_TEC3_INICIO(Compostera* handle);
static void react_TEC3_OPRIMIDO(Compostera* handle);
static void react_TEC3_VALIDACION_O(Compostera* handle);
static void react_TEC3_NO_OPRIMIDO(Compostera* handle);
static void react_TEC3_DEBOUNCE_N_O(Compostera* handle);
static void react_TEC3_VALIDACION_N_O(Compostera* handle);
static void react_TEC4_DEBOUNCE_O(Compostera* handle);
static void react_TEC4_INICIO(Compostera* handle);
static void react_TEC4_OPRIMIDO(Compostera* handle);
static void react_TEC4_VALIDACION_O(Compostera* handle);
static void react_TEC4_NO_OPRIMIDO(Compostera* handle);
static void react_TEC4_DEBOUNCE_N_O(Compostera* handle);
static void react_TEC4_VALIDACION_N_O(Compostera* handle);
static void react_activity_ESPERANDO(Compostera* handle);
static void react_activity_ENFRIANDO(Compostera* handle);
static void react_activity_HUMEDECIENDO(Compostera* handle);
static void react_activity_DESHUMEDECIENDO(Compostera* handle);
static void react_activity_COMPOSTANDO_r1_RELLENANDO(Compostera* handle);
static void react_activity_COMPOSTANDO_r1_SONANDO(Compostera* handle);
static void react_activity_COMPOSTANDO_r1_MEZCLANDO(Compostera* handle);
static void react_TEC1__entry_Default(Compostera* handle);
static void react_TEC2__entry_Default(Compostera* handle);
static void react_TEC3__entry_Default(Compostera* handle);
static void react_TEC4__entry_Default(Compostera* handle);
static void react_activity__entry_Default(Compostera* handle);
static void react_activity_COMPOSTANDO_r1__entry_Default(Compostera* handle);
static void react_activity_COMPOSTANDO_r1__exit_Default(Compostera* handle);
static void clearInEvents(Compostera* handle);
static void clearOutEvents(Compostera* handle);

const sc_integer COMPOSTERA_COMPOSTERAIFACE_LEDR = 0;
const sc_integer COMPOSTERA_COMPOSTERAIFACE_LEDG = 1;
const sc_integer COMPOSTERA_COMPOSTERAIFACE_LEDB = 2;
const sc_integer COMPOSTERA_COMPOSTERAIFACE_LED1 = 3;
const sc_integer COMPOSTERA_COMPOSTERAIFACE_LED2 = 4;
const sc_integer COMPOSTERA_COMPOSTERAIFACE_LED3 = 5;
const sc_boolean COMPOSTERA_COMPOSTERAIFACE_LED_ON = bool_true;
const sc_boolean COMPOSTERA_COMPOSTERAIFACE_LED_OFF = bool_false;
const sc_integer COMPOSTERA_COMPOSTERAIFACE_TEC1 = 1 << 0;
const sc_integer COMPOSTERA_COMPOSTERAIFACE_TEC2 = 1 << 1;
const sc_integer COMPOSTERA_COMPOSTERAIFACE_TEC3 = 1 << 2;
const sc_integer COMPOSTERA_COMPOSTERAIFACE_TEC4 = 1 << 3;

void compostera_init(Compostera* handle)
{
		sc_integer i;
	
		for (i = 0; i < COMPOSTERA_MAX_ORTHOGONAL_STATES; ++i)
		{
			handle->stateConfVector[i] = Compostera_last_state;
		}
		
		
		handle->stateConfVectorPosition = 0;
	
		clearInEvents(handle);
		clearOutEvents(handle);
	
}

void compostera_enter(Compostera* handle)
{
	/* Default enter sequence for statechart compostera */
	enseq_TEC1_default(handle);
	enseq_TEC2_default(handle);
	enseq_TEC3_default(handle);
	enseq_TEC4_default(handle);
	enseq_activity_default(handle);
}

void compostera_runCycle(Compostera* handle)
{
	clearOutEvents(handle);
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < COMPOSTERA_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Compostera_TEC1_DEBOUNCE_O:
		{
			react_TEC1_DEBOUNCE_O(handle);
			break;
		}
		case Compostera_TEC1_INICIO:
		{
			react_TEC1_INICIO(handle);
			break;
		}
		case Compostera_TEC1_OPRIMIDO:
		{
			react_TEC1_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC1_VALIDACION_O:
		{
			react_TEC1_VALIDACION_O(handle);
			break;
		}
		case Compostera_TEC1_NO_OPRIMIDO:
		{
			react_TEC1_NO_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC1_DEBOUNCE_N_O:
		{
			react_TEC1_DEBOUNCE_N_O(handle);
			break;
		}
		case Compostera_TEC1_VALIDACION_N_O:
		{
			react_TEC1_VALIDACION_N_O(handle);
			break;
		}
		case Compostera_TEC2_DEBOUNCE_O:
		{
			react_TEC2_DEBOUNCE_O(handle);
			break;
		}
		case Compostera_TEC2_INICIO:
		{
			react_TEC2_INICIO(handle);
			break;
		}
		case Compostera_TEC2_OPRIMIDO:
		{
			react_TEC2_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC2_VALIDACION_O:
		{
			react_TEC2_VALIDACION_O(handle);
			break;
		}
		case Compostera_TEC2_NO_OPRIMIDO:
		{
			react_TEC2_NO_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC2_DEBOUNCE_N_O:
		{
			react_TEC2_DEBOUNCE_N_O(handle);
			break;
		}
		case Compostera_TEC2_VALIDACION_N_O:
		{
			react_TEC2_VALIDACION_N_O(handle);
			break;
		}
		case Compostera_TEC3_DEBOUNCE_O:
		{
			react_TEC3_DEBOUNCE_O(handle);
			break;
		}
		case Compostera_TEC3_INICIO:
		{
			react_TEC3_INICIO(handle);
			break;
		}
		case Compostera_TEC3_OPRIMIDO:
		{
			react_TEC3_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC3_VALIDACION_O:
		{
			react_TEC3_VALIDACION_O(handle);
			break;
		}
		case Compostera_TEC3_NO_OPRIMIDO:
		{
			react_TEC3_NO_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC3_DEBOUNCE_N_O:
		{
			react_TEC3_DEBOUNCE_N_O(handle);
			break;
		}
		case Compostera_TEC3_VALIDACION_N_O:
		{
			react_TEC3_VALIDACION_N_O(handle);
			break;
		}
		case Compostera_TEC4_DEBOUNCE_O:
		{
			react_TEC4_DEBOUNCE_O(handle);
			break;
		}
		case Compostera_TEC4_INICIO:
		{
			react_TEC4_INICIO(handle);
			break;
		}
		case Compostera_TEC4_OPRIMIDO:
		{
			react_TEC4_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC4_VALIDACION_O:
		{
			react_TEC4_VALIDACION_O(handle);
			break;
		}
		case Compostera_TEC4_NO_OPRIMIDO:
		{
			react_TEC4_NO_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC4_DEBOUNCE_N_O:
		{
			react_TEC4_DEBOUNCE_N_O(handle);
			break;
		}
		case Compostera_TEC4_VALIDACION_N_O:
		{
			react_TEC4_VALIDACION_N_O(handle);
			break;
		}
		case Compostera_activity_ESPERANDO:
		{
			react_activity_ESPERANDO(handle);
			break;
		}
		case Compostera_activity_ENFRIANDO:
		{
			react_activity_ENFRIANDO(handle);
			break;
		}
		case Compostera_activity_HUMEDECIENDO:
		{
			react_activity_HUMEDECIENDO(handle);
			break;
		}
		case Compostera_activity_DESHUMEDECIENDO:
		{
			react_activity_DESHUMEDECIENDO(handle);
			break;
		}
		case Compostera_activity_COMPOSTANDO_r1_RELLENANDO:
		{
			react_activity_COMPOSTANDO_r1_RELLENANDO(handle);
			break;
		}
		case Compostera_activity_COMPOSTANDO_r1_SONANDO:
		{
			react_activity_COMPOSTANDO_r1_SONANDO(handle);
			break;
		}
		case Compostera_activity_COMPOSTANDO_r1_MEZCLANDO:
		{
			react_activity_COMPOSTANDO_r1_MEZCLANDO(handle);
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents(handle);
}

void compostera_exit(Compostera* handle)
{
	/* Default exit sequence for statechart compostera */
	exseq_TEC1(handle);
	exseq_TEC2(handle);
	exseq_TEC3(handle);
	exseq_TEC4(handle);
	exseq_activity(handle);
}

sc_boolean compostera_isActive(const Compostera* handle)
{
	sc_boolean result = bool_false;
	int i;
	
	for(i = 0; i < COMPOSTERA_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != Compostera_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean compostera_isFinal(const Compostera* handle)
{
   return bool_false;
}

void compostera_raiseTimeEvent(Compostera* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(ComposteraTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean compostera_isStateActive(const Compostera* handle, ComposteraStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Compostera_TEC1_DEBOUNCE_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_DEBOUNCE_O] == Compostera_TEC1_DEBOUNCE_O
			);
			break;
		case Compostera_TEC1_INICIO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_INICIO] == Compostera_TEC1_INICIO
			);
			break;
		case Compostera_TEC1_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_OPRIMIDO] == Compostera_TEC1_OPRIMIDO
			);
			break;
		case Compostera_TEC1_VALIDACION_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_VALIDACION_O] == Compostera_TEC1_VALIDACION_O
			);
			break;
		case Compostera_TEC1_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_NO_OPRIMIDO] == Compostera_TEC1_NO_OPRIMIDO
			);
			break;
		case Compostera_TEC1_DEBOUNCE_N_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_DEBOUNCE_N_O] == Compostera_TEC1_DEBOUNCE_N_O
			);
			break;
		case Compostera_TEC1_VALIDACION_N_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_VALIDACION_N_O] == Compostera_TEC1_VALIDACION_N_O
			);
			break;
		case Compostera_TEC2_DEBOUNCE_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC2_DEBOUNCE_O] == Compostera_TEC2_DEBOUNCE_O
			);
			break;
		case Compostera_TEC2_INICIO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC2_INICIO] == Compostera_TEC2_INICIO
			);
			break;
		case Compostera_TEC2_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC2_OPRIMIDO] == Compostera_TEC2_OPRIMIDO
			);
			break;
		case Compostera_TEC2_VALIDACION_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC2_VALIDACION_O] == Compostera_TEC2_VALIDACION_O
			);
			break;
		case Compostera_TEC2_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC2_NO_OPRIMIDO] == Compostera_TEC2_NO_OPRIMIDO
			);
			break;
		case Compostera_TEC2_DEBOUNCE_N_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC2_DEBOUNCE_N_O] == Compostera_TEC2_DEBOUNCE_N_O
			);
			break;
		case Compostera_TEC2_VALIDACION_N_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC2_VALIDACION_N_O] == Compostera_TEC2_VALIDACION_N_O
			);
			break;
		case Compostera_TEC3_DEBOUNCE_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC3_DEBOUNCE_O] == Compostera_TEC3_DEBOUNCE_O
			);
			break;
		case Compostera_TEC3_INICIO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC3_INICIO] == Compostera_TEC3_INICIO
			);
			break;
		case Compostera_TEC3_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC3_OPRIMIDO] == Compostera_TEC3_OPRIMIDO
			);
			break;
		case Compostera_TEC3_VALIDACION_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC3_VALIDACION_O] == Compostera_TEC3_VALIDACION_O
			);
			break;
		case Compostera_TEC3_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC3_NO_OPRIMIDO] == Compostera_TEC3_NO_OPRIMIDO
			);
			break;
		case Compostera_TEC3_DEBOUNCE_N_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC3_DEBOUNCE_N_O] == Compostera_TEC3_DEBOUNCE_N_O
			);
			break;
		case Compostera_TEC3_VALIDACION_N_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC3_VALIDACION_N_O] == Compostera_TEC3_VALIDACION_N_O
			);
			break;
		case Compostera_TEC4_DEBOUNCE_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC4_DEBOUNCE_O] == Compostera_TEC4_DEBOUNCE_O
			);
			break;
		case Compostera_TEC4_INICIO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC4_INICIO] == Compostera_TEC4_INICIO
			);
			break;
		case Compostera_TEC4_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC4_OPRIMIDO] == Compostera_TEC4_OPRIMIDO
			);
			break;
		case Compostera_TEC4_VALIDACION_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC4_VALIDACION_O] == Compostera_TEC4_VALIDACION_O
			);
			break;
		case Compostera_TEC4_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC4_NO_OPRIMIDO] == Compostera_TEC4_NO_OPRIMIDO
			);
			break;
		case Compostera_TEC4_DEBOUNCE_N_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC4_DEBOUNCE_N_O] == Compostera_TEC4_DEBOUNCE_N_O
			);
			break;
		case Compostera_TEC4_VALIDACION_N_O :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC4_VALIDACION_N_O] == Compostera_TEC4_VALIDACION_N_O
			);
			break;
		case Compostera_activity_ESPERANDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_ACTIVITY_ESPERANDO] == Compostera_activity_ESPERANDO
			);
			break;
		case Compostera_activity_ENFRIANDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_ACTIVITY_ENFRIANDO] == Compostera_activity_ENFRIANDO
			);
			break;
		case Compostera_activity_HUMEDECIENDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_ACTIVITY_HUMEDECIENDO] == Compostera_activity_HUMEDECIENDO
			);
			break;
		case Compostera_activity_DESHUMEDECIENDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_ACTIVITY_DESHUMEDECIENDO] == Compostera_activity_DESHUMEDECIENDO
			);
			break;
		case Compostera_activity_COMPOSTANDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_ACTIVITY_COMPOSTANDO] >= Compostera_activity_COMPOSTANDO
				&& handle->stateConfVector[SCVI_COMPOSTERA_ACTIVITY_COMPOSTANDO] <= Compostera_activity_COMPOSTANDO_r1_MEZCLANDO);
			break;
		case Compostera_activity_COMPOSTANDO_r1_RELLENANDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_ACTIVITY_COMPOSTANDO_R1_RELLENANDO] == Compostera_activity_COMPOSTANDO_r1_RELLENANDO
			);
			break;
		case Compostera_activity_COMPOSTANDO_r1_SONANDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_ACTIVITY_COMPOSTANDO_R1_SONANDO] == Compostera_activity_COMPOSTANDO_r1_SONANDO
			);
			break;
		case Compostera_activity_COMPOSTANDO_r1_MEZCLANDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_ACTIVITY_COMPOSTANDO_R1_MEZCLANDO] == Compostera_activity_COMPOSTANDO_r1_MEZCLANDO
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

static void clearInEvents(Compostera* handle)
{
	handle->iface.evTEC1NoOprimido_raised = bool_false;
	handle->iface.evTEC1Oprimido_raised = bool_false;
	handle->iface.evTEC2NoOprimido_raised = bool_false;
	handle->iface.evTEC2Oprimido_raised = bool_false;
	handle->iface.evTEC3NoOprimido_raised = bool_false;
	handle->iface.evTEC3Oprimido_raised = bool_false;
	handle->iface.evTEC4NoOprimido_raised = bool_false;
	handle->iface.evTEC4Oprimido_raised = bool_false;
	handle->internal.siTemperaturaMayor60_raised = bool_false;
	handle->internal.siTemperaturaEstable_raised = bool_false;
	handle->internal.siHumedadMenor40_raised = bool_false;
	handle->internal.siHumedadEstable_raised = bool_false;
	handle->internal.siHumedadMayor60_raised = bool_false;
	handle->internal.siAberturaTapa_raised = bool_false;
	handle->internal.siCerradoTapa_raised = bool_false;
	handle->timeEvents.compostera_TEC1_DEBOUNCE_O_tev0_raised = bool_false;
	handle->timeEvents.compostera_TEC1_DEBOUNCE_N_O_tev0_raised = bool_false;
	handle->timeEvents.compostera_TEC2_DEBOUNCE_O_tev0_raised = bool_false;
	handle->timeEvents.compostera_TEC2_DEBOUNCE_N_O_tev0_raised = bool_false;
	handle->timeEvents.compostera_TEC3_DEBOUNCE_O_tev0_raised = bool_false;
	handle->timeEvents.compostera_TEC3_DEBOUNCE_N_O_tev0_raised = bool_false;
	handle->timeEvents.compostera_TEC4_DEBOUNCE_O_tev0_raised = bool_false;
	handle->timeEvents.compostera_TEC4_DEBOUNCE_N_O_tev0_raised = bool_false;
	handle->timeEvents.compostera_activity_COMPOSTANDO_r1_RELLENANDO_tev0_raised = bool_false;
	handle->timeEvents.compostera_activity_COMPOSTANDO_r1_MEZCLANDO_tev0_raised = bool_false;
}

static void clearOutEvents(Compostera* handle)
{
}

void composteraIface_raise_evTEC1NoOprimido(Compostera* handle)
{
	handle->iface.evTEC1NoOprimido_raised = bool_true;
}
void composteraIface_raise_evTEC1Oprimido(Compostera* handle)
{
	handle->iface.evTEC1Oprimido_raised = bool_true;
}
void composteraIface_raise_evTEC2NoOprimido(Compostera* handle)
{
	handle->iface.evTEC2NoOprimido_raised = bool_true;
}
void composteraIface_raise_evTEC2Oprimido(Compostera* handle)
{
	handle->iface.evTEC2Oprimido_raised = bool_true;
}
void composteraIface_raise_evTEC3NoOprimido(Compostera* handle)
{
	handle->iface.evTEC3NoOprimido_raised = bool_true;
}
void composteraIface_raise_evTEC3Oprimido(Compostera* handle)
{
	handle->iface.evTEC3Oprimido_raised = bool_true;
}
void composteraIface_raise_evTEC4NoOprimido(Compostera* handle)
{
	handle->iface.evTEC4NoOprimido_raised = bool_true;
}
void composteraIface_raise_evTEC4Oprimido(Compostera* handle)
{
	handle->iface.evTEC4Oprimido_raised = bool_true;
}


const sc_integer composteraIface_get_lEDR(const Compostera* handle)
{
	return COMPOSTERA_COMPOSTERAIFACE_LEDR;
}
const sc_integer composteraIface_get_lEDG(const Compostera* handle)
{
	return COMPOSTERA_COMPOSTERAIFACE_LEDG;
}
const sc_integer composteraIface_get_lEDB(const Compostera* handle)
{
	return COMPOSTERA_COMPOSTERAIFACE_LEDB;
}
const sc_integer composteraIface_get_lED1(const Compostera* handle)
{
	return COMPOSTERA_COMPOSTERAIFACE_LED1;
}
const sc_integer composteraIface_get_lED2(const Compostera* handle)
{
	return COMPOSTERA_COMPOSTERAIFACE_LED2;
}
const sc_integer composteraIface_get_lED3(const Compostera* handle)
{
	return COMPOSTERA_COMPOSTERAIFACE_LED3;
}
const sc_boolean composteraIface_get_lED_ON(const Compostera* handle)
{
	return COMPOSTERA_COMPOSTERAIFACE_LED_ON;
}
const sc_boolean composteraIface_get_lED_OFF(const Compostera* handle)
{
	return COMPOSTERA_COMPOSTERAIFACE_LED_OFF;
}
const sc_integer composteraIface_get_tEC1(const Compostera* handle)
{
	return COMPOSTERA_COMPOSTERAIFACE_TEC1;
}
const sc_integer composteraIface_get_tEC2(const Compostera* handle)
{
	return COMPOSTERA_COMPOSTERAIFACE_TEC2;
}
const sc_integer composteraIface_get_tEC3(const Compostera* handle)
{
	return COMPOSTERA_COMPOSTERAIFACE_TEC3;
}
const sc_integer composteraIface_get_tEC4(const Compostera* handle)
{
	return COMPOSTERA_COMPOSTERAIFACE_TEC4;
}

/* implementations of all internal functions */

static sc_boolean check_TEC1_DEBOUNCE_O_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TEC1_DEBOUNCE_O_tev0_raised;
}

static sc_boolean check_TEC1_INICIO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC1Oprimido_raised;
}

static sc_boolean check_TEC1_OPRIMIDO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC1NoOprimido_raised;
}

static sc_boolean check_TEC1_OPRIMIDO_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC1Oprimido_raised;
}

static sc_boolean check_TEC1_VALIDACION_O_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC1Oprimido_raised;
}

static sc_boolean check_TEC1_VALIDACION_O_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC1NoOprimido_raised;
}

static sc_boolean check_TEC1_NO_OPRIMIDO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC1Oprimido_raised;
}

static sc_boolean check_TEC1_NO_OPRIMIDO_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC1NoOprimido_raised;
}

static sc_boolean check_TEC1_DEBOUNCE_N_O_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TEC1_DEBOUNCE_N_O_tev0_raised;
}

static sc_boolean check_TEC1_VALIDACION_N_O_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC1NoOprimido_raised;
}

static sc_boolean check_TEC1_VALIDACION_N_O_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC1Oprimido_raised;
}

static sc_boolean check_TEC2_DEBOUNCE_O_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TEC2_DEBOUNCE_O_tev0_raised;
}

static sc_boolean check_TEC2_INICIO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC2Oprimido_raised;
}

static sc_boolean check_TEC2_OPRIMIDO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC2NoOprimido_raised;
}

static sc_boolean check_TEC2_OPRIMIDO_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC2Oprimido_raised;
}

static sc_boolean check_TEC2_VALIDACION_O_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC2Oprimido_raised;
}

static sc_boolean check_TEC2_VALIDACION_O_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC2NoOprimido_raised;
}

static sc_boolean check_TEC2_NO_OPRIMIDO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC2Oprimido_raised;
}

static sc_boolean check_TEC2_NO_OPRIMIDO_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC2NoOprimido_raised;
}

static sc_boolean check_TEC2_DEBOUNCE_N_O_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TEC2_DEBOUNCE_N_O_tev0_raised;
}

static sc_boolean check_TEC2_VALIDACION_N_O_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC2NoOprimido_raised;
}

static sc_boolean check_TEC2_VALIDACION_N_O_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC2Oprimido_raised;
}

static sc_boolean check_TEC3_DEBOUNCE_O_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TEC3_DEBOUNCE_O_tev0_raised;
}

static sc_boolean check_TEC3_INICIO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC3Oprimido_raised;
}

static sc_boolean check_TEC3_OPRIMIDO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC3NoOprimido_raised;
}

static sc_boolean check_TEC3_OPRIMIDO_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC3Oprimido_raised;
}

static sc_boolean check_TEC3_VALIDACION_O_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC3Oprimido_raised;
}

static sc_boolean check_TEC3_VALIDACION_O_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC3NoOprimido_raised;
}

static sc_boolean check_TEC3_NO_OPRIMIDO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC3Oprimido_raised;
}

static sc_boolean check_TEC3_NO_OPRIMIDO_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC3NoOprimido_raised;
}

static sc_boolean check_TEC3_DEBOUNCE_N_O_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TEC3_DEBOUNCE_N_O_tev0_raised;
}

static sc_boolean check_TEC3_VALIDACION_N_O_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC3NoOprimido_raised;
}

static sc_boolean check_TEC3_VALIDACION_N_O_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC3Oprimido_raised;
}

static sc_boolean check_TEC4_DEBOUNCE_O_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TEC4_DEBOUNCE_O_tev0_raised;
}

static sc_boolean check_TEC4_INICIO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC4Oprimido_raised;
}

static sc_boolean check_TEC4_OPRIMIDO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC4NoOprimido_raised;
}

static sc_boolean check_TEC4_OPRIMIDO_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC4Oprimido_raised;
}

static sc_boolean check_TEC4_VALIDACION_O_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC4Oprimido_raised;
}

static sc_boolean check_TEC4_VALIDACION_O_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC4NoOprimido_raised;
}

static sc_boolean check_TEC4_NO_OPRIMIDO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC4Oprimido_raised;
}

static sc_boolean check_TEC4_NO_OPRIMIDO_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC4NoOprimido_raised;
}

static sc_boolean check_TEC4_DEBOUNCE_N_O_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TEC4_DEBOUNCE_N_O_tev0_raised;
}

static sc_boolean check_TEC4_VALIDACION_N_O_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC4NoOprimido_raised;
}

static sc_boolean check_TEC4_VALIDACION_N_O_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC4Oprimido_raised;
}

static sc_boolean check_activity_ESPERANDO_tr0_tr0(const Compostera* handle)
{
	return handle->internal.siTemperaturaMayor60_raised;
}

static sc_boolean check_activity_ESPERANDO_tr1_tr1(const Compostera* handle)
{
	return handle->internal.siHumedadMenor40_raised;
}

static sc_boolean check_activity_ESPERANDO_tr2_tr2(const Compostera* handle)
{
	return handle->internal.siHumedadMayor60_raised;
}

static sc_boolean check_activity_ESPERANDO_tr3_tr3(const Compostera* handle)
{
	return handle->internal.siAberturaTapa_raised;
}

static sc_boolean check_activity_ENFRIANDO_tr0_tr0(const Compostera* handle)
{
	return handle->internal.siTemperaturaEstable_raised;
}

static sc_boolean check_activity_ENFRIANDO_tr1_tr1(const Compostera* handle)
{
	return handle->internal.siAberturaTapa_raised;
}

static sc_boolean check_activity_HUMEDECIENDO_tr0_tr0(const Compostera* handle)
{
	return handle->internal.siHumedadEstable_raised;
}

static sc_boolean check_activity_HUMEDECIENDO_tr1_tr1(const Compostera* handle)
{
	return handle->internal.siAberturaTapa_raised;
}

static sc_boolean check_activity_DESHUMEDECIENDO_tr0_tr0(const Compostera* handle)
{
	return handle->internal.siHumedadEstable_raised;
}

static sc_boolean check_activity_DESHUMEDECIENDO_tr1_tr1(const Compostera* handle)
{
	return handle->internal.siAberturaTapa_raised;
}

static sc_boolean check_activity_COMPOSTANDO_r1_RELLENANDO_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_activity_COMPOSTANDO_r1_RELLENANDO_tev0_raised;
}

static sc_boolean check_activity_COMPOSTANDO_r1_RELLENANDO_tr1_tr1(const Compostera* handle)
{
	return handle->internal.siCerradoTapa_raised;
}

static sc_boolean check_activity_COMPOSTANDO_r1_SONANDO_tr0_tr0(const Compostera* handle)
{
	return handle->internal.siCerradoTapa_raised;
}

static sc_boolean check_activity_COMPOSTANDO_r1_MEZCLANDO_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_activity_COMPOSTANDO_r1_MEZCLANDO_tev0_raised;
}

static void effect_TEC1_DEBOUNCE_O_tr0(Compostera* handle)
{
	exseq_TEC1_DEBOUNCE_O(handle);
	enseq_TEC1_VALIDACION_O_default(handle);
}

static void effect_TEC1_INICIO_tr0(Compostera* handle)
{
	exseq_TEC1_INICIO(handle);
	enseq_TEC1_DEBOUNCE_O_default(handle);
}

static void effect_TEC1_OPRIMIDO_tr0(Compostera* handle)
{
	exseq_TEC1_OPRIMIDO(handle);
	enseq_TEC1_DEBOUNCE_N_O_default(handle);
}

static void effect_TEC1_OPRIMIDO_tr1(Compostera* handle)
{
	exseq_TEC1_OPRIMIDO(handle);
	enseq_TEC1_OPRIMIDO_default(handle);
}

static void effect_TEC1_VALIDACION_O_tr0(Compostera* handle)
{
	exseq_TEC1_VALIDACION_O(handle);
	enseq_TEC1_OPRIMIDO_default(handle);
}

static void effect_TEC1_VALIDACION_O_tr1(Compostera* handle)
{
	exseq_TEC1_VALIDACION_O(handle);
	enseq_TEC1_NO_OPRIMIDO_default(handle);
}

static void effect_TEC1_NO_OPRIMIDO_tr0(Compostera* handle)
{
	exseq_TEC1_NO_OPRIMIDO(handle);
	enseq_TEC1_DEBOUNCE_O_default(handle);
}

static void effect_TEC1_NO_OPRIMIDO_tr1(Compostera* handle)
{
	exseq_TEC1_NO_OPRIMIDO(handle);
	enseq_TEC1_NO_OPRIMIDO_default(handle);
}

static void effect_TEC1_DEBOUNCE_N_O_tr0(Compostera* handle)
{
	exseq_TEC1_DEBOUNCE_N_O(handle);
	enseq_TEC1_VALIDACION_N_O_default(handle);
}

static void effect_TEC1_VALIDACION_N_O_tr0(Compostera* handle)
{
	exseq_TEC1_VALIDACION_N_O(handle);
	enseq_TEC1_NO_OPRIMIDO_default(handle);
}

static void effect_TEC1_VALIDACION_N_O_tr1(Compostera* handle)
{
	exseq_TEC1_VALIDACION_N_O(handle);
	enseq_TEC1_OPRIMIDO_default(handle);
}

static void effect_TEC2_DEBOUNCE_O_tr0(Compostera* handle)
{
	exseq_TEC2_DEBOUNCE_O(handle);
	enseq_TEC2_VALIDACION_O_default(handle);
}

static void effect_TEC2_INICIO_tr0(Compostera* handle)
{
	exseq_TEC2_INICIO(handle);
	enseq_TEC2_DEBOUNCE_O_default(handle);
}

static void effect_TEC2_OPRIMIDO_tr0(Compostera* handle)
{
	exseq_TEC2_OPRIMIDO(handle);
	enseq_TEC2_DEBOUNCE_N_O_default(handle);
}

static void effect_TEC2_OPRIMIDO_tr1(Compostera* handle)
{
	exseq_TEC2_OPRIMIDO(handle);
	enseq_TEC2_OPRIMIDO_default(handle);
}

static void effect_TEC2_VALIDACION_O_tr0(Compostera* handle)
{
	exseq_TEC2_VALIDACION_O(handle);
	enseq_TEC2_OPRIMIDO_default(handle);
}

static void effect_TEC2_VALIDACION_O_tr1(Compostera* handle)
{
	exseq_TEC2_VALIDACION_O(handle);
	enseq_TEC2_NO_OPRIMIDO_default(handle);
}

static void effect_TEC2_NO_OPRIMIDO_tr0(Compostera* handle)
{
	exseq_TEC2_NO_OPRIMIDO(handle);
	enseq_TEC2_DEBOUNCE_O_default(handle);
}

static void effect_TEC2_NO_OPRIMIDO_tr1(Compostera* handle)
{
	exseq_TEC2_NO_OPRIMIDO(handle);
	enseq_TEC2_NO_OPRIMIDO_default(handle);
}

static void effect_TEC2_DEBOUNCE_N_O_tr0(Compostera* handle)
{
	exseq_TEC2_DEBOUNCE_N_O(handle);
	enseq_TEC2_VALIDACION_N_O_default(handle);
}

static void effect_TEC2_VALIDACION_N_O_tr0(Compostera* handle)
{
	exseq_TEC2_VALIDACION_N_O(handle);
	enseq_TEC2_NO_OPRIMIDO_default(handle);
}

static void effect_TEC2_VALIDACION_N_O_tr1(Compostera* handle)
{
	exseq_TEC2_VALIDACION_N_O(handle);
	enseq_TEC2_OPRIMIDO_default(handle);
}

static void effect_TEC3_DEBOUNCE_O_tr0(Compostera* handle)
{
	exseq_TEC3_DEBOUNCE_O(handle);
	enseq_TEC3_VALIDACION_O_default(handle);
}

static void effect_TEC3_INICIO_tr0(Compostera* handle)
{
	exseq_TEC3_INICIO(handle);
	enseq_TEC3_DEBOUNCE_O_default(handle);
}

static void effect_TEC3_OPRIMIDO_tr0(Compostera* handle)
{
	exseq_TEC3_OPRIMIDO(handle);
	enseq_TEC3_DEBOUNCE_N_O_default(handle);
}

static void effect_TEC3_OPRIMIDO_tr1(Compostera* handle)
{
	exseq_TEC3_OPRIMIDO(handle);
	enseq_TEC3_OPRIMIDO_default(handle);
}

static void effect_TEC3_VALIDACION_O_tr0(Compostera* handle)
{
	exseq_TEC3_VALIDACION_O(handle);
	enseq_TEC3_OPRIMIDO_default(handle);
}

static void effect_TEC3_VALIDACION_O_tr1(Compostera* handle)
{
	exseq_TEC3_VALIDACION_O(handle);
	enseq_TEC3_NO_OPRIMIDO_default(handle);
}

static void effect_TEC3_NO_OPRIMIDO_tr0(Compostera* handle)
{
	exseq_TEC3_NO_OPRIMIDO(handle);
	enseq_TEC3_DEBOUNCE_O_default(handle);
}

static void effect_TEC3_NO_OPRIMIDO_tr1(Compostera* handle)
{
	exseq_TEC3_NO_OPRIMIDO(handle);
	enseq_TEC3_NO_OPRIMIDO_default(handle);
}

static void effect_TEC3_DEBOUNCE_N_O_tr0(Compostera* handle)
{
	exseq_TEC3_DEBOUNCE_N_O(handle);
	enseq_TEC3_VALIDACION_N_O_default(handle);
}

static void effect_TEC3_VALIDACION_N_O_tr0(Compostera* handle)
{
	exseq_TEC3_VALIDACION_N_O(handle);
	enseq_TEC3_NO_OPRIMIDO_default(handle);
}

static void effect_TEC3_VALIDACION_N_O_tr1(Compostera* handle)
{
	exseq_TEC3_VALIDACION_N_O(handle);
	enseq_TEC3_OPRIMIDO_default(handle);
}

static void effect_TEC4_DEBOUNCE_O_tr0(Compostera* handle)
{
	exseq_TEC4_DEBOUNCE_O(handle);
	enseq_TEC4_VALIDACION_O_default(handle);
}

static void effect_TEC4_INICIO_tr0(Compostera* handle)
{
	exseq_TEC4_INICIO(handle);
	enseq_TEC4_DEBOUNCE_O_default(handle);
}

static void effect_TEC4_OPRIMIDO_tr0(Compostera* handle)
{
	exseq_TEC4_OPRIMIDO(handle);
	enseq_TEC4_DEBOUNCE_N_O_default(handle);
}

static void effect_TEC4_OPRIMIDO_tr1(Compostera* handle)
{
	exseq_TEC4_OPRIMIDO(handle);
	enseq_TEC4_OPRIMIDO_default(handle);
}

static void effect_TEC4_VALIDACION_O_tr0(Compostera* handle)
{
	exseq_TEC4_VALIDACION_O(handle);
	enseq_TEC4_OPRIMIDO_default(handle);
}

static void effect_TEC4_VALIDACION_O_tr1(Compostera* handle)
{
	exseq_TEC4_VALIDACION_O(handle);
	enseq_TEC4_NO_OPRIMIDO_default(handle);
}

static void effect_TEC4_NO_OPRIMIDO_tr0(Compostera* handle)
{
	exseq_TEC4_NO_OPRIMIDO(handle);
	enseq_TEC4_DEBOUNCE_O_default(handle);
}

static void effect_TEC4_NO_OPRIMIDO_tr1(Compostera* handle)
{
	exseq_TEC4_NO_OPRIMIDO(handle);
	enseq_TEC4_NO_OPRIMIDO_default(handle);
}

static void effect_TEC4_DEBOUNCE_N_O_tr0(Compostera* handle)
{
	exseq_TEC4_DEBOUNCE_N_O(handle);
	enseq_TEC4_VALIDACION_N_O_default(handle);
}

static void effect_TEC4_VALIDACION_N_O_tr0(Compostera* handle)
{
	exseq_TEC4_VALIDACION_N_O(handle);
	enseq_TEC4_NO_OPRIMIDO_default(handle);
}

static void effect_TEC4_VALIDACION_N_O_tr1(Compostera* handle)
{
	exseq_TEC4_VALIDACION_N_O(handle);
	enseq_TEC4_OPRIMIDO_default(handle);
}

static void effect_activity_ESPERANDO_tr0(Compostera* handle)
{
	exseq_activity_ESPERANDO(handle);
	enseq_activity_ENFRIANDO_default(handle);
}

static void effect_activity_ESPERANDO_tr1(Compostera* handle)
{
	exseq_activity_ESPERANDO(handle);
	enseq_activity_HUMEDECIENDO_default(handle);
}

static void effect_activity_ESPERANDO_tr2(Compostera* handle)
{
	exseq_activity_ESPERANDO(handle);
	enseq_activity_DESHUMEDECIENDO_default(handle);
}

static void effect_activity_ESPERANDO_tr3(Compostera* handle)
{
	exseq_activity_ESPERANDO(handle);
	enseq_activity_COMPOSTANDO_default(handle);
}

static void effect_activity_ENFRIANDO_tr0(Compostera* handle)
{
	exseq_activity_ENFRIANDO(handle);
	enseq_activity_ESPERANDO_default(handle);
}

static void effect_activity_ENFRIANDO_tr1(Compostera* handle)
{
	exseq_activity_ENFRIANDO(handle);
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LEDR, COMPOSTERA_COMPOSTERAIFACE_LED_OFF);
	enseq_activity_COMPOSTANDO_default(handle);
}

static void effect_activity_HUMEDECIENDO_tr0(Compostera* handle)
{
	exseq_activity_HUMEDECIENDO(handle);
	enseq_activity_ESPERANDO_default(handle);
}

static void effect_activity_HUMEDECIENDO_tr1(Compostera* handle)
{
	exseq_activity_HUMEDECIENDO(handle);
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LEDG, COMPOSTERA_COMPOSTERAIFACE_LED_OFF);
	enseq_activity_COMPOSTANDO_default(handle);
}

static void effect_activity_DESHUMEDECIENDO_tr0(Compostera* handle)
{
	exseq_activity_DESHUMEDECIENDO(handle);
	enseq_activity_ESPERANDO_default(handle);
}

static void effect_activity_DESHUMEDECIENDO_tr1(Compostera* handle)
{
	exseq_activity_DESHUMEDECIENDO(handle);
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LEDB, COMPOSTERA_COMPOSTERAIFACE_LED_OFF);
	enseq_activity_COMPOSTANDO_default(handle);
}

static void effect_activity_COMPOSTANDO_tr0(Compostera* handle)
{
	exseq_activity_COMPOSTANDO(handle);
	enseq_activity_ESPERANDO_default(handle);
}

static void effect_activity_COMPOSTANDO_r1_RELLENANDO_tr0(Compostera* handle)
{
	exseq_activity_COMPOSTANDO_r1_RELLENANDO(handle);
	enseq_activity_COMPOSTANDO_r1_SONANDO_default(handle);
}

static void effect_activity_COMPOSTANDO_r1_RELLENANDO_tr1(Compostera* handle)
{
	exseq_activity_COMPOSTANDO_r1_RELLENANDO(handle);
	enseq_activity_COMPOSTANDO_r1_MEZCLANDO_default(handle);
}

static void effect_activity_COMPOSTANDO_r1_SONANDO_tr0(Compostera* handle)
{
	exseq_activity_COMPOSTANDO_r1_SONANDO(handle);
	enseq_activity_COMPOSTANDO_r1_MEZCLANDO_default(handle);
}

static void effect_activity_COMPOSTANDO_r1_MEZCLANDO_tr0(Compostera* handle)
{
	exseq_activity_COMPOSTANDO_r1_MEZCLANDO(handle);
	react_activity_COMPOSTANDO_r1__exit_Default(handle);
}

/* Entry action for state 'DEBOUNCE_O'. */
static void enact_TEC1_DEBOUNCE_O(Compostera* handle)
{
	/* Entry action for state 'DEBOUNCE_O'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC1_DEBOUNCE_O_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void enact_TEC1_OPRIMIDO(Compostera* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siAberturaTapa_raised = bool_true;
}

/* Entry action for state 'NO_OPRIMIDO'. */
static void enact_TEC1_NO_OPRIMIDO(Compostera* handle)
{
	/* Entry action for state 'NO_OPRIMIDO'. */
	handle->internal.siCerradoTapa_raised = bool_true;
}

/* Entry action for state 'DEBOUNCE_N_O'. */
static void enact_TEC1_DEBOUNCE_N_O(Compostera* handle)
{
	/* Entry action for state 'DEBOUNCE_N_O'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC1_DEBOUNCE_N_O_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'DEBOUNCE_O'. */
static void enact_TEC2_DEBOUNCE_O(Compostera* handle)
{
	/* Entry action for state 'DEBOUNCE_O'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC2_DEBOUNCE_O_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void enact_TEC2_OPRIMIDO(Compostera* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siHumedadMayor60_raised = bool_true;
}

/* Entry action for state 'NO_OPRIMIDO'. */
static void enact_TEC2_NO_OPRIMIDO(Compostera* handle)
{
	/* Entry action for state 'NO_OPRIMIDO'. */
	handle->internal.siHumedadEstable_raised = bool_true;
}

/* Entry action for state 'DEBOUNCE_N_O'. */
static void enact_TEC2_DEBOUNCE_N_O(Compostera* handle)
{
	/* Entry action for state 'DEBOUNCE_N_O'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC2_DEBOUNCE_N_O_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'DEBOUNCE_O'. */
static void enact_TEC3_DEBOUNCE_O(Compostera* handle)
{
	/* Entry action for state 'DEBOUNCE_O'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC3_DEBOUNCE_O_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void enact_TEC3_OPRIMIDO(Compostera* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siHumedadMenor40_raised = bool_true;
}

/* Entry action for state 'NO_OPRIMIDO'. */
static void enact_TEC3_NO_OPRIMIDO(Compostera* handle)
{
	/* Entry action for state 'NO_OPRIMIDO'. */
	handle->internal.siHumedadEstable_raised = bool_true;
}

/* Entry action for state 'DEBOUNCE_N_O'. */
static void enact_TEC3_DEBOUNCE_N_O(Compostera* handle)
{
	/* Entry action for state 'DEBOUNCE_N_O'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC3_DEBOUNCE_N_O_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'DEBOUNCE_O'. */
static void enact_TEC4_DEBOUNCE_O(Compostera* handle)
{
	/* Entry action for state 'DEBOUNCE_O'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC4_DEBOUNCE_O_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void enact_TEC4_OPRIMIDO(Compostera* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siTemperaturaMayor60_raised = bool_true;
}

/* Entry action for state 'NO_OPRIMIDO'. */
static void enact_TEC4_NO_OPRIMIDO(Compostera* handle)
{
	/* Entry action for state 'NO_OPRIMIDO'. */
	handle->internal.siTemperaturaEstable_raised = bool_true;
}

/* Entry action for state 'DEBOUNCE_N_O'. */
static void enact_TEC4_DEBOUNCE_N_O(Compostera* handle)
{
	/* Entry action for state 'DEBOUNCE_N_O'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC4_DEBOUNCE_N_O_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'ESPERANDO'. */
static void enact_activity_ESPERANDO(Compostera* handle)
{
	/* Entry action for state 'ESPERANDO'. */
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LEDR, COMPOSTERA_COMPOSTERAIFACE_LED_OFF);
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LEDG, COMPOSTERA_COMPOSTERAIFACE_LED_OFF);
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LEDB, COMPOSTERA_COMPOSTERAIFACE_LED_OFF);
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LED1, COMPOSTERA_COMPOSTERAIFACE_LED_OFF);
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LED2, COMPOSTERA_COMPOSTERAIFACE_LED_OFF);
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LED3, COMPOSTERA_COMPOSTERAIFACE_LED_OFF);
}

/* Entry action for state 'ENFRIANDO'. */
static void enact_activity_ENFRIANDO(Compostera* handle)
{
	/* Entry action for state 'ENFRIANDO'. */
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LEDR, COMPOSTERA_COMPOSTERAIFACE_LED_ON);
}

/* Entry action for state 'HUMEDECIENDO'. */
static void enact_activity_HUMEDECIENDO(Compostera* handle)
{
	/* Entry action for state 'HUMEDECIENDO'. */
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LEDG, COMPOSTERA_COMPOSTERAIFACE_LED_ON);
}

/* Entry action for state 'DESHUMEDECIENDO'. */
static void enact_activity_DESHUMEDECIENDO(Compostera* handle)
{
	/* Entry action for state 'DESHUMEDECIENDO'. */
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LEDB, COMPOSTERA_COMPOSTERAIFACE_LED_ON);
}

/* Entry action for state 'RELLENANDO'. */
static void enact_activity_COMPOSTANDO_r1_RELLENANDO(Compostera* handle)
{
	/* Entry action for state 'RELLENANDO'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_activity_COMPOSTANDO_r1_RELLENANDO_tev0_raised) , 1 * 1000, bool_false);
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LED3, COMPOSTERA_COMPOSTERAIFACE_LED_ON);
}

/* Entry action for state 'SONANDO'. */
static void enact_activity_COMPOSTANDO_r1_SONANDO(Compostera* handle)
{
	/* Entry action for state 'SONANDO'. */
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LED1, COMPOSTERA_COMPOSTERAIFACE_LED_ON);
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LED3, COMPOSTERA_COMPOSTERAIFACE_LED_OFF);
}

/* Entry action for state 'MEZCLANDO'. */
static void enact_activity_COMPOSTANDO_r1_MEZCLANDO(Compostera* handle)
{
	/* Entry action for state 'MEZCLANDO'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_activity_COMPOSTANDO_r1_MEZCLANDO_tev0_raised) , 2 * 1000, bool_false);
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LED2, COMPOSTERA_COMPOSTERAIFACE_LED_ON);
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LED3, COMPOSTERA_COMPOSTERAIFACE_LED_OFF);
	composteraIface_opLED(handle, COMPOSTERA_COMPOSTERAIFACE_LED1, COMPOSTERA_COMPOSTERAIFACE_LED_OFF);
}

/* Exit action for state 'DEBOUNCE_O'. */
static void exact_TEC1_DEBOUNCE_O(Compostera* handle)
{
	/* Exit action for state 'DEBOUNCE_O'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC1_DEBOUNCE_O_tev0_raised) );		
}

/* Exit action for state 'DEBOUNCE_N_O'. */
static void exact_TEC1_DEBOUNCE_N_O(Compostera* handle)
{
	/* Exit action for state 'DEBOUNCE_N_O'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC1_DEBOUNCE_N_O_tev0_raised) );		
}

/* Exit action for state 'DEBOUNCE_O'. */
static void exact_TEC2_DEBOUNCE_O(Compostera* handle)
{
	/* Exit action for state 'DEBOUNCE_O'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC2_DEBOUNCE_O_tev0_raised) );		
}

/* Exit action for state 'DEBOUNCE_N_O'. */
static void exact_TEC2_DEBOUNCE_N_O(Compostera* handle)
{
	/* Exit action for state 'DEBOUNCE_N_O'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC2_DEBOUNCE_N_O_tev0_raised) );		
}

/* Exit action for state 'DEBOUNCE_O'. */
static void exact_TEC3_DEBOUNCE_O(Compostera* handle)
{
	/* Exit action for state 'DEBOUNCE_O'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC3_DEBOUNCE_O_tev0_raised) );		
}

/* Exit action for state 'DEBOUNCE_N_O'. */
static void exact_TEC3_DEBOUNCE_N_O(Compostera* handle)
{
	/* Exit action for state 'DEBOUNCE_N_O'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC3_DEBOUNCE_N_O_tev0_raised) );		
}

/* Exit action for state 'DEBOUNCE_O'. */
static void exact_TEC4_DEBOUNCE_O(Compostera* handle)
{
	/* Exit action for state 'DEBOUNCE_O'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC4_DEBOUNCE_O_tev0_raised) );		
}

/* Exit action for state 'DEBOUNCE_N_O'. */
static void exact_TEC4_DEBOUNCE_N_O(Compostera* handle)
{
	/* Exit action for state 'DEBOUNCE_N_O'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC4_DEBOUNCE_N_O_tev0_raised) );		
}

/* Exit action for state 'RELLENANDO'. */
static void exact_activity_COMPOSTANDO_r1_RELLENANDO(Compostera* handle)
{
	/* Exit action for state 'RELLENANDO'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_activity_COMPOSTANDO_r1_RELLENANDO_tev0_raised) );		
}

/* Exit action for state 'MEZCLANDO'. */
static void exact_activity_COMPOSTANDO_r1_MEZCLANDO(Compostera* handle)
{
	/* Exit action for state 'MEZCLANDO'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_activity_COMPOSTANDO_r1_MEZCLANDO_tev0_raised) );		
}

/* 'default' enter sequence for state DEBOUNCE_O */
static void enseq_TEC1_DEBOUNCE_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state DEBOUNCE_O */
	enact_TEC1_DEBOUNCE_O(handle);
	handle->stateConfVector[0] = Compostera_TEC1_DEBOUNCE_O;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state INICIO */
static void enseq_TEC1_INICIO_default(Compostera* handle)
{
	/* 'default' enter sequence for state INICIO */
	handle->stateConfVector[0] = Compostera_TEC1_INICIO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OPRIMIDO */
static void enseq_TEC1_OPRIMIDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	enact_TEC1_OPRIMIDO(handle);
	handle->stateConfVector[0] = Compostera_TEC1_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state VALIDACION_O */
static void enseq_TEC1_VALIDACION_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state VALIDACION_O */
	handle->stateConfVector[0] = Compostera_TEC1_VALIDACION_O;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void enseq_TEC1_NO_OPRIMIDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	enact_TEC1_NO_OPRIMIDO(handle);
	handle->stateConfVector[0] = Compostera_TEC1_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state DEBOUNCE_N_O */
static void enseq_TEC1_DEBOUNCE_N_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state DEBOUNCE_N_O */
	enact_TEC1_DEBOUNCE_N_O(handle);
	handle->stateConfVector[0] = Compostera_TEC1_DEBOUNCE_N_O;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state VALIDACION_N_O */
static void enseq_TEC1_VALIDACION_N_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state VALIDACION_N_O */
	handle->stateConfVector[0] = Compostera_TEC1_VALIDACION_N_O;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state DEBOUNCE_O */
static void enseq_TEC2_DEBOUNCE_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state DEBOUNCE_O */
	enact_TEC2_DEBOUNCE_O(handle);
	handle->stateConfVector[1] = Compostera_TEC2_DEBOUNCE_O;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state INICIO */
static void enseq_TEC2_INICIO_default(Compostera* handle)
{
	/* 'default' enter sequence for state INICIO */
	handle->stateConfVector[1] = Compostera_TEC2_INICIO;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state OPRIMIDO */
static void enseq_TEC2_OPRIMIDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	enact_TEC2_OPRIMIDO(handle);
	handle->stateConfVector[1] = Compostera_TEC2_OPRIMIDO;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state VALIDACION_O */
static void enseq_TEC2_VALIDACION_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state VALIDACION_O */
	handle->stateConfVector[1] = Compostera_TEC2_VALIDACION_O;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void enseq_TEC2_NO_OPRIMIDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	enact_TEC2_NO_OPRIMIDO(handle);
	handle->stateConfVector[1] = Compostera_TEC2_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state DEBOUNCE_N_O */
static void enseq_TEC2_DEBOUNCE_N_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state DEBOUNCE_N_O */
	enact_TEC2_DEBOUNCE_N_O(handle);
	handle->stateConfVector[1] = Compostera_TEC2_DEBOUNCE_N_O;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state VALIDACION_N_O */
static void enseq_TEC2_VALIDACION_N_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state VALIDACION_N_O */
	handle->stateConfVector[1] = Compostera_TEC2_VALIDACION_N_O;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state DEBOUNCE_O */
static void enseq_TEC3_DEBOUNCE_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state DEBOUNCE_O */
	enact_TEC3_DEBOUNCE_O(handle);
	handle->stateConfVector[2] = Compostera_TEC3_DEBOUNCE_O;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state INICIO */
static void enseq_TEC3_INICIO_default(Compostera* handle)
{
	/* 'default' enter sequence for state INICIO */
	handle->stateConfVector[2] = Compostera_TEC3_INICIO;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state OPRIMIDO */
static void enseq_TEC3_OPRIMIDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	enact_TEC3_OPRIMIDO(handle);
	handle->stateConfVector[2] = Compostera_TEC3_OPRIMIDO;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state VALIDACION_O */
static void enseq_TEC3_VALIDACION_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state VALIDACION_O */
	handle->stateConfVector[2] = Compostera_TEC3_VALIDACION_O;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void enseq_TEC3_NO_OPRIMIDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	enact_TEC3_NO_OPRIMIDO(handle);
	handle->stateConfVector[2] = Compostera_TEC3_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state DEBOUNCE_N_O */
static void enseq_TEC3_DEBOUNCE_N_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state DEBOUNCE_N_O */
	enact_TEC3_DEBOUNCE_N_O(handle);
	handle->stateConfVector[2] = Compostera_TEC3_DEBOUNCE_N_O;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state VALIDACION_N_O */
static void enseq_TEC3_VALIDACION_N_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state VALIDACION_N_O */
	handle->stateConfVector[2] = Compostera_TEC3_VALIDACION_N_O;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state DEBOUNCE_O */
static void enseq_TEC4_DEBOUNCE_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state DEBOUNCE_O */
	enact_TEC4_DEBOUNCE_O(handle);
	handle->stateConfVector[3] = Compostera_TEC4_DEBOUNCE_O;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state INICIO */
static void enseq_TEC4_INICIO_default(Compostera* handle)
{
	/* 'default' enter sequence for state INICIO */
	handle->stateConfVector[3] = Compostera_TEC4_INICIO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state OPRIMIDO */
static void enseq_TEC4_OPRIMIDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	enact_TEC4_OPRIMIDO(handle);
	handle->stateConfVector[3] = Compostera_TEC4_OPRIMIDO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state VALIDACION_O */
static void enseq_TEC4_VALIDACION_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state VALIDACION_O */
	handle->stateConfVector[3] = Compostera_TEC4_VALIDACION_O;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void enseq_TEC4_NO_OPRIMIDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	enact_TEC4_NO_OPRIMIDO(handle);
	handle->stateConfVector[3] = Compostera_TEC4_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state DEBOUNCE_N_O */
static void enseq_TEC4_DEBOUNCE_N_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state DEBOUNCE_N_O */
	enact_TEC4_DEBOUNCE_N_O(handle);
	handle->stateConfVector[3] = Compostera_TEC4_DEBOUNCE_N_O;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state VALIDACION_N_O */
static void enseq_TEC4_VALIDACION_N_O_default(Compostera* handle)
{
	/* 'default' enter sequence for state VALIDACION_N_O */
	handle->stateConfVector[3] = Compostera_TEC4_VALIDACION_N_O;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state ESPERANDO */
static void enseq_activity_ESPERANDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state ESPERANDO */
	enact_activity_ESPERANDO(handle);
	handle->stateConfVector[4] = Compostera_activity_ESPERANDO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state ENFRIANDO */
static void enseq_activity_ENFRIANDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state ENFRIANDO */
	enact_activity_ENFRIANDO(handle);
	handle->stateConfVector[4] = Compostera_activity_ENFRIANDO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state HUMEDECIENDO */
static void enseq_activity_HUMEDECIENDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state HUMEDECIENDO */
	enact_activity_HUMEDECIENDO(handle);
	handle->stateConfVector[4] = Compostera_activity_HUMEDECIENDO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state DESHUMEDECIENDO */
static void enseq_activity_DESHUMEDECIENDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state DESHUMEDECIENDO */
	enact_activity_DESHUMEDECIENDO(handle);
	handle->stateConfVector[4] = Compostera_activity_DESHUMEDECIENDO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state COMPOSTANDO */
static void enseq_activity_COMPOSTANDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state COMPOSTANDO */
	enseq_activity_COMPOSTANDO_r1_default(handle);
}

/* 'default' enter sequence for state RELLENANDO */
static void enseq_activity_COMPOSTANDO_r1_RELLENANDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state RELLENANDO */
	enact_activity_COMPOSTANDO_r1_RELLENANDO(handle);
	handle->stateConfVector[4] = Compostera_activity_COMPOSTANDO_r1_RELLENANDO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state SONANDO */
static void enseq_activity_COMPOSTANDO_r1_SONANDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state SONANDO */
	enact_activity_COMPOSTANDO_r1_SONANDO(handle);
	handle->stateConfVector[4] = Compostera_activity_COMPOSTANDO_r1_SONANDO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state MEZCLANDO */
static void enseq_activity_COMPOSTANDO_r1_MEZCLANDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state MEZCLANDO */
	enact_activity_COMPOSTANDO_r1_MEZCLANDO(handle);
	handle->stateConfVector[4] = Compostera_activity_COMPOSTANDO_r1_MEZCLANDO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for region TEC1 */
static void enseq_TEC1_default(Compostera* handle)
{
	/* 'default' enter sequence for region TEC1 */
	react_TEC1__entry_Default(handle);
}

/* 'default' enter sequence for region TEC2 */
static void enseq_TEC2_default(Compostera* handle)
{
	/* 'default' enter sequence for region TEC2 */
	react_TEC2__entry_Default(handle);
}

/* 'default' enter sequence for region TEC3 */
static void enseq_TEC3_default(Compostera* handle)
{
	/* 'default' enter sequence for region TEC3 */
	react_TEC3__entry_Default(handle);
}

/* 'default' enter sequence for region TEC4 */
static void enseq_TEC4_default(Compostera* handle)
{
	/* 'default' enter sequence for region TEC4 */
	react_TEC4__entry_Default(handle);
}

/* 'default' enter sequence for region activity */
static void enseq_activity_default(Compostera* handle)
{
	/* 'default' enter sequence for region activity */
	react_activity__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void enseq_activity_COMPOSTANDO_r1_default(Compostera* handle)
{
	/* 'default' enter sequence for region r1 */
	react_activity_COMPOSTANDO_r1__entry_Default(handle);
}

/* Default exit sequence for state DEBOUNCE_O */
static void exseq_TEC1_DEBOUNCE_O(Compostera* handle)
{
	/* Default exit sequence for state DEBOUNCE_O */
	handle->stateConfVector[0] = Compostera_last_state;
	handle->stateConfVectorPosition = 0;
	exact_TEC1_DEBOUNCE_O(handle);
}

/* Default exit sequence for state INICIO */
static void exseq_TEC1_INICIO(Compostera* handle)
{
	/* Default exit sequence for state INICIO */
	handle->stateConfVector[0] = Compostera_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OPRIMIDO */
static void exseq_TEC1_OPRIMIDO(Compostera* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[0] = Compostera_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state VALIDACION_O */
static void exseq_TEC1_VALIDACION_O(Compostera* handle)
{
	/* Default exit sequence for state VALIDACION_O */
	handle->stateConfVector[0] = Compostera_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state NO_OPRIMIDO */
static void exseq_TEC1_NO_OPRIMIDO(Compostera* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Compostera_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state DEBOUNCE_N_O */
static void exseq_TEC1_DEBOUNCE_N_O(Compostera* handle)
{
	/* Default exit sequence for state DEBOUNCE_N_O */
	handle->stateConfVector[0] = Compostera_last_state;
	handle->stateConfVectorPosition = 0;
	exact_TEC1_DEBOUNCE_N_O(handle);
}

/* Default exit sequence for state VALIDACION_N_O */
static void exseq_TEC1_VALIDACION_N_O(Compostera* handle)
{
	/* Default exit sequence for state VALIDACION_N_O */
	handle->stateConfVector[0] = Compostera_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state DEBOUNCE_O */
static void exseq_TEC2_DEBOUNCE_O(Compostera* handle)
{
	/* Default exit sequence for state DEBOUNCE_O */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
	exact_TEC2_DEBOUNCE_O(handle);
}

/* Default exit sequence for state INICIO */
static void exseq_TEC2_INICIO(Compostera* handle)
{
	/* Default exit sequence for state INICIO */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state OPRIMIDO */
static void exseq_TEC2_OPRIMIDO(Compostera* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state VALIDACION_O */
static void exseq_TEC2_VALIDACION_O(Compostera* handle)
{
	/* Default exit sequence for state VALIDACION_O */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state NO_OPRIMIDO */
static void exseq_TEC2_NO_OPRIMIDO(Compostera* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state DEBOUNCE_N_O */
static void exseq_TEC2_DEBOUNCE_N_O(Compostera* handle)
{
	/* Default exit sequence for state DEBOUNCE_N_O */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
	exact_TEC2_DEBOUNCE_N_O(handle);
}

/* Default exit sequence for state VALIDACION_N_O */
static void exseq_TEC2_VALIDACION_N_O(Compostera* handle)
{
	/* Default exit sequence for state VALIDACION_N_O */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state DEBOUNCE_O */
static void exseq_TEC3_DEBOUNCE_O(Compostera* handle)
{
	/* Default exit sequence for state DEBOUNCE_O */
	handle->stateConfVector[2] = Compostera_last_state;
	handle->stateConfVectorPosition = 2;
	exact_TEC3_DEBOUNCE_O(handle);
}

/* Default exit sequence for state INICIO */
static void exseq_TEC3_INICIO(Compostera* handle)
{
	/* Default exit sequence for state INICIO */
	handle->stateConfVector[2] = Compostera_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state OPRIMIDO */
static void exseq_TEC3_OPRIMIDO(Compostera* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[2] = Compostera_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state VALIDACION_O */
static void exseq_TEC3_VALIDACION_O(Compostera* handle)
{
	/* Default exit sequence for state VALIDACION_O */
	handle->stateConfVector[2] = Compostera_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state NO_OPRIMIDO */
static void exseq_TEC3_NO_OPRIMIDO(Compostera* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[2] = Compostera_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state DEBOUNCE_N_O */
static void exseq_TEC3_DEBOUNCE_N_O(Compostera* handle)
{
	/* Default exit sequence for state DEBOUNCE_N_O */
	handle->stateConfVector[2] = Compostera_last_state;
	handle->stateConfVectorPosition = 2;
	exact_TEC3_DEBOUNCE_N_O(handle);
}

/* Default exit sequence for state VALIDACION_N_O */
static void exseq_TEC3_VALIDACION_N_O(Compostera* handle)
{
	/* Default exit sequence for state VALIDACION_N_O */
	handle->stateConfVector[2] = Compostera_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state DEBOUNCE_O */
static void exseq_TEC4_DEBOUNCE_O(Compostera* handle)
{
	/* Default exit sequence for state DEBOUNCE_O */
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
	exact_TEC4_DEBOUNCE_O(handle);
}

/* Default exit sequence for state INICIO */
static void exseq_TEC4_INICIO(Compostera* handle)
{
	/* Default exit sequence for state INICIO */
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state OPRIMIDO */
static void exseq_TEC4_OPRIMIDO(Compostera* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state VALIDACION_O */
static void exseq_TEC4_VALIDACION_O(Compostera* handle)
{
	/* Default exit sequence for state VALIDACION_O */
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state NO_OPRIMIDO */
static void exseq_TEC4_NO_OPRIMIDO(Compostera* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state DEBOUNCE_N_O */
static void exseq_TEC4_DEBOUNCE_N_O(Compostera* handle)
{
	/* Default exit sequence for state DEBOUNCE_N_O */
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
	exact_TEC4_DEBOUNCE_N_O(handle);
}

/* Default exit sequence for state VALIDACION_N_O */
static void exseq_TEC4_VALIDACION_N_O(Compostera* handle)
{
	/* Default exit sequence for state VALIDACION_N_O */
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state ESPERANDO */
static void exseq_activity_ESPERANDO(Compostera* handle)
{
	/* Default exit sequence for state ESPERANDO */
	handle->stateConfVector[4] = Compostera_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state ENFRIANDO */
static void exseq_activity_ENFRIANDO(Compostera* handle)
{
	/* Default exit sequence for state ENFRIANDO */
	handle->stateConfVector[4] = Compostera_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state HUMEDECIENDO */
static void exseq_activity_HUMEDECIENDO(Compostera* handle)
{
	/* Default exit sequence for state HUMEDECIENDO */
	handle->stateConfVector[4] = Compostera_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state DESHUMEDECIENDO */
static void exseq_activity_DESHUMEDECIENDO(Compostera* handle)
{
	/* Default exit sequence for state DESHUMEDECIENDO */
	handle->stateConfVector[4] = Compostera_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state COMPOSTANDO */
static void exseq_activity_COMPOSTANDO(Compostera* handle)
{
	/* Default exit sequence for state COMPOSTANDO */
	exseq_activity_COMPOSTANDO_r1(handle);
}

/* Default exit sequence for state RELLENANDO */
static void exseq_activity_COMPOSTANDO_r1_RELLENANDO(Compostera* handle)
{
	/* Default exit sequence for state RELLENANDO */
	handle->stateConfVector[4] = Compostera_last_state;
	handle->stateConfVectorPosition = 4;
	exact_activity_COMPOSTANDO_r1_RELLENANDO(handle);
}

/* Default exit sequence for state SONANDO */
static void exseq_activity_COMPOSTANDO_r1_SONANDO(Compostera* handle)
{
	/* Default exit sequence for state SONANDO */
	handle->stateConfVector[4] = Compostera_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state MEZCLANDO */
static void exseq_activity_COMPOSTANDO_r1_MEZCLANDO(Compostera* handle)
{
	/* Default exit sequence for state MEZCLANDO */
	handle->stateConfVector[4] = Compostera_last_state;
	handle->stateConfVectorPosition = 4;
	exact_activity_COMPOSTANDO_r1_MEZCLANDO(handle);
}

/* Default exit sequence for region TEC1 */
static void exseq_TEC1(Compostera* handle)
{
	/* Default exit sequence for region TEC1 */
	/* Handle exit of all possible states (of compostera.TEC1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Compostera_TEC1_DEBOUNCE_O :
		{
			exseq_TEC1_DEBOUNCE_O(handle);
			break;
		}
		case Compostera_TEC1_INICIO :
		{
			exseq_TEC1_INICIO(handle);
			break;
		}
		case Compostera_TEC1_OPRIMIDO :
		{
			exseq_TEC1_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC1_VALIDACION_O :
		{
			exseq_TEC1_VALIDACION_O(handle);
			break;
		}
		case Compostera_TEC1_NO_OPRIMIDO :
		{
			exseq_TEC1_NO_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC1_DEBOUNCE_N_O :
		{
			exseq_TEC1_DEBOUNCE_N_O(handle);
			break;
		}
		case Compostera_TEC1_VALIDACION_N_O :
		{
			exseq_TEC1_VALIDACION_N_O(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region TEC2 */
static void exseq_TEC2(Compostera* handle)
{
	/* Default exit sequence for region TEC2 */
	/* Handle exit of all possible states (of compostera.TEC2) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Compostera_TEC2_DEBOUNCE_O :
		{
			exseq_TEC2_DEBOUNCE_O(handle);
			break;
		}
		case Compostera_TEC2_INICIO :
		{
			exseq_TEC2_INICIO(handle);
			break;
		}
		case Compostera_TEC2_OPRIMIDO :
		{
			exseq_TEC2_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC2_VALIDACION_O :
		{
			exseq_TEC2_VALIDACION_O(handle);
			break;
		}
		case Compostera_TEC2_NO_OPRIMIDO :
		{
			exseq_TEC2_NO_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC2_DEBOUNCE_N_O :
		{
			exseq_TEC2_DEBOUNCE_N_O(handle);
			break;
		}
		case Compostera_TEC2_VALIDACION_N_O :
		{
			exseq_TEC2_VALIDACION_N_O(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region TEC3 */
static void exseq_TEC3(Compostera* handle)
{
	/* Default exit sequence for region TEC3 */
	/* Handle exit of all possible states (of compostera.TEC3) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Compostera_TEC3_DEBOUNCE_O :
		{
			exseq_TEC3_DEBOUNCE_O(handle);
			break;
		}
		case Compostera_TEC3_INICIO :
		{
			exseq_TEC3_INICIO(handle);
			break;
		}
		case Compostera_TEC3_OPRIMIDO :
		{
			exseq_TEC3_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC3_VALIDACION_O :
		{
			exseq_TEC3_VALIDACION_O(handle);
			break;
		}
		case Compostera_TEC3_NO_OPRIMIDO :
		{
			exseq_TEC3_NO_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC3_DEBOUNCE_N_O :
		{
			exseq_TEC3_DEBOUNCE_N_O(handle);
			break;
		}
		case Compostera_TEC3_VALIDACION_N_O :
		{
			exseq_TEC3_VALIDACION_N_O(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region TEC4 */
static void exseq_TEC4(Compostera* handle)
{
	/* Default exit sequence for region TEC4 */
	/* Handle exit of all possible states (of compostera.TEC4) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Compostera_TEC4_DEBOUNCE_O :
		{
			exseq_TEC4_DEBOUNCE_O(handle);
			break;
		}
		case Compostera_TEC4_INICIO :
		{
			exseq_TEC4_INICIO(handle);
			break;
		}
		case Compostera_TEC4_OPRIMIDO :
		{
			exseq_TEC4_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC4_VALIDACION_O :
		{
			exseq_TEC4_VALIDACION_O(handle);
			break;
		}
		case Compostera_TEC4_NO_OPRIMIDO :
		{
			exseq_TEC4_NO_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC4_DEBOUNCE_N_O :
		{
			exseq_TEC4_DEBOUNCE_N_O(handle);
			break;
		}
		case Compostera_TEC4_VALIDACION_N_O :
		{
			exseq_TEC4_VALIDACION_N_O(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region activity */
static void exseq_activity(Compostera* handle)
{
	/* Default exit sequence for region activity */
	/* Handle exit of all possible states (of compostera.activity) at position 4... */
	switch(handle->stateConfVector[ 4 ])
	{
		case Compostera_activity_ESPERANDO :
		{
			exseq_activity_ESPERANDO(handle);
			break;
		}
		case Compostera_activity_ENFRIANDO :
		{
			exseq_activity_ENFRIANDO(handle);
			break;
		}
		case Compostera_activity_HUMEDECIENDO :
		{
			exseq_activity_HUMEDECIENDO(handle);
			break;
		}
		case Compostera_activity_DESHUMEDECIENDO :
		{
			exseq_activity_DESHUMEDECIENDO(handle);
			break;
		}
		case Compostera_activity_COMPOSTANDO_r1_RELLENANDO :
		{
			exseq_activity_COMPOSTANDO_r1_RELLENANDO(handle);
			break;
		}
		case Compostera_activity_COMPOSTANDO_r1_SONANDO :
		{
			exseq_activity_COMPOSTANDO_r1_SONANDO(handle);
			break;
		}
		case Compostera_activity_COMPOSTANDO_r1_MEZCLANDO :
		{
			exseq_activity_COMPOSTANDO_r1_MEZCLANDO(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void exseq_activity_COMPOSTANDO_r1(Compostera* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of compostera.activity.COMPOSTANDO.r1) at position 4... */
	switch(handle->stateConfVector[ 4 ])
	{
		case Compostera_activity_COMPOSTANDO_r1_RELLENANDO :
		{
			exseq_activity_COMPOSTANDO_r1_RELLENANDO(handle);
			break;
		}
		case Compostera_activity_COMPOSTANDO_r1_SONANDO :
		{
			exseq_activity_COMPOSTANDO_r1_SONANDO(handle);
			break;
		}
		case Compostera_activity_COMPOSTANDO_r1_MEZCLANDO :
		{
			exseq_activity_COMPOSTANDO_r1_MEZCLANDO(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state DEBOUNCE_O. */
static void react_TEC1_DEBOUNCE_O(Compostera* handle)
{
	/* The reactions of state DEBOUNCE_O. */
	if (check_TEC1_DEBOUNCE_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC1_DEBOUNCE_O_tr0(handle);
	} 
}

/* The reactions of state INICIO. */
static void react_TEC1_INICIO(Compostera* handle)
{
	/* The reactions of state INICIO. */
	if (check_TEC1_INICIO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC1_INICIO_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void react_TEC1_OPRIMIDO(Compostera* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (check_TEC1_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC1_OPRIMIDO_tr0(handle);
	}  else
	{
		if (check_TEC1_OPRIMIDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC1_OPRIMIDO_tr1(handle);
		} 
	}
}

/* The reactions of state VALIDACION_O. */
static void react_TEC1_VALIDACION_O(Compostera* handle)
{
	/* The reactions of state VALIDACION_O. */
	if (check_TEC1_VALIDACION_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC1_VALIDACION_O_tr0(handle);
	}  else
	{
		if (check_TEC1_VALIDACION_O_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC1_VALIDACION_O_tr1(handle);
		} 
	}
}

/* The reactions of state NO_OPRIMIDO. */
static void react_TEC1_NO_OPRIMIDO(Compostera* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (check_TEC1_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC1_NO_OPRIMIDO_tr0(handle);
	}  else
	{
		if (check_TEC1_NO_OPRIMIDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC1_NO_OPRIMIDO_tr1(handle);
		} 
	}
}

/* The reactions of state DEBOUNCE_N_O. */
static void react_TEC1_DEBOUNCE_N_O(Compostera* handle)
{
	/* The reactions of state DEBOUNCE_N_O. */
	if (check_TEC1_DEBOUNCE_N_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC1_DEBOUNCE_N_O_tr0(handle);
	} 
}

/* The reactions of state VALIDACION_N_O. */
static void react_TEC1_VALIDACION_N_O(Compostera* handle)
{
	/* The reactions of state VALIDACION_N_O. */
	if (check_TEC1_VALIDACION_N_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC1_VALIDACION_N_O_tr0(handle);
	}  else
	{
		if (check_TEC1_VALIDACION_N_O_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC1_VALIDACION_N_O_tr1(handle);
		} 
	}
}

/* The reactions of state DEBOUNCE_O. */
static void react_TEC2_DEBOUNCE_O(Compostera* handle)
{
	/* The reactions of state DEBOUNCE_O. */
	if (check_TEC2_DEBOUNCE_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC2_DEBOUNCE_O_tr0(handle);
	} 
}

/* The reactions of state INICIO. */
static void react_TEC2_INICIO(Compostera* handle)
{
	/* The reactions of state INICIO. */
	if (check_TEC2_INICIO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC2_INICIO_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void react_TEC2_OPRIMIDO(Compostera* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (check_TEC2_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC2_OPRIMIDO_tr0(handle);
	}  else
	{
		if (check_TEC2_OPRIMIDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC2_OPRIMIDO_tr1(handle);
		} 
	}
}

/* The reactions of state VALIDACION_O. */
static void react_TEC2_VALIDACION_O(Compostera* handle)
{
	/* The reactions of state VALIDACION_O. */
	if (check_TEC2_VALIDACION_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC2_VALIDACION_O_tr0(handle);
	}  else
	{
		if (check_TEC2_VALIDACION_O_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC2_VALIDACION_O_tr1(handle);
		} 
	}
}

/* The reactions of state NO_OPRIMIDO. */
static void react_TEC2_NO_OPRIMIDO(Compostera* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (check_TEC2_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC2_NO_OPRIMIDO_tr0(handle);
	}  else
	{
		if (check_TEC2_NO_OPRIMIDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC2_NO_OPRIMIDO_tr1(handle);
		} 
	}
}

/* The reactions of state DEBOUNCE_N_O. */
static void react_TEC2_DEBOUNCE_N_O(Compostera* handle)
{
	/* The reactions of state DEBOUNCE_N_O. */
	if (check_TEC2_DEBOUNCE_N_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC2_DEBOUNCE_N_O_tr0(handle);
	} 
}

/* The reactions of state VALIDACION_N_O. */
static void react_TEC2_VALIDACION_N_O(Compostera* handle)
{
	/* The reactions of state VALIDACION_N_O. */
	if (check_TEC2_VALIDACION_N_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC2_VALIDACION_N_O_tr0(handle);
	}  else
	{
		if (check_TEC2_VALIDACION_N_O_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC2_VALIDACION_N_O_tr1(handle);
		} 
	}
}

/* The reactions of state DEBOUNCE_O. */
static void react_TEC3_DEBOUNCE_O(Compostera* handle)
{
	/* The reactions of state DEBOUNCE_O. */
	if (check_TEC3_DEBOUNCE_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC3_DEBOUNCE_O_tr0(handle);
	} 
}

/* The reactions of state INICIO. */
static void react_TEC3_INICIO(Compostera* handle)
{
	/* The reactions of state INICIO. */
	if (check_TEC3_INICIO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC3_INICIO_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void react_TEC3_OPRIMIDO(Compostera* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (check_TEC3_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC3_OPRIMIDO_tr0(handle);
	}  else
	{
		if (check_TEC3_OPRIMIDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC3_OPRIMIDO_tr1(handle);
		} 
	}
}

/* The reactions of state VALIDACION_O. */
static void react_TEC3_VALIDACION_O(Compostera* handle)
{
	/* The reactions of state VALIDACION_O. */
	if (check_TEC3_VALIDACION_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC3_VALIDACION_O_tr0(handle);
	}  else
	{
		if (check_TEC3_VALIDACION_O_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC3_VALIDACION_O_tr1(handle);
		} 
	}
}

/* The reactions of state NO_OPRIMIDO. */
static void react_TEC3_NO_OPRIMIDO(Compostera* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (check_TEC3_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC3_NO_OPRIMIDO_tr0(handle);
	}  else
	{
		if (check_TEC3_NO_OPRIMIDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC3_NO_OPRIMIDO_tr1(handle);
		} 
	}
}

/* The reactions of state DEBOUNCE_N_O. */
static void react_TEC3_DEBOUNCE_N_O(Compostera* handle)
{
	/* The reactions of state DEBOUNCE_N_O. */
	if (check_TEC3_DEBOUNCE_N_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC3_DEBOUNCE_N_O_tr0(handle);
	} 
}

/* The reactions of state VALIDACION_N_O. */
static void react_TEC3_VALIDACION_N_O(Compostera* handle)
{
	/* The reactions of state VALIDACION_N_O. */
	if (check_TEC3_VALIDACION_N_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC3_VALIDACION_N_O_tr0(handle);
	}  else
	{
		if (check_TEC3_VALIDACION_N_O_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC3_VALIDACION_N_O_tr1(handle);
		} 
	}
}

/* The reactions of state DEBOUNCE_O. */
static void react_TEC4_DEBOUNCE_O(Compostera* handle)
{
	/* The reactions of state DEBOUNCE_O. */
	if (check_TEC4_DEBOUNCE_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC4_DEBOUNCE_O_tr0(handle);
	} 
}

/* The reactions of state INICIO. */
static void react_TEC4_INICIO(Compostera* handle)
{
	/* The reactions of state INICIO. */
	if (check_TEC4_INICIO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC4_INICIO_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void react_TEC4_OPRIMIDO(Compostera* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (check_TEC4_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC4_OPRIMIDO_tr0(handle);
	}  else
	{
		if (check_TEC4_OPRIMIDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC4_OPRIMIDO_tr1(handle);
		} 
	}
}

/* The reactions of state VALIDACION_O. */
static void react_TEC4_VALIDACION_O(Compostera* handle)
{
	/* The reactions of state VALIDACION_O. */
	if (check_TEC4_VALIDACION_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC4_VALIDACION_O_tr0(handle);
	}  else
	{
		if (check_TEC4_VALIDACION_O_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC4_VALIDACION_O_tr1(handle);
		} 
	}
}

/* The reactions of state NO_OPRIMIDO. */
static void react_TEC4_NO_OPRIMIDO(Compostera* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (check_TEC4_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC4_NO_OPRIMIDO_tr0(handle);
	}  else
	{
		if (check_TEC4_NO_OPRIMIDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC4_NO_OPRIMIDO_tr1(handle);
		} 
	}
}

/* The reactions of state DEBOUNCE_N_O. */
static void react_TEC4_DEBOUNCE_N_O(Compostera* handle)
{
	/* The reactions of state DEBOUNCE_N_O. */
	if (check_TEC4_DEBOUNCE_N_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC4_DEBOUNCE_N_O_tr0(handle);
	} 
}

/* The reactions of state VALIDACION_N_O. */
static void react_TEC4_VALIDACION_N_O(Compostera* handle)
{
	/* The reactions of state VALIDACION_N_O. */
	if (check_TEC4_VALIDACION_N_O_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC4_VALIDACION_N_O_tr0(handle);
	}  else
	{
		if (check_TEC4_VALIDACION_N_O_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC4_VALIDACION_N_O_tr1(handle);
		} 
	}
}

/* The reactions of state ESPERANDO. */
static void react_activity_ESPERANDO(Compostera* handle)
{
	/* The reactions of state ESPERANDO. */
	if (check_activity_ESPERANDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_activity_ESPERANDO_tr0(handle);
	}  else
	{
		if (check_activity_ESPERANDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_activity_ESPERANDO_tr1(handle);
		}  else
		{
			if (check_activity_ESPERANDO_tr2_tr2(handle) == bool_true)
			{ 
				effect_activity_ESPERANDO_tr2(handle);
			}  else
			{
				if (check_activity_ESPERANDO_tr3_tr3(handle) == bool_true)
				{ 
					effect_activity_ESPERANDO_tr3(handle);
				} 
			}
		}
	}
}

/* The reactions of state ENFRIANDO. */
static void react_activity_ENFRIANDO(Compostera* handle)
{
	/* The reactions of state ENFRIANDO. */
	if (check_activity_ENFRIANDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_activity_ENFRIANDO_tr0(handle);
	}  else
	{
		if (check_activity_ENFRIANDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_activity_ENFRIANDO_tr1(handle);
		} 
	}
}

/* The reactions of state HUMEDECIENDO. */
static void react_activity_HUMEDECIENDO(Compostera* handle)
{
	/* The reactions of state HUMEDECIENDO. */
	if (check_activity_HUMEDECIENDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_activity_HUMEDECIENDO_tr0(handle);
	}  else
	{
		if (check_activity_HUMEDECIENDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_activity_HUMEDECIENDO_tr1(handle);
		} 
	}
}

/* The reactions of state DESHUMEDECIENDO. */
static void react_activity_DESHUMEDECIENDO(Compostera* handle)
{
	/* The reactions of state DESHUMEDECIENDO. */
	if (check_activity_DESHUMEDECIENDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_activity_DESHUMEDECIENDO_tr0(handle);
	}  else
	{
		if (check_activity_DESHUMEDECIENDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_activity_DESHUMEDECIENDO_tr1(handle);
		} 
	}
}

/* The reactions of state RELLENANDO. */
static void react_activity_COMPOSTANDO_r1_RELLENANDO(Compostera* handle)
{
	/* The reactions of state RELLENANDO. */
	if (check_activity_COMPOSTANDO_r1_RELLENANDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_activity_COMPOSTANDO_r1_RELLENANDO_tr0(handle);
	}  else
	{
		if (check_activity_COMPOSTANDO_r1_RELLENANDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_activity_COMPOSTANDO_r1_RELLENANDO_tr1(handle);
		} 
	}
}

/* The reactions of state SONANDO. */
static void react_activity_COMPOSTANDO_r1_SONANDO(Compostera* handle)
{
	/* The reactions of state SONANDO. */
	if (check_activity_COMPOSTANDO_r1_SONANDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_activity_COMPOSTANDO_r1_SONANDO_tr0(handle);
	} 
}

/* The reactions of state MEZCLANDO. */
static void react_activity_COMPOSTANDO_r1_MEZCLANDO(Compostera* handle)
{
	/* The reactions of state MEZCLANDO. */
	if (check_activity_COMPOSTANDO_r1_MEZCLANDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_activity_COMPOSTANDO_r1_MEZCLANDO_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void react_TEC1__entry_Default(Compostera* handle)
{
	/* Default react sequence for initial entry  */
	enseq_TEC1_INICIO_default(handle);
}

/* Default react sequence for initial entry  */
static void react_TEC2__entry_Default(Compostera* handle)
{
	/* Default react sequence for initial entry  */
	enseq_TEC2_INICIO_default(handle);
}

/* Default react sequence for initial entry  */
static void react_TEC3__entry_Default(Compostera* handle)
{
	/* Default react sequence for initial entry  */
	enseq_TEC3_INICIO_default(handle);
}

/* Default react sequence for initial entry  */
static void react_TEC4__entry_Default(Compostera* handle)
{
	/* Default react sequence for initial entry  */
	enseq_TEC4_INICIO_default(handle);
}

/* Default react sequence for initial entry  */
static void react_activity__entry_Default(Compostera* handle)
{
	/* Default react sequence for initial entry  */
	enseq_activity_ESPERANDO_default(handle);
}

/* Default react sequence for initial entry  */
static void react_activity_COMPOSTANDO_r1__entry_Default(Compostera* handle)
{
	/* Default react sequence for initial entry  */
	enseq_activity_COMPOSTANDO_r1_RELLENANDO_default(handle);
}

/* The reactions of exit default. */
static void react_activity_COMPOSTANDO_r1__exit_Default(Compostera* handle)
{
	/* The reactions of exit default. */
	effect_activity_COMPOSTANDO_tr0(handle);
}


