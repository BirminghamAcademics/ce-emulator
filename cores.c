#include <tice.h>
#include <graphx.h>
#include <string.h>

#ifndef CORE_ID
#error define CORE_ID
#endif

uint8_t rom[0x8000];

void zx7_decompress(uint8_t* src,uint8_t* dst){
  memcpy(dst,src,0x8000); // placeholder
}

void save_state(void){
  // dump RAM to AppVar (stub)
}

void load_state(void){}

void emulate_frame(void){
  // CPU + PPU per frame
}

int main(void){
  gfx_Begin();
  gfx_FillScreen(0);

#if CORE_ID==1
  gfx_PrintStringXY("GB CORE",10,10);
#elif CORE_ID==3
  gfx_PrintStringXY("SMS CORE",10,10);
#elif CORE_ID==4
  gfx_PrintStringXY("GG CORE",10,10);
#endif

  while(1){
    emulate_frame();

    uint8_t k=os_GetCSC();
    if(k==sk_Mode) save_state();
    if(k==sk_Clear) break;
  }

  gfx_End();
  return 0;
}
