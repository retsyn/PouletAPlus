#include "entity.h"
#include "foes.h"


FoeRoster::FoeRoster(){
    
    for(uint8_t i = 0; i < FOE_MAX; i++){
        // Make all entries "dead duds" to start.
        entries[i]->spawned = 0;
        entries[i]->type = ENT_DUD;
    }
}

void FoeRoster::add_foe(uint8_t type, float start_x, float start_y){

    uint8_t i = 0;
    
}