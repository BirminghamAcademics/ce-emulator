#include <tice.h>
#include <graphx.h>

#ifndef CORE_ID
#error CORE_ID not defined
#endif

int main(void){
  gfx_Begin();
  gfx_FillScreen(0);

#if CORE_ID==1
  gfx_PrintStringXY("GAME BOY CORE",20,20);
#elif CORE_ID==3
  gfx_PrintStringXY("SMS CORE",20,20);
#endif

  while(1){
    if(os_GetCSC()==sk_Clear) break;
  }

  gfx_End();
  return 0;
}
