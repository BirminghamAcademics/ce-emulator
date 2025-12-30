#include <tice.h>
#include <fileioc.h>

#define EXEC ((void*)0xD40000)

void load(const char* name){
  ti_var_t v=ti_Open(name,"r");
  if(!v) return;
  ti_Read(EXEC,ti_GetSize(v),1,v);
  ti_Close(v);
  ((void(*)())EXEC)();
}

int main(void){
  os_ClrHome();
  os_PutStrFull("CHRONOS\n\n1: Game Boy\n2: SMS\n");

  while(1){
    uint8_t k=os_GetCSC();
    if(k==sk_1) load("CORE_GB");
    if(k==sk_2) load("CORE_SMS");
  }
}
