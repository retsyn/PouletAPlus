#include "entity.h"
#include "globals.h"

class FoeRoster {

    public:
        Foe *entries[FOE_MAX]; // Constructor will initialize this memory.

        FoeRoster();
        void add_foe(uint8_t new_type, float start_x, float start_y);
        void update(int16_t scroll, Stage *in_stage);
        void draw(int16_t scroll);

};