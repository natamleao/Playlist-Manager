#include "../include/music.h"
#include <stdlib.h>
#include <string.h>

/**************************************************** PRIVATE INTERFACE *******************************************************/

struct _music{
    char *_musicName;
    char *_artistName;
    unsigned int _durationTime;
    struct _music *_next; 
};

/***************************************************** PUBLIC INTERFACE *******************************************************/

Music *MusicCreate(char *musicName, char *artistName, unsigned int durationTime){
    if(!musicName || !artistName) exit(EXIT_FAILURE);

    Music *newMusic = malloc(sizeof(Music));
    if(!newMusic) exit(EXIT_FAILURE);

    MusicSetMusicName(newMusic, malloc(strlen(musicName) + 1));
    MusicSetArtistName(newMusic, malloc(strlen(artistName) + 1));

    if(!MusicGetMusicName(newMusic) || !MusicGetArtistName(newMusic)) exit(EXIT_FAILURE);

    strcpy(MusicGetMusicName(newMusic), musicName);
    strcpy(MusicGetArtistName(newMusic), artistName);

    MusicSetDurationTime(newMusic, durationTime);
    MusicSetNext(newMusic, newMusic);

    return newMusic;
}

char *MusicGetMusicName(Music *music){return music->_musicName;}
char *MusicGetArtistName(Music *music){return music->_artistName;}
unsigned int MusicGetDurationTime(Music *music){return music->_durationTime;}
Music *MusicGetNext(Music *music){return music->_next;}

void MusicSetMusicName(Music *music, char *musicName){
    if(!music || !musicName) exit(EXIT_FAILURE);
    free(music->_musicName);
    music->_musicName = malloc(strlen(musicName)+1);
    if(!music->_musicName) exit(EXIT_FAILURE);
    strcpy(music->_musicName, musicName);
}

void MusicSetArtistName(Music *music, char *artistName){
    if(!music || !artistName) exit(EXIT_FAILURE);
    free(music->_artistName);
    music->_artistName = malloc(strlen(artistName)+1);
    if(!music->_artistName) exit(EXIT_FAILURE);
    strcpy(music->_artistName, artistName);
}

void MusicSetDurationTime(Music *music, unsigned int durationTime){
    if(!music) exit(EXIT_FAILURE);
    music->_durationTime = durationTime;
}

void MusicSetNext(Music *music, Music *next){
    if(!music) exit(EXIT_FAILURE);
    music->_next = next;
}

void MusicDestroy(Music *music){
    if(!music) return;
    free(music->_musicName);
    free(music->_artistName);
    free(music);
}

/******************************************************************************************************************************/