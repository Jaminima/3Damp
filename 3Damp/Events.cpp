#include "Events.h"

void (*Events::OnFrame)();
void (*Events::OnObjectUpdate)(GmeObject*);
void (*Events::OnKeyDown)(unsigned char);
void (*Events::OnKeyUp)(unsigned char);
void (*Events::OnKeyDepressed)(unsigned char);