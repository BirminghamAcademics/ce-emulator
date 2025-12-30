#include <tice.h>
#include <fileioc.h>
#include <string.h>

#define EXEC ((void*)0xD40000)

typedef struct {
  char magic[8];
  uint8_t core;
  uint16_t size;
} ChronosHeader;

void loadGame(void){
  ti_var_t v=ti_Open("GAME","r");
  if(!v) return;

  ChronosHeader h;
  ti_Read(&h,sizeof(h),1,v);

  const char* core =
    h.core==1 ? "CORE_GB" :
    h.core==3 ? "CORE_SMS" :
    "CORE_GG";

  ti_Close(v);

  ti_var_t c=ti_Open(core,"r");
  ti_Read(EXEC,ti_GetSize(c),1,c);
  ti_Close(c);

  ((void(*)())EXEC)();
}

int main(void){
  os_ClrHome();
  os_PutStrFull("CHRONOS\n\n[ENTER] Run Game");

  while(1)
    if(os_GetCSC()==sk_Enter)
      loadGame();
}
