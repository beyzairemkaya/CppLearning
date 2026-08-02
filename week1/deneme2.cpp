#include "deneme2.h"
// işte bu şekilde yaparsan multiple definition of doub hatası alırsın
// tabii ki deneme1 ve deneme2 yi birlikte compile ettiğinde

/*
Best practice
Do not put function and variable definitions in your header files (for now).
Defining either of these in a header file will likely result in a violation of the one-definition rule (ODR) if that 
header is then #included into more than one source (.cpp) file.

In future lessons, we will encounter additional kinds of definitions that can be safely defined in header files 
(because they are exempt from the ODR). This includes definitions for inline functions, inline variables, types, and templates.
 We’ll discuss this further when we introduce each of these.
*/
