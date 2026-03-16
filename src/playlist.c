#include "../include/playlist.h"
#include "../include/music.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************************************************** PRIVATE INTERFACE *******************************************************/

struct _playList{
    unsigned int _size, _capacity;
    Music *_begin, *_end;
};

static void PlayListIncrementSize(PlayList *playList){playList->_size++;}
static void PlayListDecrementSize(PlayList *playList){if(playList->_size>0) playList->_size--;}
unsigned int PlayListGetCapacity(PlayList *playList){return playList->_capacity;}
void PlayListSetCapacity(PlayList *playList, unsigned int capacity){playList->_capacity = capacity;}

/***************************************************** PUBLIC INTERFACE *******************************************************/

PlayList *PlayListCreate(){
    PlayList *newPl = malloc(sizeof(PlayList));
    if(!newPl) exit(EXIT_FAILURE);
    PlayListSetSize(newPl, 0);
    PlayListSetBegin(newPl, NULL);
    PlayListSetEnd(newPl, NULL);
    PlayListSetCapacity(newPl, 250);

    return newPl;
}

Music *PlayListGetBegin(PlayList *playList){return playList->_begin;}
Music *PlayListGetEnd(PlayList *playList){return playList->_end;}
unsigned int PlayListGetSize(PlayList *playList){return playList->_size;}

void PlayListSetBegin(PlayList *playList, Music *begin){playList->_begin = begin;}
void PlayListSetEnd(PlayList *playList, Music *end){playList->_end = end;}
void PlayListSetSize(PlayList *playList, unsigned int size){playList->_size = size;}

void PlayListplay(PlayList *playList, unsigned int numberTimes, int *f){
    if(!playList || PlayListGetSize(playList) == 0) return;

    (*f) = 1;

    Music *aux = PlayListGetBegin(playList);
    unsigned int totalPlays = numberTimes * PlayListGetSize(playList);

    for(unsigned int i = 0; i < totalPlays; i++){
        printf("+ MÚSICA: %s | ARTISTA: %s | DURAÇÃO: %u\n", MusicGetMusicName(aux), MusicGetArtistName(aux), MusicGetDurationTime(aux));
        printf("+---------------------------------------------------------------------------+\n");

        aux = MusicGetNext(aux);
    }
}

void PlayListAdd(PlayList *playList, char *name, char *music, unsigned int time, int *f){
    if(!playList) return;  

    (*f) = 1;

    Music *newMusic = MusicCreate(music, name, time);

    if(!PlayListGetBegin(playList)){
        PlayListSetBegin(playList, newMusic);
        PlayListSetEnd(playList, newMusic);
        MusicSetNext(newMusic, newMusic); 
    } 
    
    else{
        Music *end = PlayListGetEnd(playList);
        MusicSetNext(end, newMusic);
        MusicSetNext(newMusic, PlayListGetBegin(playList));
        PlayListSetEnd(playList, newMusic);
    }

    PlayListIncrementSize(playList);
}

void PlayListRemove(PlayList *playList, char *music, int *f){
    if(!playList || PlayListGetSize(playList) == 0) return;

    Music *aux = PlayListGetBegin(playList);
    Music *prev = PlayListGetEnd(playList);

    for(unsigned int i = 0; i < PlayListGetSize(playList); i++){
        if(strcmp(MusicGetMusicName(aux), music) == 0){
            MusicSetNext(prev, MusicGetNext(aux));

            if(aux == PlayListGetBegin(playList)) PlayListSetBegin(playList, MusicGetNext(aux));
            if(aux == PlayListGetEnd(playList)) PlayListSetEnd(playList, prev);

            MusicDestroy(aux);
            PlayListDecrementSize(playList);

            if(PlayListGetSize(playList) == 0){
                PlayListSetBegin(playList, NULL);
                PlayListSetEnd(playList, NULL);
            }
            (*f) = 1;

            return; 
        }

        else
            (*f) = 0;
        prev = aux;
        aux = MusicGetNext(aux);
    }
}

void PlayListLoadFromFile(PlayList *playList, char *fileName, int *f, int *h){
    if(!playList || !fileName) return;

    FILE *file = fopen(fileName, "r");

    if(!file){
        (*h) = 0;
        return;
    }

    char artist[100];
    char music[100];
    unsigned int duration;

    while(fscanf(file, "%[^;];%[^;];%u\n", artist, music, &duration) != EOF)
        PlayListAdd(playList, artist, music, duration, f);

    fclose(file);

    (*h) = 1;
}

void PlayListPrint(PlayList *playList){
    if(!playList || PlayListGetSize(playList) == 0) return;

    Music *aux = PlayListGetBegin(playList);

    for(unsigned int i = 0; i < PlayListGetSize(playList); i++){
        printf("+ %d - %s | %s | %u seg\n", i+1, MusicGetMusicName(aux), MusicGetArtistName(aux), MusicGetDurationTime(aux));
        printf("+---------------------------------------------------------------------------+\n");

        aux = MusicGetNext(aux);
    }
}

void PlayListDestroy(PlayList *playList, int *f){
    if(!playList) return;

    while(PlayListGetSize(playList) > 0){
        Music *aux = PlayListGetBegin(playList);
        PlayListRemove(playList, MusicGetMusicName(aux), f);
    }

    free(playList);
}

/******************************************************************************************************************************/