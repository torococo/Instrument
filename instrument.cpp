#include "SDL/SDL.h"
#include <vector>
#include <stdio.h>
using namespace std;

#define N_KEYS 316


int OpenAudio(SDL_AudioSpec initMe,int freq,int format,int nChannels,int samples, void(*callback)(void*,Uint8*,int)){
  initMe.freq=freq;
  initMe.format=format;
  initMe.channels=nChannels;
  initMe.callback=callback;
  initMe.userdata=NULL;
  if(SDL_OpenAudio(&initMe,NULL)<0){
    return -1;
  }
  return 0;
}

//prints keys
void PrintKeys(int* keys){
  for(int i=0;i<N_KEYS;i++){
    printf("%i,",keys[i]);
  }
  printf("\n");
}

//main
int main(int argc, char** argv){
  SDL_Event e;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_SetVideoMode(100,100,32,SDL_SWSURFACE);
  int keys[N_KEYS];
  for(int i=0;i<N_KEYS;i++){
    keys[i]=0;
  }
  while(1){
    SDL_WaitEvent(&e);
    if(e.type==SDL_QUIT){
      return 0;
    }
    if(e.type==SDL_KEYDOWN){
        keys[e.key.keysym.sym]=1;
    }
    else if(e.type==SDL_KEYUP){
      keys[e.key.keysym.sym]=0;
    }
    PrintKeys(keys);
  }
}


