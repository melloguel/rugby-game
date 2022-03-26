// Standard headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
  // TODO: unused parameters, remove these lines later
  UNUSED(defender_spy); // Who needs a spy?

  static int turn  =  0;
  static int move  =  0;
  static int rng   =  0;
  static direction_t direction = DIR_RIGHT;
  static position_t  position  = INVALID_POSITION;

  if (!rng) {
    srand(time(NULL));
    rng = 1;
  }

  turn += 1;

  if ((turn % 3) == 0 || equal_positions(attacker_position, position)) {
    move = rand() % 100;
  }

  if      (0  <= move && move <  15) direction = (direction_t) DIR_UP;
  else if (15 <= move && move <  45) direction = (direction_t) DIR_UP_RIGHT ;
  else if (45 <= move && move <  55) direction = (direction_t) DIR_RIGHT;
  else if (55 <= move && move <  85) direction = (direction_t) DIR_DOWN_LEFT;
  else if (85 <= move && move < 100) direction = (direction_t) DIR_DOWN;

  return direction;
}

/*----------------------------------------------------------------------------*/
