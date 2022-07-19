#include "playlist.h"
#include <stdio.h>
#include <stdlib.h>

/**************************************** PRIVATE INTERFACE ****************************************/

struct _music{
    char *name;
    char *music;
    unsigned int time;
    struct _music *nextMusic;
};

struct _playList{
    unsigned int size;
    Music *begin, *end;
};

Music *MusicCreate(char *music, char *name, unsigned int time){
    Music * newMusic = malloc(sizeof(Music));
    newMusic->name = name;
    newMusic->music = music;
    newMusic->time = time;
    newMusic->nextMusic = newMusic;
    return newMusic;
}

/**************************************** PUBLIC INTERFACE *****************************************/

PlayList *PlayListCreate(){
    PlayList *circularList = (PlayList*)malloc(sizeof(PlayList));
    circularList->size = 0;
    circularList->begin = NULL;
    circularList->end = NULL;
    return circularList;
}

void PlayListplay(const PlayList *circularList, unsigned int numberTimes){
    Music *copyBegin = circularList->begin;
    for(int i = 0; i < numberTimes * circularList->size; i++){
        printf("Musica: %s\n", copyBegin->name);
        copyBegin = copyBegin->nextMusic;
    }
}

void PlayListAdd(PlayList *circularList, char * name, char *music, unsigned int time){
    Music *newMusic = MusicCreate(music, name, time);
    if(circularList->begin == NULL && circularList->end == NULL){
        circularList->begin = newMusic;
        circularList->end = newMusic;
    }
    circularList->end->nextMusic = newMusic;
    newMusic->nextMusic = circularList->begin;
    circularList->end = newMusic;
    circularList->size++;
}

void PlayListRemove(PlayList *circularList, char *music){
    Music * copyBegin = circularList->begin;
    if(circularList->begin->music != music){
        while(copyBegin->nextMusic->music != music)
            copyBegin = copyBegin->nextMusic;
    }
    Music *deleteMusic = copyBegin->nextMusic;
    copyBegin->nextMusic = copyBegin->nextMusic->nextMusic;
    if(deleteMusic->nextMusic == circularList->begin)
        circularList->end = copyBegin;
    free(deleteMusic);
    if(circularList->size == 1){
        circularList->begin = NULL;
        circularList->end = NULL;
    }
    circularList->size--;
}

/***************************************************************************************************/