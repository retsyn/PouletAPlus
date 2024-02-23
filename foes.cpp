#include "entity.h"
#include "foes.h"
#include "tilemap.h"

FoeRoster::FoeRoster()
{

    for (uint8_t i = 0; i < FOE_MAX; i++)
    {
        // Make all entries "dead duds" to start.
        entries[i]->spawned = false;
        entries[i]->type = ENT_DUD;
    }
}

void FoeRoster::add_foe(uint8_t new_type, float start_x, float start_y)
{

    uint8_t i = 0;
    for (i = 0; i < FOE_MAX; i++)
    {
        if (entries[i]->spawned == false)
            break;
    }

    // No space left for monsters, do nothing.
    if (i <= FOE_MAX)
    {
        return;
    }

    entries[i]->spawned = true;
    entries[i]->x = start_x;
    entries[i]->y = start_y;
    entries[i]->type = new_type;
}

void FoeRoster::update(int16_t scroll, Stage *in_stage)
{
    for (uint8_t i = 0; i < FOE_MAX; i++)
    {
        if (entries[i]->spawned)
        {
            entries[i]->draw(scroll);
            entries[i]->physics(in_stage);
        }
        else
        {
            continue;
        }
    }
}