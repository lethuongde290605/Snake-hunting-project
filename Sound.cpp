#include "Sound.h"


void playEatingSound() {
	PlaySound(TEXT("eatingSound.wav"), NULL, SND_FILENAME | SND_SYNC);
}