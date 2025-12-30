#include <tice.h>
#include <fileioc.h>

#define EXEC ((void*)0xD40000)

typedef struct {
  char magic[8];
  uint8_t core;
} ChronosHeader;

void runGame(void){
  ti_var_t g = ti_Open("GAME","r");
  if(!g) return;

  ChronosHeader h;
  ti_Read(&h,sizeof(h),1,g);
  ti_Close(g);

  const char* core =
    h.core==1 ? "CORE_GB" :
    h.core==3 ? "CORE_SMS" :
    "CORE_GG";

  ti_var_t c = ti_Open(core,"r");
  ti_Read(EXEC,ti_GetSize(c),1,c);
  ti_Close(c);

  ((void(*)())EXEC)();
}

int main(void){
  os_ClrHome();
  os_PutStrFull("CHRONOS\n[ENTER] Run");
  while(os_GetCSC()!=sk_Enter);
  runGame();
}
