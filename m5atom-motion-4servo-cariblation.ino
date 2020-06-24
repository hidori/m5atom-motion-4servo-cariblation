#include <M5Atom.h>
#include <AtomMotion.h>

#define DIS_COLOR_BLUE  0x000000ff
#define DIS_COLOR_GREEN 0x0000ff00
#define DIS_COLOR_RED 0x00ff0000

AtomMotion Motion;

void setup()
{
  M5.begin(true, false, true);
  M5.dis.drawpix(0, DIS_COLOR_RED);

  Motion.Init();
  home();
}

void loop()
{
  M5.update();

  if(M5.Btn.wasPressed()){
    home();
  }

  delay(100);
}

void home()
{
  M5.dis.drawpix(0, DIS_COLOR_BLUE);

  for(int ch = 0; ch < 4; ch++){
    Motion.SetServoAngle(ch, 90);
  }

  delay(100);

  M5.dis.drawpix(0, DIS_COLOR_GREEN);
}
