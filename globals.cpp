#include <Arduboy2.h>
#include "globals.h"

// Define the local pointer to the arduboy instance.
Arduboy2* arduboy;

void initArduboy2() {
  // Allocate the Arduboy2 instance on the heap
  static Arduboy2 arduboyInstance;

  // Set the global pointer to point to the Arduboy2 instance
  arduboy = &arduboyInstance;

  // Initialize the Arduboy2 instance
  arduboy->begin();

}


