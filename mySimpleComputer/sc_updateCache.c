#include <mySimpleComputer.h>
#include <sc.h>
#include <stdbool.h>
#include <time.h>

static void
updateCacheLine (int cacheIndex,
                 int address) // Обновления содержимого кэш-линии
{
  for (int j = 0; j < CACHE_LINE_SIZE; ++j)
    {
      cache[cacheIndex].data[j] = memory[address + j];
    }
  cache[cacheIndex].address = address;
  cache[cacheIndex].lastAccessTime = time (NULL);
}

void
sc_updateCacheAfterSave (int memaddress, int cacheLine, int *value)
{
  static bool initialized = false;
  static size_t currentIndex = 0;

  if (!initialized)
    {
      initialized = true;
      currentIndex = 0;
    }

  *value = memory[memaddress];

  int address = (cacheLine / 10) * 10;

  // Проверяем, есть ли уже запись в кеше для данного адреса
  size_t i;
  bool cacheHit = false;
  for (i = 0; i < CACHE_SIZE; ++i)
    {
      if (cache[i].address == address)
        {
          cacheHit = true;
          currentIndex = i; // Запоминаем индекс строки кеша, в которую попали
          break;
        }
    }

  if (!cacheHit)
    {
      if (i < CACHE_SIZE)
        {
          // Если кеш не заполнен, добавляем новую запись
          currentIndex = i;
        }
      else
        {
          // Если кеш полон, заменяем наименее используемую запись
          currentIndex = sc_findLeastRecentlyUsedCacheEntry ();
        }
      updateCacheLine (currentIndex, address);
    }
  else
    {
      // Обновляем существующую запись в кеше если найдено совпадение
      updateCacheLine (currentIndex, address);
    }
}