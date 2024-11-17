#include <limits.h> // Для INT_MAX
#include <mySimpleComputer.h>
#include <sc.h>

int
sc_findLeastRecentlyUsedCacheEntry ()
{
  size_t leastRecentlyUsedIndex
      = INT_MAX; // Инициализация максимальным значением с наимсеньшим веремен
  time_t oldestAccessTime = LONG_MAX; // Инициализация максимальным значением
                                      // времени доступа с наибольшим временем

  for (size_t i = 0; i < CACHE_SIZE; ++i)
    {
      if (cache[i].lastAccessTime < oldestAccessTime)
        {
          oldestAccessTime = cache[i].lastAccessTime;
          leastRecentlyUsedIndex = i;
        }
    }

  return leastRecentlyUsedIndex;
}