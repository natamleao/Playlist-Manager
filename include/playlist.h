/**************************************** PUBLIC INTERFACE *****************************************/

#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct _playList PlayList;
typedef struct _music Music;

/**
 * @brief Adiciona uma nova música na playlist
 * 
 * @param circularList Lista de músicas 
 * @param name Nome do cantor
 * @param music Nome da música
 * @param time Tempo de duração da música
 */
void PlayListAdd(PlayList *circularList, char *name, char *music, unsigned int time);
/**
 * @brief 'Toca' as músicas da playlist
 * 
 * @param circularList Lista de músicas
 * @param numberTimes Número de vezes que se deve tocar as músicas
 */
void PlayListplay(const PlayList *circularList, unsigned int numberTimes);
/**
 * @brief Remove uma música da playlist 
 * 
 * @param circularList Lista de músicas
 * @param name Nome do cantor ao qual se quer remover a música
 */
void PlayListRemove(PlayList *circularList, char *name);
/**
 * @brief Cria a playlist
 * 
 * @return PlayList* 
 */
PlayList *PlayListCreate();

#endif

/***************************************************************************************************/