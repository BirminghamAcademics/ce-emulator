#include <tice.h>
#include <graphx.h>

#ifndef CORE_ID
#error CORE_ID not defined
#endif

int main(void){
  gfx_Begin();
  gfx_FillScreen(0);

#if CORE_ID==1
  gfx_PrintStringXY("Game Boy Core",10,10);
#elif CORE_ID==3
  gfx_PrintStringXY("SMS Core",10,10);
#elif CORE_ID==4
  gfx_PrintStringXY("Game Gear Core",10,10);
#endif

  while(os_GetCSC()!=sk_Clear);
  gfx_End();
  return 0;
}
