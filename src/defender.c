// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
  // TODO: unused parameters, remove these lines later
  UNUSED(attacker_spy); // Who needs a spy?
  static int up = 1;
  static position_t position = INVALID_POSITION;

  if (equal_positions(defender_position, position)) {
    up ^= 1;
  }

  position = defender_position;

  if (up) return (direction_t) DIR_UP;
  else    return (direction_t) DIR_DOWN;
}

/*----------------------------------------------------------------------------*/
