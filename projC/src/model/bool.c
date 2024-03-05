#include "../../include/model/bool.h"

bool max(bool a, bool b){
  if(a || b) return true;
}

bool min(bool a, bool b){
  if(!a || !b) return false;
}
