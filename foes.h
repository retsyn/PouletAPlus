#include "entity.h"
#include "globals.h"

class FoeRoster {

    public:
        Foe *entries[FOE_MAX];  // Look how to init this super cleanly.

        FoeRoster();
        void add_foe(uint8_t type, float start_x, float start_y);

};