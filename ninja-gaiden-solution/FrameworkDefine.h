#ifndef FRAMEWORKDEFINE_H
#define FRAMEWORKDEFINE_H

#define SCREEN_HEIGHT 448

#define SCREEN_WIDTH 512

#define SAFE_DELETE(p)       if(p) { delete (p);     (p)=0; }

#define SAFE_DELETE_ARRAY(p) if(p) { delete[] (p);   (p)=0; }

#define SAFE_RELEASE(p)      if(p) { (p)->Release(); (p)=0; }




#define	GAMETITLE	"Ninja Gaiden"
#define	FRAME_RATE	60

#define	SPRITEHANDLE LPD3DXSPRITE

#define DIRECTINPUT_HEADER_VERSION  0x0800

#define DIRECTINPUT_VERSION         DIRECTINPUT_HEADER_VERSION

#endif