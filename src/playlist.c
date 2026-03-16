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

unsigned int PlayListDuration(PlayList *playList){
    unsigned int totalTime = 0.0;
    Music *aux = PlayListGetBegin(playList);
    
    for(unsigned int i = 0; i < PlayListGetSize(playList); i++){
        totalTime += MusicGetDurationTime(aux);
        aux = MusicGetNext(aux);
    }

    return totalTime;
}

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

void PlayListSortByDuration(PlayList *playList){
    if(!playList || PlayListGetSize(playList) < 2) return;

    Music *begin = PlayListGetBegin(playList);
    Music *i = begin;

    do{
        Music *j = MusicGetNext(i);

        while(j != begin){
            if(MusicGetDurationTime(i) > MusicGetDurationTime(j)){

                char *musicTmp = MusicGetMusicName(i);
                char *artistTmp = MusicGetArtistName(i);
                unsigned int timeTmp = MusicGetDurationTime(i);

                MusicSetMusicName(i, MusicGetMusicName(j));
                MusicSetArtistName(i, MusicGetArtistName(j));
                MusicSetDurationTime(i, MusicGetDurationTime(j));

                MusicSetMusicName(j, musicTmp);
                MusicSetArtistName(j, artistTmp);
                MusicSetDurationTime(j, timeTmp);
            }

            j = MusicGetNext(j);
        }

        i = MusicGetNext(i);

    } while(i != begin);
}

Music *PlayListSearch(PlayList *playList, char *music, int *f){
    if(!playList || !music) return NULL;

    Music *aux = PlayListGetBegin(playList);

    for(unsigned int i = 0; i < PlayListGetSize(playList); i++){
        if(strcmp(MusicGetMusicName(aux), music) == 0){
            (*f) = 1;
            return aux;
        }

        aux = MusicGetNext(aux);
    }

    (*f) = 0;
    return NULL;
}

void PlayListSaveToFile(PlayList *playList, char *fileName, int *f){
    if(!playList || !fileName) return;

    FILE *file = fopen(fileName, "w");

    if(!file){
        (*f) = 0;
        return;
    }

    Music *aux = PlayListGetBegin(playList);

    for(unsigned int i = 0; i < PlayListGetSize(playList); i++){
        fprintf(file, "%s;%s;%u\n", MusicGetArtistName(aux), MusicGetMusicName(aux), MusicGetDurationTime(aux));

        aux = MusicGetNext(aux);
    }

    fclose(file);

    (*f) = 1;
}

void PlayListStats(PlayList *playList){
    if(!playList || PlayListGetSize(playList) == 0) return;

    unsigned int totalTime = PlayListDuration(playList);
    unsigned int size = PlayListGetSize(playList);

    unsigned int hours = totalTime / 3600;
    unsigned int minutes = (totalTime % 3600) / 60;
    unsigned int seconds = totalTime % 60;

    double average = (double) totalTime / size;

    Music *aux = PlayListGetBegin(playList);

    Music *longest = aux;
    Music *shortest = aux;

    for(unsigned int i = 0; i < PlayListGetSize(playList); i++){
        if(MusicGetDurationTime(aux) > MusicGetDurationTime(longest))
            longest = aux;

        if(MusicGetDurationTime(aux) < MusicGetDurationTime(shortest))
            shortest = aux;

        aux = MusicGetNext(aux);
    }

    printf("+---------------------------------------------------------------------------+\n");
    printf("+ MÚSICA MAIS LONGA: %s | %s | %u seg\n", MusicGetMusicName(longest), MusicGetArtistName(longest), MusicGetDurationTime(longest));
    printf("+---------------------------------------------------------------------------+\n");
    printf("+ MÚSICA MAIS CURTA: %s | %s | %u seg\n", MusicGetMusicName(shortest), MusicGetArtistName(shortest), MusicGetDurationTime(shortest));
    printf("+---------------------------------------------------------------------------+\n");
    printf("+ DURAÇÃO TOTAL DA PLAYLIST: %u h %u min %u s\n", hours, minutes, seconds);
    printf("+---------------------------------------------------------------------------+\n");
    printf("+ DURAÇÃO MÉDIA DAS MÚSICAS: %.2f segundos\n", average);
    printf("+---------------------------------------------------------------------------+\n");
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