/***************************************************** PUBLIC INTERFACE *******************************************************/

#ifndef MUSIC_H
#define MUSIC_H

typedef struct _music Music;

/**
 * @brief Cria uma nova música
 * 
 * @param musicName Nome da música
 * @param artistName Nome do artista
 * @param durationTime Duração da música (em segundos)
 * @return Music* Ponteiro para a música criada
 */
Music *MusicCreate(char *musicName, char *artistName, unsigned int durationTime);

/**
 * @brief Retorna o nome da música
 * 
 * @param music Ponteiro para a música
 * @return char* Nome da música
 */
char *MusicGetMusicName(Music *music);

/**
 * @brief Retorna o nome do artista
 * 
 * @param music Ponteiro para a música
 * @return char* Nome do artista
 */
char *MusicGetArtistName(Music *music);

/**
 * @brief Retorna a duração da música
 * 
 * @param music Ponteiro para a música
 * @return unsigned int Duração em segundos
 */
unsigned int MusicGetDurationTime(Music *music);

/**
 * @brief Retorna a próxima música da playlist
 * 
 * @param music Ponteiro para a música atual
 * @return Music* Ponteiro para a próxima música
 */
Music *MusicGetNext(Music *music);

/**
 * @brief Define o nome da música
 * 
 * @param music Ponteiro para a música
 * @param musicName Novo nome da música
 */
void MusicSetMusicName(Music *music, char *musicName);

/**
 * @brief Define o nome do artista
 * 
 * @param music Ponteiro para a música
 * @param artistName Novo nome do artista
 */
void MusicSetArtistName(Music *music, char *artistName);

/**
 * @brief Define a duração da música
 * 
 * @param music Ponteiro para a música
 * @param durationTime Duração em segundos
 */
void MusicSetDurationTime(Music *music, unsigned int durationTime);

/**
 * @brief Define a próxima música
 * 
 * @param music Ponteiro para a música atual
 * @param next Ponteiro para a próxima música
 */
void MusicSetNext(Music *music, Music *next);

/**
 * @brief Libera memória de uma música
 * 
 * @param music Ponteiro para a música a ser destruída
 */
void MusicDestroy(Music *music);

#endif 

/******************************************************************************************************************************/