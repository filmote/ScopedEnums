#include <Arduboy2.h>

Arduboy2 arduboy;

enum class Direction : uint8_t {
  North,
  NorthEast,
  East,
  SouthEast,
  South,
  SouthWest,
  West,
  NorthWest,
  Unknown
};

inline bool operator==(const Direction lhs, const Direction rhs) { return ((uint8_t)lhs == (uint8_t)Direction::Unknown ? false : (uint8_t)lhs == (uint8_t)rhs); }
inline bool operator!=(const Direction lhs, const Direction rhs) { return !(lhs == rhs); }
inline bool operator<(const Direction lhs, const Direction rhs)  { return (abs((uint8_t)lhs - (uint8_t)rhs) < 4 ? (uint8_t)lhs - (uint8_t)rhs : (uint8_t)lhs - (8 + (uint8_t)rhs)) < 0; } 
inline bool operator>(const Direction lhs, const Direction rhs)  { return (abs((uint8_t)lhs - (uint8_t)rhs) < 4 ? (uint8_t)lhs - (uint8_t)rhs : (8 + (uint8_t)lhs) - (uint8_t)rhs) > 0; } 
inline bool operator<=(const Direction lhs, const Direction rhs) { return !(lhs > rhs); }
inline bool operator>=(const Direction lhs, const Direction rhs) { return !(lhs < rhs); }

inline Direction &operator++( Direction &c ) { 
  
  c = ( c == Direction::NorthWest ) ? Direction::North : static_cast<Direction>( static_cast<uint8_t>(c) + 1 );
  return c;

}

inline Direction operator++( Direction &c, int ) {

  Direction result = c;
  ++c;
  return result;

}

inline Direction &operator--( Direction & c ) {

  c = ( c == Direction::North ) ? Direction::NorthWest : static_cast<Direction>( static_cast<uint8_t>(c) - 1 );
  return c;

}

inline Direction operator--( Direction & c, int ) {

  Direction result = c;
  --c;
  return result;

}


void printDirection(Direction direction) {
  
  switch (direction) {
  
    case Direction::North:        Serial.println("North");        break;
    case Direction::NorthEast:    Serial.println("NorthEast");    break;
    case Direction::East:         Serial.println("East");         break;
    case Direction::SouthEast:    Serial.println("SouthEast");    break;
    case Direction::South:        Serial.println("South");        break;
    case Direction::SouthWest:    Serial.println("SouthWest");    break;
    case Direction::West:         Serial.println("West");         break;
    case Direction::NorthWest:    Serial.println("NorthWest");    break;
  
  }
    
}

void setup() {

  arduboy.begin();

}

void loop() {
        
  Direction a = Direction::East;
  Direction b = Direction::South;
  
  if (a < b)  { Serial.println("1 East is less than South"); }
  if (a != b) { Serial.println("2 South is not equal to East"); }
  
  a = Direction::NorthWest;
  b = Direction::North;
  
  if (b > a)  { Serial.println("3 North is greater than NorthWest"); }
  if (a <= b) { Serial.println("4 NorthWest is less than or equal to North"); }
  
  a = Direction::North;
  b = Direction::North;
  
  if (a <= b) { Serial.println("5 North is less or equal to North"); }
  if (b == a) { Serial.println("6 North is equal than North"); }
  
  Direction c = Direction::North;
  
  Serial.println("Clockwise (using increment) :");
  for (int16_t i = 0; i < 16; ++i) { 
  
    printDirection(c);
    c++;
  
  }
  
  Direction d = Direction::South;
  
  Serial.println("");
  Serial.println("Anticlockwise (using decrement) :");
  for (int16_t i = 0; i < 16; ++i) { 
  
    printDirection(d);
    d--;
  
  }
  
}





