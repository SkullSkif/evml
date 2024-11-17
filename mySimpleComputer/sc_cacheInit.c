#include <mySimpleComputer.h>
#include <sc.h>

void
sc_initCache ()
{
  cache = calloc (CACHE_SIZE, sizeof (CacheLine));
  if (cache == NULL)
    {
      return;
    }

  for (size_t i = 0; i < CACHE_SIZE; ++i)
    {
      cache[i].address = -1;
      cache[i].lastAccessTime = 0;
    }
}