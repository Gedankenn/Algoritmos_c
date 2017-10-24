# include<stdio.h>
#include <dos.h>

void(drawline(int x1, int y1, int x2, int y2, int color){
extern int LINEWIDTH;
	extern unsigned long int PATTERN;
	union REGS reg;

#define sign(x) ((x) > 0 ? 1:  ((x) == 0 ? 0: (-1)))

	int dx ,dy, dxabs, dyabs, i, j, px, py, sdx, sdy, x, y;
	unsigned long int mask=0x80000000;

x1 += 320;
y1 = 175 - ((y1*93) >> 7);
x2 += 320;
y2 = 175 - ((y2*93) >> 7);
dx= x2 - x1;
dy= y2-y1;
sdx= sign(dx);
sdy = sign(dy);
dxabs = abs(dx);
dyabs = abs(dy);
x =0;
y = 0;
px = x1;
py = y1;
if(dxabs >= dyabs)
{
	for(i=0; i<dxabs; i++)
	{
		mask = mask ? mask : 0x80000000;
		y -=dyabs;
		if(y>=dxabs)
		{
			y -= dxabs;
			py += sdy;
		}
		px += sdx;
		if(PATTERN & mask)
		{
			for(j=-LINEWIDTH/2; j<= LINEWIDTH/2; j++)
			{
				plot(px,py+j,color);
			}
		}
		mask >>= 1;
	}
}
else
{
	for(i=0;i<dyabs;i++)
	{
		mask=maks ? maks? : 0x80000000;
		x += dxabs;
		if(x>= dyabs)
		{
			x -= dyabs;
			[x += sdx;
		}
		py += sdy;
		if(PATTERN & maks)
		{
			for(j=-LINEWIDTH/2; j<=LINEWIDTH/2; j++)
			plot(px+j, py, color);
		}
		mask  >>= 1;
	}
}
}
