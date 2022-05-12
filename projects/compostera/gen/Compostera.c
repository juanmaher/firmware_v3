
#include "Compostera.h"
#include "..\inc\sc_types.h"
#include "ComposteraRequired.h"

#include <stdlib.h>
#include <string.h>
/*! \file Implementation of the state machine 'compostera'
*/

/* prototypes of all internal functions */
static sc_boolean check_TEC1_DEBOUNCE_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC1_ESPERA_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC1_OPRIMIDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC1_VALIDACION_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC1_VALIDACION_tr1_tr1(const Compostera* handle);
static sc_boolean check_TEC1_NO_OPRIMIDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC1_Copy_1_DEBOUNCE_tr0_tr0(const Compostera* handle);
static sc_boolean check_TEC1_Copy_1_VALIDACION_tr0_tr0(const Compostera* handle);
static sc_boolean check_TECX_DEBOUNCE_tr0_tr0(const Compostera* handle);
static sc_boolean check_TECX_ESPERA_tr0_tr0(const Compostera* handle);
static sc_boolean check_TECX_OPRIMIDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TECX_VALIDACION_tr0_tr0(const Compostera* handle);
static sc_boolean check_TECX_VALIDACION_tr1_tr1(const Compostera* handle);
static sc_boolean check_TECX_NO_OPRIMIDO_tr0_tr0(const Compostera* handle);
static sc_boolean check_TECX_Copy_1_DEBOUNCE_tr0_tr0(const Compostera* handle);
static sc_boolean check_TECX_Copy_1_VALIDACION_tr0_tr0(const Compostera* handle);
static sc_boolean check_main_region_ESPERA_tr0_tr0(const Compostera* handle);
static sc_boolean check_main_region_ESPERA_tr1_tr1(const Compostera* handle);
static sc_boolean check_main_region_ESPERA_tr2_tr2(const Compostera* handle);
static sc_boolean check_main_region_ESPERA_tr3_tr3(const Compostera* handle);
static sc_boolean check_main_region_ESPERA_tr4_tr4(const Compostera* handle);
static sc_boolean check_main_region_ESPERA_tr5_tr5(const Compostera* handle);
static sc_boolean check_main_region_ESPERA_tr6_tr6(const Compostera* handle);
static sc_boolean check_main_region_ESPERA_tr7_tr7(const Compostera* handle);
static sc_boolean check_main_region_ESPERA_tr8_tr8(const Compostera* handle);
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
static void effect_TEC1_DEBOUNCE_tr0(Compostera* handle);
static void effect_TEC1_ESPERA_tr0(Compostera* handle);
static void effect_TEC1_OPRIMIDO_tr0(Compostera* handle);
static void effect_TEC1_VALIDACION_tr0(Compostera* handle);
static void effect_TEC1_VALIDACION_tr1(Compostera* handle);
static void effect_TEC1_NO_OPRIMIDO_tr0(Compostera* handle);
static void effect_TEC1_Copy_1_DEBOUNCE_tr0(Compostera* handle);
static void effect_TEC1_Copy_1_VALIDACION_tr0(Compostera* handle);
static void effect_TECX_DEBOUNCE_tr0(Compostera* handle);
static void effect_TECX_ESPERA_tr0(Compostera* handle);
static void effect_TECX_OPRIMIDO_tr0(Compostera* handle);
static void effect_TECX_VALIDACION_tr0(Compostera* handle);
static void effect_TECX_VALIDACION_tr1(Compostera* handle);
static void effect_TECX_NO_OPRIMIDO_tr0(Compostera* handle);
static void effect_TECX_Copy_1_DEBOUNCE_tr0(Compostera* handle);
static void effect_TECX_Copy_1_VALIDACION_tr0(Compostera* handle);
static void effect_main_region_ESPERA_tr0(Compostera* handle);
static void effect_main_region_ESPERA_tr1(Compostera* handle);
static void effect_main_region_ESPERA_tr2(Compostera* handle);
static void effect_main_region_ESPERA_tr3(Compostera* handle);
static void effect_main_region_ESPERA_tr4(Compostera* handle);
static void effect_main_region_ESPERA_tr5(Compostera* handle);
static void effect_main_region_ESPERA_tr6(Compostera* handle);
static void effect_main_region_ESPERA_tr7(Compostera* handle);
static void effect_main_region_ESPERA_tr8(Compostera* handle);
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
static void enact_TEC1_DEBOUNCE(Compostera* handle);
static void enact_TEC1_OPRIMIDO(Compostera* handle);
static void enact_TEC1_NO_OPRIMIDO(Compostera* handle);
static void enact_TEC1_Copy_1_DEBOUNCE(Compostera* handle);
static void enact_TECX_DEBOUNCE(Compostera* handle);
static void enact_TECX_OPRIMIDO(Compostera* handle);
static void enact_TECX_NO_OPRIMIDO(Compostera* handle);
static void enact_TECX_Copy_1_DEBOUNCE(Compostera* handle);
static void enact_activity_ESPERANDO(Compostera* handle);
static void enact_activity_ENFRIANDO(Compostera* handle);
static void enact_activity_HUMEDECIENDO(Compostera* handle);
static void enact_activity_DESHUMEDECIENDO(Compostera* handle);
static void enact_activity_COMPOSTANDO_r1_RELLENANDO(Compostera* handle);
static void enact_activity_COMPOSTANDO_r1_SONANDO(Compostera* handle);
static void enact_activity_COMPOSTANDO_r1_MEZCLANDO(Compostera* handle);
static void exact_TEC1_DEBOUNCE(Compostera* handle);
static void exact_TEC1_NO_OPRIMIDO(Compostera* handle);
static void exact_TEC1_Copy_1_DEBOUNCE(Compostera* handle);
static void exact_TECX_DEBOUNCE(Compostera* handle);
static void exact_TECX_NO_OPRIMIDO(Compostera* handle);
static void exact_TECX_Copy_1_DEBOUNCE(Compostera* handle);
static void exact_activity_COMPOSTANDO_r1_RELLENANDO(Compostera* handle);
static void exact_activity_COMPOSTANDO_r1_MEZCLANDO(Compostera* handle);
static void enseq_TEC1_DEBOUNCE_default(Compostera* handle);
static void enseq_TEC1_ESPERA_default(Compostera* handle);
static void enseq_TEC1_OPRIMIDO_default(Compostera* handle);
static void enseq_TEC1_VALIDACION_default(Compostera* handle);
static void enseq_TEC1_NO_OPRIMIDO_default(Compostera* handle);
static void enseq_TEC1_Copy_1_DEBOUNCE_default(Compostera* handle);
static void enseq_TEC1_Copy_1_VALIDACION_default(Compostera* handle);
static void enseq_TECX_DEBOUNCE_default(Compostera* handle);
static void enseq_TECX_ESPERA_default(Compostera* handle);
static void enseq_TECX_OPRIMIDO_default(Compostera* handle);
static void enseq_TECX_VALIDACION_default(Compostera* handle);
static void enseq_TECX_NO_OPRIMIDO_default(Compostera* handle);
static void enseq_TECX_Copy_1_DEBOUNCE_default(Compostera* handle);
static void enseq_TECX_Copy_1_VALIDACION_default(Compostera* handle);
static void enseq_main_region_ESPERA_default(Compostera* handle);
static void enseq_activity_ESPERANDO_default(Compostera* handle);
static void enseq_activity_ENFRIANDO_default(Compostera* handle);
static void enseq_activity_HUMEDECIENDO_default(Compostera* handle);
static void enseq_activity_DESHUMEDECIENDO_default(Compostera* handle);
static void enseq_activity_COMPOSTANDO_default(Compostera* handle);
static void enseq_activity_COMPOSTANDO_r1_RELLENANDO_default(Compostera* handle);
static void enseq_activity_COMPOSTANDO_r1_SONANDO_default(Compostera* handle);
static void enseq_activity_COMPOSTANDO_r1_MEZCLANDO_default(Compostera* handle);
static void enseq_TEC1_default(Compostera* handle);
static void enseq_TECX_default(Compostera* handle);
static void enseq_main_region_default(Compostera* handle);
static void enseq_activity_default(Compostera* handle);
static void enseq_activity_COMPOSTANDO_r1_default(Compostera* handle);
static void exseq_TEC1_DEBOUNCE(Compostera* handle);
static void exseq_TEC1_ESPERA(Compostera* handle);
static void exseq_TEC1_OPRIMIDO(Compostera* handle);
static void exseq_TEC1_VALIDACION(Compostera* handle);
static void exseq_TEC1_NO_OPRIMIDO(Compostera* handle);
static void exseq_TEC1_Copy_1_DEBOUNCE(Compostera* handle);
static void exseq_TEC1_Copy_1_VALIDACION(Compostera* handle);
static void exseq_TECX_DEBOUNCE(Compostera* handle);
static void exseq_TECX_ESPERA(Compostera* handle);
static void exseq_TECX_OPRIMIDO(Compostera* handle);
static void exseq_TECX_VALIDACION(Compostera* handle);
static void exseq_TECX_NO_OPRIMIDO(Compostera* handle);
static void exseq_TECX_Copy_1_DEBOUNCE(Compostera* handle);
static void exseq_TECX_Copy_1_VALIDACION(Compostera* handle);
static void exseq_main_region_ESPERA(Compostera* handle);
static void exseq_activity_ESPERANDO(Compostera* handle);
static void exseq_activity_ENFRIANDO(Compostera* handle);
static void exseq_activity_HUMEDECIENDO(Compostera* handle);
static void exseq_activity_DESHUMEDECIENDO(Compostera* handle);
static void exseq_activity_COMPOSTANDO(Compostera* handle);
static void exseq_activity_COMPOSTANDO_r1_RELLENANDO(Compostera* handle);
static void exseq_activity_COMPOSTANDO_r1_SONANDO(Compostera* handle);
static void exseq_activity_COMPOSTANDO_r1_MEZCLANDO(Compostera* handle);
static void exseq_TEC1(Compostera* handle);
static void exseq_TECX(Compostera* handle);
static void exseq_main_region(Compostera* handle);
static void exseq_activity(Compostera* handle);
static void exseq_activity_COMPOSTANDO_r1(Compostera* handle);
static void react_TEC1_DEBOUNCE(Compostera* handle);
static void react_TEC1_ESPERA(Compostera* handle);
static void react_TEC1_OPRIMIDO(Compostera* handle);
static void react_TEC1_VALIDACION(Compostera* handle);
static void react_TEC1_NO_OPRIMIDO(Compostera* handle);
static void react_TEC1_Copy_1_DEBOUNCE(Compostera* handle);
static void react_TEC1_Copy_1_VALIDACION(Compostera* handle);
static void react_TECX_DEBOUNCE(Compostera* handle);
static void react_TECX_ESPERA(Compostera* handle);
static void react_TECX_OPRIMIDO(Compostera* handle);
static void react_TECX_VALIDACION(Compostera* handle);
static void react_TECX_NO_OPRIMIDO(Compostera* handle);
static void react_TECX_Copy_1_DEBOUNCE(Compostera* handle);
static void react_TECX_Copy_1_VALIDACION(Compostera* handle);
static void react_main_region_ESPERA(Compostera* handle);
static void react_activity_ESPERANDO(Compostera* handle);
static void react_activity_ENFRIANDO(Compostera* handle);
static void react_activity_HUMEDECIENDO(Compostera* handle);
static void react_activity_DESHUMEDECIENDO(Compostera* handle);
static void react_activity_COMPOSTANDO_r1_RELLENANDO(Compostera* handle);
static void react_activity_COMPOSTANDO_r1_SONANDO(Compostera* handle);
static void react_activity_COMPOSTANDO_r1_MEZCLANDO(Compostera* handle);
static void react_TEC1__entry_Default(Compostera* handle);
static void react_TECX__entry_Default(Compostera* handle);
static void react_main_region__entry_Default(Compostera* handle);
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
	
		/* Default init sequence for statechart compostera */
		handle->internal.viTecla = 0;
		handle->internal.viTecla1 = 0;
}

void compostera_enter(Compostera* handle)
{
	/* Default enter sequence for statechart compostera */
	enseq_TEC1_default(handle);
	enseq_TECX_default(handle);
	enseq_main_region_default(handle);
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
		case Compostera_TEC1_DEBOUNCE:
		{
			react_TEC1_DEBOUNCE(handle);
			break;
		}
		case Compostera_TEC1_ESPERA:
		{
			react_TEC1_ESPERA(handle);
			break;
		}
		case Compostera_TEC1_OPRIMIDO:
		{
			react_TEC1_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC1_VALIDACION:
		{
			react_TEC1_VALIDACION(handle);
			break;
		}
		case Compostera_TEC1_NO_OPRIMIDO:
		{
			react_TEC1_NO_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC1_Copy_1_DEBOUNCE:
		{
			react_TEC1_Copy_1_DEBOUNCE(handle);
			break;
		}
		case Compostera_TEC1_Copy_1_VALIDACION:
		{
			react_TEC1_Copy_1_VALIDACION(handle);
			break;
		}
		case Compostera_TECX_DEBOUNCE:
		{
			react_TECX_DEBOUNCE(handle);
			break;
		}
		case Compostera_TECX_ESPERA:
		{
			react_TECX_ESPERA(handle);
			break;
		}
		case Compostera_TECX_OPRIMIDO:
		{
			react_TECX_OPRIMIDO(handle);
			break;
		}
		case Compostera_TECX_VALIDACION:
		{
			react_TECX_VALIDACION(handle);
			break;
		}
		case Compostera_TECX_NO_OPRIMIDO:
		{
			react_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Compostera_TECX_Copy_1_DEBOUNCE:
		{
			react_TECX_Copy_1_DEBOUNCE(handle);
			break;
		}
		case Compostera_TECX_Copy_1_VALIDACION:
		{
			react_TECX_Copy_1_VALIDACION(handle);
			break;
		}
		case Compostera_main_region_ESPERA:
		{
			react_main_region_ESPERA(handle);
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
	exseq_TECX(handle);
	exseq_main_region(handle);
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
		case Compostera_TEC1_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_DEBOUNCE] == Compostera_TEC1_DEBOUNCE
			);
			break;
		case Compostera_TEC1_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_ESPERA] == Compostera_TEC1_ESPERA
			);
			break;
		case Compostera_TEC1_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_OPRIMIDO] == Compostera_TEC1_OPRIMIDO
			);
			break;
		case Compostera_TEC1_VALIDACION :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_VALIDACION] == Compostera_TEC1_VALIDACION
			);
			break;
		case Compostera_TEC1_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_NO_OPRIMIDO] == Compostera_TEC1_NO_OPRIMIDO
			);
			break;
		case Compostera_TEC1_Copy_1_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_COPY_1_DEBOUNCE] == Compostera_TEC1_Copy_1_DEBOUNCE
			);
			break;
		case Compostera_TEC1_Copy_1_VALIDACION :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TEC1_COPY_1_VALIDACION] == Compostera_TEC1_Copy_1_VALIDACION
			);
			break;
		case Compostera_TECX_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TECX_DEBOUNCE] == Compostera_TECX_DEBOUNCE
			);
			break;
		case Compostera_TECX_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TECX_ESPERA] == Compostera_TECX_ESPERA
			);
			break;
		case Compostera_TECX_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TECX_OPRIMIDO] == Compostera_TECX_OPRIMIDO
			);
			break;
		case Compostera_TECX_VALIDACION :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TECX_VALIDACION] == Compostera_TECX_VALIDACION
			);
			break;
		case Compostera_TECX_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TECX_NO_OPRIMIDO] == Compostera_TECX_NO_OPRIMIDO
			);
			break;
		case Compostera_TECX_Copy_1_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TECX_COPY_1_DEBOUNCE] == Compostera_TECX_Copy_1_DEBOUNCE
			);
			break;
		case Compostera_TECX_Copy_1_VALIDACION :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_TECX_COPY_1_VALIDACION] == Compostera_TECX_Copy_1_VALIDACION
			);
			break;
		case Compostera_main_region_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_COMPOSTERA_MAIN_REGION_ESPERA] == Compostera_main_region_ESPERA
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
	handle->iface.evTECXNoOprimido_raised = bool_false;
	handle->iface.evTECXOprimido_raised = bool_false;
	handle->internal.siTECXOK_raised = bool_false;
	handle->internal.siTECXNoOK_raised = bool_false;
	handle->internal.siTEC1OK_raised = bool_false;
	handle->internal.siTEC1NoOK_raised = bool_false;
	handle->internal.siTemperaturaMayor60_raised = bool_false;
	handle->internal.siTemperaturaEstable_raised = bool_false;
	handle->internal.siHumedadMenor40_raised = bool_false;
	handle->internal.siHumedadEstable_raised = bool_false;
	handle->internal.siHumedadMayor60_raised = bool_false;
	handle->internal.siAberturaTapa_raised = bool_false;
	handle->internal.siCerradoTapa_raised = bool_false;
	handle->timeEvents.compostera_TEC1_DEBOUNCE_tev0_raised = bool_false;
	handle->timeEvents.compostera_TEC1_NO_OPRIMIDO_tev0_raised = bool_false;
	handle->timeEvents.compostera_TEC1_Copy_1_DEBOUNCE_tev0_raised = bool_false;
	handle->timeEvents.compostera_TECX_DEBOUNCE_tev0_raised = bool_false;
	handle->timeEvents.compostera_TECX_NO_OPRIMIDO_tev0_raised = bool_false;
	handle->timeEvents.compostera_TECX_Copy_1_DEBOUNCE_tev0_raised = bool_false;
	handle->timeEvents.compostera_activity_COMPOSTANDO_r1_RELLENANDO_tev0_raised = bool_false;
	handle->timeEvents.compostera_activity_COMPOSTANDO_r1_MEZCLANDO_tev0_raised = bool_false;
}

static void clearOutEvents(Compostera* handle)
{
}

void composteraIface_raise_evTEC1NoOprimido(Compostera* handle, sc_integer value)
{
	handle->iface.evTEC1NoOprimido_value = value;
	handle->iface.evTEC1NoOprimido_raised = bool_true;
}
void composteraIface_raise_evTEC1Oprimido(Compostera* handle, sc_integer value)
{
	handle->iface.evTEC1Oprimido_value = value;
	handle->iface.evTEC1Oprimido_raised = bool_true;
}
void composteraIface_raise_evTECXNoOprimido(Compostera* handle, sc_integer value)
{
	handle->iface.evTECXNoOprimido_value = value;
	handle->iface.evTECXNoOprimido_raised = bool_true;
}
void composteraIface_raise_evTECXOprimido(Compostera* handle, sc_integer value)
{
	handle->iface.evTECXOprimido_value = value;
	handle->iface.evTECXOprimido_raised = bool_true;
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

static sc_boolean check_TEC1_DEBOUNCE_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TEC1_DEBOUNCE_tev0_raised;
}

static sc_boolean check_TEC1_ESPERA_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC1Oprimido_raised;
}

static sc_boolean check_TEC1_OPRIMIDO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC1NoOprimido_raised;
}

static sc_boolean check_TEC1_VALIDACION_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC1Oprimido_raised;
}

static sc_boolean check_TEC1_VALIDACION_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTEC1NoOprimido_raised;
}

static sc_boolean check_TEC1_NO_OPRIMIDO_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TEC1_NO_OPRIMIDO_tev0_raised;
}

static sc_boolean check_TEC1_Copy_1_DEBOUNCE_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TEC1_Copy_1_DEBOUNCE_tev0_raised;
}

static sc_boolean check_TEC1_Copy_1_VALIDACION_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTEC1NoOprimido_raised;
}

static sc_boolean check_TECX_DEBOUNCE_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TECX_DEBOUNCE_tev0_raised;
}

static sc_boolean check_TECX_ESPERA_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean check_TECX_OPRIMIDO_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean check_TECX_VALIDACION_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean check_TECX_VALIDACION_tr1_tr1(const Compostera* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean check_TECX_NO_OPRIMIDO_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TECX_NO_OPRIMIDO_tev0_raised;
}

static sc_boolean check_TECX_Copy_1_DEBOUNCE_tr0_tr0(const Compostera* handle)
{
	return handle->timeEvents.compostera_TECX_Copy_1_DEBOUNCE_tev0_raised;
}

static sc_boolean check_TECX_Copy_1_VALIDACION_tr0_tr0(const Compostera* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean check_main_region_ESPERA_tr0_tr0(const Compostera* handle)
{
	return ((handle->internal.siTEC1OK_raised) && (handle->internal.viTecla1 == COMPOSTERA_COMPOSTERAIFACE_TEC1)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr1_tr1(const Compostera* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == COMPOSTERA_COMPOSTERAIFACE_TEC4)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr2_tr2(const Compostera* handle)
{
	return ((handle->internal.siTECXNoOK_raised) && (handle->internal.viTecla == COMPOSTERA_COMPOSTERAIFACE_TEC3)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr3_tr3(const Compostera* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == COMPOSTERA_COMPOSTERAIFACE_TEC3)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr4_tr4(const Compostera* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == COMPOSTERA_COMPOSTERAIFACE_TEC2)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr5_tr5(const Compostera* handle)
{
	return ((handle->internal.siTECXNoOK_raised) && (handle->internal.viTecla == COMPOSTERA_COMPOSTERAIFACE_TEC2)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr6_tr6(const Compostera* handle)
{
	return ((handle->internal.siTECXNoOK_raised) && (handle->internal.viTecla == COMPOSTERA_COMPOSTERAIFACE_TEC4)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr7_tr7(const Compostera* handle)
{
	return ((handle->internal.siTEC1NoOK_raised) && (handle->internal.viTecla1 == COMPOSTERA_COMPOSTERAIFACE_TEC1)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr8_tr8(const Compostera* handle)
{
	return ((handle->internal.siTEC1OK_raised) && (handle->internal.viTecla1 == 3)) ? bool_true : bool_false;
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

static void effect_TEC1_DEBOUNCE_tr0(Compostera* handle)
{
	exseq_TEC1_DEBOUNCE(handle);
	enseq_TEC1_VALIDACION_default(handle);
}

static void effect_TEC1_ESPERA_tr0(Compostera* handle)
{
	exseq_TEC1_ESPERA(handle);
	enseq_TEC1_DEBOUNCE_default(handle);
}

static void effect_TEC1_OPRIMIDO_tr0(Compostera* handle)
{
	exseq_TEC1_OPRIMIDO(handle);
	enseq_TEC1_Copy_1_DEBOUNCE_default(handle);
}

static void effect_TEC1_VALIDACION_tr0(Compostera* handle)
{
	exseq_TEC1_VALIDACION(handle);
	enseq_TEC1_OPRIMIDO_default(handle);
}

static void effect_TEC1_VALIDACION_tr1(Compostera* handle)
{
	exseq_TEC1_VALIDACION(handle);
	enseq_TEC1_ESPERA_default(handle);
}

static void effect_TEC1_NO_OPRIMIDO_tr0(Compostera* handle)
{
	exseq_TEC1_NO_OPRIMIDO(handle);
	enseq_TEC1_ESPERA_default(handle);
}

static void effect_TEC1_Copy_1_DEBOUNCE_tr0(Compostera* handle)
{
	exseq_TEC1_Copy_1_DEBOUNCE(handle);
	enseq_TEC1_Copy_1_VALIDACION_default(handle);
}

static void effect_TEC1_Copy_1_VALIDACION_tr0(Compostera* handle)
{
	exseq_TEC1_Copy_1_VALIDACION(handle);
	enseq_TEC1_NO_OPRIMIDO_default(handle);
}

static void effect_TECX_DEBOUNCE_tr0(Compostera* handle)
{
	exseq_TECX_DEBOUNCE(handle);
	enseq_TECX_VALIDACION_default(handle);
}

static void effect_TECX_ESPERA_tr0(Compostera* handle)
{
	exseq_TECX_ESPERA(handle);
	enseq_TECX_DEBOUNCE_default(handle);
}

static void effect_TECX_OPRIMIDO_tr0(Compostera* handle)
{
	exseq_TECX_OPRIMIDO(handle);
	enseq_TECX_Copy_1_DEBOUNCE_default(handle);
}

static void effect_TECX_VALIDACION_tr0(Compostera* handle)
{
	exseq_TECX_VALIDACION(handle);
	enseq_TECX_OPRIMIDO_default(handle);
}

static void effect_TECX_VALIDACION_tr1(Compostera* handle)
{
	exseq_TECX_VALIDACION(handle);
	enseq_TECX_ESPERA_default(handle);
}

static void effect_TECX_NO_OPRIMIDO_tr0(Compostera* handle)
{
	exseq_TECX_NO_OPRIMIDO(handle);
	enseq_TECX_ESPERA_default(handle);
}

static void effect_TECX_Copy_1_DEBOUNCE_tr0(Compostera* handle)
{
	exseq_TECX_Copy_1_DEBOUNCE(handle);
	enseq_TECX_Copy_1_VALIDACION_default(handle);
}

static void effect_TECX_Copy_1_VALIDACION_tr0(Compostera* handle)
{
	exseq_TECX_Copy_1_VALIDACION(handle);
	enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void effect_main_region_ESPERA_tr0(Compostera* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siAberturaTapa_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr1(Compostera* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siHumedadMayor60_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr2(Compostera* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siTemperaturaEstable_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr3(Compostera* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siTemperaturaMayor60_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr4(Compostera* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siHumedadMenor40_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr5(Compostera* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siHumedadEstable_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr6(Compostera* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siHumedadEstable_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr7(Compostera* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siCerradoTapa_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr8(Compostera* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siAberturaTapa_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
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

/* Entry action for state 'DEBOUNCE'. */
static void enact_TEC1_DEBOUNCE(Compostera* handle)
{
	/* Entry action for state 'DEBOUNCE'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC1_DEBOUNCE_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void enact_TEC1_OPRIMIDO(Compostera* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siTEC1OK_raised = bool_true;
	handle->internal.viTecla1 = handle->iface.evTEC1Oprimido_value;
}

/* Entry action for state 'NO_OPRIMIDO'. */
static void enact_TEC1_NO_OPRIMIDO(Compostera* handle)
{
	/* Entry action for state 'NO_OPRIMIDO'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC1_NO_OPRIMIDO_tev0_raised) , 100, bool_false);
	handle->internal.siTEC1NoOK_raised = bool_true;
	handle->internal.viTecla1 = handle->iface.evTEC1Oprimido_value;
}

/* Entry action for state 'Copy_1_DEBOUNCE'. */
static void enact_TEC1_Copy_1_DEBOUNCE(Compostera* handle)
{
	/* Entry action for state 'Copy_1_DEBOUNCE'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC1_Copy_1_DEBOUNCE_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'DEBOUNCE'. */
static void enact_TECX_DEBOUNCE(Compostera* handle)
{
	/* Entry action for state 'DEBOUNCE'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TECX_DEBOUNCE_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void enact_TECX_OPRIMIDO(Compostera* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siTECXOK_raised = bool_true;
	handle->internal.viTecla = handle->iface.evTECXOprimido_value;
}

/* Entry action for state 'NO_OPRIMIDO'. */
static void enact_TECX_NO_OPRIMIDO(Compostera* handle)
{
	/* Entry action for state 'NO_OPRIMIDO'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TECX_NO_OPRIMIDO_tev0_raised) , 100, bool_false);
	handle->internal.siTECXNoOK_raised = bool_true;
	handle->internal.viTecla = handle->iface.evTECXOprimido_value;
}

/* Entry action for state 'Copy_1_DEBOUNCE'. */
static void enact_TECX_Copy_1_DEBOUNCE(Compostera* handle)
{
	/* Entry action for state 'Copy_1_DEBOUNCE'. */
	compostera_setTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TECX_Copy_1_DEBOUNCE_tev0_raised) , 100, bool_false);
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

/* Exit action for state 'DEBOUNCE'. */
static void exact_TEC1_DEBOUNCE(Compostera* handle)
{
	/* Exit action for state 'DEBOUNCE'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC1_DEBOUNCE_tev0_raised) );		
}

/* Exit action for state 'NO_OPRIMIDO'. */
static void exact_TEC1_NO_OPRIMIDO(Compostera* handle)
{
	/* Exit action for state 'NO_OPRIMIDO'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC1_NO_OPRIMIDO_tev0_raised) );		
}

/* Exit action for state 'Copy_1_DEBOUNCE'. */
static void exact_TEC1_Copy_1_DEBOUNCE(Compostera* handle)
{
	/* Exit action for state 'Copy_1_DEBOUNCE'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TEC1_Copy_1_DEBOUNCE_tev0_raised) );		
}

/* Exit action for state 'DEBOUNCE'. */
static void exact_TECX_DEBOUNCE(Compostera* handle)
{
	/* Exit action for state 'DEBOUNCE'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TECX_DEBOUNCE_tev0_raised) );		
}

/* Exit action for state 'NO_OPRIMIDO'. */
static void exact_TECX_NO_OPRIMIDO(Compostera* handle)
{
	/* Exit action for state 'NO_OPRIMIDO'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TECX_NO_OPRIMIDO_tev0_raised) );		
}

/* Exit action for state 'Copy_1_DEBOUNCE'. */
static void exact_TECX_Copy_1_DEBOUNCE(Compostera* handle)
{
	/* Exit action for state 'Copy_1_DEBOUNCE'. */
	compostera_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.compostera_TECX_Copy_1_DEBOUNCE_tev0_raised) );		
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

/* 'default' enter sequence for state DEBOUNCE */
static void enseq_TEC1_DEBOUNCE_default(Compostera* handle)
{
	/* 'default' enter sequence for state DEBOUNCE */
	enact_TEC1_DEBOUNCE(handle);
	handle->stateConfVector[0] = Compostera_TEC1_DEBOUNCE;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ESPERA */
static void enseq_TEC1_ESPERA_default(Compostera* handle)
{
	/* 'default' enter sequence for state ESPERA */
	handle->stateConfVector[0] = Compostera_TEC1_ESPERA;
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

/* 'default' enter sequence for state VALIDACION */
static void enseq_TEC1_VALIDACION_default(Compostera* handle)
{
	/* 'default' enter sequence for state VALIDACION */
	handle->stateConfVector[0] = Compostera_TEC1_VALIDACION;
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

/* 'default' enter sequence for state Copy_1_DEBOUNCE */
static void enseq_TEC1_Copy_1_DEBOUNCE_default(Compostera* handle)
{
	/* 'default' enter sequence for state Copy_1_DEBOUNCE */
	enact_TEC1_Copy_1_DEBOUNCE(handle);
	handle->stateConfVector[0] = Compostera_TEC1_Copy_1_DEBOUNCE;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Copy_1_VALIDACION */
static void enseq_TEC1_Copy_1_VALIDACION_default(Compostera* handle)
{
	/* 'default' enter sequence for state Copy_1_VALIDACION */
	handle->stateConfVector[0] = Compostera_TEC1_Copy_1_VALIDACION;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state DEBOUNCE */
static void enseq_TECX_DEBOUNCE_default(Compostera* handle)
{
	/* 'default' enter sequence for state DEBOUNCE */
	enact_TECX_DEBOUNCE(handle);
	handle->stateConfVector[1] = Compostera_TECX_DEBOUNCE;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state ESPERA */
static void enseq_TECX_ESPERA_default(Compostera* handle)
{
	/* 'default' enter sequence for state ESPERA */
	handle->stateConfVector[1] = Compostera_TECX_ESPERA;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state OPRIMIDO */
static void enseq_TECX_OPRIMIDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	enact_TECX_OPRIMIDO(handle);
	handle->stateConfVector[1] = Compostera_TECX_OPRIMIDO;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state VALIDACION */
static void enseq_TECX_VALIDACION_default(Compostera* handle)
{
	/* 'default' enter sequence for state VALIDACION */
	handle->stateConfVector[1] = Compostera_TECX_VALIDACION;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void enseq_TECX_NO_OPRIMIDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	enact_TECX_NO_OPRIMIDO(handle);
	handle->stateConfVector[1] = Compostera_TECX_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state Copy_1_DEBOUNCE */
static void enseq_TECX_Copy_1_DEBOUNCE_default(Compostera* handle)
{
	/* 'default' enter sequence for state Copy_1_DEBOUNCE */
	enact_TECX_Copy_1_DEBOUNCE(handle);
	handle->stateConfVector[1] = Compostera_TECX_Copy_1_DEBOUNCE;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state Copy_1_VALIDACION */
static void enseq_TECX_Copy_1_VALIDACION_default(Compostera* handle)
{
	/* 'default' enter sequence for state Copy_1_VALIDACION */
	handle->stateConfVector[1] = Compostera_TECX_Copy_1_VALIDACION;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state ESPERA */
static void enseq_main_region_ESPERA_default(Compostera* handle)
{
	/* 'default' enter sequence for state ESPERA */
	handle->stateConfVector[2] = Compostera_main_region_ESPERA;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state ESPERANDO */
static void enseq_activity_ESPERANDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state ESPERANDO */
	enact_activity_ESPERANDO(handle);
	handle->stateConfVector[3] = Compostera_activity_ESPERANDO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state ENFRIANDO */
static void enseq_activity_ENFRIANDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state ENFRIANDO */
	enact_activity_ENFRIANDO(handle);
	handle->stateConfVector[3] = Compostera_activity_ENFRIANDO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state HUMEDECIENDO */
static void enseq_activity_HUMEDECIENDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state HUMEDECIENDO */
	enact_activity_HUMEDECIENDO(handle);
	handle->stateConfVector[3] = Compostera_activity_HUMEDECIENDO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state DESHUMEDECIENDO */
static void enseq_activity_DESHUMEDECIENDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state DESHUMEDECIENDO */
	enact_activity_DESHUMEDECIENDO(handle);
	handle->stateConfVector[3] = Compostera_activity_DESHUMEDECIENDO;
	handle->stateConfVectorPosition = 3;
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
	handle->stateConfVector[3] = Compostera_activity_COMPOSTANDO_r1_RELLENANDO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state SONANDO */
static void enseq_activity_COMPOSTANDO_r1_SONANDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state SONANDO */
	enact_activity_COMPOSTANDO_r1_SONANDO(handle);
	handle->stateConfVector[3] = Compostera_activity_COMPOSTANDO_r1_SONANDO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state MEZCLANDO */
static void enseq_activity_COMPOSTANDO_r1_MEZCLANDO_default(Compostera* handle)
{
	/* 'default' enter sequence for state MEZCLANDO */
	enact_activity_COMPOSTANDO_r1_MEZCLANDO(handle);
	handle->stateConfVector[3] = Compostera_activity_COMPOSTANDO_r1_MEZCLANDO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for region TEC1 */
static void enseq_TEC1_default(Compostera* handle)
{
	/* 'default' enter sequence for region TEC1 */
	react_TEC1__entry_Default(handle);
}

/* 'default' enter sequence for region TECX */
static void enseq_TECX_default(Compostera* handle)
{
	/* 'default' enter sequence for region TECX */
	react_TECX__entry_Default(handle);
}

/* 'default' enter sequence for region main region */
static void enseq_main_region_default(Compostera* handle)
{
	/* 'default' enter sequence for region main region */
	react_main_region__entry_Default(handle);
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

/* Default exit sequence for state DEBOUNCE */
static void exseq_TEC1_DEBOUNCE(Compostera* handle)
{
	/* Default exit sequence for state DEBOUNCE */
	handle->stateConfVector[0] = Compostera_last_state;
	handle->stateConfVectorPosition = 0;
	exact_TEC1_DEBOUNCE(handle);
}

/* Default exit sequence for state ESPERA */
static void exseq_TEC1_ESPERA(Compostera* handle)
{
	/* Default exit sequence for state ESPERA */
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

/* Default exit sequence for state VALIDACION */
static void exseq_TEC1_VALIDACION(Compostera* handle)
{
	/* Default exit sequence for state VALIDACION */
	handle->stateConfVector[0] = Compostera_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state NO_OPRIMIDO */
static void exseq_TEC1_NO_OPRIMIDO(Compostera* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Compostera_last_state;
	handle->stateConfVectorPosition = 0;
	exact_TEC1_NO_OPRIMIDO(handle);
}

/* Default exit sequence for state Copy_1_DEBOUNCE */
static void exseq_TEC1_Copy_1_DEBOUNCE(Compostera* handle)
{
	/* Default exit sequence for state Copy_1_DEBOUNCE */
	handle->stateConfVector[0] = Compostera_last_state;
	handle->stateConfVectorPosition = 0;
	exact_TEC1_Copy_1_DEBOUNCE(handle);
}

/* Default exit sequence for state Copy_1_VALIDACION */
static void exseq_TEC1_Copy_1_VALIDACION(Compostera* handle)
{
	/* Default exit sequence for state Copy_1_VALIDACION */
	handle->stateConfVector[0] = Compostera_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state DEBOUNCE */
static void exseq_TECX_DEBOUNCE(Compostera* handle)
{
	/* Default exit sequence for state DEBOUNCE */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
	exact_TECX_DEBOUNCE(handle);
}

/* Default exit sequence for state ESPERA */
static void exseq_TECX_ESPERA(Compostera* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state OPRIMIDO */
static void exseq_TECX_OPRIMIDO(Compostera* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state VALIDACION */
static void exseq_TECX_VALIDACION(Compostera* handle)
{
	/* Default exit sequence for state VALIDACION */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state NO_OPRIMIDO */
static void exseq_TECX_NO_OPRIMIDO(Compostera* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
	exact_TECX_NO_OPRIMIDO(handle);
}

/* Default exit sequence for state Copy_1_DEBOUNCE */
static void exseq_TECX_Copy_1_DEBOUNCE(Compostera* handle)
{
	/* Default exit sequence for state Copy_1_DEBOUNCE */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
	exact_TECX_Copy_1_DEBOUNCE(handle);
}

/* Default exit sequence for state Copy_1_VALIDACION */
static void exseq_TECX_Copy_1_VALIDACION(Compostera* handle)
{
	/* Default exit sequence for state Copy_1_VALIDACION */
	handle->stateConfVector[1] = Compostera_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state ESPERA */
static void exseq_main_region_ESPERA(Compostera* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[2] = Compostera_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state ESPERANDO */
static void exseq_activity_ESPERANDO(Compostera* handle)
{
	/* Default exit sequence for state ESPERANDO */
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state ENFRIANDO */
static void exseq_activity_ENFRIANDO(Compostera* handle)
{
	/* Default exit sequence for state ENFRIANDO */
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state HUMEDECIENDO */
static void exseq_activity_HUMEDECIENDO(Compostera* handle)
{
	/* Default exit sequence for state HUMEDECIENDO */
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state DESHUMEDECIENDO */
static void exseq_activity_DESHUMEDECIENDO(Compostera* handle)
{
	/* Default exit sequence for state DESHUMEDECIENDO */
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
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
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
	exact_activity_COMPOSTANDO_r1_RELLENANDO(handle);
}

/* Default exit sequence for state SONANDO */
static void exseq_activity_COMPOSTANDO_r1_SONANDO(Compostera* handle)
{
	/* Default exit sequence for state SONANDO */
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state MEZCLANDO */
static void exseq_activity_COMPOSTANDO_r1_MEZCLANDO(Compostera* handle)
{
	/* Default exit sequence for state MEZCLANDO */
	handle->stateConfVector[3] = Compostera_last_state;
	handle->stateConfVectorPosition = 3;
	exact_activity_COMPOSTANDO_r1_MEZCLANDO(handle);
}

/* Default exit sequence for region TEC1 */
static void exseq_TEC1(Compostera* handle)
{
	/* Default exit sequence for region TEC1 */
	/* Handle exit of all possible states (of compostera.TEC1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Compostera_TEC1_DEBOUNCE :
		{
			exseq_TEC1_DEBOUNCE(handle);
			break;
		}
		case Compostera_TEC1_ESPERA :
		{
			exseq_TEC1_ESPERA(handle);
			break;
		}
		case Compostera_TEC1_OPRIMIDO :
		{
			exseq_TEC1_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC1_VALIDACION :
		{
			exseq_TEC1_VALIDACION(handle);
			break;
		}
		case Compostera_TEC1_NO_OPRIMIDO :
		{
			exseq_TEC1_NO_OPRIMIDO(handle);
			break;
		}
		case Compostera_TEC1_Copy_1_DEBOUNCE :
		{
			exseq_TEC1_Copy_1_DEBOUNCE(handle);
			break;
		}
		case Compostera_TEC1_Copy_1_VALIDACION :
		{
			exseq_TEC1_Copy_1_VALIDACION(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region TECX */
static void exseq_TECX(Compostera* handle)
{
	/* Default exit sequence for region TECX */
	/* Handle exit of all possible states (of compostera.TECX) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Compostera_TECX_DEBOUNCE :
		{
			exseq_TECX_DEBOUNCE(handle);
			break;
		}
		case Compostera_TECX_ESPERA :
		{
			exseq_TECX_ESPERA(handle);
			break;
		}
		case Compostera_TECX_OPRIMIDO :
		{
			exseq_TECX_OPRIMIDO(handle);
			break;
		}
		case Compostera_TECX_VALIDACION :
		{
			exseq_TECX_VALIDACION(handle);
			break;
		}
		case Compostera_TECX_NO_OPRIMIDO :
		{
			exseq_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Compostera_TECX_Copy_1_DEBOUNCE :
		{
			exseq_TECX_Copy_1_DEBOUNCE(handle);
			break;
		}
		case Compostera_TECX_Copy_1_VALIDACION :
		{
			exseq_TECX_Copy_1_VALIDACION(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region main region */
static void exseq_main_region(Compostera* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of compostera.main_region) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Compostera_main_region_ESPERA :
		{
			exseq_main_region_ESPERA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region activity */
static void exseq_activity(Compostera* handle)
{
	/* Default exit sequence for region activity */
	/* Handle exit of all possible states (of compostera.activity) at position 3... */
	switch(handle->stateConfVector[ 3 ])
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
	/* Handle exit of all possible states (of compostera.activity.COMPOSTANDO.r1) at position 3... */
	switch(handle->stateConfVector[ 3 ])
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

/* The reactions of state DEBOUNCE. */
static void react_TEC1_DEBOUNCE(Compostera* handle)
{
	/* The reactions of state DEBOUNCE. */
	if (check_TEC1_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC1_DEBOUNCE_tr0(handle);
	} 
}

/* The reactions of state ESPERA. */
static void react_TEC1_ESPERA(Compostera* handle)
{
	/* The reactions of state ESPERA. */
	if (check_TEC1_ESPERA_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC1_ESPERA_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void react_TEC1_OPRIMIDO(Compostera* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (check_TEC1_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC1_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state VALIDACION. */
static void react_TEC1_VALIDACION(Compostera* handle)
{
	/* The reactions of state VALIDACION. */
	if (check_TEC1_VALIDACION_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC1_VALIDACION_tr0(handle);
	}  else
	{
		if (check_TEC1_VALIDACION_tr1_tr1(handle) == bool_true)
		{ 
			effect_TEC1_VALIDACION_tr1(handle);
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
	} 
}

/* The reactions of state Copy_1_DEBOUNCE. */
static void react_TEC1_Copy_1_DEBOUNCE(Compostera* handle)
{
	/* The reactions of state Copy_1_DEBOUNCE. */
	if (check_TEC1_Copy_1_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC1_Copy_1_DEBOUNCE_tr0(handle);
	} 
}

/* The reactions of state Copy_1_VALIDACION. */
static void react_TEC1_Copy_1_VALIDACION(Compostera* handle)
{
	/* The reactions of state Copy_1_VALIDACION. */
	if (check_TEC1_Copy_1_VALIDACION_tr0_tr0(handle) == bool_true)
	{ 
		effect_TEC1_Copy_1_VALIDACION_tr0(handle);
	} 
}

/* The reactions of state DEBOUNCE. */
static void react_TECX_DEBOUNCE(Compostera* handle)
{
	/* The reactions of state DEBOUNCE. */
	if (check_TECX_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_DEBOUNCE_tr0(handle);
	} 
}

/* The reactions of state ESPERA. */
static void react_TECX_ESPERA(Compostera* handle)
{
	/* The reactions of state ESPERA. */
	if (check_TECX_ESPERA_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_ESPERA_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void react_TECX_OPRIMIDO(Compostera* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (check_TECX_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state VALIDACION. */
static void react_TECX_VALIDACION(Compostera* handle)
{
	/* The reactions of state VALIDACION. */
	if (check_TECX_VALIDACION_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_VALIDACION_tr0(handle);
	}  else
	{
		if (check_TECX_VALIDACION_tr1_tr1(handle) == bool_true)
		{ 
			effect_TECX_VALIDACION_tr1(handle);
		} 
	}
}

/* The reactions of state NO_OPRIMIDO. */
static void react_TECX_NO_OPRIMIDO(Compostera* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (check_TECX_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_NO_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state Copy_1_DEBOUNCE. */
static void react_TECX_Copy_1_DEBOUNCE(Compostera* handle)
{
	/* The reactions of state Copy_1_DEBOUNCE. */
	if (check_TECX_Copy_1_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_Copy_1_DEBOUNCE_tr0(handle);
	} 
}

/* The reactions of state Copy_1_VALIDACION. */
static void react_TECX_Copy_1_VALIDACION(Compostera* handle)
{
	/* The reactions of state Copy_1_VALIDACION. */
	if (check_TECX_Copy_1_VALIDACION_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_Copy_1_VALIDACION_tr0(handle);
	} 
}

/* The reactions of state ESPERA. */
static void react_main_region_ESPERA(Compostera* handle)
{
	/* The reactions of state ESPERA. */
	if (check_main_region_ESPERA_tr0_tr0(handle) == bool_true)
	{ 
		effect_main_region_ESPERA_tr0(handle);
	}  else
	{
		if (check_main_region_ESPERA_tr1_tr1(handle) == bool_true)
		{ 
			effect_main_region_ESPERA_tr1(handle);
		}  else
		{
			if (check_main_region_ESPERA_tr2_tr2(handle) == bool_true)
			{ 
				effect_main_region_ESPERA_tr2(handle);
			}  else
			{
				if (check_main_region_ESPERA_tr3_tr3(handle) == bool_true)
				{ 
					effect_main_region_ESPERA_tr3(handle);
				}  else
				{
					if (check_main_region_ESPERA_tr4_tr4(handle) == bool_true)
					{ 
						effect_main_region_ESPERA_tr4(handle);
					}  else
					{
						if (check_main_region_ESPERA_tr5_tr5(handle) == bool_true)
						{ 
							effect_main_region_ESPERA_tr5(handle);
						}  else
						{
							if (check_main_region_ESPERA_tr6_tr6(handle) == bool_true)
							{ 
								effect_main_region_ESPERA_tr6(handle);
							}  else
							{
								if (check_main_region_ESPERA_tr7_tr7(handle) == bool_true)
								{ 
									effect_main_region_ESPERA_tr7(handle);
								}  else
								{
									if (check_main_region_ESPERA_tr8_tr8(handle) == bool_true)
									{ 
										effect_main_region_ESPERA_tr8(handle);
									} 
								}
							}
						}
					}
				}
			}
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
	enseq_TEC1_ESPERA_default(handle);
}

/* Default react sequence for initial entry  */
static void react_TECX__entry_Default(Compostera* handle)
{
	/* Default react sequence for initial entry  */
	enseq_TECX_ESPERA_default(handle);
}

/* Default react sequence for initial entry  */
static void react_main_region__entry_Default(Compostera* handle)
{
	/* Default react sequence for initial entry  */
	enseq_main_region_ESPERA_default(handle);
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


