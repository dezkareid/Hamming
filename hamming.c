#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>

my_bool hamming_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
  if(args->arg_count != 2)
  {
   
    strcpy(message, "Cantidad de parametros incorrecto");
    return 1;
    
  }
  
  if(args->arg_type[0] != INT_RESULT || args->arg_type[1] != INT_RESULT)
  {
   
    strcpy(message,"Ambos campos deben ser enteros");
    return 1;
    
  }
  
  return 0;
}


long long hamming(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error)
 {
 
  
  long long c1 = *(long long*) args->args[0];
  
  long long c2 = *(long long*) args->args[1];
  
  long long dist = 0;
  
  long long val = c1^c2;
  
  while (val)
  {
    ++dist;
    val &= val - 1;
  }
  
  return dist;
 
 }
